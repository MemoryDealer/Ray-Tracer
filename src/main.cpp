// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Bitmap.h"
#include "Camera.h"
#include "Color.h"
#include "Light.h"
#include "Plane.h"
#include "Ray.h"
#include "Sphere.h"
#include "Vector3.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace RT;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

typedef std::vector<std::reference_wrapper<Object>> ObjectList;
typedef std::shared_ptr<Object> ObjectPtr;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

inline const uint32_t getFirstIntersection( const std::vector<double>& intersections )
{
    if ( intersections.size() == 0 ) {
        return -1;
    }

    if ( intersections.size() == 1 ) {
        if ( intersections[0] > 0 ) {
            return 0;
        }

        return -1;
    }

    // More than one intersection.
    // Find max first.
    double max = 0.;
    for ( auto& i : intersections ) {
        const double d = i;

        if ( max < d ) {
            max = d;
        }
    }

    // Find minimum from max.
    uint32_t minIndex = 0;
    if ( max > 0 ) {
        for ( uint32_t index = 0; index < intersections.size(); ++index ) {
            if ( intersections.at( index ) > 0 && intersections.at( index ) <= max ) {
                max = intersections.at( index );
                minIndex = index;
            }
        }

        return minIndex;
    }

    return -1;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

int main( int argc, char** argv )
{
    const uint32_t w = 640;
    const uint32_t h = 480;
    const double aspect = static_cast<double>( w ) / static_cast<double>( h );
    Color* pixels = new Color[w * h];
    
    Vector3 pos = Vector3( 0., 0., 10. );
    Vector3 lookAt = Vector3::NEGATIVE_UNIT_Z;
    Vector3 right = Vector3::UNIT_X;
    Vector3 down = Vector3::NEGATIVE_UNIT_Y;
    Camera cam( pos, lookAt, right, down );

    Light sceneLight( Vector3( 7., 10., 0. ), Color::WHITE );

    // Objects in scene.

    std::vector<ObjectPtr> objects;
    ObjectPtr sphere( new Sphere( Vector3(0., 0., 0.), 1., Color( 1., 0., 0. ) ) );
    objects.push_back( sphere );
    ObjectPtr plane( new Plane( Vector3( 0., 1., 0. ), -1., Color( 0., 0., 1. ) ) );
    objects.push_back( plane );

    double xa, ya;

    for ( int x = 0; x < w; ++x ) {
        for ( int y = 0; y < h; ++y ) {
            const int i = y * w + x;

            // Offset the position from the camera to the image plane.
            // No AA.
            if ( w > h ) {
                xa = ( ( x + 0.5 ) / w ) * aspect - ( ( w - h ) / static_cast<double>( h ) / 2. );
                ya = ( ( h - y ) + 0.5 ) / h;
            }
            else if ( h > w ) {
                xa = ( x + 0.5 ) / w;
                ya = ( ( ( h - y ) + 0.5 ) / h ) / aspect - ( ( h - w ) / static_cast<double>( w ) / 2. );
            }
            else {
                xa = ( x + 0.5 ) / w;
                ya = ( ( h - y ) + 0.5 ) / h;
            }

            // Create ray for this pixel.
            Vector3 rayOrigin = cam.getPosition();          
            Vector3 v = cam.getDown() * ( ya - 0.5 );
            Vector3 u = cam.getRight() * ( xa - 0.5 );
            Vector3 uv = u + v;
            Vector3 rayDirection = cam.getDirection() + uv;
            rayDirection.normalize();

            Ray camRay( rayOrigin, rayDirection );

            std::vector<double> intersections;

            for ( auto& i : objects ) {
                ObjectPtr object = i;
                const double intersection = object->getIntersection( camRay );
                intersections.push_back( intersection );
            }

            const uint32_t index = getFirstIntersection( intersections );

            printf( "%d", index );

            if ( index == -1 ) {
                pixels[i].setR( 1. );
                pixels[i].setG( 1. );
                pixels[i].setB( 1. );
            }
            else {
                Color c = objects[index]->getColor();

                pixels[i].setR( c.getR() );
                pixels[i].setG( c.getG() );
                pixels[i].setB( c.getB() );
            }
        }
    }

    Bitmap b( "p.bmp", w, h, 72, pixels );

    return 0;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Scene.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace RT;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Camera.h"
#include "Color.h"
#include "Light.h"
#include "Plane.h"
#include "Ray.h"
#include "Sphere.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

namespace SceneNS {

    inline const Vector3 getReflectionDirection( const Vector3& pos,
                                          const Vector3& dir,
                                          const Vector3& normal )
    {
        const double d1 = normal.dot( -dir );
        const Vector3 s1 = normal * d1;
        const Vector3 a1 = s1 + dir;
        const Vector3 s2 = a1 * 2;
        const Vector3 a2 = -dir + s2;
        return a2.normalizedCopy();
    }

}
using namespace SceneNS;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Scene::Scene( const uint32_t width,
              const uint32_t height )
: mWidth( width )
, mHeight( height )
, mAspectRatio( static_cast<double>( mWidth ) / static_cast<double>( mHeight ) )
, mCamera( nullptr )
, mPixels( new Color[ width * height ] )
, mObjects( )
, mLights( )
, mAmbient( 0.2 )
, mAccuracy( 0.000001 )
{
    // Setup camera with default values.
    mCamera.reset( new Camera( Vector3( 0., 2.5, 10. ),
                               (Vector3::NEGATIVE_UNIT_Z + Vector3(0., -0.15, 0.) ).normalizedCopy(),
                               Vector3::UNIT_X,
                               Vector3::NEGATIVE_UNIT_Y ) );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Scene::~Scene( void )
{
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Scene::addPlane( const Vector3& normal,
                      const double d,
                      const Color& color )
{
    mObjects.push_back( ObjectPtr( new Plane( normal, d, color ) ) );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Scene::addSphere( const Vector3& pos,
                       const double r,
                       const Color& color )
{
    mObjects.push_back( ObjectPtr( new Sphere( pos, r, color ) ) );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Scene::addLight( const Vector3& pos,
                      const Color& color )
{
    mLights.push_back( LightPtr( new Light( pos, color ) ) );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Scene::render( const uint32_t aaDepth )
{
    double xa, ya;
    const double aaThreshold = 0.1;

    for ( int x = 0; x < mWidth; ++x ) {
        for ( int y = 0; y < mHeight; ++y ) {
            const int i = y * static_cast<int>( mWidth ) + x;

            // Anti-aliasing fires additional rays for each pixel according to depth.
            // The average is calculated to form the final color.
            double* tempR = new double[aaDepth * aaDepth];
            double* tempG = new double[aaDepth * aaDepth];
            double* tempB = new double[aaDepth * aaDepth];

            // Offset the position from the camera to the image plane.
            // No AA.
            if ( mWidth > mHeight ) {
                xa = ( ( x + 0.5 ) / mWidth ) * mAspectRatio - 
                    ( ( mWidth - mHeight ) / static_cast<double>( mHeight ) / 2. );
                ya = ( ( mHeight - y ) + 0.5 ) / mHeight;
            }
            else if ( mWidth < mHeight ) {
                xa = ( x + 0.5 ) / mWidth;
                ya = ( ( ( mHeight - y ) + 0.5 ) / mHeight ) / mAspectRatio - 
                    ( ( mHeight - mWidth ) / static_cast<double>( mWidth ) / 2. );
            }
            else {
                xa = ( x + 0.5 ) / mWidth;
                ya = ( ( mHeight - y ) + 0.5 ) / mHeight;
            }

            // Create ray for this pixel.
            const Vector3 rayOrigin = mCamera->getPosition();
            const Vector3 v = mCamera->getDown() * ( ya - 0.5 );
            const Vector3 u = mCamera->getRight() * ( xa - 0.5 );
            const Vector3 uv = u + v;
            const Vector3 rayDirection = ( mCamera->getDirection() + uv ).normalizedCopy();
 
            const Ray camRay( rayOrigin, rayDirection );

            std::vector<double> intersections;

            for ( auto& i : mObjects ) {
                ObjectPtr object = i;
                const double intersection = object->getIntersection( camRay );
                intersections.push_back( intersection );
            }

            const int32_t index = getFirstIntersection( intersections );

            //printf( "%d", index );

            if ( index == -1 ) {
                mPixels[i].setR( 0. );
                mPixels[i].setG( 0. );
                mPixels[i].setB( 0. );
            }
            else if ( intersections[index] > 0.000001 ) {
                    const Vector3 p = rayOrigin + ( rayDirection * intersections[index] );
                    const Vector3 q = rayDirection;

                    const Color c = getColorAt( p, q, index );

                    mPixels[i] = c;
            }
            else {
                mPixels[i] = Color::BLACK;
            }

            delete [] tempR, tempG, tempB;
        }
    }
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const int32_t Scene::getFirstIntersection( const std::vector<double>& intersections )
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
            if ( intersections[index] > 0 && intersections[index] <= max ) {
                max = intersections[index];
                minIndex = index;
            }
        }

        return minIndex;
    }

    return -1;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const Color Scene::getColorAt( const Vector3& pos,
                               const Vector3& dir,
                               const uint32_t index )
{
    Vector3 objectNormal = mObjects[index]->getNormalAt( pos );
    Color objectColor = mObjects[index]->getColor();

    // Detect checkered color object.
    if ( objectColor == Color::CHECKER ) {
        int32_t square = static_cast<int>( std::floor( pos.getX() ) +
                                           std::floor( pos.getZ() ) );

        if ( ( square % 2 ) == 0 ) {
            objectColor = Color::BLACK;
        }
        else {
            objectColor = Color::WHITE;
        }
    }
    
    // The resulting pixel color.
    Color color = objectColor * mAmbient;

    // Test for reflections.
    if ( objectColor.getShininess() > 0. ) {
        const Vector3 rd = getReflectionDirection( pos, dir, objectNormal );
        Ray rr( pos, rd );

        std::vector<double> rintersections;
        for ( auto& i : mObjects ) {
            rintersections.push_back( i->getIntersection( rr ) );
        }

        const int32_t rindex = getFirstIntersection( rintersections );

        // No collision.
        if ( rindex != -1 ) {
            if ( rintersections[rindex] > mAccuracy ) {
                // Get position of the intersection by adding the distance * direction.
                Vector3 rpos = pos + ( rd * rintersections[rindex] );
                
                Color rcolor = getColorAt( rpos, rd, rindex );

                color = color + ( rcolor * objectColor.getShininess() );
            }
        }
    }

    // Test for shadows.
    for ( auto& i : mLights ) {
        Vector3 lightDir = i->getPosition() - pos;
        lightDir.normalize();

        double cosAngle = objectNormal.dot( lightDir );
        if ( cosAngle > 0 ) {
            bool shadowed = false;

            Vector3 distToLight = ( i->getPosition() - pos ).normalizedCopy();
            const double distToLightMag = distToLight.magnitude();

            // Test for another intersection towards light source. If there is 
            // one, this intersection is shadowed.
            Ray shadowRay( pos, distToLight );
            std::vector<double> shadowIntersections;

            for ( auto& i : mObjects ) {
                shadowIntersections.push_back( i->getIntersection( shadowRay ) );
            }

            for ( auto& i : shadowIntersections ) {
                if ( i > mAccuracy ) {
                    if ( i <= distToLightMag ) {
                        shadowed = true;
                        break;
                    }
                }
                
            }

            if ( !shadowed ) {
                color = color + objectColor * ( i->getColor() * cosAngle );

                if ( objectColor.getShininess() > 0. ) {
                    const Vector3 rd = getReflectionDirection( pos, dir, objectNormal );
                    double spec = rd.dot( lightDir );
                    if ( spec > 0 ) {
                        spec = std::pow( spec, 10 );
                        color = color + i->getColor() * ( spec * objectColor.getShininess() );
                    }
                }
            }
        }
    }

    return color.clip();
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
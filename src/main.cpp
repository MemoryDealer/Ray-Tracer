// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Bitmap.h"
#include "Color.h"
#include "Scene.h"
#include "Vector3.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace RT;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

int main( int argc, char** argv )
{
    const uint32_t width = 1920;
    const uint32_t height = 1080;
    Scene scene( width, height );

    // Objects in scene.
    Color planeColor = Color::CHECKER;
    planeColor.setShininess( 0. );
    Vector3 planeNormal = Vector3( 0., 1., 0. ).normalizedCopy();
    scene.addPlane( planeNormal, -1., planeColor );   

    const double angle = std::acos( planeNormal.dot( Vector3::UNIT_X ) );

    // Generate spheres that follow a sine pattern.
    uint32_t colorIndex = 0;
    for ( double d = 0.; d < 25.; d += 0.2 ) {
        Vector3 sphere;
        sphere.setZ( -( d * 15.) );
        sphere.setY( 10. * std::sin( d ) );
        sphere.rotate( Vector3::UNIT_Z, angle );

        scene.addSphere( sphere, 1., Color::BLACK );
        scene.addSphere( sphere + Vector3( 0., 2.0, 0. ), 1., Color::WHITE );
    }

    scene.addSphere( Vector3( 9., 5., -15. ), 6., Color::RED );
    scene.addSphere( Vector3( -8., 15., -20. ), 3.5, Color::CYAN );
    scene.addSphere( Vector3( -6., 2., 5. ), 2., Color::WHITE );
    scene.addSphere( Vector3( -30., 10., -30. ), 10., Color::BLACK );

    // Lights.
    scene.addLight( Vector3( 7., 10., 0. ), Color::WHITE );

    // Generate the pixel data.
    scene.render( 4 );

    // Save to BMP.
    Bitmap b( width, height, 72 );
    b.write( "render.bmp", scene.getPixels() );

    return 0;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
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
    const uint32_t width = 640;
    const uint32_t height = 480;
    Scene scene( width, height );

    // Objects in scene.
    Color planeColor = Color::CHECKER;
    planeColor.setShininess( 0. );
    scene.addPlane( Vector3( 0., 1., 0. ), -1., planeColor );
    scene.addSphere( Vector3( 0., 0., 0. ), 1., Color( 1., 0., 0. ) );
    scene.addSphere( Vector3( 2.5, 0., -1. ), 0.75, Color( 0., 1., 0.) );

    // Lights.
    scene.addLight( Vector3( -7., 10., 0. ), Color::WHITE );

    // Generate the pixel data.
    scene.render();

    // Save to BMP.
    Bitmap b( width, height, 72 );
    b.write( "render.bmp", scene.getPixels() );

    return 0;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
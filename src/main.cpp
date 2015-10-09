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

    double ambient = 0.2;
    double accuracy = 0.000001;

    // Objects in scene.
    scene.addPlane( Vector3( 0., 1., 0. ), -1., Color( 0., 0., 1. ) );
    scene.addSphere( Vector3( 0., 0., 0. ), 1., Color( 1., 0., 0. ) );

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
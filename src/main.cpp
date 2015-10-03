// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Bitmap.h"
#include "Camera.h"
#include "Color.h"
#include "Light.h"
#include "Vector3.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace RT;

int main( int argc, char** argv )
{
    const uint32_t w = 640;
    const uint32_t h = 480;
    Color* pixels = new Color[w * h];
    
    Vector3 pos = Vector3::ZERO;
    Vector3 lookAt = Vector3::NEGATIVE_UNIT_Z;
    Vector3 right = Vector3::UNIT_X;
    Vector3 down = Vector3::NEGATIVE_UNIT_Y;
    Camera( pos, lookAt, right, down );

    Light sceneLight( Vector3( 7., 10., 0. ), Color::WHITE );
    

    for ( int x = 0; x < w; ++x ) {
        for ( int y = 0; y < h; ++y ) {
            const int i = y * w + x;

            pixels[i].setR( 0. );
            pixels[i].setG( 0. );
            pixels[i].setB( 0. );
        }
    }

    Bitmap b( "p.bmp", w, h, 72, pixels );

    return 0;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
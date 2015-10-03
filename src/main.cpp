// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Bitmap.h"
#include "Color.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace RT;

int main( int argc, char** argv )
{
    const uint32_t w = 640;
    const uint32_t h = 480;

    Color* pixels = new Color[w * h];

    for ( int x = 0; x < w; ++x ) {
        for ( int y = 0; y < h; ++y ) {
            const int i = y * w + x;

            pixels[i].r = 0.;
            pixels[i].g = 0.;
            pixels[i].b = 0.;
        }
    }

    Bitmap b( "p.bmp", w, h, 72, pixels );

    return 0;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
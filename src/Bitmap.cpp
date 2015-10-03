// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Bitmap.h"

#include "Color.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace RT;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Bitmap::Bitmap( const std::string& filename,
                const uint32_t width,
                const uint32_t height,
                const uint32_t dpi,
                const Color* pixels )
{   
    const int k = width * height;
    const int s = 4 * k;
    const size_t size = 54 + s;
    const double factor = 39.375;
    const int m = static_cast<int>( factor );
    const int ppm = dpi * m;

    unsigned char fileHeader[14] = { 'B', 'M', 0,0,0,0, 0,0,0,0, 54,0,0,0 };
    unsigned char infoHeader[40] = { 40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,24,0 };

    // Prepare BMP header.
    fileHeader[2] = static_cast<char>( size );
    fileHeader[3] = static_cast<char>( size >> 8 );
    fileHeader[4] = static_cast<char>( size >> 16 );
    fileHeader[5] = static_cast<char>( size >> 24 );

    infoHeader[4] = static_cast<char>( width );
    infoHeader[5] = static_cast<char>( width >> 8 );
    infoHeader[6] = static_cast<char>( width >> 16 );
    infoHeader[7] = static_cast<char>( width >> 24 );

    infoHeader[8] = static_cast<char>( height );
    infoHeader[9] = static_cast<char>( height >> 8 );
    infoHeader[10] = static_cast<char>( height >> 16 );
    infoHeader[11] = static_cast<char>( height >> 24 );

    infoHeader[21] = static_cast<char>( s );
    infoHeader[22] = static_cast<char>( s >> 8 );
    infoHeader[23] = static_cast<char>( s >> 16 );
    infoHeader[24] = static_cast<char>( s >> 24 );

    infoHeader[25] = static_cast<char>( ppm );
    infoHeader[26] = static_cast<char>( ppm >> 8 );
    infoHeader[27] = static_cast<char>( ppm >> 16 );
    infoHeader[28] = static_cast<char>( ppm >> 24 );

    infoHeader[29] = static_cast<char>( ppm );
    infoHeader[30] = static_cast<char>( ppm >> 8 );
    infoHeader[31] = static_cast<char>( ppm >> 16 );
    infoHeader[32] = static_cast<char>( ppm >> 24 );


    // Open file and write header.
    std::ofstream file( filename, std::ofstream::binary );

    file.write( reinterpret_cast<const char*>( fileHeader ), sizeof( fileHeader ) );
    file.write( reinterpret_cast<const char*>( infoHeader ), sizeof( infoHeader ) );

    // Write pixel data.
    for ( int i = 0; i < k; ++i ) {
        Color c = pixels[i];

        const double r = c.r * 255;
        const double g = c.g * 255;
        const double b = c.b * 255;

        const char pixel[3] = { static_cast<char>( std::floor( b ) ), 
                                static_cast<char>( std::floor( g ) ),
                                static_cast<char>( std::floor( b ) ) };

        file.write( pixel, sizeof( pixel ) );
    }

    file.close();
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Bitmap::~Bitmap( void )
{

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
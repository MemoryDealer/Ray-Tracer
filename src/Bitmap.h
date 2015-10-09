// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

namespace RT {

    class Color;

    class Bitmap final {

    public:

        explicit Bitmap( const uint32_t width,
                         const uint32_t height,
                         const uint32_t dpi );

        ~Bitmap( void );

        const bool write( const std::string& filename,
                         const Color* pixels );

    private:

        uint32_t mWidth, mHeight, mDPI;

    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

namespace RT {

    struct Color;

    class Bitmap final {

    public:

        explicit Bitmap( const std::string& filename,
                         const uint32_t width,
                         const uint32_t height,
                         const uint32_t dpi,
                         const Color* pixels );

        ~Bitmap( void );

    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

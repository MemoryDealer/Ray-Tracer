// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Color.h"
#include "Vector3.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

namespace RT {

    class Light
    {

    public:

        explicit Light( const Vector3& pos,
                        const Color& color );

        explicit Light( void );

        ~Light( void );

        // Getters:

        const Vector3& getPosition( void ) const { return mPosition; }
        const Color& getColor( void ) const { return mColor; }

    private:

        Vector3 mPosition;
        Color mColor;

    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Vector3.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

namespace RT {

    // ( An infinite line in 3-space ).
    class Ray{

    public:

        explicit Ray( void );

        explicit Ray( const Vector3& origin, const Vector3& direction );

        ~Ray( void );

        // Getters:

        const Vector3& getOrigin( void ) const { return mOrigin; }
        const Vector3& getDirection( void ) const { return mDirection; }

    private:

        Vector3 mOrigin, mDirection;

    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

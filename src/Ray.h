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

    private:

        Vector3 mOrigin, mDirection;

    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

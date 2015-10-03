// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Vector3.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

namespace RT {

    class Camera
    {

    public:

        explicit Camera( void );

        explicit Camera( const Vector3& pos,
                         const Vector3& dir,
                         const Vector3& right,
                         const Vector3& down );

        ~Camera( void );

        // Getters:

        const Vector3& getPosition( void ) const { return mPosition; }
        const Vector3& getDirection( void ) const { return mDirection; }
        const Vector3& getRight( void ) const { return mRight; }
        const Vector3& getDown( void ) const { return mDown; }

    private:

        Vector3 mPosition, mDirection, mRight, mDown;

    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

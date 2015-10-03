// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Object.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

namespace RT {

    class Plane : public Object
    {

    public:

        explicit Plane( const Vector3& normal,
                        const double d,
                        const Color& color );

        explicit Plane( void );

        virtual ~Plane( void ) override;

        virtual const Vector3 getNormalAt( const Vector3& p ) override;

        // Returns distance from ray origin to point of intersection.
        virtual const double getIntersection( const Ray& ray ) override;

        // Getters:

        const Vector3& getNormal( void ) const { return mNormal; }
        const double getDistance( void ) const { return mDistance; }
        virtual const Color getColor( void ) const { return mColor; }

    private:

        Vector3 mNormal;
        double mDistance;
        Color mColor;

    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Object.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

namespace RT {

    class Sphere : public Object
    {

    public:

        explicit Sphere( const Vector3& center,
                         const double r,
                         const Color& color );

        explicit Sphere( void );

        virtual ~Sphere( void ) override;

        virtual const Vector3 getNormalAt( const Vector3& p ) override;

        virtual const double getIntersection( const Ray& ray ) override;

        // Getters:

        const Vector3& getCenter( void ) const { return mCenter; }
        const double getRadius( void ) const { return mRadius; }
        virtual const Color getColor( void ) const override { return mColor; }

    private:

        Vector3 mCenter;
        double mRadius;
        Color mColor;

    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

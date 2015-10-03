// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Color.h"
#include "Vector3.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

namespace RT {

    class Ray;

    class Object
    {

    public:

        explicit Object( void ) { }

        virtual ~Object( void ) = 0 { }

        virtual const Color getColor( void ) const { return Color::BLACK; }

        virtual const Vector3 getNormalAt( const Vector3& p ) { return Vector3::ZERO; }

        virtual const double getIntersection( const Ray& ray ) { return 0.; }

    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

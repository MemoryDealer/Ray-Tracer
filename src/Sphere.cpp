// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Sphere.h"

#include "Ray.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace RT;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Sphere::Sphere( const Vector3& center,
                const double r,
                const Color& color )
: mCenter( center )
, mRadius( r )
, mColor( color )
{
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Sphere::Sphere( void )
: mCenter( Vector3::ZERO )
, mRadius( 0. )
, mColor( Color::BLACK )
{
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Sphere::~Sphere( void )
{

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const Vector3 Sphere::getNormalAt( const Vector3& p )
{
    // Normal direction goes from center out towards the point.
    Vector3 n = p - mCenter;
    return n.normalizedCopy();
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const double Sphere::getIntersection( const Ray& ray )
{
    Vector3 rayOrigin = ray.getOrigin();
    Vector3 rayDir = ray.getDirection();

    const double a = 1;
    const double b = ( 2. * ( rayOrigin.getX() - mCenter.getX() ) * rayDir.getX() ) +
        ( 2. * ( rayOrigin.getY() - mCenter.getY() ) * rayDir.getY() ) +
        ( 2. * ( rayOrigin.getZ() - mCenter.getZ() ) * rayDir.getZ() );
    const double c = std::pow( rayOrigin.getX() - mCenter.getX(), 2 ) +
        std::pow( rayOrigin.getY() - mCenter.getY(), 2 ) +
        std::pow( rayOrigin.getZ() - mCenter.getZ(), 2 ) - ( mRadius * mRadius );
    
    const double discr = b * b - 4 * c;
    if ( discr > 0. ) {
        // Intersection occurred, find smallest positive root.
        const double r1 = ( ( -1. * b - std::sqrt( discr ) ) / 2. ) - 0.000001;
        if ( r1 > 0 ) {
            return r1;
        }

        const double r2 = ( ( std::sqrt( discr ) - b ) / 2. ) - 0.000001;
        return r2;
    }
    
    return -1.;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
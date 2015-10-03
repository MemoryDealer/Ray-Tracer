// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Plane.h"

#include "Ray.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace RT;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Plane::Plane( const Vector3& normal,
              const double d,
              const Color& color )
: mNormal( normal )
, mDistance( d )
, mColor( color )
{
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Plane::Plane( void )
: mNormal( Vector3::UNIT_Y )
, mDistance( 0. )
, mColor( Color::BLACK )
{
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Plane::~Plane( void )
{
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const Vector3 Plane::getNormalAt( const Vector3& p )
{
    return mNormal;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const double Plane::getIntersection( const Ray& ray )
{
    Vector3 rayDir = ray.getDirection();

    double a = rayDir.dot( mNormal );

    if ( a == 0 ) {        
        return -1.;
    }

    Vector3 nn = -( mNormal * mDistance ) + ray.getOrigin();
    const double b = mNormal.dot( nn );
    return -1. * ( b / a );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
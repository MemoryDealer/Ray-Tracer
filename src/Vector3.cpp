// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Vector3.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace RT;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const Vector3 Vector3::ZERO = Vector3( 0., 0., 0. );
const Vector3 Vector3::UNIT_X = Vector3( 1., 0., 0. );
const Vector3 Vector3::UNIT_Y = Vector3( 0., 1., 0. );
const Vector3 Vector3::UNIT_Z = Vector3( 0., 0., 1. );
const Vector3 Vector3::NEGATIVE_UNIT_X = Vector3( -1., 0., 0. );
const Vector3 Vector3::NEGATIVE_UNIT_Y = Vector3( 0., -1., 0. );
const Vector3 Vector3::NEGATIVE_UNIT_Z = Vector3( 0., 0., -1. );

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Vector3::Vector3( void )
: mX( 0. )
, mY( 0. )
, mZ( 0. )
{
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Vector3::Vector3( const double x,
                  const double y,
                  const double z )
: mX( x )
, mY( y )
, mZ( z )
{
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Vector3::~Vector3( void )
{
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const double Vector3::magnitude( void ) const
{
    return std::sqrt( mX * mX + mY * mY + mZ * mZ );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const double Vector3::magnitudeSquared( void ) const
{
    return ( mX * mX + mY * mY + mZ * mZ );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const double Vector3::normalize( void )
{
    double mag = magnitude();

    if ( mag > 0.0 ) {
        double inv = 1.0 / mag;
        mX *= inv;
        mY *= inv;
        mZ *= inv;
    }

    return mag;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const Vector3 Vector3::normalizedCopy( void )
{
    Vector3 v = *this;
    v.normalize();
    return v;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const Vector3 Vector3::normalizedCopy( void ) const
{
    Vector3 v = *this;
    v.normalize();
    return v;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const double Vector3::dot( const Vector3& r ) const
{
    return mX * r.getX() + mY * r.getY() + mZ * r.getZ();
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const Vector3 Vector3::cross( const Vector3& r )
{
    return Vector3(
        mY * r.getZ() - mZ * r.getY(),
        mZ * r.getX() - mX * r.getZ(),
        mX * r.getY() - mY * r.getX() );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const Vector3 Vector3::cross( const Vector3& r ) const
{
    return Vector3(
        mY * r.getZ() - mZ * r.getY(),
        mZ * r.getX() - mX * r.getZ(),
        mX * r.getY() - mY * r.getX() );
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

void Vector3::rotate( const Vector3& axis, const double angle )
{
    // Ensure axis is a normal vector.
    const Vector3 k = axis.normalizedCopy();
    const Vector3 v = *this;

    // Use Rodrigues' rotation formula.
    Vector3 v_rot = v * std::cos( angle ) +
        ( k.cross( v ) * std::sin( angle ) ) +
        k * k.dot( v ) * ( 1. - std::cos( angle ) );
    *this = v_rot;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const Vector3 Vector3::rotatedCopy( const Vector3& axis, const double angle )
{
    // Ensure axis is a normal vector.
    const Vector3 k = axis.normalizedCopy();
    const Vector3 v = *this;

    // Use Rodrigues' rotation formula.
    Vector3 v_rot = v * std::cos( angle ) + 
        ( k.cross( v ) * std::sin( angle ) ) + 
        k * k.dot( v ) * ( 1. - std::cos( angle ) );
    return v_rot;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
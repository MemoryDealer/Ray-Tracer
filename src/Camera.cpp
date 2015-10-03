// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Camera.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace RT;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Camera::Camera( void )
: mPosition( Vector3::ZERO )
, mDirection( Vector3::UNIT_Z )
, mRight( Vector3::ZERO )
, mDown( Vector3::ZERO )
{
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Camera::Camera( const Vector3& pos,
                const Vector3& dir,
                const Vector3& right,
                const Vector3& down )
: mPosition( pos )
, mDirection( dir )
, mRight( right )
, mDown( down )
{
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Camera::~Camera( void )
{
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
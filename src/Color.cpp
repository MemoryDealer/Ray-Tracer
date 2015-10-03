// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Color.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace RT;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const Color Color::WHITE = Color( 1., 1., 1. );
const Color Color::BLACK = Color( 0., 0., 0. );

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Color::Color( const double r,
              const double g,
              const double b,
              const double a )
: mR( r )
, mG( g )
, mB( b )
, mA( a )
{
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Color::Color( void )
: mR( 0. )
, mG( 0. )
, mB( 0. )
, mA( 0. )
{
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Color::~Color( void )
{
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
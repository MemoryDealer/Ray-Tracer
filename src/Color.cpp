// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#include "Color.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

using namespace RT;

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

const Color Color::WHITE = Color( 1., 1., 1. );
const Color Color::BLACK = Color( 0., 0., 0. );
const Color Color::RED = Color( 1., 0., 0. );
const Color Color::GREEN = Color( 0., 1., 0. );
const Color Color::BLUE = Color( 0., 0., 1. );
const Color Color::FORESTGREEN = Color( 127. / 255., 0., 1. );
const Color Color::GOLD = Color( 1., 0.84, 0. );
const Color Color::ORANGE = Color( 1., 165. / 255., 0. );
const Color Color::YELLOW = Color( 1., 1., 0. );
const Color Color::PURPLE = Color( 204. / 255., 0., 1. );
const Color Color::CYAN = Color( 0., 1., 1. );
const Color Color::TEAL = Color( 0., 128. / 255., 128. / 255. );
const Color Color::PINK = Color( 1., 0., 1. );
const Color Color::CHECKER = Color( -1., -1., -1. );

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Color::Color( const double r,
              const double g,
              const double b,
              const double s )
: mR( r )
, mG( g )
, mB( b )
, mShininess( s )
{
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Color::Color( void )
: mR( 0. )
, mG( 0. )
, mB( 0. )
, mShininess( 0.3 )
{
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

Color::~Color( void )
{
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //
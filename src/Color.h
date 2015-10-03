// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

namespace RT {

    class Color
    {

    public:

        explicit Color( const double r,
                        const double g,
                        const double b,
                        const double a = 1. );

        explicit Color( void );

        ~Color( void );

        const double getBrightness( void ) const
        {
            return ( mR + mG + mB ) / 3.;
        }

        // Getters:

        const double getR( void ) const { return mR; }
        const double getG( void ) const { return mG; }
        const double getB( void ) const { return mB; }
        const double getA( void ) const { return mA; }

        // Setters:

        void setR( const double r ) { mR = r; }
        void setG( const double g ) { mG = g; }
        void setB( const double b ) { mB = b; }
        void setA( const double a ) { mA = a; }

        // Static colors:

        static const Color WHITE;
        static const Color BLACK;

    private:

        double mR, mG, mB, mA;

    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

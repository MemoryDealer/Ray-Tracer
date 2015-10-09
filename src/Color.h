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

        const Color average( const Color& r )
        {
            return Color(
                ( mR + r.mR ) / 2,
                ( mG + r.mG ) / 2,
                ( mB + r.mB ) / 2 );
        }

        const Color clip( void )
        {
            double all = mR + mG + mB;
            double exc = all - 3.;
            if ( exc > 0 ) {
                mR = mR + exc * ( mR / all );
                mG = mG + exc * ( mG / all );
                mB = mB + exc * ( mR / all );
            }

            if ( mR > 1. ) mR = 1.;
            else if ( mR < 0. ) mR = 0.;
            if ( mG > 1. ) mG = 1.;
            else if ( mG < 0. ) mG = 0.;
            if ( mB > 1. ) mB = 1.;
            else if ( mB < 0. ) mB = 0.;

            return *this;
        }

        inline Color& operator = ( const Color& r )
        {
            mR = r.mR;
            mG = r.mG;
            mB = r.mB;
            mA = r.mA;

            return *this;
        }

        inline Color operator + ( const Color& r )
        {
            return Color(
                mR + r.mR,
                mG + r.mG,
                mB + r.mG,
                mA + r.mA );
        }

        inline Color operator + ( const Color& r ) const
        {
            return Color(
                mR + r.mR,
                mG + r.mG,
                mB + r.mG,
                mA + r.mA );
        }

        inline Color operator * ( const Color& r )
        {
            return Color(
                mR * r.mR,
                mG * r.mG,
                mB * r.mB,
                mA * r.mA );
        }

        inline Color operator * ( const double s )
        {
            return Color(
                mR * s,
                mG * s,
                mB * s,
                mA * s );
        }

        inline Color operator * ( const double s ) const
        {
            return Color(
                mR * s,
                mG * s,
                mB * s,
                mA * s );
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

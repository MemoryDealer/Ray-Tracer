// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

namespace RT {

    class Vector3
    {

    public:

        explicit Vector3( void );

        explicit Vector3( const double x,
                          const double y,
                          const double z );

        ~Vector3( void );

        // Calculations:

        const double magnitude( void ) const;

        const double magnitudeSquared( void ) const;

        const double normalize( void );

        const Vector3 normalizedCopy( void );

        const Vector3 normalizedCopy( void ) const;

        const double dot( const Vector3& r ) const;

        const Vector3 cross( const Vector3& r );

        // Operators:

        inline Vector3& operator = ( const Vector3& r )
        {
            mX = r.mX;
            mY = r.mY;
            mZ = r.mZ;

            return *this;
        }

        inline bool operator == ( const Vector3& r )
        {
            return ( mX == r.mX &&
                     mY == r.mY &&
                     mZ == r.mZ );
        }

        inline Vector3 operator + ( const Vector3& r )
        {
            return Vector3(
                mX + r.mX,
                mY + r.mY,
                mZ + r.mZ );
        }

        inline Vector3 operator + ( const Vector3& r ) const
        {
            return Vector3(
                mX + r.mX,
                mY + r.mY,
                mZ + r.mZ );
        }

        inline Vector3 operator - ( const Vector3& r )
        {
            return Vector3(
                mX - r.mX,
                mY - r.mY,
                mZ - r.mZ );
        }

        inline Vector3 operator - ( const Vector3& r ) const
        {
            return Vector3(
                mX - r.mX,
                mY - r.mY,
                mZ - r.mZ );
        }

        inline Vector3 operator - ( void ) const
        {
            return Vector3( -mX, -mY, -mZ );
        }

        inline Vector3 operator * ( const Vector3& r )
        {
            return Vector3(
                mX * r.mX,
                mY * r.mY,
                mZ * r.mZ );
        }

        inline Vector3 operator * ( const double s )
        {
            return Vector3(
                mX * s,
                mY * s,
                mZ * s );
        }

        inline Vector3 operator * ( const double s ) const
        {
            return Vector3(
                mX * s,
                mY * s,
                mZ * s );
        }

        inline Vector3 operator / ( const Vector3& r )
        {
            return Vector3(
                mX / r.mX,
                mY / r.mY,
                mZ / r.mZ );
        }

        // Getters:

        const double getX( void ) const { return mX; }
        const double getY( void ) const { return mY; }
        const double getZ( void ) const { return mZ; }

        // Static unit vectors for each axis.

        static const Vector3 ZERO;
        static const Vector3 UNIT_X;
        static const Vector3 UNIT_Y;
        static const Vector3 UNIT_Z;
        static const Vector3 NEGATIVE_UNIT_X;
        static const Vector3 NEGATIVE_UNIT_Y;
        static const Vector3 NEGATIVE_UNIT_Z;

    private:

        double mX, mY, mZ;

    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

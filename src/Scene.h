// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

#pragma once

#include "Vector3.h"

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //

namespace RT {

    class Camera;
    class Color;
    class Light;
    class Object;

    typedef std::shared_ptr<Object> ObjectPtr;
    typedef std::shared_ptr<Light> LightPtr;
    typedef std::vector<ObjectPtr> ObjectList;
    typedef std::vector<LightPtr> LightList;
    typedef std::vector<double> IntersectionList;


    class Scene final {

    public:

        explicit Scene( const uint32_t width,
                        const uint32_t height );

        ~Scene( void );

        void addPlane( const Vector3& normal,
                       const double d,
                       const Color& color );

        void addSphere( const Vector3& pos,
                        const double r,
                        const Color& color );

        void addLight( const Vector3& pos,
                       const Color& color );

        void render( const uint32_t aaDepth = 1 );

        // Getters:

        const Color* getPixels( void ) const
        {
            return mPixels;
        }

    private:

        const int32_t getFirstIntersection( const std::vector<double>& intersections );
        const Color getColorAt( const Vector3& pos,
                                const Vector3& dir,
                                const uint32_t index );

    private:

        double mWidth, mHeight;
        double mAspectRatio;

        // Logical representation of scene view.
        std::shared_ptr<Camera> mCamera;

        // Each pixel whose color must be calculated.
        Color* mPixels;

        // Objects in scene.
        ObjectList mObjects;
        LightList mLights;

        double mAmbient;
        double mAccuracy;
    };

}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: //


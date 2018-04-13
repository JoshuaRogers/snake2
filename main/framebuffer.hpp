#ifndef __FRAMEBUFFER_HPP__
#define __FRAMEBUFFER_HPP__

#include "globals.hpp"

class FrameBuffer
{
    public:
        void clear();

        unsigned char r[X_SIZE * Y_SIZE * Z_SIZE];
        unsigned char g[X_SIZE * Y_SIZE * Z_SIZE];
        unsigned char b[X_SIZE * Y_SIZE * Z_SIZE];
};

#endif
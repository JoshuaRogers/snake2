#ifndef __GRAPHICSDRIVER_HPP__
#define __GRAPHICSDRIVER_HPP__

#include "framebuffer.hpp"

class GraphicsDriver
{
    public:
        GraphicsDriver(Cube);
        void update(double ratio);
        void flip();
        void clear();
        void setVoxel(unsigned char, unsigned char, unsigned char, Color);

    private:
        FrameBuffer _sourceBuffer;
        FrameBuffer _targetBuffer;
        Cube _cube;
};

#endif
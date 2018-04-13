#include "framebuffer.hpp"

void FrameBuffer::clear()
{
    for (auto i = 0; i < X_SIZE * Y_SIZE * Z_SIZE; i++) {
        r[i] = 0;
        g[i] = 0;
        b[i] = 0;
    }
}
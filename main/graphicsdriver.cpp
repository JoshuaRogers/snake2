#include "graphicsdriver.hpp"

GraphicsDriver::GraphicsDriver(Cube cube) : _cube(cube)
{
    _cube.begin();
    _sourceBuffer.clear();
    _targetBuffer.clear();
}

void GraphicsDriver::update(double percentSource)
{
    auto percentTarget = 1 - percentSource;
    _cube.background(black);

    for (auto i = 0; i < X_SIZE * Y_SIZE * Z_SIZE; i++) {
        // @Todo: Make this a little less ugly
        auto r1 = _sourceBuffer.r[i] * percentSource;
        auto r2 = _targetBuffer.r[i] * percentTarget;
        auto g1 = _sourceBuffer.g[i] * percentSource;
        auto g2 = _targetBuffer.g[i] * percentTarget;
        auto b1 = _sourceBuffer.b[i] * percentSource;
        auto b2 = _targetBuffer.b[i] * percentTarget;
        _cube.setVoxel(i, Color(r1 + r2, g1 + g2, b1 + b2));
    }
    _cube.show();
}

void GraphicsDriver::setVoxel(unsigned char x, unsigned char y, unsigned char z, Color color)
{
    auto index = (z * Z_SIZE * Z_SIZE) + (y * Y_SIZE) + x;
    _sourceBuffer.r[index] = color.red;
    _sourceBuffer.g[index] = color.green;
    _sourceBuffer.b[index] = color.blue;
}

void GraphicsDriver::clear()
{
    _sourceBuffer.clear();
}

void GraphicsDriver::flip()
{
    for (auto i = 0; i < X_SIZE * Y_SIZE * Z_SIZE; i++) {
        _targetBuffer.r[i] = _sourceBuffer.r[i];
        _targetBuffer.g[i] = _sourceBuffer.g[i];
        _targetBuffer.b[i] = _sourceBuffer.b[i];
    }

}
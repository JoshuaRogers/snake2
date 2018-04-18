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

double clamp(double v, double low, double high)
{
    return max(low, min(high, v));
}

Color GraphicsDriver::fromHSV(int h, double s, double v)
{
    auto hue = h % 360;
    auto saturation = clamp(s, 0, 1);
    auto value = clamp(v, 0, 1);

    double h1 = hue / 60.0;
    int h2 = floor(h1);
    
    double f = h1 - h2;
    
    double v1 = 255 * v;
    double pv = v1 * (1 - s);
    double qv = v1 * (1 - s * f);
    double tv = v1 * (1 - s * (1 - f));
    
    if (h2 == 0) { return Color(v1, tv, pv); }
    if (h2 == 1) { return Color(qv, v1, pv); }
    if (h2 == 2) { return Color(pv, v1, tv); }
    if (h2 == 3) { return Color(pv, qv, v1); }
    if (h2 == 4) { return Color(tv, pv, v1); }
    if (h2 == 5) { return Color(v1, pv, qv); }
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
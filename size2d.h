#ifndef SIZE_H
#define SIZE_H

struct Size2D
{
    Size2D(int _width, int _height): width(_width), height(_height)
    {
        if(width < 0 || height < 0)
        {
            throw std::invalid_argument("Size2D::Size2D(width,height): incorrect size");
        }
    }

    int width;
    int height;
};

#endif // SIZE_H

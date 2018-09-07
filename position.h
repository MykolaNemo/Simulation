#ifndef POSITION_H
#define POSITION_H

struct Position
{
    Position(): x(0),y(0){}
    Position(const int _x, const int _y): x(_x),y(_y){}

    bool operator==(const Position& other) const
    {
        return (x == other.x) && (y == other.y);
    }
    int x;
    int y;
};

#endif // POSITION_H

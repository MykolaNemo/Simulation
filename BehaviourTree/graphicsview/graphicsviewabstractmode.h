#ifndef GRAPHICSVIEWABSTRACTMODE_H
#define GRAPHICSVIEWABSTRACTMODE_H

class QMouseEvent;

class GraphicsViewAbstractMode
{
public:
    enum class Mode
    {
        None,
        Normal,
        ArrowPlace
    };
    virtual Mode getMode() const = 0;
    virtual Mode mousePress(QMouseEvent* /*event*/)
    {
        return Mode::None;
    }
    virtual Mode mouseMove(QMouseEvent* /*event*/)
    {
        return Mode::None;
    }
};

#endif // GRAPHICSVIEWABSTRACTMODE_H

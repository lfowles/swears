#ifndef _SWEARS_WIDGETS_FILLWIDGET_HPP_
#define _SWEARS_WIDGETS_FILLWIDGET_HPP_

#include "widget.hpp"

namespace Swears
{
    class FillWidget : public Widget
    {
    public:
        FillWidget(const Vec2& minsize, char fill) : minsize(minsize), fill(fill) {};

        virtual void Draw(Vec2 &pos, Vec2 &size) override;
        virtual const Vec2 GetMinSize(void) override { return minsize; }

    private:
        Vec2 minsize;
        char fill;
    };
}

#endif // _SWEARS_WIDGETS_FILLWIDGET_HPP_

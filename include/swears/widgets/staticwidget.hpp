#ifndef _SWEARS_WIDGETS_STATICWIDGET_HPP_
#define _SWEARS_WIDGETS_STATICWIDGET_HPP_

#include "widget.hpp"

namespace Swears
{

    class StaticWidget : public Widget
    {
    public:
        StaticWidget() = default;
        explicit StaticWidget(const Vec2& size) : static_size(size) {};

        const Vec2 GetMinSize() { return static_size; }

        virtual void Draw(Vec2& pos, Vec2& size, Window& window);

    private:
        Vec2 static_size{};
    };
}

#endif // _SWEARS_WIDGETS_STATICWIDGET_HPP_

#ifndef _SWEARS_WIDGETS_STATICWIDGET_HPP_
#define _SWEARS_WIDGETS_STATICWIDGET_HPP_

#include "widget.hpp"

namespace Swears
{

    class StaticWidget : public Widget
    {
    public:
        StaticWidget(const Vec2& size, Swears::Window& win) : static_size(size), window(std::move(win)) {};

        const Vec2 GetMinSize(void) { return static_size; }

        virtual Swears::Window& GetWindow(void) override { return window; }

        virtual void Draw(Vec2& pos, Vec2& size);

    private:
        Vec2 static_size;
        Swears::Window window;
    };
}

#endif // _SWEARS_WIDGETS_STATICWIDGET_HPP_

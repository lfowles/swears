#ifndef _SWEARS_WIDGETS_WIDGET_HPP_
#define _SWEARS_WIDGETS_WIDGET_HPP_

#include <memory>
#include "../helpers.hpp"
#include "../window.hpp"

namespace Swears
{
    class Widget
    {
    public:
        /*
        Widget(void) = default;
        virtual ~Widget(void) = default;

        Widget(Widget&& other) = default;
        Widget& operator=(Widget&& other) = default;
        */
        virtual void Draw(Vec2 &pos, Vec2 &size) = 0;

        virtual const Vec2 GetMinSize(void) = 0;

        virtual void AddChild(std::shared_ptr<Widget> new_child);

        virtual void SetParent(Widget *parentptr) { parent = parentptr; }

        virtual Swears::Window &GetWindow(void);


    protected:
        Widget *parent;
        std::shared_ptr<Widget> child;
    };
}
#endif // _SWEARS_WIDGETS_WIDGET_HPP_


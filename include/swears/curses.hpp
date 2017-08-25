#ifndef _SWEARS_CURSES_HPP_
#define _SWEARS_CURSES_HPP_

#include "window.hpp"

namespace Swears
{
    class Curses
    {
    public:
        enum class Visibility
        {
            Invisible=0,
            Visible=1,
            VeryVisible=2
        };
        Curses();
        ~Curses();
        void pause();
        void refresh();
        void echo(bool enable);
        void raw(bool enable);
        void Draw();
        void Cursor(Visibility level);
        Window& GetRoot();
        const Window& GetRoot() const;

    private:
        Window root_win;
    };
}

#endif // _SWEARS_CURSES_HPP_
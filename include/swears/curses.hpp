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
        Curses(void);
        ~Curses(void);
        void pause(void);
        void refresh(void);
        void echo(bool enable);
        void raw(bool enable);
        void Draw(void);
        void Cursor(Visibility level);

        Window stdscr;
    };
}

#endif // _SWEARS_CURSES_HPP_
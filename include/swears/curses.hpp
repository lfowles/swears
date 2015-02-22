#ifndef _SWEARS_CURSES_HPP_
#define _SWEARS_CURSES_HPP_

#include "window.hpp"

namespace Swears
{
    class Curses
    {
    public:
        Curses(void);
        ~Curses(void);
        void pause(void);
        void refresh(void);
        void echo(bool enable);
        void raw(bool enable);
        void Draw(void);

        Window stdscr;
    };
}

#endif // _SWEARS_CURSES_HPP_
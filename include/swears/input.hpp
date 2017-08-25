#ifndef _SWEARS_INPUT_HPP_
#define _SWEARS_INPUT_HPP_

#include "ncurses.hpp"
#include "window.hpp"

namespace Swears
{
    using MouseEvent = MEVENT;

    class Input
    {
    public:
        explicit Input(Window &win);
        //void start_loop(void);
        //void shutdown(void);
        int read();
        MouseEvent read_mouse();
        bool has_input();

    private:
        //void loop(void);
    };
}

#endif // _SWEARS_INPUT_HPP_
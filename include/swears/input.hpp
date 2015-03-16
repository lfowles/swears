#ifndef _SWEARS_INPUT_HPP_
#define _SWEARS_INPUT_HPP_

#include "ncurses.hpp"
#include "window.hpp"

namespace Swears
{
    class Input
    {
    public:
        Input(Window &win);
        //void start_loop(void);
        //void shutdown(void);
        int read(void);
        bool has_input(void);

    private:
        //void loop(void);
    };
}

#endif // _SWEARS_INPUT_HPP_
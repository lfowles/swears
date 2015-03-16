#ifndef _SWEARS_NCURSES_HPP_
#define _SWEARS_NCURSES_HPP_

#ifdef USE_NCURSESW
#include <ncursesw/ncurses.h>
#else
#include <ncurses.h>
#endif

namespace Swears
{
    const bool WideChar = NCURSES_WIDECHAR;
}

#endif //_SWEARS_NCURSES_HPP_

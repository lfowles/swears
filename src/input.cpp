#include <swears/input.hpp>

#include <sys/select.h>
#include <unistd.h>

#include <swears/ncurses.hpp>

using namespace Swears;


Input::Input(Window &win)
{
    ::keypad(win.get(), true);
    ::mousemask(ALL_MOUSE_EVENTS, nullptr); // If mouse support, blah blah blah
    ::nodelay(win.get(), true);
}

int Input::read()
{
    return getch();
}

MouseEvent Input::read_mouse()
{
    MouseEvent event;
    ::getmouse(&event);
    return event;
}

bool Input::has_input()
{
    fd_set readfds;
    auto timeout = timeval{0,0};
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    return static_cast<bool>(select(STDIN_FILENO+1, &readfds, nullptr, nullptr, &timeout));
}

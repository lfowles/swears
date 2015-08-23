#include <swears/input.hpp>

#include <sys/select.h>
#include <unistd.h>

#include <swears/ncurses.hpp>

using namespace Swears;


Input::Input(Window &win)
{
    ::keypad(win, true);
    ::mousemask(ALL_MOUSE_EVENTS, NULL); // If mouse support, blah blah blah
    ::nodelay(win, true);
}

int Input::read(void)
{
    return getch();
}

MouseEvent Input::read_mouse(void)
{
    MouseEvent event;
    ::getmouse(&event);
    return event;
}

bool Input::has_input(void)
{
    fd_set readfds;
    auto timeout = timeval{0,0};
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    return static_cast<bool>(select(STDIN_FILENO+1, &readfds, nullptr, nullptr, &timeout));
}

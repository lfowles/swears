#include <swears/input.hpp>

#include <ncurses.h>
#include <sys/select.h>
#include <unistd.h>

using namespace Swears;

Input::Input(Window &win)
{
    //::keypad(win, true);
    ::nodelay(win, true);
}

int Input::read(void)
{
    return getch();
}

bool Input::has_input(void)
{
    fd_set readfds;
    auto timeout = timeval{0,0};
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    return static_cast<bool>(select(STDIN_FILENO+1, &readfds, nullptr, nullptr, &timeout));
}

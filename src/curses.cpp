#include <swears/curses.hpp>

#include <swears/helpers.hpp>

#include <swears/ncurses.hpp>

using namespace Swears;

Curses::Curses()
{
    setlocale(LC_ALL, "en_US.utf8");
    try
    {
        root_win = Window(::initscr());
    } catch (const CursesError& e)
    {
        throw CursesError("ncurses failed to initialize, see stderr.");
    }
}

Curses::~Curses()
{
    ::endwin();
}

void Curses::pause()
{
    getch();
}

void Curses::refresh()
{
    ::refresh();
}

void Curses::echo(bool enable)
{
    if (enable)
    {
        ::echo();
    } else {
        ::noecho();
    }
}

void Curses::raw(bool enable)
{
    if (enable)
    {
        ::raw();
    } else {
        ::noraw();
    }
}

void Curses::Draw()
{
    ::doupdate();
}

void Curses::Cursor(Curses::Visibility level)
{
    ::curs_set(static_cast<int>(level));
}

Window &Curses::GetRoot() {
    return root_win;
}

const Window &Curses::GetRoot() const {
    return root_win;
}

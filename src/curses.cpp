#include <swears/curses.hpp>

#include <swears/helpers.hpp>

#include <ncurses.h>

using namespace Swears;

Curses::Curses(void)
{
    WINDOW* win = initscr();
    if (win == nullptr)
    {
        throw CursesError("ncurses failed to initialize, see stderr.");
    }
    stdscr = Window(win);
}

Curses::~Curses(void)
{
    ::endwin();
}

void Curses::pause(void)
{
    ::getch();
}

void Curses::refresh(void)
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

void Curses::Draw(void)
{
    doupdate();
}

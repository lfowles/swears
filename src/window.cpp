#include <swears/window.hpp>

#include <swears/ncurses.hpp>

using namespace Swears;

Window::~Window(void)
{
    if (win != nullptr)
    {
        ::delwin(win);
    }
}

void Window::Write(char c)
{
    ::waddch(win, c);
}

#ifdef USE_NCURSESW
void Window::WriteWide(wchar_t c)
{

    cchar_t char_struct;
    wchar_t f = c;
    ::setcchar(&char_struct, &f, WA_NORMAL, 0, NULL);
    ::wadd_wch(win, &char_struct);
}
#else
void Window::WriteWide(wchar_t c)
{
    throw WideSupportError("Not compiled against ncursesw.");
}
#endif // USE_NCURSESW


void Window::Write(char c, const Vec2 &pos)
{
    mvwaddch(win, pos.y, pos.x, c);
}

#ifdef USE_NCURSESW
void Window::WriteWide(wchar_t c, const Vec2 &pos)
{
    auto char_struct = cchar_t{0, {c,0}};
    mvwadd_wch(win, pos.y, pos.x, &char_struct);
    //mvwaddch(win, pos.y, pos.x, c);
}
#else
void Window::WriteWide(wchar_t c, const Vec2 &pos)
{
    throw WideSupportError("Not compiled against ncursesw.");
}
#endif

void Window::Write(const std::string str)
{
    ::waddstr(win, str.c_str());

}

void Window::Write(std::string str, const Vec2 &pos)
{
    mvwaddstr(win, pos.y, pos.x, str.c_str());
}

Vec2 Window::Size(void)
{
    Vec2 size;
    getmaxyx(win, size.y, size.x);
    return size;
}

Vec2 Window::CursorPosition(void)
{
    Vec2 pos;
    getyx(win, pos.y, pos.x);
    return pos;
}

Window Window::Create(const Vec2& origin, const Vec2& size)
{
    return Window(newwin(size.y, size.x, origin.y, origin.x));
}

void Window::Refresh(void)
{
    wnoutrefresh(win);
}

void Window::Erase(void)
{
    werase(win);
}

void Window::Move(const Vec2 &pos)
{
    wmove(win, pos.y, pos.x);
}

void Window::SetAttr(int attr)
{
    wattrset(win,attr);
}

void Window::AttrOn(int attr)
{
    ::wattron(win,attr);
}

void Window::AttrOff(int attr)
{
    ::wattroff(win,attr);
}

void Window::Clear(void)
{
    ::wclear(win);
}

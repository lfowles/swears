#include <swears/window.hpp>

#include <swears/ncurses.hpp>

namespace Swears {
    WINDOW *Window::get() {
        return win.get();
    }

    const WINDOW *Window::get() const {
        return win.get();
    }

    void DeleteWindow(WINDOW *window_ptr) {
        ::delwin(window_ptr);
    }

    Window::Window(WINDOW *window_ptr) : win(window_ptr, &DeleteWindow) {
        if (!win) {
            throw CursesError("Invalid window.");
        }
    }

    void Window::Write(char c) {
        ::waddch(win.get(), static_cast<::chtype>(c));
    }

#ifdef USE_NCURSESW
    void Window::WriteWide(wchar_t c)
    {

        cchar_t char_struct;
        wchar_t f = c;
        ::setcchar(&char_struct, &f, WA_NORMAL, 0, NULL);
        ::wadd_wch(win.get(), &char_struct);
    }
#else

    void Window::WriteWide(wchar_t /*c*/) {
        throw WideSupportError("Not compiled against ncursesw.");
    }

#endif // USE_NCURSESW


    void Window::Write(char c, const Vec2 &pos) {
        mvwaddch(win.get(), pos.y, pos.x, static_cast<::chtype>(c));
    }

#ifdef USE_NCURSESW
    void Window::WriteWide(wchar_t c, const Vec2 &pos)
    {
        auto char_struct = cchar_t{0, {c,0}};
        mvwadd_wch(win.get(), pos.y, pos.x, &char_struct);
        //mvwaddch(win.get(), pos.y, pos.x, c);
    }
#else

    void Window::WriteWide(wchar_t /*c*/, const Vec2 &/*pos*/) {
        throw WideSupportError("Not compiled against ncursesw.");
    }

#endif

    void Window::Write(const std::string &str) {
        ::waddstr(win.get(), str.c_str());

    }

    void Window::Write(const std::string &str, const Vec2 &pos) {
        mvwaddstr(win.get(), pos.y, pos.x, str.c_str());
    }

    Vec2 Window::Size() const {
        Vec2 size;
        getmaxyx(win.get(), size.y, size.x);
        return size;
    }

    Vec2 Window::CursorPosition() {
        Vec2 pos;
        getyx(win, pos.y, pos.x);
        return pos;
    }

    Window Window::Create(const Vec2 &origin, const Vec2 &size) {
        return Window(newwin(size.y, size.x, origin.y, origin.x));
    }

    void Window::Refresh() {
        wnoutrefresh(win.get());
    }

    void Window::Erase() {
        werase(win.get());
    }

    void Window::Move(const Vec2 &pos) {
        wmove(win.get(), pos.y, pos.x);
    }

    void Window::SetAttr(int attr) {
        wattrset(win.get(), attr);
    }

    void Window::AttrOn(int attr) {
        ::wattron(win.get(), attr);
    }

    void Window::AttrOff(int attr) {
        ::wattroff(win.get(), attr);
    }

    void Window::Clear() {
        ::wclear(win.get());
    }
}
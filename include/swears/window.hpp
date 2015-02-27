#ifndef _SWEARS_WINDOW_HPP_
#define _SWEARS_WINDOW_HPP_

#include <string>
#include <ncurses.h>
#include "helpers.hpp"

struct _win_st;
typedef struct _win_st WINDOW;

namespace Swears
{
    class Window
    {
    public:
        Window(void): win(nullptr) {};
        Window(WINDOW* win): win(win) {};

        //Copy
        Window(const Window&) = delete;
        Window& operator=(const Window&) = delete;

        //Move
        Window(Window&& other) { win = other.win; other.win = nullptr;};
        Window& operator=(Window&& other) { win = other.win; other.win = nullptr; return *this;};

        operator WINDOW*() {return win;};
        operator const WINDOW*() {return win;};

        void Write(char c);
        void Write(char c, const Vec2 & pos);

        void Write(const std::string str);
        void Write(const std::string str, const Vec2 & pos);

        Vec2 Size(void);
        void Refresh(void);

        void Erase(void);
        void Move(const Vec2& pos);

        void SetAttr(int attr);

        ~Window(void);

        static Window Create(const Vec2& origin, const Vec2& size);
        void Clear(void);

    private:
        WINDOW* win;
    };
}

#endif // _SWEARS_WINDOW_HPP_
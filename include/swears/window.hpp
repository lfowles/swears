#ifndef _SWEARS_WINDOW_HPP_
#define _SWEARS_WINDOW_HPP_

#include <memory>
#include <string>
#include "helpers.hpp"

struct _win_st;
typedef struct _win_st WINDOW;

namespace Swears
{
    void DeleteWindow(WINDOW* window_ptr);

    class Window
    {
    public:
        Window() = default;
        explicit Window(WINDOW* window_ptr);

        //Move
        Window(Window&& other) = default;
        Window& operator=(Window&& other) = default;

        WINDOW* get();
        const WINDOW* get() const;

        void Write(char c);
        void WriteWide(wchar_t c);
        void Write(char c, const Vec2 & pos);
        void WriteWide(wchar_t c, const Vec2 & pos);

        void Write(const std::string& str);
        void Write(const std::string& str, const Vec2 & pos);

        Vec2 Size() const;
        Vec2 CursorPosition();
        void Refresh();

        void Erase();
        void Move(const Vec2& pos);

        void SetAttr(int attr);
        void AttrOn(int attr);
        void AttrOff(int attr);

        static Window Create(const Vec2& origin, const Vec2& size);
        void Clear();

    private:
        std::unique_ptr<WINDOW, decltype(&DeleteWindow)> win{nullptr, &DeleteWindow};
    };
}

#endif // _SWEARS_WINDOW_HPP_
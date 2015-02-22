#include <swears/widgets/fillwidget.hpp>

using namespace Swears;

void FillWidget::Draw(Vec2 &pos, Vec2 &size)
{
    auto fillstring = std::string(minsize.x, fill);
    std::string filler(size.x, fill^0x20);
    auto& win = GetWindow();
    for (auto cursor = Vec2(pos); cursor.y < pos.y+size.y; cursor.y++) {
        win.Write(filler, cursor);
    }
    win.SetAttr(A_BOLD);
    for (auto cursor = Vec2(pos); cursor.y < pos.y+minsize.y; cursor.y++) {
        win.Write(fillstring, cursor);
    }
    win.SetAttr(A_NORMAL);

    if (child)
    {
        child->Draw(pos, size);
    }
}

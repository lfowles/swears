#include <swears/widgets/fillwidget.hpp>

using namespace Swears;

void FillWidget::Draw(Vec2 &pos, Vec2 &size, Window& window)
{
    auto fillstring = std::string(minsize.x, fill);
    std::string filler(size.x, fill^0x20);
    for (auto cursor = Vec2(pos); cursor.y < pos.y+size.y; cursor.y++) {
        window.Write(filler, cursor);
    }
    window.SetAttr(A_BOLD);
    for (auto cursor = Vec2(pos); cursor.y < pos.y+minsize.y; cursor.y++) {
        window.Write(fillstring, cursor);
    }
    window.SetAttr(A_NORMAL);

    if (child)
    {
        child->Draw(pos, size, window);
    }
}

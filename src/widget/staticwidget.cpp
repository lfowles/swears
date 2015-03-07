#include <swears/widgets/staticwidget.hpp>

using namespace Swears;

void StaticWidget::Draw(Vec2 &pos, Vec2 &size, Window& window)
{
    Vec2 zeros;
    child->Draw(zeros, static_size, window);
    window.Refresh();
};
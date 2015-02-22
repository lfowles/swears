#include <swears/widgets/staticwidget.hpp>

using namespace Swears;

void StaticWidget::Draw(Vec2 &pos, Vec2 &size)
{
    Vec2 zeros;
    child->Draw(zeros, static_size);
    window.Refresh();
};
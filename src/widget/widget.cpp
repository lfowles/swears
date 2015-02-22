#include <swears/widgets/widget.hpp>

using namespace Swears;

void Widget::AddChild(std::shared_ptr<Widget> new_child)
{
    child = std::move(new_child);
    child->SetParent(this);
};

Swears::Window& Widget::GetWindow(void)
{
    // Should assert that parent is non-null. Everything should be parented EXCEPT StaticWindow.
    return parent->GetWindow();
};

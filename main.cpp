#include <chrono>
#include <memory>
#include <thread>
#include <vector>

#include <swears/curses.hpp>
#include <swears/input.hpp>
#include <swears/widgets/gridwidget.hpp>
#include <swears/widgets/fillwidget.hpp>
#include <swears/widgets/staticwidget.hpp>


int main()
{

    Swears::Curses curses;
    Swears::Input input(curses.stdscr);
    curses.raw(true);
    curses.echo(false);
    auto term_size = curses.stdscr.Size();
    auto win = Swears::Window::Create({0,0}, term_size);
    auto base_widget = std::shared_ptr<Swears::Widget>(new Swears::StaticWidget(term_size));
    auto grid_widget = std::shared_ptr<Swears::GridBox>(new Swears::GridBox());
    auto background_widget = std::shared_ptr<Swears::Widget>(new Swears::FillWidget({0,0}, '.'^0x20));

    std::vector<std::pair<std::shared_ptr<Swears::Widget>, Swears::Vec2>> widgets;

    widgets.push_back({std::shared_ptr<Swears::Widget>(new Swears::FillWidget({8,2}, 'X')), {8, 2}});
    widgets.push_back({std::shared_ptr<Swears::Widget>(new Swears::FillWidget({3,1}, 'k')), {3, 9}});
    widgets.push_back({std::shared_ptr<Swears::Widget>(new Swears::FillWidget({9,4}, 'f')), {3, 7}});
    widgets.push_back({std::shared_ptr<Swears::Widget>(new Swears::FillWidget({4,5}, 'V')), {1, 10}});
    widgets.push_back({std::shared_ptr<Swears::Widget>(new Swears::FillWidget({2,3}, 'V')), {2, 5}});
    widgets.push_back({std::shared_ptr<Swears::Widget>(new Swears::FillWidget({4,5}, 'f')), {3, 2}});
    widgets.push_back({std::shared_ptr<Swears::Widget>(new Swears::FillWidget({10,8}, 'b')), {4, 2}});
    widgets.push_back({std::shared_ptr<Swears::Widget>(new Swears::FillWidget({2,8}, 'k')), {9, 9}});
    widgets.push_back({std::shared_ptr<Swears::Widget>(new Swears::FillWidget({5,9}, 'O')), {4, 10}});
    widgets.push_back({std::shared_ptr<Swears::Widget>(new Swears::FillWidget({8,10}, 'K')), {9, 10}});
    widgets.push_back({std::shared_ptr<Swears::Widget>(new Swears::FillWidget({10,2}, 'I')), {8, 6}});
    widgets.push_back({std::shared_ptr<Swears::Widget>(new Swears::FillWidget({3,1}, 'G')), {7, 1}});
    widgets.push_back({std::shared_ptr<Swears::Widget>(new Swears::FillWidget({10,4}, 'v')), {10, 10}});
    widgets.push_back({std::shared_ptr<Swears::Widget>(new Swears::FillWidget({5,5}, 'h')), {9, 6}});
    widgets.push_back({std::shared_ptr<Swears::Widget>(new Swears::FillWidget({4,2}, 'F')), {10, 5}});
    widgets.push_back({std::shared_ptr<Swears::Widget>(new Swears::FillWidget({5,8}, 'A')), {8, 1}});
    widgets.push_back({std::shared_ptr<Swears::Widget>(new Swears::FillWidget({10,8}, 'm')), {6, 6}});
    widgets.push_back({std::shared_ptr<Swears::Widget>(new Swears::FillWidget({5,7}, 'X')), {9, 10}});
    widgets.push_back({std::shared_ptr<Swears::Widget>(new Swears::FillWidget({7,10}, 'U')), {2, 1}});

    for (auto& widget : widgets)
    {
        try
        {
            grid_widget->AddChild(widget.first, widget.second);
        } catch (Swears::GridBox::GridBoxException e) {

        }
    }

    base_widget->AddChild(background_widget);
    background_widget->AddChild(grid_widget);

    base_widget->Draw(term_size, term_size, curses.stdscr);

    curses.Draw();

    while (!input.has_input())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}

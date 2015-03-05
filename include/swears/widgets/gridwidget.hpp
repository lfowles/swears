#ifndef _SWEARS_WIDGETS_GRIDWIDGET_HPP_
#define _SWEARS_WIDGETS_GRIDWIDGET_HPP_

#include <memory>
#include <vector>

#include "widget.hpp"

namespace Swears
{
    struct GridSizeInfo
    {
        unsigned int size;
        unsigned int weight;
    };

    struct GridCell
    {
        bool widget_origin;
        Vec2 widget_area;
        std::shared_ptr<Widget> widget;
    };

    class GridBox : public Widget
    {
    public:
        using GridBoxException = std::runtime_error;

        virtual void AddChild(std::shared_ptr<Widget> child) override { AddChild(child, {0, 0}, {1, 1}); };

        void AddChild(std::shared_ptr<Widget> child, const Swears::Vec2& grid_pos) { AddChild(child, grid_pos, {1, 1}); };

        void AddChild(std::shared_ptr<Widget> child, const Swears::Vec2& grid_pos, const Swears::Vec2& grid_size);

        virtual void Draw(Vec2& pos, Vec2& size, Window& window) override;

        void CalculateSize(void);

        virtual const Vec2 GetMinSize(void) override;

    private:
        GridCell& GetCell(int x, int y);


        void SetCell(int x, int y, GridCell c);


        void ClearCell(int x, int y);


        std::vector<std::vector<GridCell>> grid;
        std::vector<GridSizeInfo> row_info, col_info;

        Vec2 prev_pos;
        Vec2 prev_size;
    };
}

#endif // _SWEARS_WIDGETS_GRIDWIDGET_HPP_

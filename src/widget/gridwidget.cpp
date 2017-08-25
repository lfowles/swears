#include <swears/widgets/gridwidget.hpp>

using namespace Swears;

void GridBox::AddChild(std::shared_ptr<Widget> child, const Swears::Vec2 &grid_pos, const Swears::Vec2 &grid_size)
{
    auto& cell = GetCell(grid_pos.x, grid_pos.y);
    if (cell.widget)
    {
        throw(GridBoxException("Cannot overlap widgets in GridBox."));
    }

    cell = GridCell{true, grid_size, child};
    child->SetParent(this);


    for (auto row_pos = 0; row_pos < grid_size.y; row_pos++)
    {
        for (auto col_pos = 0; col_pos < grid_size.x; col_pos++)
        {
            if (not (row_pos == 0 and col_pos == 0))
            {
                auto& ref_cell = GetCell(grid_pos.y+col_pos, grid_pos.y+row_pos);
                ref_cell = GridCell{false, grid_size, child};
            }
        }
    }

    // Invalidate cached sizes
    prev_pos = Vec2();
    prev_size = Vec2();
}

void GridBox::Draw(Vec2 &pos, Vec2 &size, Window &window)
{
    if (pos != prev_pos or size != prev_size)
    {
        CalculateSize();
    }

    std::vector<int> expanded_row, expanded_col;
    expanded_row.resize(row_info.size());
    expanded_col.resize(col_info.size());

    auto minsize = GetMinSize();
    int col_remainder = size.x-minsize.x;
    int row_remainder = size.y-minsize.y;

    while (row_remainder > 0)
    {
        auto ctr = 0;
        for (auto &row : row_info)
        {
            int added;
            if (row.weight > 1) {
                added = row.weight % row_remainder;
            } else {
                added = 1;
            }
            expanded_row[ctr] += added;
            row_remainder -= added;

            if (row_remainder == 0)
            {
                break;
            }
            ctr++;
        }
    }

    while (col_remainder > 0)
    {
        auto ctr = 0;
        for (auto &col : col_info)
        {
            int added;
            if (col.weight > 1) {
                added = col.weight % col_remainder;
            } else {
                added = 1;
            }
            expanded_col[ctr] += added;
            col_remainder -= added;

            if (col_remainder == 0)
            {
                break;
            }
            ctr++;
        }
    }

    Vec2 cell_origin;
    for (auto y = 0; y < static_cast<int>(row_info.size()); y++)
    {
        for (auto x = 0; x < static_cast<int>(col_info.size()); x++)
        {
            auto &cell = GetCell(x, y);
            if (cell.widget_origin)
            {
                Vec2 child_size;
                for (auto row = 0; row < cell.widget_area.y; row++)
                {
                    child_size.y += row_info[y + row].size + expanded_row[y + row];
                }

                for (auto col = 0; col < cell.widget_area.x; col++)
                {
                    child_size.x += col_info[x + col].size + expanded_col[x + col];
                }

                cell.widget->Draw(cell_origin, child_size, window);
            }
            cell_origin.x += col_info[x].size + expanded_col[x];
            if (cell_origin.x > size.x)
            {
                break;
            }
        }
        cell_origin.x = 0;
        cell_origin.y += row_info[y].size+expanded_row[y];
        if (cell_origin.y > size.y)
        {
            break;
        }
    }
}

void GridBox::CalculateSize()
{

    auto normalized_row_size = 0;
    auto normalized_col_size = 0;

    for (auto y = 0; y < static_cast<int>(col_info.size()); y++)
    {
        for (auto x = 0; x < static_cast<int>(row_info.size()); x++)
        {
            auto& cell = GetCell(x, y);
            if (cell.widget)
            {
                auto minsize = cell.widget->GetMinSize();
                auto avg_col_size = minsize.x/cell.widget_area.x;
                auto avg_row_size = minsize.y/cell.widget_area.y;
                if (col_info[x].weight > 0 and avg_col_size/col_info[x].weight > normalized_col_size)
                {
                    normalized_col_size = avg_col_size/col_info[x].weight;
                    if (avg_col_size%col_info[x].weight > 0)
                    {
                        normalized_col_size++;
                    }
                }
                if (row_info[y].weight > 0 and avg_row_size/row_info[y].weight > normalized_row_size)
                {
                    normalized_row_size = avg_row_size/row_info[y].weight;
                    if (avg_row_size%row_info[y].weight > 0)
                    {
                        normalized_row_size++;
                    }
                }

                // Set size, because 0 weight rows/cols _need_ to know this and if this row/col does have a weight, this will be a minimum bound for the size which will be calculated later
                if (avg_col_size > col_info[x].size)
                {
                    col_info[x].size = avg_col_size;
                }
                if (avg_row_size > row_info[y].size)
                {
                    row_info[y].size = avg_row_size;
                }
            }
        }
    }

    for (auto& row : row_info)
    {
        if (row.weight > 0)
        {
            row.size = row.weight * normalized_row_size;
        }
    }

    for (auto& col : col_info)
    {
        if (col.weight > 0)
        {
            col.size = col.weight * normalized_col_size;
        }
    }

}

const Vec2 GridBox::GetMinSize()
{
    auto minsize = Vec2{0,0};
    for (auto& row : row_info)
    {
        minsize.y += row.size;
    }
    for (auto& col : col_info)
    {
        minsize.x += col.size;
    }
    return minsize;
}

GridCell &GridBox::GetCell(int x, int y)
{
    // Resize if x or y out of bounds
    if (y+1 > static_cast<int>(row_info.size()))
    {
        row_info.resize(y+1);
        grid.resize(y+1);
    }
    if (x+1 > static_cast<int>(col_info.size()))
    {
        // Don't resize the individual arrays yet until they are actually needed
        col_info.resize(x+1);
    }

    auto& row = grid[y];
    if (x+1 > static_cast<int>(row.size()))
    {
        row.resize(x+1, GridCell());
    }

    return row[x];
}

void GridBox::SetCell(int x, int y, GridCell c)
{
    auto& cell = GetCell(x, y);
    cell = std::move(c);
}

void GridBox::ClearCell(int x, int y)
{
    SetCell(x, y, GridCell());
}

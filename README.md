This is an ncurses wrapper in C++ that includes some basic widgets.

Widgets:

* FillWidget - Fills a set area with a bold character and any extra area with an unbold reverse-case of that character.
* StaticWidget - Takes ownership of an ncurses Window
* GridWidget - Inspired by the Tcl/Tk grid geometry manager (or at least my hazy memories of it), this widget organizes child widgets into a grid. Child widgets can span multiple columns and rows. Columns and rows can also have different relative weights (e.g. a weight 2 column will always be twice as large as a weight 1 column.)

Follow along in the code if you're interested, I haven't done any serious documentation efforts yet.
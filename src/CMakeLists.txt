project(swears)
set(SOURCE_FILES curses.cpp
                 window.cpp
                 input.cpp
                 widget/widget.cpp
                 widget/gridwidget.cpp
                 widget/fillwidget.cpp
                 widget/staticwidget.cpp)

include_directories("../include")

add_library(swears SHARED ${SOURCE_FILES})
target_link_libraries(swears ncurses)
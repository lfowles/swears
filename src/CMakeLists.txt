set(HEADER_FILES
        ../include/swears/curses.hpp
        ../include/swears/helpers.hpp
        ../include/swears/input.hpp
        ../include/swears/ncurses.hpp
        ../include/swears/window.hpp
        ../include/swears/widgets/widget.hpp
        ../include/swears/widgets/gridwidget.hpp
        ../include/swears/widgets/fillwidget.hpp
        ../include/swears/widgets/staticwidget.hpp)
set(SOURCE_FILES
        curses.cpp
        window.cpp
        input.cpp
        widget/widget.cpp
        widget/gridwidget.cpp
        widget/fillwidget.cpp
        widget/staticwidget.cpp)

set(NCURSES_LIB ncurses)
if (USE_NCURSESW)
    set(NCURSES_LIB ncursesw)
    add_definitions(-DUSE_NCURSESW)
endif ()

# TODO: Switch for ncursesw/ncurses that can be checked in the code.
add_library(swears ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(swears ${NCURSES_LIB})
target_include_directories(swears PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include/>
        $<INSTALL_INTERFACE:include/>)
target_compile_options(swears PUBLIC -Wall)
target_compile_options(swears PRIVATE -Wextra)

install(TARGETS swears EXPORT swears
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        INCLUDES DESTINATION include)

install(EXPORT swears DESTINATION share/swears/cmake)

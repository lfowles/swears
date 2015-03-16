project(swears)
set(SOURCE_FILES curses.cpp
                 window.cpp
                 input.cpp
                 widget/widget.cpp
                 widget/gridwidget.cpp
                 widget/fillwidget.cpp
                 widget/staticwidget.cpp)

include_directories("../include")

set(NCURSES_LIB ncurses)
if(USE_NCURSESW)
    set(NCURSES_LIB ncursesw)
    add_definitions(-DUSE_NCURSESW)
endif()

# TODO: Switch for ncursesw/ncurses that can be checked in the code.
add_library(swears SHARED ${SOURCE_FILES})
target_link_libraries(swears ${NCURSES_LIB})
target_include_directories(swears PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include/>
    $<INSTALL_INTERFACE:include/>)

add_library(swears_static STATIC ${SOURCE_FILES})
target_link_libraries(swears_static ${NCURSES_LIB})
set_target_properties(swears_static PROPERTIES OUTPUT_NAME "swears")

target_include_directories(swears_static PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include/>
    $<INSTALL_INTERFACE:include/>)

install(TARGETS swears swears_static EXPORT swears
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        INCLUDES DESTINATION include)

install(EXPORT swears DESTINATION share/swears/cmake)

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
target_include_directories(swears PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>)
    #$<INSTALL_INTERFACE:../include/>)

add_library(swears_static STATIC ${SOURCE_FILES})
target_link_libraries(swears_static ncurses)
set_target_properties(swears_static PROPERTIES OUTPUT_NAME "swears")
#set_target_properties(swears_static PROPERTIES PREFIX "lib")
target_include_directories(swears_static PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>)
    #$<INSTALL_INTERFACE:../include/>)

install(TARGETS swears swears_static EXPORT swears
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        INCLUDES DESTINATION include)

#file(GLOB_RECURSE swears_public_headers RELATIVE ../include/ *.hpp)
#install(DIRECTORY ../include/swears
#        DESTINATION include)

install(EXPORT swears DESTINATION share/swears/cmake)

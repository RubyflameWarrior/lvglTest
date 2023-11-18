cmake_minimum_required(VERSION 3.14)
include(FetchContent)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

project(MyProject LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Specify path to own LVGL config header
set(LV_CONF_PATH
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lv_conf.h
    CACHE STRING "" FORCE)

# Fetch LVGL from GitHub
FetchContent_Declare(lvgl
  GIT_REPOSITORY https://github.com/lvgl/lvgl.git
  GIT_TAG v8.3.6

  )
FetchContent_MakeAvailable(lvgl)

# Specify path to own LVGL demos config header
set(LV_DEMO_CONF_PATH
    ${CMAKE_CURRENT_SOURCE_DIR}/src/lv_demo_conf.h
    CACHE STRING "" FORCE)

FetchContent_Declare(lv_drivers
                     GIT_REPOSITORY https://github.com/lvgl/lv_drivers
                     GIT_TAG 49c4b17
                     )
FetchContent_MakeAvailable(lv_drivers)

include_directories(include)

# Build an executable called "lvglTest"
add_executable(lvglTest
  src/gui/screen.cpp
  src/gui/page.cpp
  src/gui/graph.cpp
  src/mouse_cursor_icon.c 
  src/main.cpp
  )
target_link_libraries(lvglTest lvgl lv_drivers ${SDL2_LIBRARIES})

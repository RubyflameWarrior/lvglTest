cmake_minimum_required(VERSION 3.14)
include(FetchContent)

project(MyProject LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Build an executable called "lvglTest"
add_executable(lvglTest src/main.cpp )

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


# The target "lvglTest" depends on LVGL, drivers and demos
target_link_libraries(lvglTest PUBLIC lvgl::lvgl lvgl::drivers lvgl::examples lv_drivers ${SDL2_LIBRARIES})

cmake_minimum_required(VERSION 3.14)

project(qt_process_arm LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
add_compile_options("-g")
add_executable(qt_process_arm
  main.cpp
)
add_executable(simple_fork
  fork.cpp
)
add_executable(simple_exec
  exec.cpp
)
target_link_libraries(qt_process_arm Qt${QT_VERSION_MAJOR}::Core)

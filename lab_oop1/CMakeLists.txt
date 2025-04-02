cmake_minimum_required(VERSION 3.16)

project(lab_oop1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab_oop1
    shape.h

    circle.cpp
    triangle.cpp
    rectangle.h
    circle.h
    triangle.h
    rectangle.cpp

    app_errors.h
    console_ui.cpp
    console_ui.h
    convexpolygon.h
    convexpolygon.cpp
    main.cpp
    shape_container.h
    shape_container.cpp)

include(GNUInstallDirs)
install(TARGETS lab_oop1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

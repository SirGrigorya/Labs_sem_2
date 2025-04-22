cmake_minimum_required(VERSION 3.16)

project(lab_oop1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab_oop1 main.cpp
    AppErrors.h
    Shape.h
    Point.h
    Circle.h
    Rectangle.h
    ConsoleUi.h
    Triangle.h
    ConvexPolygon.h
    Circle.cpp
    ConsoleUi.cpp
    Rectangle.cpp
    Triangle.cpp
    ConvexPolygon.cpp
    ShapeContainer.h
    ShapeContainer.cpp
    ShapeFactory.h
    ShapeFactory.cpp
    GeometryUtils.cpp
    GeometryUtils.h)

include(GNUInstallDirs)
install(TARGETS lab_oop1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

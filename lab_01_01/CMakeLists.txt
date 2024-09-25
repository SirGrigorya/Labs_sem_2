cmake_minimum_required(VERSION 3.16)

project(lab_01_01 LANGUAGES C)

add_executable(lab_01_01 main.c)

include(GNUInstallDirs)
install(TARGETS lab_01_01
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

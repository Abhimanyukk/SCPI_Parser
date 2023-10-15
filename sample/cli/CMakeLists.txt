cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME scpi_cli)
project(${PROJECT_NAME} VERSION 1.0)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SCPI REQUIRED "Scpi")

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${SCPI_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${SCPI_LIBRARIES})

install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

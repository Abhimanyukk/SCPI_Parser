cmake_minimum_required(VERSION 3.10)
set(SCPI_LIB "Scpi")
project(${SCPI_LIB} VERSION 1.0)

file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(${SCPI_LIB} SHARED ${SRC_FILES})
include_directories(${SCPI_LIB} ${CMAKE_CURRENT_SOURCE_DIR}/inc/)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/ScpiLib.pc.in ${CMAKE_CURRENT_SOURCE_DIR}/${SCPI_LIB}.pc @ONLY)
set(ENV{PKG_CONFIG_PATH} $ENV{PKG_CONFIG_PATH}:${CMAKE_CURRENT_SOURCE_DIR}/)

install(TARGETS ${SCPI_LIB}
    LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)

install(DIRECTORY inc/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include)

# install(FILES ${CMAKE_BINARY_DIR}/MyLibrary.pc DESTINATION lib/pkgconfig)

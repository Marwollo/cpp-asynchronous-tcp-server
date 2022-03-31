cmake_minimum_required(VERSION 3.9)

include(FetchContent)
FetchContent_Declare(
    asio
    GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
    GIT_TAG master
)

FetchContent_GetProperties(asio)
if(NOT asio_POPULATED)
    FetchContent_Populate(asio)
    include_directories(${asio_SOURCE_DIR}/asio/include)
endif()

include_directories(.)

project(AsyncTCPServer)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS src/*.cpp src/*.hpp include/*.hpp)
add_library(AsyncTCPServer ${sources})
target_include_directories(AsyncTCPServer PUBLIC include PRIVATE src)

set_target_properties(AsyncTCPServer PROPERTIES CXX_STANDARD 17)

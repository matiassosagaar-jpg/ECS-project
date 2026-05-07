cmake_minimum_required(VERSION 3.16)
project(ECS CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/PositionStorage.cpp
    src/RenderSystem.cpp
)
set(raylib_DIR "C:/msys64/ucrt64/lib/cmake/raylib")
set(CMAKE_PREFIX_PATH "C:/msys64/ucrt64")
find_package(raylib REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    include
)
if(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE m pthread dl rt X11)
endif()
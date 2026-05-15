cmake_minimum_required(VERSION 3.16)
project(ECS CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/RenderSystem.cpp
    src/MovementSystem.cpp
    src/BounceSystem.cpp
    src/EntitySpawner.cpp
    src/CollisionSystem.cpp
)
target_include_directories(${PROJECT_NAME}
    PRIVATE
    include
)
find_package(raylib REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

if(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE m pthread dl rt X11)
endif()
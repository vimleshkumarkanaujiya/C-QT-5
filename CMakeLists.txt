cmake_minimum_required(VERSION 3.5)

project(calculator)

# Find the required Qt packages
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Set the C++ standard to use
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the source files for the project
set(SOURCES
    main.cpp
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link against the Qt libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Widgets)


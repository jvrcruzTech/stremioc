cmake_minimum_required(VERSION 3.10)

project(stremioc VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the source files
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")
list(APPEND APP_PLATFORM_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include")


# Find the required libraries
find_package(CURL REQUIRED)
find_package(Threads REQUIRED)

target_include_directories(${PROJECT_NAME} PRIVATE include ${CURL_INCLUDE_DIRS} 
    ${APP_PLATFORM_INCLUDE})
target_link_libraries(${PROJECT_NAME} PRIVATE ${CURL_LIBRARIES})
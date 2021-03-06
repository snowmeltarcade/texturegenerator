set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

cmake_minimum_required(VERSION 3.15)
project(texturegenerator VERSION 1.0.0)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

set(RUNNER_PROJECT_NAME "${PROJECT_NAME}_runner")

set(NODES_COLOR_PROJECT_NAME "${PROJECT_NAME}_nodes_color")
set(NODES_SERIALIZE_PROJECT_NAME "${PROJECT_NAME}_nodes_serialize")
set(NODES_SHARED_PROJECT_NAME "${PROJECT_NAME}_nodes_shared")

set(LIBRARIES_ROOT_DIR "${CMAKE_CURRENT_LIST_DIR}/libraries")

set(INSTALL_DIRECTORY "${CMAKE_BINARY_DIR}/install/bin")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_LIST_DIR}/cmake/)

if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Debug")
endif()

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
	set(IS_DEBUG true)
endif()

if(IS_DEBUG)
	add_compile_definitions(DEBUG)
else()
	add_compile_definitions(RELEASE)
endif()

if (UNIX AND NOT APPLE)
	set(LINUX TRUE)
elseif(APPLE AND CMAKE_SYSTEM_NAME STREQUAL "iOS")
	set(IOS TRUE)
endif()

configure_file("${CMAKE_CURRENT_LIST_DIR}/version.h.in" "${CMAKE_CURRENT_LIST_DIR}/version.h")

include("${CMAKE_CURRENT_LIST_DIR}/cmake/libraries.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/cmake/buildsettings.cmake")

include_directories("${CMAKE_CURRENT_LIST_DIR}")

add_subdirectory("nodes")
add_subdirectory("runner")

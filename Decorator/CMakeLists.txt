cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME CURRENT_FOLDER_NAME)
set(CURRENT_TARGET_NAME "${CURRENT_FOLDER_NAME}")

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})

file(GLOB_RECURSE SOURCES
        "${INCLUDE_DIR}/*.h"
        "${SOURCE_DIR}/*.cpp"
)

add_executable(Decorator ${SOURCES})

target_include_directories(Decorator PRIVATE ${INCLUDE_DIR})
target_include_directories(Decorator PRIVATE ${SOURCE_DIR})

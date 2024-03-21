cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME CURRENT_FOLDER_NAME)
set(CURRENT_TARGET_NAME "${CURRENT_FOLDER_NAME}")

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(SALE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Sale")
set(SALE_FACTORY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SaleFactory")

include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})
include_directories(${SALE_DIR})
include_directories(${SALE_FACTORY_DIR})

file(GLOB_RECURSE SOURCES
        "${INCLUDE_DIR}/*.h"
        "${SOURCE_DIR}/*.cpp"
        "${SALE_DIR}/*.h"
        "${SALE_DIR}/*.cpp"        
        "${SALE_FACTORY_DIR}/*.h"
        "${SALE_FACTORY_DIR}/*.cpp"
)

add_executable(Factory ${SOURCES})

target_include_directories(Factory PRIVATE ${INCLUDE_DIR})
target_include_directories(Factory PRIVATE ${SOURCE_DIR})
target_include_directories(Factory PRIVATE ${SALE_DIR})
target_include_directories(Factory PRIVATE ${SALE_FACTORY_DIR})

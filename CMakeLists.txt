cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(libtorch_owndataset VERSION 0.1 LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(Torch QUIET PATHS "${CMAKE_SOURCE_DIR}/libtorch")

set(EXECUTABLE_NAME owndatabin)

#meine libs:
add_library(
  owndata
  "${CMAKE_SOURCE_DIR}/include/owndata.hpp"
  "${CMAKE_SOURCE_DIR}/src/owndata.cpp"
)
add_library(
  csv2vector
  "${CMAKE_SOURCE_DIR}/include/csv2vector.hpp"
  "${CMAKE_SOURCE_DIR}/src/csv2vector.cpp"
)

add_executable(${EXECUTABLE_NAME})

target_sources(${EXECUTABLE_NAME} PRIVATE main.cpp)

set_target_properties(${EXECUTABLE_NAME} PROPERTIES
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED YES
)

target_link_libraries(${EXECUTABLE_NAME} "${TORCH_LIBRARIES}"
owndata
csv2vector)

if(MSVC)
    include(copy_torch_dlls)
    copy_torch_dlls(${EXECUTABLE_NAME})
endif(MSVC)
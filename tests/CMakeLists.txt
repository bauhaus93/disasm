cmake_minimum_required(VERSION 3.10)
project(test_disasm CXX)

macro(add_test_sources)
  file(RELATIVE_PATH
       _relPath
       "${CMAKE_SOURCE_DIR}/tests"
       "${CMAKE_CURRENT_SOURCE_DIR}")
  foreach(_src ${ARGN})
    if(_relPath)
      file(TO_NATIVE_PATH "${_relPath}/${_src}" _nativePath)
    else()
      file(TO_NATIVE_PATH ${_src} _nativePath)
    endif()
    set_property(TARGET all_tests APPEND PROPERTY SRC_LIST ${_nativePath})
  endforeach()
endmacro()

set(EXEC_NAME "all_tests")

add_executable(${EXEC_NAME} "main_test.cpp")

target_link_libraries(${EXEC_NAME} "disasm")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  target_compile_options(${EXEC_NAME} PRIVATE -Wall -fmax-errors=1 -Werror)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  target_compile_options(${EXEC_NAME} PRIVATE -Wall -ferror-limit=1 -Werror)
endif()

add_subdirectory(disasm)

get_property(TEST_SRCS TARGET ${EXEC_NAME} PROPERTY SRC_LIST)
target_sources(${EXEC_NAME} PRIVATE ${TEST_SRCS})

target_include_directories(${EXEC_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/src")

find_package(GTest REQUIRED COMPONENTS gtest gmock)
target_link_libraries(${EXEC_NAME} ${GTEST_LIBRARIES})
target_include_directories(${EXEC_NAME} SYSTEM PRIVATE ${GTEST_INCLUDE_DIR})

enable_testing()

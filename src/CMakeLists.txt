cmake_minimum_required(VERSION 3.10)
project(disasm C)

macro(add_sources)
  file(RELATIVE_PATH
       _relPath
       "${CMAKE_SOURCE_DIR}/src"
       "${CMAKE_CURRENT_SOURCE_DIR}")
  foreach(_src ${ARGN})
    if(_relPath)
      file(TO_NATIVE_PATH "${_relPath}/${_src}" _nativePath)
    else()
      file(TO_NATIVE_PATH ${_src} _nativePath)
    endif()
    set_property(TARGET disasm APPEND PROPERTY SRC_LIST ${_nativePath})
  endforeach()
endmacro()

set(CMAKE_C_STANDARD 99)
set(LIB_NAME "disasm")

add_library(${LIB_NAME} "")

if("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
  target_compile_options(${LIB_NAME} PRIVATE -Wall -fmax-errors=1 -Werror)
elseif("${CMAKE_C_COMPILER_ID}" STREQUAL "Clang")
  target_compile_options(${LIB_NAME} PRIVATE -Wall -ferror-limit=1 -Werror)
endif()

add_subdirectory(disasm)
target_include_directories(${LIB_NAME} PRIVATE disasm)

get_property(SRCS TARGET ${LIB_NAME} PROPERTY SRC_LIST)
target_sources(${LIB_NAME} PRIVATE ${SRCS})

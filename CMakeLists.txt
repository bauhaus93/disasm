cmake_minimum_required(VERSION 3.10)
project(disassembler CXX)

add_subdirectory(src)
add_subdirectory(tests)

add_dependencies("all_tests" "disasm")

add_custom_target(run_tests
		  COMMAND "all_tests"
		  DEPENDS "all_tests"
		  WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/tests")

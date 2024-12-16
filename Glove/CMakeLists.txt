# CMakeList.txt : CMake project for Glove, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Glove "src//Core//Core.cpp" "src/Core/CLITerminal/CLI.cpp" "src/Core/Logger/Log.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Glove PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

target_include_directories(Glove PRIVATE ${fast_io_SOURCE_DIR}/include ${CLI11_SOURCE_DIR}/include)
target_link_libraries(Glove PRIVATE eventpp::eventpp spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32> PUBLIC yaml-cpp::yaml-cpp zlibstatic CLI11::CLI11)
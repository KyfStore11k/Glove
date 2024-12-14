# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

if (POLICY CMP0079)
  cmake_policy(SET CMP0079 NEW)
endif()

project ("Glove")

# Include sub-projects.
add_subdirectory ("Glove")
add_subdirectory ("Glove\\external\\CLI11")

include(FetchContent)
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.11.0  # Adjust this to the version you want
)
FetchContent_MakeAvailable(spdlog)

FetchContent_Declare(
    fast_io
    GIT_REPOSITORY https://github.com/cppfastio/fast_io.git
    GIT_TAG master  # You can specify a branch, tag, or commit hash
)

# Download and make it available
FetchContent_MakeAvailable(fast_io)

FetchContent_Declare(
  yaml-cpp
  GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
  GIT_TAG 0.8.0 # Can be a tag (yaml-cpp-x.x.x), a commit hash, or a branch name (master)
)
FetchContent_MakeAvailable(yaml-cpp)

FetchContent_Declare(
    zlib
    GIT_REPOSITORY https://github.com/madler/zlib.git
    GIT_TAG v1.3.1
)
FetchContent_MakeAvailable(zlib)

FetchContent_Declare(
    eventpp
    GIT_REPOSITORY https://github.com/wqking/eventpp
    GIT_TAG        d2db8af2a46c79f8dc75759019fba487948e9442 # v0.1.3
)
FetchContent_MakeAvailable(eventpp)

include("C:/vcpkg/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(CURL CONFIG REQUIRED)
target_link_libraries(Glove PRIVATE CURL::libcurl)
find_path(EVENTPP_INCLUDE_DIR eventpp/eventqueue.h)
include_directories(${EVENTPP_INCLUDE_DIR})
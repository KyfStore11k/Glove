# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/dev/Glove/out/build/x64-debug/_deps/spdlog-src"
  "D:/dev/Glove/out/build/x64-debug/_deps/spdlog-build"
  "D:/dev/Glove/out/build/x64-debug/_deps/spdlog-subbuild/spdlog-populate-prefix"
  "D:/dev/Glove/out/build/x64-debug/_deps/spdlog-subbuild/spdlog-populate-prefix/tmp"
  "D:/dev/Glove/out/build/x64-debug/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp"
  "D:/dev/Glove/out/build/x64-debug/_deps/spdlog-subbuild/spdlog-populate-prefix/src"
  "D:/dev/Glove/out/build/x64-debug/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/dev/Glove/out/build/x64-debug/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/dev/Glove/out/build/x64-debug/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()

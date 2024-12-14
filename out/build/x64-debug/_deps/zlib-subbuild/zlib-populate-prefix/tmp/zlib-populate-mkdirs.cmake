# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/dev/Glove/out/build/x64-debug/_deps/zlib-src"
  "D:/dev/Glove/out/build/x64-debug/_deps/zlib-build"
  "D:/dev/Glove/out/build/x64-debug/_deps/zlib-subbuild/zlib-populate-prefix"
  "D:/dev/Glove/out/build/x64-debug/_deps/zlib-subbuild/zlib-populate-prefix/tmp"
  "D:/dev/Glove/out/build/x64-debug/_deps/zlib-subbuild/zlib-populate-prefix/src/zlib-populate-stamp"
  "D:/dev/Glove/out/build/x64-debug/_deps/zlib-subbuild/zlib-populate-prefix/src"
  "D:/dev/Glove/out/build/x64-debug/_deps/zlib-subbuild/zlib-populate-prefix/src/zlib-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/dev/Glove/out/build/x64-debug/_deps/zlib-subbuild/zlib-populate-prefix/src/zlib-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/dev/Glove/out/build/x64-debug/_deps/zlib-subbuild/zlib-populate-prefix/src/zlib-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()

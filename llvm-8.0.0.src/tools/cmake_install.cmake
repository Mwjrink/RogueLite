# Install script for directory: C:/Development/C++/RogueLite/llvm-8.0.0.src/tools

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/LLVM")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/lto/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/gold/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-ar/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-config/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-lto/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-profdata/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/bugpoint/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/bugpoint-passes/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/dsymutil/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llc/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/lli/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-as/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-as-fuzzer/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-bcanalyzer/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-c-test/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-cat/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-cfi-verify/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-cov/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-cvtres/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-cxxdump/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-cxxfilt/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-cxxmap/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-diff/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-dis/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-dwarfdump/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-dwp/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-elfabi/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-exegesis/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-extract/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-go/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-isel-fuzzer/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-itanium-demangle-fuzzer/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-link/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-lto2/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-mc/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-mc-assemble-fuzzer/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-mc-disassemble-fuzzer/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-mca/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-microsoft-demangle-fuzzer/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-modextract/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-mt/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-nm/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-objcopy/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-objdump/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-opt-fuzzer/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-opt-report/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-pdbutil/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-rc/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-readobj/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-rtdyld/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-size/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-special-case-list-fuzzer/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-split/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-stress/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-strings/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-symbolizer/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-undname/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-xray/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/llvm-yaml-numeric-parser-fuzzer/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/obj2yaml/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/opt/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/opt-remarks/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/opt-viewer/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/sancov/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/sanstats/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/verify-uselistorder/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/xcode-toolchain/cmake_install.cmake")
  include("C:/Development/C++/RogueLite/llvm-8.0.0.src/tools/yaml2obj/cmake_install.cmake")

endif()


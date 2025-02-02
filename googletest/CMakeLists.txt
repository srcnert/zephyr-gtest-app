cmake_minimum_required(VERSION 3.20.0)
set(This googletest)

FILE(GLOB SOURCES googletest/googletest/src/gtest-assertion-result.cc
                  googletest/googletest/src/gtest-death-test.cc
                  googletest/googletest/src/gtest-filepath.cc
                  googletest/googletest/src/gtest-matchers.cc
                  googletest/googletest/src/gtest-port.cc
                  googletest/googletest/src/gtest-printers.cc
                  googletest/googletest/src/gtest-test-part.cc
                  googletest/googletest/src/gtest-typed-test.cc
                  gtest.cc # Updating time functions for Zephyr
                  googletest/googlemock/src/gmock-all.cc
                  GoogleTestMain.cpp)

add_definitions(
    -DGTEST_HAS_FILE_SYSTEM=0
    -DGTEST_HAS_POSIX_RE=0
    -DGTEST_HAS_STREAM_REDIRECTION=0
)

zephyr_library_named(${This})
zephyr_library_sources(${SOURCES})
zephyr_include_directories(
    inc # Added to use my version gtest-port.h file
    googletest/googletest
    googletest/googletest/include
    googletest/googlemock
    googletest/googlemock/include
)

cmake_minimum_required(VERSION 3.21)
project(misysTest)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(./googletest)
set(LIBRARIES
        gtest
        pthread)

# 添加下面三行，在编译和链接时会加上-fprofile-arcs -ftest-coverage参数
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage -lgcov")
add_executable(misysTest test/handleTest.cpp src/handlePath.cpp src/handlePath.h test/handleTest.cpp)

target_link_libraries(misysTest ${LIBRARIES})

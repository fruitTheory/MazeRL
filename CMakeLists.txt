cmake_minimum_required(VERSION 3.29)
project( MyProject 
    LANGUAGES CXX )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

set(BUILD_DIR ${CMAKE_SOURCE_DIR}/build)

include(FetchContent)

FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
)
FetchContent_MakeAvailable(SFML)

add_executable(main src/main.cpp src/app.cpp src/world.cpp src/algorithm.cpp src/utility.cpp)

target_include_directories(main PRIVATE src)

target_link_libraries(main PRIVATE sfml-graphics)
target_compile_features(main PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET main
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
        VERBATIM)
endif()

add_custom_target(
  clean-all
  COMMAND ${CMAKE_COMMAND} -E rm -rf ${BUILD_DIR}
  COMMENT "Cleaning build artifacts"
)

#[[
Helpful commands:
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake -S . -B build -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release

time make -C build -j 8  
time cmake --build build -- -j 8
msbuild ./build/MyProject.sln -p:Configuration=Release -m:8

cmake --build build --target clean-all
cmake --build build --target install
]]
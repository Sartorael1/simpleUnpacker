cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)


list(APPEND CMAKE_PREFIX_PATH
        "$ENV{CMAKE_PREFIX_PATH}"
        "C:/Users/Vlad/.vcpkg-clion/vcpkg/installed/x64-mingw-dynamic/include/bit7z"
        "C:/Users/Vlad/.vcpkg-clion/vcpkg/installed/x64-mingw-dynamic/share/unofficial-bit7z"
        "C:/Users/Vlad/.vcpkg-clion/vcpkg/installed/x64-mingw-dynamic/share/7zip"
        "C:/Users/Vlad/.vcpkg-clion/vcpkg/installed/x64-mingw-dynamic/share/ghc_filesystem"
        "C:/Users/Vlad/.vcpkg-clion/vcpkg/installed/x64-mingw-dynamic/share/sfml"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
find_package(7zip CONFIG REQUIRED)
find_package(unofficial-bit7z CONFIG REQUIRED)
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main src/main.cpp
        source/DispatcherHat.cpp
        headers/DispatcherHat.h
        source/SevenZipExtractor.cpp
        headers/SevenZipExtractor.h
        source/MyApplicationGui.cpp
        headers/MyApplicationGui.h
)
target_link_libraries(main PRIVATE sfml-graphics sfml-window unofficial::bit7z::bit7z64 7zip::7zip)
add_compile_options(-l bit7z)
target_compile_features(main PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET main
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
        VERBATIM)
endif()


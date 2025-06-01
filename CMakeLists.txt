cmake_minimum_required(VERSION 3.10)

project(MyProject)

add_executable(MyProject main.cpp functions.cpp)

target_compile_options(MyProject PRIVATE /utf-8 /W3)
target_compile_definitions(MyProject PRIVATE _UNICODE UNICODE)
target_compile_definitions(MyProject PRIVATE _UTF8_SOURCE)

set_target_properties(MyProject PROPERTIES
    VS_GLOBAL_WindowsTargetPlatformVersion "10.0"
)
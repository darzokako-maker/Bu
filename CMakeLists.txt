cmake_minimum_required(VERSION 3.10)
project(ZenithAllInOne)

# DLL Projesi (Hile)
add_library(cheat_dll SHARED src/cheat/main.cpp src/cheat/gui.cpp)

# EXE Projesi (Loader)
add_executable(ZenithLoader src/loader/main.cpp)

# DLL'i EXE'ye kaynak olarak ekle
target_compile_definitions(ZenithLoader PRIVATE DLL_EMBEDDED)


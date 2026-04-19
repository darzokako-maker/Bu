cmake_minimum_required(VERSION 3.15)
project(ZenithProject)

# C++ Standart Ayarları
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Klasörleri Tanıt
include_directories(include)
include_directories(src/cheat)
include_directories(src/loader)

# 1. Hileyi (DLL) Derle
add_library(cheat SHARED 
    src/cheat/main.cpp 
    src/cheat/gui.cpp
)

# 2. Loader'ı (EXE) Derle
add_executable(loader 
    src/loader/main.cpp
)

# 3. Windows Sistem Kütüphanelerini Bağla (HATAYI ÇÖZEN KISIM)
if(WIN32)
    target_link_libraries(loader dwmapi.lib user32.lib gdi32.lib)
    target_link_libraries(cheat dwmapi.lib user32.lib gdi32.lib)
endif()

# EXE'nin DLL'den sonra derlenmesi için
add_dependencies(loader cheat)

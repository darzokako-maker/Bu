cmake_minimum_required(VERSION 3.15)
project(ZenithProject)

# 1. Hileyi (DLL) Derle
add_library(cheat SHARED src/cheat/main.cpp src/cheat/gui.cpp)

# 2. Loader'ı (EXE) Derle
add_executable(loader src/loader/main.cpp src/loader/resources.rc)

# 3. DLL bittikten sonra EXE'yi başlat
add_dependencies(loader cheat)

cmake_minimum_required(VERSION 3.15)
project(ZenithProject)

# C++ Standart Ayarı
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Kütüphane Yollarını Belirt (ImGui vb. buraya gelecek)
include_directories(include)
include_directories(src/cheat)
include_directories(src/loader)

# 2. Hileyi (DLL) Derle
# src/cheat içindeki tüm .cpp dosyalarını buraya ekle
add_library(cheat SHARED 
    src/cheat/main.cpp 
    src/cheat/gui.cpp
)

# 3. Loader'ı (EXE) Derle
# src/loader içindeki tüm .cpp dosyalarını buraya ekle
add_executable(loader 
    src/loader/main.cpp
    # src/loader/resources.rc  <-- Resource dosyan hazır olduğunda burayı aç
)

# 4. EXE'nin DLL'den sonra derlenmesini sağla
add_dependencies(loader cheat)

# Windows kütüphanelerini bağla
target_link_libraries(loader Dwmapi.lib)

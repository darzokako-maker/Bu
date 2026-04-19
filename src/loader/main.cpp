#include <windows.h>
#include <iostream>
#include "dumper.hpp"     // Otomatik offset bulucu
#include "injector.hpp"   // Manual Map motoru
#include "resources.h"    // DLL'in gömülü olduğu yer

int main() {
    SetConsoleTitleA("Zenith Project - All-In-One");
    std::cout << "[*] Sistem Baslatiliyor..." << std::endl;

    // 1. ADIM: Dumper ile Güncel Offsetleri Bul
    if (!AutoDumper::Init()) {
        std::cout << "[!] Oyun bulunamadi veya offsetler okunamadi!" << std::endl;
        Sleep(3000); return 1;
    }
    std::cout << "[+] Offsetler Guncellendi!" << std::endl;

    // 2. ADIM: Gömülü DLL'i EXE İçinden Çıkar (Bellekte)
    size_t dllSize = 0;
    void* dllData = Resource::GetDLL(IDR_CHEAT_DLL, dllSize);

    // 3. ADIM: Sessiz Enjeksiyon (Manual Map)
    if (Injector::DoInfection("cs2.exe", dllData, dllSize)) {
        std::cout << "[+] Hile Yuklendi. Menuyu INSERT ile acin." << std::endl;
    }

    Sleep(5000);
    return 0;
}


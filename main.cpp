#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <urlmon.h>
#include <string>
#include <cstdlib>
#include <string_view>

#pragma comment(lib, "urlmon.lib")

bool DownloadFile(const char* url, std::string_view output) {

    HRESULT result = URLDownloadToFileA(nullptr, url, output.data(), 0, nullptr);
    if (!SUCCEEDED(result)) {
        MessageBoxA(NULL, "Failed to install Fish++", "Fish++ Installer", MB_OK | MB_ICONERROR);
        return false;
    }
    printf("Installed %s\n", output.data());
    return true;
}

int main() {
    std::string roaming = std::string(getenv("APPDATA"));
    std::string hytale = roaming + "\\Hytale\\install\\release\\package\\game\\latest\\Client";
    if (DownloadFile("https://github.com/Limitlesschicken/FishPlusPlus-Hytale/releases/download/Release/Fish++.dll", hytale + "\\Fish++.dll") &&
        DownloadFile("https://github.com/Limitlesschicken/FishPlusPlus-Hytale/releases/download/Release/Fish++.pdb", hytale + "\\Fish++.pdb") &&
        DownloadFile("https://github.com/Limitlesschicken/FishPlusPlus-Hytale-Installer/releases/download/Resource/XInput1_4.dll", hytale + "\\XInput1_4.dll") &&
        DownloadFile("https://github.com/Limitlesschicken/FishPlusPlus-Hytale-Installer/releases/download/Resource/XInput1_4.pdb", hytale + "\\XInput1_4.pdb")
        ) {
        MessageBoxA(NULL, "Successfuly installed Fish++", "Fish++ Installer", MB_OK | MB_ICONINFORMATION);
    }
}
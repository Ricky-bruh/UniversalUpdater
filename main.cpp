#include <iostream>
#include <cstdlib>
#include <windows.h>

bool user_accept(const std::string& message) {
    char choice;
    std::cout << message << " (y/n): ";
    std::cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

int main() {

    std::cout << "This program will update multiple programs on your PC.\n";

    // --- Winget apps ---
    if (user_accept("Do you want to update all Winget apps and accept the source/package agreements?")) {
        std::cout << "Updating Winget apps..." << std::endl;
        system("winget upgrade --all --accept-source-agreements --accept-package-agreements");
    } else {
        std::cout << "Skipped Winget updates." << std::endl;
    }

    // --- Chocolatey apps ---
    if (user_accept("Do you want to update all Chocolatey apps?")) {
        std::cout << "Updating Chocolatey apps..." << std::endl;
        system("choco upgrade all -y");
    } else {
        std::cout << "Skipped Chocolatey updates." << std::endl;
    }

    // --- Python itself ---
    if (user_accept("Do you want to update Python via Winget and accept agreements?")) {
        std::cout << "Updating Python..." << std::endl;
        system("winget upgrade Python.Python.3 --accept-source-agreements --accept-package-agreements");
    } else {
        std::cout << "Skipped Python update." << std::endl;
    }

    // --- Python packages via pip ---
    if (user_accept("Do you want to update all Python packages via pip?")) {
        std::cout << "Updating pip..." << std::endl;
        system("python -m pip install --upgrade pip");
        std::cout << "Checking outdated packages..." << std::endl;
        system("python -m pip list --outdated --format=freeze > outdated.txt");
        std::cout << "Updating outdated packages..." << std::endl;
        system("for /F \"tokens=1 delims==\" %i in (outdated.txt) do python -m pip install --upgrade %i");
        system("del outdated.txt");
    } else {
        std::cout << "Skipped Python package updates." << std::endl;
    }

    std::cout << "All selected updates finished!" << std::endl;
    return 0;
}

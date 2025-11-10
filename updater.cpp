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
    if (user_accept("Do you want to update all Winget apps and accept source/package agreements?")) {
        std::cout << "Updating Winget apps..." << std::endl;
        system("winget upgrade --all --accept-source-agreements --accept-package-agreements");
    } else { std::cout << "Skipped Winget updates.\n"; }

    // --- Chocolatey apps ---
    if (user_accept("Do you want to update all Chocolatey apps?")) {
        std::cout << "Updating Chocolatey apps..." << std::endl;
        system("choco upgrade all -y");
    } else { std::cout << "Skipped Chocolatey updates.\n"; }

    // --- Scoop apps ---
    if (user_accept("Do you want to update all Scoop apps?")) {
        std::cout << "Updating Scoop apps..." << std::endl;
        system("scoop update *");
    } else { std::cout << "Skipped Scoop updates.\n"; }

    // --- Python itself ---
    if (user_accept("Do you want to update Python via Winget?")) {
        std::cout << "Updating Python..." << std::endl;
        system("winget upgrade Python.Python.3 --accept-source-agreements --accept-package-agreements");
    } else { std::cout << "Skipped Python update.\n"; }

    // --- Python packages via pip ---
    if (user_accept("Do you want to update all Python packages via pip?")) {
        std::cout << "Updating pip..." << std::endl;
        system("python -m pip install --upgrade pip");
        std::cout << "Checking outdated packages..." << std::endl;
        system("python -m pip list --outdated --format=freeze > outdated.txt");
        std::cout << "Updating outdated packages..." << std::endl;
        system("for /F \"tokens=1 delims==\" %i in (outdated.txt) do python -m pip install --upgrade %i");
        system("del outdated.txt");
    } else { std::cout << "Skipped Python package updates.\n"; }

    // --- Node.js & NPM ---
    if (user_accept("Do you want to update Node.js and all global NPM packages?")) {
        std::cout << "Updating Node.js..." << std::endl;
        system("winget upgrade OpenJS.NodeJS --accept-source-agreements --accept-package-agreements");
        std::cout << "Updating global NPM packages..." << std::endl;
        system("npm install -g npm");
        system("npm update -g");
    } else { std::cout << "Skipped Node.js/NPM updates.\n"; }

    // --- Rust & Cargo ---
    if (user_accept("Do you want to update Rust and all Cargo packages?")) {
        std::cout << "Updating Rust..." << std::endl;
        system("rustup update");
        std::cout << "Updating Cargo packages..." << std::endl;
        system("cargo install-update -a"); // requires cargo-update
    } else { std::cout << "Skipped Rust/Cargo updates.\n"; }

    // --- Go ---
    if (user_accept("Do you want to update Go packages?")) {
        std::cout << "Updating Go tools..." << std::endl;
        system("go install all@latest");
    } else { std::cout << "Skipped Go updates.\n"; }

    // --- VS Code extensions ---
    if (user_accept("Do you want to update all VS Code extensions?")) {
        std::cout << "Updating VS Code extensions..." << std::endl;
        system("for /F \"tokens=*\" %i in ('code --list-extensions') do code --install-extension %i --force");
    } else { std::cout << "Skipped VS Code extensions updates.\n"; }

    // --- Git ---
    if (user_accept("Do you want to update Git?")) {
        std::cout << "Updating Git..." << std::endl;
        system("winget upgrade Git.Git --accept-source-agreements --accept-package-agreements");
    } else { std::cout << "Skipped Git update.\n"; }

    // --- Browsers ---
    if (user_accept("Do you want to update browsers (Chrome, Edge, Firefox)?")) {
        std::cout << "Updating browsers..." << std::endl;
        system("winget upgrade Google.Chrome --accept-source-agreements --accept-package-agreements");
        system("winget upgrade Mozilla.Firefox --accept-source-agreements --accept-package-agreements");
        system("winget upgrade Microsoft.Edge --accept-source-agreements --accept-package-agreements");
    } else { std::cout << "Skipped browser updates.\n"; }

    // --- Games & apps (Steam, Epic, Discord, Spotify) ---
    if (user_accept("Do you want to update Steam, Epic Games Launcher, Discord, and Spotify?")) {
        std::cout << "Updating apps..." << std::endl;
        system("winget upgrade Valve.Steam --accept-source-agreements --accept-package-agreements");
        system("winget upgrade EpicGames.EpicGamesLauncher --accept-source-agreements --accept-package-agreements");
        system("winget upgrade Discord.Discord --accept-source-agreements --accept-package-agreements");
        system("winget upgrade Spotify.Spotify --accept-source-agreements --accept-package-agreements");
    } else { std::cout << "Skipped games/apps updates.\n"; }

    std::cout << "All selected updates finished!" << std::endl;
    return 0;
}

// updater.cpp
// Updater for Windows
// Currently updates: all winget, chocolatey, scoop packages, python/pip, nodejs/npm, rust/cargo, go modules, vscode, git, browsers, steam, epic games launcher, discord, spotify.
// Author: Ricky-Bruh
// 
// (https://github.com/Ricky-bruh/UniversalUpdater)
// License: Apache License 2.0 (https://raw.githubusercontent.com/Ricky-bruh/UniversalUpdater/refs/heads/main/LICENSE)

#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

// Function to ask user before running an update
bool askUser(const string& name) {
    cout << "\nDo you want to update " << name << "? (Y/N): ";
    char choice;
    cin >> choice;
    return (choice == 'Y' || choice == 'y');
}

// Function to execute a command and show feedback
void execute(const string& description, const string& command) {
    cout << "\n=== " << description << " ===" << endl;
    int result = system(command.c_str());
    if (result == 0)
        cout << "[SUCCESS] " << description << " completed." << endl;
    else
        cout << "[ERROR] " << description << " failed with code " << result << "." << endl;
}

int main() {
    cout << "===== Universal Windows Updater =====" << endl;
    cout << "This program will help you update most apps, languages, and tools on your PC." << endl;
    cout << "Each section will ask for confirmation before running.\n" << endl;
    system("pause");

    // WINGET
    if (askUser("Winget packages"))
        execute("Updating all Winget packages", 
                "winget upgrade --all --accept-source-agreements --accept-package-agreements");

    // CHOCOLATEY
    if (askUser("Chocolatey packages"))
        execute("Updating all Chocolatey packages", 
                "choco upgrade all -y");

    // SCOOP
    if (askUser("Scoop packages"))
        execute("Updating Scoop and all apps", 
                "scoop update *");

    // PYTHON
    if (askUser("Python and PIP packages")) {
        execute("Updating Python", "winget upgrade Python.Python.3 --accept-source-agreements --accept-package-agreements");
        execute("Upgrading pip", "python -m pip install --upgrade pip");
        execute("Listing outdated packages", "python -m pip list --outdated --format=freeze > outdated.txt");
        execute("Updating all PIP packages", "for /F \"tokens=1 delims==\" %i in (outdated.txt) do python -m pip install --upgrade %i");
        execute("Cleaning temporary file", "del outdated.txt");
    }

    // NODEJS + NPM
    if (askUser("Node.js and NPM packages")) {
        execute("Updating Node.js", "winget upgrade OpenJS.NodeJS --accept-source-agreements --accept-package-agreements");
        execute("Updating NPM itself", "npm install -g npm");
        execute("Updating all global NPM packages", "npm update -g");
    }

    // RUST + CARGO
    if (askUser("Rust and Cargo packages")) {
        execute("Updating Rust toolchain", "rustup update");
        execute("Updating Cargo packages", "cargo install-update -a");
    }

    // GO
    if (askUser("Go and its modules")) {
        execute("Updating Go", "winget upgrade GoLang.Go --accept-source-agreements --accept-package-agreements");
        execute("Updating all Go modules", "go get -u ./...");
    }

    // VSCODE
    if (askUser("Visual Studio Code"))
        execute("Updating Visual Studio Code", 
                "winget upgrade Microsoft.VisualStudioCode --accept-source-agreements --accept-package-agreements");

    // GIT
    if (askUser("Git"))
        execute("Updating Git", 
                "winget upgrade Git.Git --accept-source-agreements --accept-package-agreements");

    // BROWSERS
    if (askUser("all web browsers")) {
        execute("Updating Google Chrome", "winget upgrade Google.Chrome --accept-source-agreements --accept-package-agreements");
        execute("Updating Mozilla Firefox", "winget upgrade Mozilla.Firefox --accept-source-agreements --accept-package-agreements");
        execute("Updating Microsoft Edge", "winget upgrade Microsoft.Edge --accept-source-agreements --accept-package-agreements");
        execute("Updating Opera", "winget upgrade Opera.Opera --accept-source-agreements --accept-package-agreements");
        execute("Updating Brave Browser", "winget upgrade Brave.Brave --accept-source-agreements --accept-package-agreements");
    }

    // STEAM
    if (askUser("Steam"))
        execute("Updating Steam", "winget upgrade Valve.Steam --accept-source-agreements --accept-package-agreements");

    // EPIC GAMES LAUNCHER
    if (askUser("Epic Games Launcher"))
        execute("Updating Epic Games Launcher", "winget upgrade EpicGames.EpicGamesLauncher --accept-source-agreements --accept-package-agreements");

    // DISCORD
    if (askUser("Discord"))
        execute("Updating Discord", "winget upgrade Discord.Discord --accept-source-agreements --accept-package-agreements");

    // SPOTIFY
    if (askUser("Spotify"))
        execute("Updating Spotify", "winget upgrade Spotify.Spotify --accept-source-agreements --accept-package-agreements");

    cout << "\nAll selected updates completed." << endl;
    cout << "Press any key to exit..." << endl;
    system("pause");
    return 0;
}

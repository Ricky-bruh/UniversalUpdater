# All-in-One Windows Updater

A C++ program that helps you update **most applications, package managers, programming languages, and development tools** on a Windows PC.  

It currently supports:
- Winget and Chocolatey apps  
- Scoop apps  
- Python and all pip packages  
- Node.js and global npm packages  
- Rust and Cargo packages  
- Go tools  
- VS Code extensions  
- Git  
- Browsers: Chrome, Firefox, Edge  
- Popular apps: Steam, Epic Games Launcher, Discord, Spotify  

---

## ⚡ Features
- Prompts the user for confirmation before each type of update.  
- Updates as much software as possible via CLI commands.  

---

## 📦 Requirements
- Windows 10/11  
- C++ compiler (e.g., Visual Studio, MinGW)  
- Installed tools to be updated (Winget, Chocolatey, Scoop, Python, Node.js, Rust, Go, VS Code, etc.)  
- Internet connection  

> **Note:** Some updates shall require **admin privileges**.

---

## 🛠️ How to Build
1. Open your C++ IDE (Visual Studio, Code::Blocks, etc.) or terminal.  
2. Add `updater.cpp` (the main program file).  
3. Compile the program:
    ```sh
   cl updater.cpp /EHsc   # Visual Studio
   g++ updater.cpp -o updater.exe  # MinGW
    ```
Run the executable:
    `updater.exe`
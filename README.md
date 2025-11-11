# All-in-One Updater

A C++ program that helps you update **most applications, package managers, programming languages, and development tools** on a Windows PC.  

It supports:
- Winget and Chocolatey apps  
- Scoop apps  
- Python and all pip packages  
- Node.js and global npm packages  
- Rust and Cargo packages  
- Go tools  
- VS Code extensions  
- Git  
- Browsers: Chrome, Firefox, Edge  
- Popular apps/games: Steam, Epic Games Launcher, Discord, Spotify  

---

## ⚡ Features
- Prompts the user for confirmation before each type of update.  
- Automatically accepts Winget source and package agreements.  
- Updates as much software as possible via CLI commands.  
- Can be extended to include more apps/tools easily.  

---

## 📦 Requirements
- Windows 10/11  
- C++ compiler (e.g., Visual Studio, MinGW)  
- Installed tools to be updated (Winget, Chocolatey, Scoop, Python, Node.js, Rust, Go, VS Code, etc.)  
- Internet connection  

> **Note:** Some updates require **admin privileges**.

---

## 🛠️ How to Build
1. Open your C++ IDE (Visual Studio, Code::Blocks, etc.) or terminal.  
2. Add `updater.cpp` (the main program file).  
3. Compile the program:
   ```sh
   cl updater.cpp /EHsc   # Visual Studio
   g++ updater.cpp -o updater.exe  # MinGW
   ```

4. Run the executable as Administrator:

   ```sh
   updater.exe
   ```

---

## ⚙️ How it Works

1. The program prompts the user for each type of update (Winget, Chocolatey, Python, etc.).
2. If the user agrees:
   * CLI commands are executed to update the software.
   * For Winget, the program automatically accepts the source and package agreements.
3. Python packages are upgraded individually using pip.
4. VS Code extensions are updated using the `code` CLI.
5. Steam, Epic, Discord, and Spotify are updated via Winget.
6. The program prints the status of each update step.

---

## ⚠️ Limitations

* Tools/apps without a CLI updater cannot be updated automatically.
* Some apps may require manual interaction or a restart.
* Always run the program **as Administrator** for system-level updates.

---

## 💡 Tips

* Can be scheduled with **Task Scheduler** to run periodically.

---

## License

Apache License 2.0.
[License](https://github.com/Ricky-bruh/UniversalUpdater/blob/main/LICENSE)

# 🎮 Gautam's Shell Games

Welcome to **Gautam's Shell Game**, a fun and interactive terminal-based game suite written entirely in C. This project was **created from scratch by Abhisekha Gautam**, combining creativity, logic, and a love for classic games — all wrapped in a single shell.

Whether you're here to test your luck, reflexes, or memory, there's a game for everyone!

---

## 📜 Table of Contents

* [Features](#-features)
* [Games Included](#-games-included)
* [Technical Concepts](#-technical-concepts)
* [Build & Run](#-build--run)
* [Screenshots](#-screenshots)
* [Future Improvements](#-future-improvements)
* [Author](#-author)
* [License](#-license)

---

## 🎯 Features

* ASCII-styled game menu with colorful terminal output
* Multiple classic games all in one shell
* Easy to navigate interface
* Use of arrays, function pointers, and `switch-case` for modularity
* Includes emojis and colors for a visually engaging experience

---

## 🕹️ Games Included

The menu offers the following game modes:

1. **Rock 🪨 | Paper 📄 | Scissors ✂️** — The Classic Showdown
2. **Guess the Number 🧠** — Test Your Luck and Smarts
3. **Snake 🐍 | Water 💧 | Gun 🔫** — Choose Your Fighter
4. **Head 🪖 | Tail 🐾** — Flip the Coin and Choose Your Side
5. **Memorize 🧠 | Type ⌨️** — Challenge Your Memory and Typing Speed

And of course:

* **Q** to **Quit** gracefully and return another day.

---

## 🧠 Technical Concepts

This project is designed with **readability**, **modularity**, and **educational value** in mind. It utilizes:

* **Function pointers in arrays** for dynamic game selection
* **`switch-case`** statements for input handling
* **ANSI escape codes** for colored and styled terminal output
* **Separation of concerns**: UI and logic are modularized
* Use of **`sleep()`** for pacing and effects

### 📌 Sample Function Pointer Usage

```c
void (*games[])(void) = { game_rps, game_guess, game_swg, game_coin, game_memory };

switch (choice) {
    case 1: case 2: case 3: case 4: case 5:
        (*games[choice - 1])();
        break;
    case 'Q': case 'q':
        exit(0);
    default:
        printf("Invalid option!\n");
}
```

---

## 🛠️ Build & Run

### Requirements

* **Tested and verified only on Linux**
* GCC or any standard C compiler
* Terminal that supports ANSI escape sequences (for colored output)

> ⚠️ **Note**:
> This project **has not been tested on Windows or macOS**.
> Behavior and appearance may differ or break on those systems due to terminal and system-level differences.

### Build

```bash
gcc "Gautam'sShellGames.c" -o GSG
```

### Run

```bash
./GSG
```

---

## 🖼️ Screenshots

<img width="613" height="356" alt="Screenshot from 2025-09-28 22-23-58" src="https://github.com/user-attachments/assets/3e191814-dfc0-41a7-b7e2-30b98a70de8d" />

<img width="795" height="460" alt="Screenshot from 2025-09-28 22-38-07" src="https://github.com/user-attachments/assets/8fc1d9a9-99af-463a-9e27-6ee615b01695" />

---

## 🚀 Future Improvements

* Add high score tracking
* Implement multiplayer options
* Improve animations with custom ASCII art
* Port for **Windows and macOS** for broader compatibility

---

## 👤 Author

**Abhisekha Gautam**
Solo Developer & Creator of this project.
Designed, developed, and built entirely from scratch.

> *Tested and developed exclusively on **Linux**. Compatibility with **Windows or macOS** is currently **not verified**.*

---

## 📝 License

This project is licensed under the **MIT License**.
Feel free to use, modify, and distribute it as per the terms.

---

Let the fun begin — and may the odds be ever in your favor!

---

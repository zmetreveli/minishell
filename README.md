# 🐚 Minishell

> A tiny yet mighty UNIX shell written in C — built from scratch to mimic Bash-like behavior.  
> Developed with ❤️ by [@zmetreveli](https://github.com/zmetreveli) & [@jbusom](https://github.com/jbusom) as part of the 42Barcelona resume.

---

## 🧭 Table of Contents
- [✨ Features](#-features)
- [⚙️ Installation](#️-installation)
- [🚀 Usage](#-usage)
- [📎 Examples](#-examples)
- [🏗 Architecture Overview](#-architecture-overview)
- [🧠 How it Works](#-how-it-works)
- [💎 Bonus Features](#-bonus-features)
- [⚠️ Known Limitations](#️-known-limitations)
- [🙌 Credits](#-credits)
- [🪪 License](#-license)

---

## ✨ Features

✅ Built-in commands:
- `cd`, `echo`, `pwd`, `env`, `export`, `unset`, `exit`

✅ I/O Redirections:
- `>`, `>>`, `<`, `<<` (heredoc)

✅ Pipes:
- `ls | grep minishell`

✅ Variable Expansion:
- Supports `$USER`, `$?`, etc.

✅ Signal Handling:
- Graceful response to `Ctrl+C`, `Ctrl+D`

✅ Prompt:
- Custom colored prompt with user, path & current time ⏰

✅ Quote Management:
- Supports `'single'` and `"double"` quotes

✅ Memory Management:
- 100% Valgrind clean 🧼

---

## ⚙️ Installation

```bash
git clone https://github.com/zmetreveli/minishell.git
cd minishell
make
```

> 🧵 Requires `readline` library installed. On macOS:  
```bash
brew install readline
```

---

## 🚀 Usage

```bash
./minishell
```

Then enter commands just like in Bash:

```bash
echo Hello, Minishell!
```

Exit the shell with:

```bash
exit
```

---

## 📎 Examples

```bash
# 🔀 Redirections
echo "Hello" > file.txt
cat < file.txt

# 📋 Pipes
ls -l | grep .c

# 📌 Heredoc
cat << EOF
This is a heredoc input.
EOF

# 🌱 Variable Expansion
echo $USER
echo Last command status: $?
```

---

## 🏗 Architecture Overview

```bash
minishell/
├── src/                    # Source code
│   ├── builtins/           # Implementation of built-in commands (cd, echo, export, etc.)
│   ├── clean_and_exit/     # Graceful exit, cleanup functions, and error handling
│   ├── env/                # Environment variables handling (env, export, unset)
│   ├── executor/           # Command execution logic, piping, fork/exec handling
│   ├── expancion/          # Variable expansion and quote resolution
│   ├── lexer/              # Tokenizer: splits input into valid tokens
│   ├── parser/             # Parses tokens into commands and syntax structures
│   ├── redirection/        # Handles redirections: <, >, >>, <<
│   ├── signals/            # Signal handling (SIGINT, SIGQUIT, etc.)
│   └── utils/              # General utility functions
├── includes/               # Header files (function prototypes, structs, macros)
├── libft/                  # Custom implementation of standard C library functions
└── minishell.c             # Main entry point: initializes shell and runs the loop
```

---

## 🧠 How it Works

🔹 **Lexer**: Tokenizes user input, respecting quotes  
🔹 **Parser**: Constructs command trees (with redirections, pipes)  
🔹 **Executor**: Runs processes via `fork()`, `execve()`, `dup2()`  
🔹 **Environment Manager**: Handles `export`, `env`, `unset`  
🔹 **Signal Handler**: Reacts to `SIGINT`, `SIGQUIT`, `EOF` properly  
🔹 **Heredoc Logic**: Manages temporary input until a delimiter  

---

## 💎 Bonus Features

- 🌈 Color-coded, dynamic prompt
- ⌛ Prompt includes system time
- 🤖 Custom error messages like Bash
- 🧪 Fully tested with Valgrind
- 👥 Team-based collaboration & code reviews

---

## ⚠️ Known Limitations

- ❌ No `&&`, `||`, or parentheses grouping  
- ❌ No wildcard expansion (`*`)  

> We focused on core shell behavior first — enhancements could come in future forks 🚀

---

## 🙌 Credits

🧑‍💻 Built with passion and late nights by:

- [@zmetreveli](https://github.com/zurabmetreveli)  
- [@jbusom](https://github.com/jbusom)

🧑‍🏫 Developed as part of the [42Barcelona](https://42barcelona.com) project curriculum.

---

## 🪪 License

Licensed under the MIT License.  
Feel free to fork, remix, or improve — just give credit back 💡

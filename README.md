<h1  align="center"> Simple Shell Project! </h1>
Welcome to the Simple Shell Project! This project is a basic implementation of a UNIX shell, which can execute commands, handle built-in functions, and manage input/output redirections.

<h2 align="center">Description</h2>
The Simple Shell Project is a basic UNIX shell implementation that allows users to execute commands, manage processes, and handle file operations. It supports built-in commands, input/output redirection, and command chaining, offering a hands-on introduction to system programming and operating system concepts.

<h2  align="center">What We're Working With</h2> 
The implementation has a variety of functions and system calls to manage file operations, process control, and memory allocation. Specifically, we utilize functions from the string.h library, as well as system calls and functions such as access, chdir, close, execve, fork, getpid, kill, malloc, open, read, write, and many more. The shell is designed to handle both interactive and non-interactive modes, enabling users to execute commands directly or through input redirection. We are adhering to strict compilation standards using 
gcc with the -Wall, -Werror, -Wextra and -pedantic flags, ensuring that the code is robust and adheres to the GNU89 standard.

<h2  align="center">Files Description</h2>

- **AUTHORS**: This file contains the list of contributors to the project, providing proper attribution for those who have worked on this simple shell implementation.
  
- **README.md**: The README file provides an overview of the project, including its purpose, installation instructions, usage examples, and details about the functions and system calls used. It serves as the main documentation for the project.
  
- **hsh**: This is the compiled executable of the simple shell program. Running this file starts the shell, allowing users to enter commands in both interactive and non-interactive modes.
  
- **shell.c**: The main C source file for the simple shell program. It contains the core logic and functions necessary to interpret and execute commands entered by the user.

- **shell.h**: The main.h file contains all the libraries used within our shell

<h2  align="center">Flow Chart</h2>
  <img src="https://github.com/user-attachments/assets/965fe6f7-67dd-4ed1-bab5-c37b1501b162" alt="Flowchart">

<h2  align="center">Examples of Use</h2>

<h2 align="left">Command ls</h2>
The ls command in Unix and Linux systems is used to list the contents of a directory. It displays the names of the files and subdirectories located in the current directory or in a specified directory.
<img src="https://github.com/user-attachments/assets/c7a42ff1-6c72-4948-ab98-96221d01e165" alt="Examples ls">
<br>
<h2 align="left">Command cat</h2>
The cat command in Unix and Linux systems is used to concatenate and display the contents of files in the terminal.
<img src= "https://github.com/user-attachments/assets/9b9e8e86-6ecb-44a5-97e3-c4b9bb9b65d3" alt="Example cat">

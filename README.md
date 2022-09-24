# simple_shell


### Description

------------


This is a simple UNIX command interpreter based on bash and Sh.<br>
A custom sh for learning purposes was developed by cohort  #8 students Aminu Rabiu & Abdullateef Odufeso.<br>
simple_shell is a command-line interpreter or shell that provides a command line user interface for Unix-like operating systems. The shell is both an interactive command language and a scripting language, and is used by the operating system to control the execution of the system using shell scripts.

------------


#### Resources

------------


- [Unix shell](https://en.wikipedia.org/wiki/Unix_shell)
- [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)
- [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)
- Run - man sh

------------

#### Compilation

------------

The code must be compiled this way:

**gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh**

As a consequence, be careful not to push any c file containing a main function in the root directory of your project (you could have a test folder containing all your tests files including main functions)

The main files will include your main header file (main.h): **#include main.h**


#### Testing


------------

Your shell should work like this in interactive mode:
```bash
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
````
But also in non-interactive mode:
```bash
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

------------

#### Files contained in this repository


------------

|Name                |Information                        |Relevant Files                         |
|----------------|-------------------------------|-----------------------------|
|`(File Name)`|(Description here)| `(Extra files needed by this particular file) or None` |
|`(File Name)`|(Description here)| `(Extra files needed by this particular file) or None` |
|`(File Name)`|(Description here)| `(Extra files needed by this particular file) or None` |
|`(File Name)`|(Description here)| `(Extra files needed by this particular file) or None` |
|`(File Name)`|(Description here)| `(Extra files needed by this particular file) or None` |
|`(File Name)`|(Description here)| `(Extra files needed by this particular file) or None` |
|`(File Name)`|(Description here)| `(Extra files needed by this particular file) or None` |
|`(File Name)`|(Description here)| `(Extra files needed by this particular file) or None` |
|`(File Name)`|(Description here)| `(Extra files needed by this particular file) or None` |
|`(File Name)`|(Description here)| `(Extra files needed by this particular file) or None` |
|`(File Name)`|(Description here)| `(Extra files needed by this particular file) or None` |
|`(File Name)`|(Description here)| `(Extra files needed by this particular file) or None` |
|`(File Name)`|(Description here)| `(Extra files needed by this particular file) or None` |
|`(File Name)`|(Description here)| `(Extra files needed by this particular file) or None` |
|`(File Name)`|(Description here)| `(Extra files needed by this particular file) or None` |
|`(File Name)`|(Description here)| `(Extra files needed by this particular file) or None` |
|`(File Name)`|(Description here)| `(Extra files needed by this particular file) or None` |


------------

#### Tasks required for this project


------------

0. #### Betty would be proud
Write a beautiful code that passes the Betty checks

1. #### Simple shell 0.1
Write a UNIX command line interpreter.

Usage: simple_shell
Your Shell should:

Display a prompt and wait for the user to type a command. A command line always ends with a new line.<br>
The prompt is displayed again each time a command has been executed.<br>
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.<br>
The command lines are made only of one word. No arguments will be passed to programs.<br>
If an executable cannot be found, print an error message and display the prompt again.<br>
Handle errors.<br>
You have to handle the “end of file” condition (Ctrl+D)<br>
You don’t have to:<br>
<br>
use the PATH<br>
implement built-ins<br>
handle special characters : ", ', `, \, *, &, #<br>
be able to move the cursor<br>
handle commands with arguments<br>
execve will be the core part of your Shell, don’t forget to pass the environ to it…<br>

2. #### Simple shell 0.2
Handle command lines with arguments

3. #### Simple shell 0.3
Handle the `PATH`<br>
`fork` must not be called if the command doesn’t exist<br>

4. #### Simple shell 0.4
Implement the `exit` built-in, that exits the shell<br>
Usage: `exit`<br>
You don’t have to handle any argument to the built-in `exit`<br>

5. #### Simple shell 1.0
Implement the env built-in, that prints the current environment

6. #### Simple shell 0.1.1
Write your own `getline` function<br>
Use a buffer to read many chars at once and call the least possible the `read` system call<br>
You will need to use `static` variables<br>
You are not allowed to use `getline`

7. #### Simple shell 0.2.1
You are not allowed to use `strtok`

8. #### Simple shell 0.4.1
handle arguments for the built-in exit<br>
Usage: exit status, where status is an integer used to exit the shell

9. #### setenv, unsetenv
Implement the `setenv` and `unsetenv` builtin commands
- `setenv`
  - Initialize a new environment variable, or modify an existing one
  - Command syntax: `setenv VARIABLE VALUE`
  - Should print something on stderr on failure
- `unsetenv`
  - Remove an environment variable
  - Command syntax: `unsetenv VARIABLE`
  - Should print something on stderr on failure

10. #### cd
Implement the builtin command `cd`:
  - Changes the current directory of the process.
  - Command syntax: cd [DIRECTORY]
  - If no argument is given to cd the command must be interpreted like cd $HOME
  - You have to handle the command cd -
  - You have to update the environment variable PWD when you change directory
  
`man chdir`, `man getcwd`

11. #### ;
Handle the commands separator `;`

12. #### && and ||
Handle the `&&` and `||` shell logical operators

13. #### alias
- Implement the `alias` builtin command
- Usage: `alias [name[='value'] ...]`
    - `alias`: Prints a list of all aliases, one per line, in the form `name='value'`
    - `alias name [name2 ...]`: Prints the aliases `name`, `name2`, etc 1 per line, in the form `name='value'`
    - `alias name='value' [...]`: Defines an alias for each `name` whose `value` is given. If `name` is already an alias, replaces its `value` with value

14. #### Variables
Handle variables replacement<br>
Handle the `$?` variable<br>
Handle the `$$` variable

15. #### Comments
Handle comments (`#`)

16. #### File as input
Usage: `simple_shell [filename]`<br>
Your shell can take a file as a command line argument<br>
The file contains all the commands that your shell should run before exiting<br>
The file should contain one command per line<br>
In this mode, the shell should not print a prompt and should not read from `stdin`

### Authors &copy;

- Abdullateef Odufeso
- Aminu Rabi

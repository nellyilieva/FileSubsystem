# File Subsystem Project

## Overview

This project aims to implement a simplified version of a UNIX-like file system, along with a terminal application that provides a set of basic commands for interacting with the file system. The file system consists of directories and files, each with specific attributes, and supports various file types such as text files, script files, and links.

### Supported File Types

1. **Text File (.txt)**: A file containing human-readable data.
2. **Script File (.sh)**: A file containing a sequence of commands.
3. **Link (.lnk)**: A file that contains a path to another file in the file system. The path can be absolute or relative.

## Command Interface

The terminal application supports the following commands for interacting with the file system:

- **`cd <path>`**: Changes the current working directory to the specified path. The path can be relative or absolute. If the path is invalid, an appropriate error message is displayed.
- **`ls`**: Lists the names of all files and directories in the current working directory, along with their creation and modification dates.
- **`ls <directory path>`**: Lists the contents of the specified directory.
- **`pwd`**: Prints the absolute path of the current working directory.
- **`mkdir <directory name>`**: Creates a new subdirectory in the current working directory. If a directory or file with the same name already exists, an error message is displayed.
- **`touch <file name>`**: Creates a new file in the current working directory. If the file name ends with ".sh", it is treated as a script file. If it ends with ".lnk", it is treated as a link. If the extension is ".txt" or missing, it is treated as a text file. If a file or directory with the same name already exists, the modification date is updated.
- **`rm <file path>`**: Deletes the specified file. If the file does not exist, an error message is displayed.
- **`rmdir <directory path>`**: Deletes the specified subdirectory. If the directory does not exist or contains files, an error message is displayed.
- **`exec <file path>`**: Executes the specified file based on its type:
  - **Text File**: Displays the content of the file on the console.
  - **Script File**: Executes each command in the file line by line.
  - **Link**: Executes the file that the link points to. If the link points to a directory, an error message is displayed.
  - If the file is a directory or does not exist, an error message is displayed.
- **`find <path> <search string>`**: Searches for files and directories that contain the specified search string, starting from the given path. If the path is invalid (e.g., it points to a file instead of a directory), an error message is displayed.
- **`echo <text>`**: Prints the specified text to the standard output.
- **`echo <text> > <file>`**: Overwrites the specified file with the given text.
- **`echo <text> >> <file>`**: Appends the specified text to the end of the given file.
- **`exit`**: Saves the changes made to the file system and closes the application.
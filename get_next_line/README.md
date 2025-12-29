# get_next_line

The **get_next_line** project from [42 School](https://42.fr) is about implementing a function that reads from a file descriptor **line by line**.  
The challenge is to manage **buffered reads**, handle **partial lines**, and ensure **memory safety** with dynamic allocation.

---

## 📌 Project Overview

- Function prototype:
```c
char *get_next_line(int fd);
Reads one line at a time from a file descriptor.

Returns:

The line read (including \n if present).

NULL if there is nothing else to read or on error.

Uses a static variable to store leftover data between function calls.

⚙️ Compilation
sh
Copy code
make        # compiles get_next_line.a
make clean  # removes object files
make fclean # removes .a library and objects
make re     # rebuild everything
🚀 Usage
Example program main.c:

c
Copy code
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
Run:
sh
Copy code
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
./gnl
📊 Project Structure
arduino
Copy code
get_next_line/
│── get_next_line.c        # main function logic
│── get_next_line_utils.c  # helper functions
│── get_next_line.h        # header file
│── main.c                 # example usage (not graded)
│── Makefile
│── README.md
✅ Features
Reads line by line from:

Files

stdin

Any valid file descriptor

Handles multiple file descriptors at the same time (bonus).

Efficient memory management (no leaks).

Fully 42 Norm compliant.

🔧 Implementation Details
Uses read() with a BUFFER_SIZE defined at compile time.

Stores leftover text in a static variable until the next call.

Joins and trims strings dynamically to reconstruct lines.

Bonus:

Supports reading from multiple fds simultaneously using an array of static buffers.

📝 Author
👤 Vache Zohrabyan
42 Yerevan — GitHub

yaml
Copy code

---

👉 Do you want me to also include a **section with diagrams** (like how the buffer shifts and stores leftovers between calls) so it’s easier for recruiters/peers to understand?







Ask ChatGPT

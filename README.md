# Get Next Line (42 School Project)

A C function that reads a line from a file descriptor, handling buffering and static variables.

**Goal:** Implement `get_next_line`, a function that returns one line at a time (ending with '\n' or EOF) from a given file descriptor (`fd`) when called repeatedly.

**Key Concepts:**
*   Reading from file descriptors using `read()`.
*   Using `static` variables to maintain state (the leftover buffer) between function calls.
*   Dynamic memory allocation (`malloc`, `free`).
*   Handling different `BUFFER_SIZE` values during compilation.
*   Reading line by line without reading the entire file at once.
  
**Tech:** C, Static Variables, File Descriptors, `read()`, `malloc()`, `free`, Make

---

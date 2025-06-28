# C++ Stack Implementation

A simple generic stack data structure implemented in C++ using a linked list.

## Features

*   Generic implementation using templates, allowing it to be used with any data type.
*   Basic stack operations:
    *   `push(element)`: Adds an element to the top of the stack.
    *   `pop()`: Removes the element from the top of the stack.
    *   `gettop()`: Returns the value of the top element.
    *   `isempty()`: Checks if the stack is empty.
    *   `display()`: Displays all the elements in the stack.

## How to Compile and Run

This is a single-file C++ program. You can compile and run it using a C++ compiler like g++.

### Compilation

Open a terminal or command prompt and run the following command in the project directory:

```bash
g++ stack.c++ -o stack
```

This will create an executable file named `stack` (or `stack.exe` on Windows).

### Running

To run the program, execute the following command in your terminal:

On macOS or Linux:
```bash
./stack
```

On Windows:
```bash
.\stack.exe
```

The program will run the example usage from the `main` function and print the output to the console.

## Usage

You can modify the `main` function in `stack.c++` to use the stack with different data types and operations.

Here's an example of how to use the stack with integers:

```cpp
#include <iostream>
// You would include the header file if you separate declaration and implementation
// #include "stack.h" 

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    std.cout << "Top element is: " << s.gettop() << std::endl;

    s.pop();

    std::cout << "Top element after pop is: " << s.gettop() << std::endl;

    std::cout << "Stack elements: ";
    s.display();
    std::cout << std::endl;

    return 0;
}
``` 
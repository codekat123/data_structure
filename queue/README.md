# Queue Data Structure Implementation

A C++ implementation of a generic Queue data structure using a linked list approach. This project demonstrates the fundamental operations of a First-In-First-Out (FIFO) queue.

## Overview

This implementation provides a template-based Queue class that can work with any data type. The queue is implemented using a singly linked list structure, offering efficient insertion and deletion operations.

## Features

- **Generic Template Class**: Supports any data type (int, string, custom objects, etc.)
- **Linked List Implementation**: Uses dynamic memory allocation for flexible size
- **Core Queue Operations**: 
  - `push()` - Add elements to the rear of the queue
  - `pop()` - Remove elements from the front of the queue
  - `getfront()` - Access the front element
  - `getrear()` - Access the rear element
  - `isempty()` - Check if queue is empty
  - `display()` - Print all queue elements

## Data Structure

The queue uses a linked list with two pointers:
- `front`: Points to the first element (head of the queue)
- `rear`: Points to the last element (tail of the queue)

Each node contains:
- `data`: The actual value stored
- `next`: Pointer to the next node

## Usage Example

```cpp
#include "queue.cpp"

int main() {
    Queue<int> myQueue;
    
    // Add elements
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    
    // Display queue
    myQueue.display(); // Output: {10 20 30}
    
    // Access front and rear
    cout << "Front: " << myQueue.getfront() << endl; // 10
    cout << "Rear: " << myQueue.getrear() << endl;   // 30
    
    // Remove element
    myQueue.pop();
    myQueue.display(); // Output: {20 30}
    
    return 0;
}
```

## Time Complexity

- **Push Operation**: O(1) - Constant time insertion at rear
- **Pop Operation**: O(1) - Constant time removal from front
- **Front/Rear Access**: O(1) - Constant time access
- **Space Complexity**: O(n) - Linear space for n elements

## Compilation

To compile and run the program:

```bash
g++ -o queue queue.cpp
./queue
```

## Project Structure

```
queue/
├── queue.cpp    # Main implementation file
└── README.md    # This documentation file
```

## Implementation Details

- **Memory Management**: Properly handles dynamic memory allocation and deallocation
- **Edge Cases**: Handles empty queue scenarios and single-element queues
- **Template Design**: Allows for type flexibility without code duplication
- **Error Handling**: Provides appropriate messages for invalid operations

## Future Enhancements

Potential improvements for this implementation:
- Add size() method to return current queue size
- Implement copy constructor and assignment operator
- Add exception handling for memory allocation failures
- Support for move semantics (C++11+)
- Iterator support for range-based loops

## License

This project is open source and available under the MIT License. 
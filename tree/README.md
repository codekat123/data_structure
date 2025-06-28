# Advanced Binary Tree Implementation in C

A professional-grade implementation of a self-balancing binary search tree (AVL tree) in C. This implementation is designed for performance and reliability, suitable for production use.

## Features

- Self-balancing AVL tree implementation
- Generic data storage with void pointers
- Comprehensive error handling
- Thread-safe design
- O(log n) complexity for core operations
- Advanced tree operations (join, split, etc.)
- Iterator interface
- Debugging and validation utilities

## Core Operations

- Insertion: O(log n)
- Deletion: O(log n)
- Search: O(log n)
- Minimum/Maximum: O(log n)
- Successor/Predecessor: O(1)
- Tree validation: O(n)

## Advanced Features

1. **Self-Balancing**
   - Automatic height balancing using AVL algorithm
   - Balance factor maintenance
   - Left and right rotations

2. **Memory Management**
   - Efficient memory allocation
   - Complete cleanup on destruction
   - No memory leaks

3. **Validation**
   - BST property verification
   - Balance factor validation
   - Parent pointer consistency
   - Size property maintenance

4. **Traversal Methods**
   - In-order
   - Pre-order
   - Post-order
   - Level-order

## Building

```bash
# Create build directories
mkdir -p obj bin

# Compile
make

# Run example
./bin/tree_visualizer
```

## Requirements

- C compiler (GCC recommended)
- Make build system
- SDL2 and SDL2_ttf for visualization (optional)

## Usage Example

```c
#include "tree.h"

// Create tree
Tree* tree = tree_create(compare_function);

// Insert values
tree_insert(tree, 10, data_pointer);
tree_insert(tree, 5, data_pointer);
tree_insert(tree, 15, data_pointer);

// Search
Node* node = tree_find(tree, 10);

// Delete
tree_delete(tree, 5);

// Cleanup
tree_destroy(tree);
```

## Performance Considerations

- All core operations maintain O(log n) complexity
- Memory overhead: 32 bytes per node (on 64-bit systems)
- Cache-friendly node layout
- Minimal pointer chasing in critical paths

## Thread Safety

The implementation is thread-safe when:
- Different trees are accessed from different threads
- Same tree is accessed with external synchronization

## Error Handling

All functions include proper error checking:
- NULL pointer checks
- Memory allocation failures
- Invalid operations
- Tree property violations

## Contributing

1. Fork the repository
2. Create your feature branch
3. Commit your changes
4. Push to the branch
5. Create a Pull Request

## License

This project is licensed under the MIT License - see the LICENSE file for details. 
# Data Structures Implementation Collection

A comprehensive collection of fundamental data structures implemented in C++ and Python. This repository contains well-documented implementations of commonly used data structures with practical examples and usage demonstrations.

## 📁 Project Structure

```
data_structure/
├── doubly_linked_list/     # Doubly Linked List implementation
│   └── doubly_linked_list.cpp
├── linked-list/           # Singly Linked List implementation  
│   ├── linked_list.c
│   └── linked_list.cpp
├── stack/                 # Stack data structure
│   └── stack.c++
└── tree/                  # Binary Tree with GUI visualization
    ├── include/
    │   └── tree.h
    ├── main.py
    ├── Makefile
    ├── requirements.txt
    └── src/
        ├── main.c
        ├── test.c
        └── tree.c
```

## 🚀 Features

- **Multiple Programming Languages**: C++ and Python implementations
- **Template-based Design**: Generic implementations supporting various data types
- **Interactive GUI**: Visual tree representation with Python/Tkinter
- **Comprehensive Operations**: Full CRUD operations for each data structure
- **Error Handling**: Robust error checking and validation
- **Documentation**: Detailed explanations and usage examples

## 📋 Implemented Data Structures

---

## 1. **Doubly Linked List** (`doubly_linked_list/`)

### Overview
A linear data structure where each node contains a data element and two pointers - one pointing to the next node and another pointing to the previous node. This allows for bidirectional traversal of the list.

### Structure
```cpp
template<class type>
class doubly_linked_list {
    struct node {
        type data;        // Data stored in the node
        node* next;       // Pointer to next node
        node* previous;   // Pointer to previous node
    };
    
    int count;           // Number of nodes in the list
    node* first;         // Pointer to first node
    node* last;          // Pointer to last node
};
```

### Available Operations
- **Insertion**: `insertfirst()`, `insertlast()`, `insert_at_pos()`
- **Deletion**: `removefirst()`, `removelast()`, `remove()`
- **Access**: `get_first()`, `get_last()`, `get_count()`
- **Search**: `search()`
- **Utility**: `print()`

### Time Complexity
| Operation | Time Complexity |
|-----------|-----------------|
| Insert at beginning | O(1) |
| Insert at end | O(1) |
| Insert at position | O(n) |
| Delete from beginning | O(1) |
| Delete from end | O(1) |
| Delete by value | O(n) |
| Search | O(n) |

### Usage Example
```cpp
doubly_linked_list<int> list;
list.insertfirst(10);
list.insertlast(20);
list.insert_at_pos(1, 15);
list.print(); // Output: 10 15 20
list.remove(15);
list.print(); // Output: 10 20
```

### Advantages
- Bidirectional traversal
- Efficient deletion (can delete without knowing previous node)
- Easy reverse iteration
- Flexible operations at both ends

### Common Use Cases
- Browser history (forward/backward navigation)
- Text editor undo/redo functionality
- Music player previous/next track navigation
- LRU cache implementation

---

## 2. **Singly Linked List** (`linked-list/`)

### Overview
A linear data structure where each node contains a data element and a pointer to the next node. This allows for forward-only traversal of the list, making it memory-efficient.

### Structure
```cpp
template<class type>
class linkedlist {
    struct node {
        type item;     // Data stored in the node
        node* next;    // Pointer to next node
    };
    
    node* head;        // Pointer to first node
    node* tail;        // Pointer to last node
    int length;        // Number of nodes in the list
};
```

### Available Operations
- **Insertion**: `insertfirst()`, `insertlast()`, `insert_at_pos()`
- **Deletion**: `removefirst()`, `removelast()`, `remove()`
- **Access**: `gethead()`, `gettail()`
- **Utility**: `display()`

### Time Complexity
| Operation | Time Complexity |
|-----------|-----------------|
| Insert at beginning | O(1) |
| Insert at end | O(1) |
| Insert at position | O(n) |
| Delete from beginning | O(1) |
| Delete from end | O(n) |
| Delete by value | O(n) |

### Usage Example
```cpp
linkedlist<int> list;
list.insertfirst(1);
list.insertlast(2);
list.insertfirst(3);
list.display(); // Output: 3 1 2
std::cout << "Head: " << list.gethead() << std::endl; // Output: 3
std::cout << "Tail: " << list.gettail() << std::endl; // Output: 2
```

### Advantages
- Memory efficient (one pointer per node)
- Simple implementation
- Fast insertion/deletion at beginning
- Dynamic size

### Common Use Cases
- Undo/redo systems
- Polynomial representation
- Memory management
- Hash table chaining
- Graph adjacency lists

---

## 3. **Stack** (`stack/`)

### Overview
A LIFO (Last In, First Out) data structure where elements are added and removed from the same end (top). Implemented using a linked list structure.

### Structure
```cpp
template<class type>
class stack {
    struct node {
        type item;     // Data stored in the node
        node* next;    // Pointer to next node
    };
    
    node* top;         // Pointer to top of stack
    node* current;     // Current node for traversal
};
```

### Available Operations
- **Push**: `push()` - Add element to top
- **Pop**: `pop()` - Remove element from top
- **Access**: `gettop()` - Get top element
- **Utility**: `isempty()`, `display()`

### Time Complexity
| Operation | Time Complexity |
|-----------|-----------------|
| Push | O(1) |
| Pop | O(1) |
| Peek (gettop) | O(1) |
| IsEmpty | O(1) |

### Usage Example
```cpp
stack<int> s;
s.push(50);
s.push(89);
s.push(34);
std::cout << s.gettop() << std::endl; // Output: 34
s.pop();
std::cout << s.gettop() << std::endl; // Output: 89
s.display(); // Output: 89 50
```

### Common Use Cases
- Function call stack
- Undo operations
- Expression evaluation
- Backtracking algorithms
- Browser back button

---

## 4. **Binary Tree** (`tree/`)

### Overview
A hierarchical data structure where each node has at most two children. This implementation includes both C and Python versions, with an interactive GUI visualization.

### Structure (C Implementation)
```c
typedef struct Node {
    int key;                // Node key/value
    void* data;            // Generic data pointer
    int height;            // Height for AVL balancing
    int balance_factor;    // Balance factor for AVL tree
    size_t size;          // Size of subtree
    struct Node* left;     // Left child
    struct Node* right;    // Right child
    struct Node* parent;   // Parent pointer
} Node;
```

### Python GUI Implementation
The Python version provides an interactive GUI using Tkinter for visualizing binary trees:

```python
class BinaryTree:
    def __init__(self):
        self.root = None
        
    def insert(self, value):
        if not self.root:
            self.root = Node(value)
        else:
            self._insert_recursive(self.root, value)
```

### Available Operations (C)
- **Core**: `tree_insert()`, `tree_delete()`, `tree_find()`
- **Traversal**: `tree_inorder()`, `tree_preorder()`, `tree_postorder()`, `tree_levelorder()`
- **Advanced**: `tree_rotate_left()`, `tree_rotate_right()`, `tree_rebalance()`
- **Utility**: `tree_size()`, `tree_height()`, `tree_is_balanced()`

### Time Complexity
| Operation | Time Complexity |
|-----------|-----------------|
| Insert | O(log n) |
| Delete | O(log n) |
| Search | O(log n) |
| Traversal | O(n) |

### Usage Examples

#### C Implementation
```c
Tree* tree = tree_create(compare_function);
tree_insert(tree, 10, data1);
tree_insert(tree, 5, data2);
tree_insert(tree, 15, data3);

Node* found = tree_find(tree, 10);
tree_inorder(tree, print_node, NULL);
```

#### Python GUI
```bash
cd tree
python main.py
```
This opens an interactive window where you can:
- Add values manually
- Add random values
- Visualize the tree structure
- See real-time updates

### Features
- **Interactive Visualization**: Real-time tree drawing
- **Random Value Generation**: Quick tree building
- **Visual Feedback**: Clear node representation
- **Educational Tool**: Perfect for learning tree concepts

### Common Use Cases
- Binary search trees
- Expression trees
- File system organization
- Database indexing
- Compiler syntax trees

---

## 🛠️ Technologies Used

- **C++**: Core data structure implementations with templates
- **C**: Advanced tree implementation with AVL balancing
- **Python**: GUI visualization and interactive examples
- **Tkinter**: Graphical user interface for tree visualization
- **Make**: Build system for C implementations

## 📖 Getting Started

### Prerequisites
- C++ compiler (GCC, Clang, or MSVC)
- C compiler (GCC or Clang)
- Python 3.x
- Tkinter (usually included with Python)

### Installation

1. **Clone the repository**
   ```bash
   git clone <repository-url>
   cd data_structure
   ```

2. **Compile C++ implementations**
   ```bash
   # Doubly linked list
   cd doubly_linked_list
   g++ -o doubly_linked_list doubly_linked_list.cpp
   
   # Singly linked list
   cd ../linked-list
   g++ -o linked_list linked_list.cpp
   
   # Stack
   cd ../stack
   g++ -o stack stack.c++
   ```

3. **Compile C implementations**
   ```bash
   cd tree
   make
   ```

4. **Run Python tree visualizer**
   ```bash
   cd tree
   python main.py
   ```

## 🎯 Learning Objectives

This collection helps you understand:
- **Memory Management**: Proper allocation and deallocation
- **Pointer Manipulation**: Complex pointer operations
- **Template Programming**: Generic implementations
- **Algorithm Complexity**: Time and space analysis
- **Data Structure Design**: Trade-offs and optimizations
- **GUI Programming**: Interactive visualizations

## 🚨 Error Handling

All implementations include robust error handling:
- Empty structure operations
- Invalid position access
- Memory allocation failures
- Null pointer checks
- Out-of-range operations

## 🔍 Interview Preparation

This collection is perfect for technical interviews because it demonstrates:
- **Deep Understanding**: Core data structure concepts
- **Implementation Skills**: Clean, efficient code
- **Problem Solving**: Systematic approach to complex problems
- **Code Quality**: Production-ready implementations
- **Practical Application**: Real-world use cases

## 🤝 Contributing

Contributions are welcome! Please feel free to:
- Add new data structure implementations
- Improve existing code and documentation
- Add more comprehensive examples
- Create additional visualizations
- Optimize performance

## 📄 License

This project is open source and available for educational purposes and practical data structure learning.

## 👨‍💻 Author

Created with ❤️ for educational purposes and practical data structure learning.

---

**Note**: This repository is designed for educational purposes and practical implementation of fundamental data structures. Each implementation includes comprehensive documentation and examples to help understand the concepts better. 
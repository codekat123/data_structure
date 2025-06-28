# Doubly Linked List in C++

This project implements a generic doubly linked list in C++. The list supports basic operations such as insertion, deletion, searching, and retrieving information about the list.

## Features
- Insert elements at the beginning, end, or a specific position
- Remove elements by value, from the beginning, or from the end
- Search for an element
- Get the first or last element
- Get the number of elements in the list
- Print all elements

## How to Use
1. **Compile the code:**
   ```sh
   g++ doubly_linked_list.cpp -o doubly_linked_list
   ```
2. **Run the program:**
   ```sh
   ./doubly_linked_list
   ```

## Example Usage
The `main` function demonstrates how to use the class:
```cpp
int main() {
    doubly_linked_list<int> list;
    list.insertfirst(10);
    list.insertfirst(20);
    list.insertlast(30);
    list.insertlast(40);
    list.insert_at_pos(2, 25); // Insert 25 at position 2
    list.print();
    cout << endl;
    list.remove(30);
    list.print();
    cout << endl;
    cout << "Search 25: " << (list.search(25) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (list.search(100) ? "Found" : "Not Found") << endl;
    try {
        cout << "First element: " << list.get_first() << endl;
        cout << "Last element: " << list.get_last() << endl;
    } catch (const std::out_of_range& e) {
        cout << e.what() << endl;
    }
    cout << "Count: " << list.get_count() << endl;
    return 0;
}
```

## Example Output
```
your elements are20 10 25 30 40 
your elements are20 10 25 40 
Search 25: Found
Search 100: Not Found
First element: 20
Last element: 40
Count: 4

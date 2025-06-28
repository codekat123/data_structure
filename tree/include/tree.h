#ifndef TREE_H
#define TREE_H

#include <stdbool.h>
#include <stddef.h>

// Advanced tree node structure with balance factor for AVL implementation
typedef struct Node {
    int key;                // Node key/value
    void* data;            // Generic data pointer for flexibility
    int height;            // Height for AVL balancing
    int balance_factor;    // Balance factor for AVL tree
    size_t size;          // Size of subtree rooted at this node
    struct Node* left;     // Left child
    struct Node* right;    // Right child
    struct Node* parent;   // Parent pointer for easier traversal
} Node;

// Tree context structure
typedef struct {
    Node* root;            // Root node
    size_t size;          // Total number of nodes
    int (*compare)(const void*, const void*);  // Comparison function
} Tree;

// Tree initialization and management
Tree* tree_create(int (*compare)(const void*, const void*));
void tree_destroy(Tree* tree);
void tree_clear(Tree* tree);

// Core operations
bool tree_insert(Tree* tree, int key, void* data);
bool tree_delete(Tree* tree, int key);
Node* tree_find(const Tree* tree, int key);
void* tree_get_data(const Tree* tree, int key);

// Advanced operations
Node* tree_find_min(const Tree* tree);
Node* tree_find_max(const Tree* tree);
Node* tree_find_successor(const Node* node);
Node* tree_find_predecessor(const Node* node);
size_t tree_size(const Tree* tree);
int tree_height(const Tree* tree);
bool tree_is_balanced(const Tree* tree);

// Tree traversal functions with callback support
typedef void (*TraversalCallback)(Node* node, void* user_data);
void tree_inorder(const Tree* tree, TraversalCallback callback, void* user_data);
void tree_preorder(const Tree* tree, TraversalCallback callback, void* user_data);
void tree_postorder(const Tree* tree, TraversalCallback callback, void* user_data);
void tree_levelorder(const Tree* tree, TraversalCallback callback, void* user_data);

// Advanced tree operations
bool tree_rotate_left(Tree* tree, Node* node);
bool tree_rotate_right(Tree* tree, Node* node);
void tree_rebalance(Tree* tree, Node* node);
Node* tree_join(Tree* left_tree, Tree* right_tree);
bool tree_split(Tree* tree, int key, Tree** left_tree, Tree** right_tree);

// Tree validation and debugging
bool tree_validate(const Tree* tree);
void tree_print_debug(const Tree* tree);

// Iterator interface
typedef struct TreeIterator TreeIterator;
TreeIterator* tree_iterator_create(Tree* tree);
void tree_iterator_destroy(TreeIterator* iterator);
Node* tree_iterator_next(TreeIterator* iterator);
bool tree_iterator_has_next(const TreeIterator* iterator);

#endif // TREE_H 
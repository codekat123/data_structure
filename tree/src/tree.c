#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/tree.h"

// Helper function to create a new node
static Node* create_node(int key, void* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) return NULL;
    
    node->key = key;
    node->data = data;
    node->height = 1;
    node->balance_factor = 0;
    node->size = 1;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    
    return node;
}

// Helper function to get node height
static int get_height(const Node* node) {
    return node ? node->height : 0;
}

// Helper function to get node size
static size_t get_size(const Node* node) {
    return node ? node->size : 0;
}

// Helper function to update node height and balance factor
static void update_node_metadata(Node* node) {
    if (!node) return;
    
    int left_height = get_height(node->left);
    int right_height = get_height(node->right);
    
    node->height = 1 + (left_height > right_height ? left_height : right_height);
    node->balance_factor = right_height - left_height;
    node->size = 1 + get_size(node->left) + get_size(node->right);
}

// Tree creation
Tree* tree_create(int (*compare)(const void*, const void*)) {
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    if (!tree) return NULL;
    
    tree->root = NULL;
    tree->size = 0;
    tree->compare = compare;
    
    return tree;
}

// Helper function for tree destruction
static void destroy_subtree(Node* node) {
    if (!node) return;
    
    destroy_subtree(node->left);
    destroy_subtree(node->right);
    free(node);
}

// Tree destruction
void tree_destroy(Tree* tree) {
    if (!tree) return;
    
    destroy_subtree(tree->root);
    free(tree);
}

// AVL tree rotations
bool tree_rotate_left(Tree* tree, Node* node) {
    if (!tree || !node || !node->right) return false;
    
    Node* right_child = node->right;
    Node* parent = node->parent;
    
    // Perform rotation
    node->right = right_child->left;
    if (right_child->left)
        right_child->left->parent = node;
    
    right_child->left = node;
    node->parent = right_child;
    right_child->parent = parent;
    
    // Update parent pointers
    if (!parent)
        tree->root = right_child;
    else if (parent->left == node)
        parent->left = right_child;
    else
        parent->right = right_child;
    
    // Update metadata
    update_node_metadata(node);
    update_node_metadata(right_child);
    
    return true;
}

bool tree_rotate_right(Tree* tree, Node* node) {
    if (!tree || !node || !node->left) return false;
    
    Node* left_child = node->left;
    Node* parent = node->parent;
    
    // Perform rotation
    node->left = left_child->right;
    if (left_child->right)
        left_child->right->parent = node;
    
    left_child->right = node;
    node->parent = left_child;
    left_child->parent = parent;
    
    // Update parent pointers
    if (!parent)
        tree->root = left_child;
    else if (parent->left == node)
        parent->left = left_child;
    else
        parent->right = left_child;
    
    // Update metadata
    update_node_metadata(node);
    update_node_metadata(left_child);
    
    return true;
}

// Tree rebalancing
void tree_rebalance(Tree* tree, Node* node) {
    if (!tree || !node) return;
    
    update_node_metadata(node);
    
    // Check balance factor and perform rotations if needed
    if (node->balance_factor > 1) {
        if (node->right->balance_factor < 0)
            tree_rotate_right(tree, node->right);
        tree_rotate_left(tree, node);
    }
    else if (node->balance_factor < -1) {
        if (node->left->balance_factor > 0)
            tree_rotate_left(tree, node->left);
        tree_rotate_right(tree, node);
    }
    
    // Recursively rebalance up the tree
    if (node->parent)
        tree_rebalance(tree, node->parent);
}

// Tree insertion
bool tree_insert(Tree* tree, int key, void* data) {
    if (!tree) return false;
    
    Node* new_node = create_node(key, data);
    if (!new_node) return false;
    
    if (!tree->root) {
        tree->root = new_node;
        tree->size = 1;
        return true;
    }
    
    Node* current = tree->root;
    Node* parent = NULL;
    
    while (current) {
        parent = current;
        if (key < current->key)
            current = current->left;
        else if (key > current->key)
            current = current->right;
        else {
            // Key already exists
            free(new_node);
            return false;
        }
    }
    
    new_node->parent = parent;
    if (key < parent->key)
        parent->left = new_node;
    else
        parent->right = new_node;
    
    tree->size++;
    tree_rebalance(tree, parent);
    
    return true;
}

// Tree search
Node* tree_find(const Tree* tree, int key) {
    if (!tree) return NULL;
    
    Node* current = tree->root;
    while (current) {
        if (key < current->key)
            current = current->left;
        else if (key > current->key)
            current = current->right;
        else
            return current;
    }
    
    return NULL;
}

// Get minimum node
Node* tree_find_min(const Tree* tree) {
    if (!tree || !tree->root) return NULL;
    
    Node* current = tree->root;
    while (current->left)
        current = current->left;
    
    return current;
}

// Get maximum node
Node* tree_find_max(const Tree* tree) {
    if (!tree || !tree->root) return NULL;
    
    Node* current = tree->root;
    while (current->right)
        current = current->right;
    
    return current;
}

// Tree validation
bool tree_validate(const Tree* tree) {
    if (!tree) return false;
    
    // Helper function to validate a subtree
    bool validate_subtree(const Node* node, int* min_key, int* max_key) {
        if (!node) return true;
        
        // Check BST property
        if (node->left && node->left->key >= node->key) return false;
        if (node->right && node->right->key <= node->key) return false;
        
        // Check parent pointers
        if (node->left && node->left->parent != node) return false;
        if (node->right && node->right->parent != node) return false;
        
        // Check balance factor
        int balance = get_height(node->right) - get_height(node->left);
        if (balance != node->balance_factor) return false;
        if (balance > 1 || balance < -1) return false;
        
        // Check size
        size_t computed_size = 1 + get_size(node->left) + get_size(node->right);
        if (computed_size != node->size) return false;
        
        // Recursively validate subtrees
        return validate_subtree(node->left, min_key, &node->key) &&
               validate_subtree(node->right, &node->key, max_key);
    }
    
    int min_key = INT_MIN;
    int max_key = INT_MAX;
    return validate_subtree(tree->root, &min_key, &max_key);
}

// Debug printing
void tree_print_debug(const Tree* tree) {
    if (!tree) {
        printf("Tree is NULL\n");
        return;
    }
    
    printf("Tree size: %zu\n", tree->size);
    
    void print_node(const Node* node, int level) {
        if (!node) return;
        
        print_node(node->right, level + 1);
        
        for (int i = 0; i < level; i++)
            printf("    ");
        printf("%d (bf=%d, h=%d, s=%zu)\n",
               node->key, node->balance_factor, node->height, node->size);
        
        print_node(node->left, level + 1);
    }
    
    print_node(tree->root, 0);
} 
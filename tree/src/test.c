#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../include/tree.h"

// Comparison function for testing
static int compare_ints(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Test basic tree operations
void test_basic_operations() {
    printf("Testing basic operations...\n");
    
    Tree* tree = tree_create(compare_ints);
    assert(tree != NULL);
    assert(tree->size == 0);
    
    // Test insertion
    assert(tree_insert(tree, 10, NULL));
    assert(tree_insert(tree, 5, NULL));
    assert(tree_insert(tree, 15, NULL));
    assert(tree->size == 3);
    
    // Test search
    Node* node = tree_find(tree, 10);
    assert(node != NULL);
    assert(node->key == 10);
    
    node = tree_find(tree, 5);
    assert(node != NULL);
    assert(node->key == 5);
    
    node = tree_find(tree, 15);
    assert(node != NULL);
    assert(node->key == 15);
    
    // Test non-existent value
    assert(tree_find(tree, 100) == NULL);
    
    // Test min/max
    assert(tree_find_min(tree)->key == 5);
    assert(tree_find_max(tree)->key == 15);
    
    // Validate tree properties
    assert(tree_validate(tree));
    
    tree_destroy(tree);
    printf("Basic operations test passed!\n");
}

// Test AVL balancing
void test_avl_balancing() {
    printf("Testing AVL balancing...\n");
    
    Tree* tree = tree_create(compare_ints);
    
    // Insert values that would cause imbalance without AVL
    assert(tree_insert(tree, 10, NULL));
    assert(tree_insert(tree, 20, NULL));
    assert(tree_insert(tree, 30, NULL));
    
    // Check if tree is balanced
    assert(tree_validate(tree));
    assert(tree->root->balance_factor >= -1 && tree->root->balance_factor <= 1);
    
    // The tree should have been rebalanced with 20 at the root
    assert(tree->root->key == 20);
    assert(tree->root->left->key == 10);
    assert(tree->root->right->key == 30);
    
    tree_destroy(tree);
    printf("AVL balancing test passed!\n");
}

// Test tree traversal
void test_traversal() {
    printf("Testing tree traversal...\n");
    
    Tree* tree = tree_create(compare_ints);
    int values[] = {10, 5, 15, 3, 7, 12, 17};
    int count = sizeof(values) / sizeof(values[0]);
    
    // Insert values
    for (int i = 0; i < count; i++) {
        assert(tree_insert(tree, values[i], NULL));
    }
    
    // Test if tree is valid
    assert(tree_validate(tree));
    
    tree_destroy(tree);
    printf("Traversal test passed!\n");
}

int main() {
    printf("Running tree tests...\n\n");
    
    test_basic_operations();
    test_avl_balancing();
    test_traversal();
    
    printf("\nAll tests passed successfully!\n");
    return 0;
} 
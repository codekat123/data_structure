#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/tree.h"

// Comparison function for integers
static int compare_ints(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Example callback for tree traversal
static void print_node_callback(Node* node, void* user_data) {
    printf("%d ", node->key);
}

int main() {
    // Create a new tree
    Tree* tree = tree_create(compare_ints);
    if (!tree) {
        fprintf(stderr, "Failed to create tree\n");
        return 1;
    }

    // Insert some random values
    srand(time(NULL));
    printf("Inserting random values...\n");
    for (int i = 0; i < 10; i++) {
        int value = rand() % 100;
        printf("Inserting %d\n", value);
        if (!tree_insert(tree, value, NULL)) {
            printf("Failed to insert %d (might be duplicate)\n", value);
        }
    }

    // Print tree structure
    printf("\nTree structure:\n");
    tree_print_debug(tree);

    // Demonstrate traversals
    printf("\nIn-order traversal: ");
    tree_inorder(tree, print_node_callback, NULL);
    printf("\n");

    // Find min and max
    Node* min_node = tree_find_min(tree);
    Node* max_node = tree_find_max(tree);
    printf("\nMinimum value: %d\n", min_node ? min_node->key : -1);
    printf("Maximum value: %d\n", max_node ? max_node->key : -1);

    // Validate tree properties
    if (tree_validate(tree)) {
        printf("\nTree validation passed!\n");
    } else {
        printf("\nTree validation failed!\n");
    }

    // Cleanup
    tree_destroy(tree);
    printf("\nTree destroyed successfully\n");

    return 0;
} 
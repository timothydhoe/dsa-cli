#ifndef ALGORITHMS_H
#define ALGORITHMS_H

// Animation function prototypes
int show_selection_sort(void);
int show_bubble_sort(void);
int show_merge_sort(void);
int show_insertion_sort(void);

// Helper for merge sort recursion
void animate_merge_sort_recursive(int arr[], int start, int end, int total_size);

// Code display function prototypes
void code_selection_sort(void);
void code_bubble_sort(void);
void code_merge_sort(void);
void code_insertion_sort(void);

// Pseudocode display function prototypes
void pseudo_selection_sort(void);
void pseudo_bubble_sort(void);
void pseudo_merge_sort(void);
void pseudo_insertion_sort(void);

// Eli5 print functions
void eli5_selection_sort(void);
void eli5_bubble_sort(void);
void eli5_merge_sort(void);
void eli5_insertion_sort(void);


#endif

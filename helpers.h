#ifndef HELPERS_H
#define HELPERS_H

// Display function prototypes
void print_header(void);
void print_usage(void);

// Visualisation function prototypes
void print_bars(int arr[], int size, int active_idx, int sorted_idx);
void print_bars_bubble(int arr[], int size, int active1, int active2, int sorted_start_idx);
void print_bars_merge(int arr[], int size, int start, int mid, int end);
void animate_merge_sort_recursive(int arr[], int left, int right, int total_size);

// Helper for merge sort recursion
void animate_merge_sort_recursive(int arr[], int start, int end, int total_size);
void merge_arrays(int arr[], int left, int mid, int right);

// Utility function prototypes
void clear_screen(void);
void wait_for_step(void);

#endif

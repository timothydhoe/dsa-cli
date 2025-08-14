#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "style.h"
#include "helpers.h"
#include "config.h"

void print_header(void)
{
    if (g_settings.use_colors) {
        printf(YELLOW BOLD);
    }
    
    printf("\n--------------------------------------------------------\n");
    printf("         ____  ____   __         ___  __    __\n");
    printf("        (    \\/ ___) / •\\  ___  / __)(  )  (  )\n");
    printf("         ) • (\\___ \\/    \\(___)( (__ / (_/\\ )(\n");
    printf("        (____/(____/\\_/\\_/      \\___)\\____/(__)\n");
    printf("\n--------------------------------------------------------\n");
    printf("  • Learn algorithms & data structures interactively •\n\n");
    
    if (g_settings.use_colors) {
        printf(RESET);
    }
}

void print_usage(void)
{
    print_header();

    print_heading("Usage:\n");
    printf("  ./dsa [algorithm]           Show animation\n");
    printf("  ./dsa [algorithm] --code    Show C code\n");
    printf("  ./dsa [algorithm] --pseudo  Show pseudocode\n");
    printf("  ./dsa [algorithm] --eli5    Explain Like I'm Five\n");
    printf("\n");

    print_heading("Algorithms:\n");
    printf("  bubble      Bubble sort\n");
    printf("  selection   Selection sort\n");
    printf("  merge       Merge sort\n");
    printf("  insertion   Insertion sort\n");
    printf("\n");

    print_heading("Settings:\n");
    printf("  --settings      Check your current settings\n");
    printf("  --speed [1-3]   Set animation speed (1=slow, 2=medium, 3=fast)\n");
    printf("  --colors        Toggle colors on/off\n");
    printf("  --bar [char]    Set bar character\n");
    printf("\n");

    print_heading("Other:\n");
    printf("  --list          List all algorithms\n");
    printf("  --tutorial      Start tutorial\n");
    printf("  --help          Show this help\n");
    printf("\n");

    print_heading("Examples:\n");
    printf("  ./dsa bubble\n");
    printf("  ./dsa selection --code\n");
    printf("  ./dsa --speed 1\n");
    printf("  ./dsa --bar '*'\n");
    printf("\n");
}

void clear_screen(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void print_bars(int arr[], int size, int active_idx, int sorted_idx)
{
    // Find max value for scaling
    int max_val = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    printf("Array:\n");
    for (int i = 0; i < size; i++) {
        // Calculate bar width (max 40 characters)
        int bar_width = max_val > 0 ? (arr[i] * 40) / max_val : 0;

        // Set color based on element state
        if (g_settings.use_colors) {
            if (i == active_idx) {
                printf(RED);  // current element
            } else if (i <= sorted_idx) {
                printf(GREEN); // sorted elements
            }
        }

        // Print value and bar
        printf("[%2d] ", arr[i]);
        for (int j = 0; j < bar_width; j++) {
            printf("%c", g_settings.bar_char);
        }
        
        if (g_settings.use_colors) {
            printf(RESET);
        }
        printf("\n");
    }
}

void print_bars_bubble(int arr[], int size, int active1, int active2, int sorted_start_idx)
{
    int max_val = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max_val) max_val = arr[i];
    }

    printf("Bubble sort:\n");
    for (int i = 0; i < size; i++) {
        int bar_width = max_val > 0 ? (arr[i] * 40) / max_val : 0;
        
        if (g_settings.use_colors) {
            if (i == active1 || i == active2) {
                printf(RED);  // comparing elements
            } else if (i >= sorted_start_idx) {
                printf(GREEN); // sorted elements
            }
        }
        
        printf("[%2d] ", arr[i]);
        for (int j = 0; j < bar_width; j++) {
            printf("%c", g_settings.bar_char);
        }
        
        if (g_settings.use_colors) {
            printf(RESET);
        }
        printf("\n");
    }
}

void print_bars_merge(int arr[], int size, int start, int mid, int end)
{
    int max_val = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max_val) max_val = arr[i];
    }

    printf("Merge sort:\n");
    for (int i = 0; i < size; i++) {
        int bar_width = max_val > 0 ? (arr[i] * 40) / max_val : 0;
        
        if (g_settings.use_colors) {
            if (i >= start && i <= mid) {
                printf(RED);   // left subarray
            } else if (i > mid && i <= end) {
                printf(BLUE);  // right subarray
            }
        }
        
        printf("[%2d] ", arr[i]);
        for (int j = 0; j < bar_width; j++) {
            printf("%c", g_settings.bar_char);
        }
        
        if (g_settings.use_colors) {
            printf(RESET);
        }
        printf("\n");
    }
}

// Helper function for merge sort animation
void animate_merge_sort_recursive(int arr[], int left, int right, int total_size)
{
    if (left >= right) {
        return; // Base case: single element
    }

    int mid = left + (right - left) / 2;

    // Show the divide phase
    clear_screen();
    printf("Merge Sort - Dividing...\n");
    printf("Splitting [%d-%d] into [%d-%d] and [%d-%d]\n\n", 
           left, right, left, mid, mid + 1, right);
    print_bars_merge(arr, total_size, left, mid, right);
    usleep(get_delay_time());

    // FIRST: Completely sort the left half
    animate_merge_sort_recursive(arr, left, mid, total_size);
    
    // THEN: Completely sort the right half  
    animate_merge_sort_recursive(arr, mid + 1, right, total_size);

    // NOW: Both halves are sorted, so we can merge them
    clear_screen();
    printf("Merge Sort - Both halves sorted, now merging...\n");
    printf("Left half [%d-%d] and right half [%d-%d] are both sorted\n\n", 
           left, mid, mid + 1, right);
    print_bars_merge(arr, total_size, left, mid, right);
    usleep(get_delay_time());

    // Perform the actual merge (without showing each step)
    merge_arrays(arr, left, mid, right);

    // Show the final merged result
    clear_screen();
    printf("Merge Sort - Merge complete!\n");
    printf("Successfully merged [%d-%d]\n\n", left, right);
    print_bars_merge(arr, total_size, left, -1, right);
    usleep(get_delay_time());
}

// Separate function that just does the merge without animation
void merge_arrays(int arr[], int left, int mid, int right)
{
    int left_size = mid - left + 1;
    int right_size = right - mid;
    int left_arr[left_size];
    int right_arr[right_size];

    // Copy data to temp arrays
    for (int i = 0; i < left_size; i++) {
        left_arr[i] = arr[left + i];
    }
    for (int j = 0; j < right_size; j++) {
        right_arr[j] = arr[mid + 1 + j];
    }

    // Merge the temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;

    while (i < left_size && j < right_size) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        } else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements
    while (i < left_size) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }
    while (j < right_size) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}
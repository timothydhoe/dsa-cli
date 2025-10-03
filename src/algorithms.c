#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "algorithms.h"
#include "helpers.h"    // Contains helper functions for visualisation.
#include "style.h"
#include "config.h"

int show_selection_sort(void)
{
    printf("Starting Selection Sort Animation...\n\n");
    
    // Create array
    int n = 5;
    int arr[] = {40, 18, 5, 32, 22};

    // Selection sort with animation
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        
        // Find minimum
        for (int j = i + 1; j < n; j++)
        {
            clear_screen();
            printf("Selection Sort - Finding minimum...\n\n");
            print_bars(arr, n, j, i - 1);
            usleep(get_delay_time());
            
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        // Swap if needed
        if (min_idx != i)
        {
            clear_screen();
            printf("Selection Sort - Swapping...\n\n");
            print_bars(arr, n, min_idx, i - 1);
            usleep(get_delay_time());
            
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
        
        clear_screen();
        printf("Selection Sort - Element in place!\n\n");
        print_bars(arr, n, -1, i);
        usleep(get_delay_time());
    }

    clear_screen();
    printf("Selection Sort Complete!\n\n");
    print_bars(arr, n, -1, n - 1);
    
    return 0;
}

int show_bubble_sort(void)
{
    printf("Starting Bubble Sort Animation...\n\n");
    
    int n = 6;
    int arr[] = {64, 34, 25, 12, 22, 11};

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            clear_screen();
            printf("Bubble Sort - Comparing elements...\n\n");
            print_bars_bubble(arr, n, j, j + 1, n - i);
            usleep(get_delay_time());

            if (arr[j] > arr[j + 1])
            {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                clear_screen();
                printf("Bubble Sort - Swapped!\n\n");
                print_bars_bubble(arr, n, j, j + 1, n - i);
                usleep(get_delay_time());
            }
        }
    }

    clear_screen();
    printf("Bubble Sort Complete!\n\n");
    print_bars_bubble(arr, n, -1, -1, 0);
    
    return 0;
}

int show_insertion_sort(void)
{
    printf("Starting Insertion Sort Animation...\n\n");
    
    int n = 6;
    int arr[] = {25, 12, 37, 8, 45, 19};

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        clear_screen();
        printf("Insertion Sort - Inserting %d...\n\n", key);
        print_bars(arr, n, i, i - 1);
        usleep(get_delay_time());

        // Move elements
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
            
            clear_screen();
            printf("Insertion Sort - Moving elements...\n\n");
            print_bars(arr, n, j + 1, i - 1);
            usleep(get_delay_time() / 2);  // faster for shifts
        }
        
        arr[j + 1] = key;
        
        clear_screen();
        printf("Insertion Sort - Element inserted!\n\n");
        print_bars(arr, n, -1, i);
        usleep(get_delay_time());
    }

    clear_screen();
    printf("Insertion Sort Complete!\n\n");
    print_bars(arr, n, -1, n - 1);
    
    return 0;
}

// Merge sort
int show_merge_sort(void)
{
    printf(GREEN "Starting Merge Sort Animation...\n\n" RESET);
    
    int n = 8;
    int arr[] = {38, 27, 43, 3, 9, 82, 10, 50};

    printf("Initial array:\n");
    print_bars_merge(arr, n, -1, -1, -1);
    usleep(get_delay_time());

    // Start the recursive merge sort
    animate_merge_sort_recursive(arr, 0, n - 1, n);

    // Show final result
    clear_screen();
    printf("Merge Sort Complete!\n\n");
    print_bars_merge(arr, n, -1, -1, -1);
    
    printf("\nMerge sort: O(n log n) - much faster than O(n²) algorithms!\n");
    
    return 0;
}

// Code display functions
void code_selection_sort(void)
{
    printf(GREEN "\n=== Selection Sort Code ===\n\n" RESET);
    printf("void selection_sort(int arr[], int n)\n");
    printf("{\n");
    printf("    for (int i = 0; i < n - 1; i++)\n");
    printf("    {\n");
    printf("        int min_idx = i;\n");
    printf("        \n");
    printf(CYAN "        // Find minimum element\n" RESET);
    printf("        for (int j = i + 1; j < n; j++)\n");
    printf("        {\n");
    printf("            if (arr[j] < arr[min_idx])\n");
    printf("            {\n");
    printf("                min_idx = j;\n");
    printf("            }\n");
    printf("        }\n");
    printf("        \n");
    printf(CYAN "        // Swap if needed\n" RESET);
    printf("        if (min_idx != i)\n");
    printf("        {\n");
    printf("            int temp = arr[i];\n");
    printf("            arr[i] = arr[min_idx];\n");
    printf("            arr[min_idx] = temp;\n");
    printf("        }\n");
    printf("    }\n");
    printf("}\n\n");
}

void code_bubble_sort(void)
{
    printf(GREEN "\n=== Bubble Sort Code ===\n\n" RESET);
    printf("void bubble_sort(int arr[], int n)\n");
    printf("{\n");
    printf("    for (int i = 0; i < n - 1; i++)\n");
    printf("    {\n");
    printf("        for (int j = 0; j < n - 1 - i; j++)\n");
    printf("        {\n");
    printf("            if (arr[j] > arr[j + 1])\n");
    printf("            {\n");
    printf(CYAN "                // Swap elements\n" RESET);
    printf("                int temp = arr[j];\n");
    printf("                arr[j] = arr[j + 1];\n");
    printf("                arr[j + 1] = temp;\n");
    printf("            }\n");
    printf("        }\n");
    printf("    }\n");
    printf("}\n\n");
}

void code_insertion_sort(void)
{
    printf(GREEN "\n=== Insertion Sort Code ===\n\n" RESET);
    printf("void insertion_sort(int arr[], int n) {\n");
    printf("    for (int i = 1; i < n; i++) {\n");
    printf("        int key = arr[i];\n");
    printf("        int j = i - 1;\n");
    printf("        \n");
    printf(CYAN "        // Move elements greater than key\n" RESET);
    printf("        while (j >= 0 && arr[j] > key) {\n");
    printf("            arr[j + 1] = arr[j];\n");
    printf("            j--;\n");
    printf("        }\n");
    printf("        \n");
    printf("        arr[j + 1] = key;\n");
    printf("    }\n");
    printf("}\n\n");
}

void code_merge_sort(void)
{
    printf(GREEN "\n=== Merge Sort Code ===\n\n" RESET);
    printf("// Simplified version - full implementation is more complex\n");
    printf("void merge_sort(int arr[], int n) {\n");
    printf("    if (n < 2) return;\n");
    printf("    \n");
    printf("    int mid = n / 2;\n");
    printf("    // Split into left and right arrays\n");
    printf("    // Recursively sort both halves\n");
    printf("    // Merge the sorted halves back together\n");
    printf("}\n\n");
}

// Pseudocode functions
void pseudo_selection_sort(void)
{
    printf(GREEN "\n=== Selection Sort Pseudocode ===\n\n" RESET);
    printf("FOR i = 0 to n-2:\n");
    printf("    min_index = i\n");
    printf("    \n");
    printf("    FOR j = i+1 to n-1:\n");
    printf("        IF array[j] < array[min_index]:\n");
    printf("            min_index = j\n");
    printf("    \n");
    printf("    SWAP array[i] with array[min_index]\n");
    printf("\n");
}

void pseudo_bubble_sort(void)
{
    printf(GREEN "\n=== Bubble Sort Pseudocode ===\n\n" RESET);
    printf("FOR i = 0 to n-2:\n");
    printf("    FOR j = 0 to n-2-i:\n");
    printf("        IF array[j] > array[j+1]:\n");
    printf("            SWAP array[j] with array[j+1]\n");
    printf("\n");
}

void pseudo_insertion_sort(void)
{
    printf(GREEN "\n=== Insertion Sort Pseudocode ===\n\n" RESET);
    printf("FOR i = 1 to n-1:\n");
    printf("    key = array[i]\n");
    printf("    j = i - 1\n");
    printf("    \n");
    printf("    WHILE j >= 0 AND array[j] > key:\n");
    printf("        array[j+1] = array[j]\n");
    printf("        j = j - 1\n");
    printf("    \n");
    printf("    array[j+1] = key\n");
    printf("\n");
}

void pseudo_merge_sort(void)
{
    printf(GREEN "\n=== Merge Sort Pseudocode ===\n\n" RESET);
    printf("FUNCTION merge_sort(array):\n");
    printf("    IF length of array <= 1:\n");
    printf("        RETURN array\n");
    printf("    \n");
    printf("    SPLIT array into left and right halves\n");
    printf("    left = merge_sort(left_half)\n");
    printf("    right = merge_sort(right_half)\n");
    printf("    \n");
    printf("    RETURN merge(left, right)\n");
    printf("\n");
}

// ELI5 functions
void eli5_selection_sort(void)
{
    printf(GREEN "\n--- ELI5: Selection Sort ---\n\n" RESET);
    printf("You're playing cards and want to sort your hand from lowest to highest.\n\n");
    printf("1. Look at all the cards in your hand at once. Find the absolute lowest card (the '2').\n");
    printf("2. Take that '2' and place it down as the first card on the table.\n");
    printf("3. Now look at the remaining cards in your hand. Find the next lowest card (the '3').\n");
    printf("4. Take the '3' and place it down on the table next to the '2'.\n\n");
    printf("You repeat this process—finding the lowest card from your remaining hand and putting it in the next open spot on the table—until your hand is empty and the table has a perfectly sorted row of cards.\n\n");
}

void eli5_bubble_sort(void)
{
    printf(GREEN "\n--- ELI5: Bubble Sort ---\n\n" RESET);
    printf("Imagine a train with its cars all mixed up (e.g., 5-2-4-1-3).\n");
    printf("The train conductor can only compare two cars that are right next to each other.\n\n");
    printf("1. The conductor starts at the front of the train and compares car #1 and car #2.\n");
    printf("2. If they're in the wrong order (e.g., 5 is before 2), they swap them. The train is now 2-5-4-1-3.\n");
    printf("3. The conductor moves one step down and compares the new car #2 (now 5) and car #3 (4). They swap those too. The train becomes 2-4-5-1-3.\n");
    printf("4. This continues all the way to the end. After one full trip, the heaviest car (5) is guaranteed to be at the very end.\n\n");
    printf("The conductor goes back to the beginning and repeats the whole trip. With each trip, the next heaviest car 'bubbles' to its correct spot at the end.\n\n");
}

void eli5_insertion_sort(void)
{
    printf(GREEN "\n--- ELI5: Insertion Sort ---\n\n" RESET);
    printf("Imagine you're being dealt playing cards, one at a time.\n\n");
    printf("1. You get your first card (a '7'). Your 'hand' is now just a 7. It's already sorted!\n");
    printf("2. The dealer gives you a second card (a '4'). You look at your hand, see the '7', and **insert** the '4' before it. Your hand is now a sorted [4, 7].\n");
    printf("3. The dealer gives you a third card (a '9'). You find its correct spot and **insert** it at the end. Your hand is now [4, 7, 9].\n");
    printf("4. The dealer gives you a fourth card (a '5'). You scan your sorted hand, find the spot between the '4' and '7', make room, and **insert** it there. Your hand becomes [4, 5, 7, 9].\n\n");
    printf("You continue this for every card. You take one new card at a time from the 'unsorted' pile and find its proper place to insert it into your 'sorted' hand.\n\n");
}

void eli5_merge_sort(void)
{
    printf(GREEN "\n--- ELI5: Merge Sort ---\n\n" RESET);
    printf("Imagine a librarian has a huge, messy pile of a thousand books to sort alphabetically.\n\n");
    printf("It's too big to handle at once! So they use a trick called " CYAN BOLD"'Divide and Conquer'.\n\n" RESET);
    printf("1. " CYAN BOLD "DIVIDE: " RESET "The librarian splits the giant pile into two smaller piles of 500. They give one pile to an assistant. They both keep splitting their piles in half until everyone is left holding tiny piles with just one book each. (A pile of one book is already sorted!)\n\n");
    printf("2." CYAN BOLD "CONQUER (MERGE): " RESET "Now, everyone starts merging their tiny piles back together, but in sorted order. You take two sorted 1-book piles and merge them into one sorted 2-book pile. Then you take two sorted 2-book piles and merge them into one sorted 4-book pile.\n\n");
    printf("This continues—merging sorted piles with other sorted piles—until the librarian finally merges the two giant, sorted 500-book piles back into the original 1000-book pile, which is now perfectly sorted.\n\n");
}
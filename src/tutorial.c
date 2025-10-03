#include <stdio.h>
#include <string.h>
#include "helpers.h"
#include "tutorial.h"
#include "style.h"

// Helper to wait for ENTER
void wait_for_enter(void) {
    printf("\nPress ENTER to continue...");
    while (getchar() != '\n'); // wait until newline
}

void run_tutorial(void) {
    print_header(); // Your ASCII art title

    printf("Welcome to the " GREEN "DSA-CLI Tutorial" RESET "!\n");
    printf("This tutorial will guide you step-by-step on how to use this tool.\n\n");

    wait_for_enter();

    printf("Step 1: Listing algorithms\n");
    printf("Type: " CYAN "./dsa --list" RESET "\n");
    printf("This will show all available sorting algorithms.\n");
    wait_for_enter();

    printf("Step 2: Showing how an algorithm works\n");
    printf("Example: " CYAN "./dsa bubble" RESET "\n");
    printf("This will play an animation of Bubble Sort.\n");
    wait_for_enter();

    printf("Step 3: Viewing the C code for an algorithm\n");
    printf("Example: " CYAN "./dsa merge --code" RESET "\n");
    printf("This prints the actual C code for Merge Sort.\n");
    wait_for_enter();

    printf("Step 4: Viewing pseudocode\n");
    printf("Example: " CYAN "./dsa insertion --pseudo" RESET "\n");
    printf("This prints a language-agnostic version of the algorithm.\n");
    wait_for_enter();

    printf("Step 5: Make it your own\n");
    printf("Example: " CYAN "./dsa --settings" RESET "\n");
    printf("To check your configuration. And you might change it yourself!\n");
    wait_for_enter();

    printf("🎉 That's it! You've completed the DSA-CLI tutorial!\n");
    printf("Try running some commands now, or use " CYAN "./dsa --help" RESET " to see all options.\n\n");
}

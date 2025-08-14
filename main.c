#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "algorithms.h"
#include "helpers.h"
#include "structures.h"
#include "tutorial.h"
#include "config.h"

int main(int argc, char *argv[])
{
    // Load default settings
    load_default_settings();

    // No arguments - show help
    if (argc == 1) {
        print_usage();
        return 0;
    }

    // Help command
    if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0) {
        print_usage();
        return 0;
    }

    // Tutorial
    if (strcmp(argv[1], "--tutorial") == 0) {
        run_tutorial();
        return 0;
    }

    // Settings commands
    if (strcmp(argv[1], "--speed") == 0 && argc >= 3) {
        int speed = atoi(argv[2]);  // convert string to number
        set_speed(speed);
        return 0;
    }

    if (strcmp(argv[1], "--colors") == 0) {
        if (argc >= 3) {
            set_colors(argv[2]);  // set specific value
        } else {
            toggle_colors();      // just toggle if no value given
        }
        return 0;
    }

    if (strcmp(argv[1], "--bar") == 0 && argc >= 3) {
        set_bar_char(argv[2][0]);  // first character of argument
        return 0;
    }

    // Show current settings
    if (strcmp(argv[1], "--settings") == 0) {
        printf("Current settings:\n");
        printf("  Speed: %d (%s)\n", g_settings.animation_speed,
               g_settings.animation_speed == 1 ? "slow" : 
               g_settings.animation_speed == 2 ? "medium" : "fast");
        printf("  Colors: %s\n", g_settings.use_colors ? "ON" : "OFF");
        printf("  Bar character: %c\n", g_settings.bar_char);
        return 0;
    }

    // List commands
    if (strcmp(argv[1], "--list") == 0) {
        printf("Available algorithms:\n");
        printf("  bubble\n  selection\n  merge\n  insertion\n");
        return 0;
    }

    // Algorithm commands
    // Default action is show animation
    if (argc == 2) {
        if (strcmp(argv[1], "bubble") == 0) {
            return show_bubble_sort();
        }
        if (strcmp(argv[1], "selection") == 0) {
            return show_selection_sort();
        }
        if (strcmp(argv[1], "merge") == 0) {
            return show_merge_sort();
        }
        if (strcmp(argv[1], "insertion") == 0) {
            return show_insertion_sort();
        }
    }

    // Algorithm with action
    if (argc == 3) {
        // Show code
        if (strcmp(argv[2], "--code") == 0) {
            if (strcmp(argv[1], "bubble") == 0) {
                code_bubble_sort();
                return 0;
            }
            if (strcmp(argv[1], "selection") == 0) {
                code_selection_sort();
                return 0;
            }
            if (strcmp(argv[1], "merge") == 0) {
                code_merge_sort();
                return 0;
            }
            if (strcmp(argv[1], "insertion") == 0) {
                code_insertion_sort();
                return 0;
            }
        }

        // Show pseudocode
        if (strcmp(argv[2], "--pseudo") == 0) {
            if (strcmp(argv[1], "bubble") == 0) {
                pseudo_bubble_sort();
                return 0;
            }
            if (strcmp(argv[1], "selection") == 0) {
                pseudo_selection_sort();
                return 0;
            }
            if (strcmp(argv[1], "merge") == 0) {
                pseudo_merge_sort();
                return 0;
            }
            if (strcmp(argv[1], "insertion") == 0) {
                pseudo_insertion_sort();
                return 0;
            }
        }

        // Show ELI5
        if (strcmp(argv[2], "--eli5") == 0) {
            if (strcmp(argv[1], "bubble") == 0) {
                eli5_bubble_sort();
                return 0;
            }
            if (strcmp(argv[1], "selection") == 0) {
                eli5_selection_sort();
                return 0;
            }
            if (strcmp(argv[1], "merge") == 0) {
                eli5_merge_sort();
                return 0;
            }
            if (strcmp(argv[1], "insertion") == 0) {
                eli5_insertion_sort();
                return 0;
            }
        }
    }

    // If we get here, command wasn't recognized
    printf("Unknown command: %s\n", argv[1]);
    printf("Try: ./dsa --help\n");
    return 1;
}
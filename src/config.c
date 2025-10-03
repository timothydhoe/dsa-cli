#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"

// Global settings variable
settings_t g_settings;

void load_default_settings(void)
{
    g_settings.animation_speed = 2;    // medium speed
    g_settings.use_colors = true;      // colors on
    g_settings.bar_char = '#';         // use # for bars
    
    // Try to load from file
    load_settings_from_file();
}

void save_settings_to_file(void)
{
    FILE *file = fopen("dsa_config.txt", "w");
    if (file == NULL) {
        printf("Warning: Could not save settings to file\n");
        return;
    }
    
    fprintf(file, "# DSA-CLI Settings\n");
    fprintf(file, "speed=%d\n", g_settings.animation_speed);
    fprintf(file, "colors=%s\n", g_settings.use_colors ? "true" : "false");
    fprintf(file, "bar_char=%c\n", g_settings.bar_char);
    
    fclose(file);
}

void load_settings_from_file(void)
{
    FILE *file = fopen("dsa_config.txt", "r");
    if (file == NULL) {
        return; // File doesn't exist, use defaults
    }
    
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        // Skip comments and empty lines
        if (line[0] == '#' || line[0] == '\n') {
            continue;
        }
        
        // Parse speed
        if (strncmp(line, "speed=", 6) == 0) {
            int speed = atoi(line + 6);
            if (speed >= 1 && speed <= 3) {
                g_settings.animation_speed = speed;
            }
        }
        // Parse colors
        else if (strncmp(line, "colors=", 7) == 0) {
            if (strncmp(line + 7, "true", 4) == 0) {
                g_settings.use_colors = true;
            } else if (strncmp(line + 7, "false", 5) == 0) {
                g_settings.use_colors = false;
            }
        }
        // Parse bar character
        else if (strncmp(line, "bar_char=", 9) == 0) {
            g_settings.bar_char = line[9];
        }
    }
    
    fclose(file);
}

void set_speed(int speed)
{
    if (speed >= 1 && speed <= 3) {
        g_settings.animation_speed = speed;
        printf("Speed set to: %s\n", 
               speed == 1 ? "slow" : speed == 2 ? "medium" : "fast");
        save_settings_to_file();
    } else {
        printf("Invalid speed. Use 1 (slow), 2 (medium), or 3 (fast)\n");
    }
}

void toggle_colors(void)
{
    g_settings.use_colors = !g_settings.use_colors;
    printf("Colors: %s\n", g_settings.use_colors ? "ON" : "OFF");
    save_settings_to_file();
}

void set_colors(const char *value)
{
    if (strcmp(value, "on") == 0 || strcmp(value, "true") == 0 || strcmp(value, "1") == 0) {
        g_settings.use_colors = true;
        printf("Colors: ON\n");
    } else if (strcmp(value, "off") == 0 || strcmp(value, "false") == 0 || strcmp(value, "0") == 0) {
        g_settings.use_colors = false;
        printf("Colors: OFF\n");
    } else {
        printf("Invalid color setting. Use: on/off, true/false, or 1/0\n");
        return;
    }
    save_settings_to_file();
}

void set_bar_char(char c)
{
    g_settings.bar_char = c;
    printf("Bar character set to: %c\n", c);
    save_settings_to_file();
}

int get_delay_time(void)
{
    switch (g_settings.animation_speed) {
        case 1: return 1500000;  // slow: 1.5 seconds
        case 2: return 800000;   // medium: 0.8 seconds  
        case 3: return 400000;   // fast: 0.4 seconds
        default: return 800000;
    }
}
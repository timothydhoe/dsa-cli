#ifndef CONFIG_H
#define CONFIG_H

#include <stdbool.h>

// Settings structure
typedef struct {
    int animation_speed;     // 1=slow, 2=medium, 3=fast
    bool use_colors;        // true=colors, false=no colors
    char bar_char;          // character for bars: #, *, =, etc.
} settings_t;

// Global settings (accessible everywhere)
extern settings_t g_settings;

// Config Functions Prototypes
void load_default_settings(void);
void save_settings_to_file(void);       // save current settings to file
void load_settings_from_file(void);     // load settings from file
void set_speed(int speed);               // 1, 2, or 3
void toggle_colors(void);                // switch colors on/off
void set_colors(const char *value);      // set colors on/off with value
void set_bar_char(char c);               // change bar character

// Get timing for animations
int get_delay_time(void);          // returns microseconds for usleep()

#endif
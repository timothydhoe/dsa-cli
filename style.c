// style.c
#include "style.h"
#include <stdio.h>

void print_heading(char *text)
{
    printf("%s%s%s%s\n", GREEN, BOLD, text, RESET);
}
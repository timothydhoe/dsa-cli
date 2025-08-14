// style.h


// ANSI escape codes for colours
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define RED "\x1b[31m"
#define RESET "\x1b[0m"
#define YELLOW "\033[33m"

// ANSI escape codes for text treatment
#define BOLD "\x1b[1m"
#define ITALIC "\x1b[3m"

// Function prototypes
void print_heading(char *text);

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
// magic clear screen string
void clearScreen() {
  printf("\033[2J\033[1;1H");
}
char *dt_str();
int main () {
	WINDOW *mainwin;
	  // Initialise ncurses
    if ((mainwin = initscr()) == NULL)
    {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(EXIT_FAILURE);
    }
    cbreak(); // disable line-buffering
    noecho(); // don't echo input to the screen
    nodelay(mainwin, TRUE); // make getch non-blocking
    curs_set(0); // hide the cursor
    int x, y;// Get the width and height of the terminal area
    getmaxyx(mainwin, y, x); // (y, x)
    // Draw a border around the terminal area
    box(mainwin, 0, 0);
    // Draw out 'Hello...'
    mvprintw(y / 2, x / 2 - (strlen("Welcome to SMITTY for Linux!") / 2), "Welcome to SMITTY for Linux!");
    
  
    // Draw out the prompt
    char *prompt = "Press q to exit.";
    
    mvprintw((y / 2) + 5, x / 2 - (strlen(prompt) / 2), prompt);
int current_char;           // the latest input typed
    char last_valid_char = ERR; // the latest non-error input typed

    while ((current_char = wgetch(mainwin)) != 'q') // our non-blocking getch
    {
        if (current_char != ERR)
        {
            last_valid_char = current_char;
        }
}
    // Clean up
    delwin(mainwin);
    endwin();
    refresh();
    return EXIT_SUCCESS;

}


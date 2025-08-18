#include "maze.h"
#include <stdio.h>

int main(){
    Maze maze = load_maze("maze.txt");
    print_maze(&maze);

    int pr,pc;
    find_position(&maze, 'S', &pr, &pc);
    printf("Player start at (%d, %d)\n", pr, pc);

    return 0;
}

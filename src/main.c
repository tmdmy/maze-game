#include <stdio.h>
#include "maze.h"

int main(void) {
    Maze maze = load_maze("maps/maze1.txt");
    print_maze(&maze);
    return 0;
}

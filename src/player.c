#include "player.h"
#include "maze.h"//include find_position function
#include <stdio.h>

void move_player(Maze *maze, char input){
    int pr,pc;
    find_position(&maze, 'P', &pr, &pc); // Find the player's current position

    int nr = pr , nc = pc;
    if(input == 'w')nr--;
    else if(input == 's')nr++;
    else if(input == 'a')nc--;
    else if(input == 'd')nc++;

    if(maze->grid[nr][nc]!= '#'){
        maze->grid[pr][pc] = ' ';
        maze->grid[nr][nc] = 'P';

    }
}
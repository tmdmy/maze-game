#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maze.h"

Maze load_maze(const char *filename){
    Maze maze;
    FILE *fp = fopen(filename, "r");
    if (!fp){
        perror("Failed to open maze file");
        exit(1);
    }

    int row = 0;
    char line[MAX_COLS];
    while(fgets(line,sizeof(line),fp)){
        line[strcspn(line,"\n")] = '\0';
        strcpy(maze.grid[row], line);
        row++;
    }
    maze.rows = row;
    maze.cols = strlen(maze.grid[0]);

    fclose(fp);
    return maze;
}

void print_maze(const Maze *maze){// Print the maze to the console
    for (int i=0;i<maze->rows;i++){
        printf("%s\n", maze->grid[i]);
    }
}

void find_position(const Maze *maze, char symbol, int *row, int *col){
    for (int i = 0; i < maze->rows; i++){
        for (int j = 0; j < maze->cols; j++){
            if (maze->grid[i][j] == symbol){
                *row = i;
                *col = j;
                return;
            }
        }
    }
    *row = -1; // Not found
    *col = -1; // Not found
}
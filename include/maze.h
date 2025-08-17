#ifndef MAZE_H
#define MAZE_H

#define MAX_ROWS 50
#define MAX_COLS 50

typedef struct{
    int rows;
    int cols;
    char grid[MAX_ROWS][MAX_COLS];
}Maze;

Maze load_maze(const char *filename);

void print_maze(const Maze *maze);

void find_position(const Maze *maze, char symbol, int *row, int *col);

#endif // MAZE_H
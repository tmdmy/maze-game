#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "player.h"

int main() {
    // �t�@�C��������H�ǂݍ���
    Maze maze = load_maze("maps/maze.txt");

    printf("���H�Q�[��: �t�@�C���ǂݍ��݃e�X�g\n");
    print_maze(&maze);

    int goal_r, goal_c;
    find_position(&maze, 'G', &goal_r, &goal_c);

    char command;
    while (1) {
        printf("WASD�ňړ�, q�ŏI��: ");
        scanf(" %c", &command);

        if (command == 'q') break;

        move_player(&maze, command); // �� ���W�͓n���Ȃ�
        print_maze(&maze);

        // �S�[������: �v���C���[�ʒu��T���Ċm�F
        int row, col;
        find_position(&maze, 'P', &row, &col);
        if (row == goal_r && col == goal_c) {
            printf("�S�[�����܂����I\n");
            break;
        }
    }

    return 0;
}

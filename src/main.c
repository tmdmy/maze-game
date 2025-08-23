#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include "player.h"

int main() {
    // ファイルから迷路読み込み
    Maze maze = load_maze("maps/maze.txt");

    printf("迷路ゲーム: ファイル読み込みテスト\n");
    print_maze(&maze);

    int goal_r, goal_c;
    find_position(&maze, 'G', &goal_r, &goal_c);

    char command;
    while (1) {
        printf("WASDで移動, qで終了: ");
        scanf(" %c", &command);

        if (command == 'q') break;

        move_player(&maze, command); // ← 座標は渡さない
        print_maze(&maze);

        // ゴール判定: プレイヤー位置を探して確認
        int row, col;
        find_position(&maze, 'P', &row, &col);
        if (row == goal_r && col == goal_c) {
            printf("ゴールしました！\n");
            break;
        }
    }

    return 0;
}

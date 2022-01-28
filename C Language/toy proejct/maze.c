#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>

// 5X5의 플래이 판을 얻습니다
int **getMap() {
    printf("get map...\n");
    int **map = (int **) malloc(sizeof(int *) * 5);
    int i;
    printf("2's array\n");
    for (i = 0; i < 5; ++i)
        map[i] = (int *) malloc(sizeof(int) * 5);
    printf("return map\n");
    return map;
}

void reset_map(int **_map) {
    printf("format map\n");
    int i, j;

    for (i = 0; i < 5; ++i) {
        for (j = 0; j < 5; ++j) {
            printf("%d %d\n", i, j);
            *(*(_map + i) + j) = 0;
        }
    }
    _map[0][0] = 2;
    _map[4][4] = 3;
    printf("format complete\n");
}

// 장애물을 n개만큼 설치합니다.
void set_hurdle(int **_map, int _hurdle) {
    puts("set hurdle...");
    srand(time(NULL));
    int posX, posY;
    int i;

    for (i = 0; i < _hurdle; ++i) {
        posX = rand() % 5;
        posY = rand() % 5;
        printf("%d %d\n", posX, posY);
        // 이미 장애물이 설치되어있거나 시작지점(0, 0) 또는 도착지점(4, 4)일 경우 다시 rand를 돌린다.
        if (*(*(_map + posX) + posY) == 1 || (posX == 0 && posY == 0) || (posX == 4 && posY == 4)) {
            --i;
            continue;
        }
        *(*(_map + posX) + posY) = 1;
    }
    puts("set hurdle complete");
}

// 플레이어가 움직일 수 있는 범위를 넘엇는지 확인합니다.
int is_over_line(int _player_posX, int _player_posY) {
    if (_player_posX >= 5 || _player_posY >= 5 || _player_posX < 0 || _player_posY < 0)
        return true;
    return false;
}

// 플레이어가 갈 곳에 장애물이 있는지 확인합니다.
int is_over_hurdle(int** _map, int _posX, int _posY) {
    if(_map[_posY][_posX] == 1)
        return true;
    return false;
}

// 현재 map상황을 보여줍니다.
void show_map(int **_map) {
    int i, j;
    for (i = 0; i < 5; ++i) {
        for(j = 0; j < 5; ++j) {
            switch(_map[i][j]) {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("@");
                    break;
                case 2:
                    printf("|");
                    break;
                case 3:
                    printf("▲");

            }
        }
        puts("");
    }
}

void move_player(int** _map, int* _player_pos, int _move){
    int posX = _player_pos[0], posY = _player_pos[1];
    // 72: UP, 80: DOWN, 75: LEFT, 77: RIGHT
    switch(_move) {
        case 72:
            if(!is_over_line(posX, posY-1) && !is_over_hurdle(_map, posX, posY-1)) {
                _map[posY][posX] = 0;
                _map[--posY][posX] = 2;
            }
            break;
        case 80:
            if(!is_over_line(posX, posY+1) && !is_over_hurdle(_map, posX, posY+1)) {
                _map[posY][posX] = 0;
                _map[++posY][posX] = 2;
            }
            break;
        case 75:
            if(!is_over_line(posX-1, posY) && !is_over_hurdle(_map, posX-1, posY)) {
                _map[posY][posX] = 0;
                _map[posY][--posX] = 2;
            }
            break;
        case 77:
            if(!is_over_line(posX+1, posY) && !is_over_hurdle(_map, posX+1, posY)) {
                _map[posY][posX] = 0;
                _map[posY][++posX] = 2;
            }
            break;
        default:
            return;
    }
    _player_pos[0] = posX;
    _player_pos[1] = posY;
}

int is_goal(int _player_posX, int _player_posY) {
    if(_player_posX == 4 && _player_posY == 4)
        return true;
    return false;
}
int main() {
    int **map = getMap();
    int player_pos[2] = {0, 0};
    int input;
    reset_map(map);
    set_hurdle(map, 5);

    while(true) {
        system("cls");
        printf("player pos : %d %d\n", player_pos[0], player_pos[1]);
        show_map(map);
        if(is_goal(player_pos[0], player_pos[1])) {
            printf("Finish!!\n");
            break;
        }
        input = _getch();
        move_player(map, player_pos, input);
    }
    return 0;
}


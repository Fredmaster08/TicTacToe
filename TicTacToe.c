
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    unsigned int row;
    unsigned int column;
}Index;

Index getIndex(int userInput) {
    unsigned int updatedInput = userInput - 1;
    unsigned int row = updatedInput / 3;
    unsigned int column = updatedInput % 3;
    return (Index){row, column};
}

void drawMap(char map[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf(" %c ", map[i][j]);
            if(j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if(i < 2) {
            printf("-----------\n");
        }
    }
}
                                                                                                                                   // well, its not going well
bool wonMatch(char sym, char map[3][3]) {
    if(map[2][0] ==  sym && map[1][1] == sym && map[0][2] == sym) {
        return true;
    }
    if(map[2][2] ==  sym && map[1][1] == sym && map[0][0] == sym) {
        return true;
    }
    for(int i = 0; i < 3; i++) {
        if(map[i][0] == sym && map[i][1] == sym && map[i][2] == sym) {
            return true;
        }
        if(map[0][i] == sym && map[1][i] == sym && map[2][i] == sym) {
            return true;
        }
    }

    return false;
}

int main() {

    printf("***Welcome to TicTacToe!***\n");

    int userInput = 0;

    char map[3][3];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            map[i][j] = ' ';
        }
    }
    
    while(1) {
        printf("Enter a number between 1-9 to select your turn: ");
        scanf("%d", &userInput);
        if(userInput > 9 || userInput < 1) {
            printf("Out of bounds!\n");
            continue;
        }

        Index index = getIndex(userInput);

        if(map[index.row][index.column] != ' ') {
            printf("Invalid input\n");
            continue;
        }

        map[index.row][index.column] = 'X';

        drawMap(map);

        if(wonMatch('X', map)) {
            printf("You won!\n");
            break;
        }
    }

    
    return 0;
}
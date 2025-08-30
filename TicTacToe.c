
#include <stdio.h>

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

int main() {

    printf("***Welcome to TicTacToe!***\n");

    int userInput = 0;

    printf("Enter a number between 1-9 to select your turn: ");
    scanf("%d", &userInput);

    Index index = getIndex(userInput);

    char map[3][3];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            map[i][j] = ' ';
        }
    }
    map[index.row][index.column] = 'X';

    drawMap(map);
    
    return 0;
}
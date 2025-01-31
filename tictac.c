#include<stdio.h>

#define SIZE 3

void printboard(char board[SIZE][SIZE]);
int checkwinner(char board[SIZE][SIZE]);

int main(){
    char board[SIZE][SIZE]= {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };
    int choice, row, col;
    char currentplayer = 'X';

    while(1){
        printboard(board);
        printf("Player %c, enter a number (1-9):", currentplayer);
        scanf("%d", &choice);

        row = (choice-1)/SIZE;
        col = (choice-1)%SIZE;

        if(choice<1 || choice>9 || board[row][col]=='X' && board[row][col]=='O'){
            printf("Invalide move, please try again\n");
            continue;
        }
        board[row][col] = currentplayer;

        if(checkwinner(board)){
            printboard(board);
            printf("Player %c amazingly wins!!!\n", currentplayer);
            break;
        }

        int full = 1;
        for(int i = 0; i<SIZE; i++)
            for(int j=0; j<SIZE; j++)
                if(board[i][j]!='X' && board[i][j]!='O')full=0;
                
        if(full){
            printboard(board);
            printf("The game is a tie, you two are very smart i see, but who will win the next game!!!\n");
            break;
        }
        currentplayer = (currentplayer=='X') ? 'O' : 'X';
    }
    return 0;
}

void printboard(char board[SIZE][SIZE]){
    printf("\n");
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            printf(" %c ", board[i][j]);
            if(j<2) printf("|");
        }
        printf("\n");
        if(i<2) printf("---|---|---\n");
    }
    printf("\n");
}

int checkwinner(char board[SIZE][SIZE]){
    for(int i=0; i<SIZE; i++){
        if((board[i][0]==board[i][1] && board[i][1]==board[i][2]) || 
        (board[0][i]==board[1][i] && board[1][i]==board[2][i]))
            return 1;
    }
    if((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || 
       (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
       return 1;

    return 0;
}

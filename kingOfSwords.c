//jชนะqแบบยังไม่โดน
//
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char board[5][5] = {{' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' '}};

char boardBack[5][5] = {{' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' '}};

int column, row;
int turn = 0;
int start = 1;
char player = '1';

int j1 = 0;
int j2 = 0;

void displayBoard();
void moveAgent(int row,int column, char player);
void checkWin();

void clearXPosition();
void eatAgentJ(int row,int column,int rowE,int columnE);


int main(void){

    board[0][2] = 'J';
    board[0][1] = 'Q';
    board[0][3] = 'K';

    board[4][1] = 'J';
    board[4][2] = 'Q';
    board[4][3] = 'K';

    boardBack[0][1] = '1';
    boardBack[0][3] = '1';
    boardBack[0][2] = '1';

    boardBack[4][1] = '2';
    boardBack[4][2] = '2';
    boardBack[4][3] = '2';

    srand(time(NULL));   
    int r1 = rand();    
    int r2 = rand();     
    r1 = r1%5;
    r2 = r2%5;


    while (start == 1) {
        
        checkWin();

        displayBoard();
        // printf("Turn : %d\n",turn);
        // printf("J1 : %d\n",j1);
        // printf("J2 : %d\n",j2);
        printf("Player %c, select agent\n",player);

        printf("Enter the row [1-5]: ");
        scanf("%d", &row);

        printf("Enter the column [1-5]: ");
        scanf("%d", &column);

        moveAgent(row-1,column-1,player);

        // printf(checkWin());
        if(player == '2')
            player = '1';
        else
            player ='2';

        checkWin();

        //random position falling 
        if(turn % 2 == 0){

            //clear X position
            clearXPosition();
            for (int i = 0; i < 2; i++)
            {
               while (board[r1][r2] != ' ')
                {
                    r1 = rand();    
                    r2 = rand();     
                    r1 = r1%5;
                    r2 = r2%5;
                }
                board[r1][r2] = 'X';
            }
        }

    }

}


void displayBoard() {
    printf("\n  ____________________\n");
    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            if(j == 0){
                int num = i+1;
                printf("%d| %c ",num, board[i][j]);
            }
            else{
                printf("| %c ", board[i][j]);
            }
        }
        printf("|");
        printf("\n  ____________________\n");

    }
    printf("  1   2   3   4   5\n");
}


void moveAgent(int row,int column, char player) {

    int movement = 0;

        if (boardBack[row][column] == player) {

            printf("\n1)Up\n2)Left\n3)Right\n4)Down\nSelect your movement :");
            scanf("%d", &movement);

            switch (movement) {
                case 1:
                    if(board[row-1][column] == ' ' || 
                    (board[row-1][column] == 'K' && board[row][column] == 'J') || 
                    (board[row-1][column] == 'J' && board[row][column] == 'Q') || 
                    (board[row-1][column] == 'Q' && board[row][column] == 'K')){
                        eatAgentJ(row,column,row-1,column);
                    }
                    else if(board[row-1][column] == board[row][column] ){
                        board[row-1][column] = ' ';
                        board[row][column] = ' ';
                        boardBack[row-1][column] = ' ';
                        boardBack[row][column] = ' ';
                    }
                    else{
                        printf("!!! Please select again !!!\n\n");
                    }
                    break;

                case 2:
                    if(board[row][column-1] == ' ' || 
                    (board[row][column-1] == 'K' && board[row][column] == 'J') || 
                    (board[row][column-1] == 'J' && board[row][column] == 'Q') || 
                    (board[row][column-1] == 'Q' && board[row][column] == 'K')){
                        eatAgentJ(row,column,row,column-1);
                        
                    }
                    else if(board[row][column-1] == board[row][column] ){
                        board[row][column-1] = ' ';
                        board[row][column] = ' ';
                        boardBack[row][column-1] = ' ';
                        boardBack[row][column] = ' ';
                    }
                    else{
                        printf("\n!!! Please select again !!!\n");
                    }
                    break;

                case 3:
                    if(board[row][column+1] == ' ' || 
                    (board[row][column+1] == 'K' && board[row][column] == 'J') || 
                    (board[row][column+1] == 'J' && board[row][column] == 'Q') || 
                    (board[row][column+1] == 'Q' && board[row][column] == 'K')){
                        eatAgentJ(row,column,row,column+1);
                    }
                    else if(board[row][column+1] == board[row][column] ){
                        board[row][column+1] = ' ';
                        board[row][column] = ' ';
                        boardBack[row][column+1] = ' ';
                        boardBack[row][column] = ' ';
                    }
                    else{
                        printf("!!! Please select again !!!\n\n");
                    }
                    break;

                case 4:
                    if(board[row+1][column] == ' ' || 
                    (board[row+1][column] == 'K' && board[row][column] == 'J') || 
                    (board[row+1][column] == 'J' && board[row][column] == 'Q') || 
                    (board[row+1][column] == 'Q' && board[row][column] == 'K')){
                        eatAgentJ(row,column,row+1,column);
                    }

                    else if(board[row+1][column] == board[row][column] ){
                        board[row+1][column] = ' ';
                        board[row][column] = ' ';
                        boardBack[row+1][column] = ' ';
                        boardBack[row][column] = ' ';
                    }

                    else{
                        printf("!!! Please select again !!!\n\n");
                    }
                    break;
                
                }
                turn++;
        }

        else{
            printf("Not your agent please select again !!!\n");
        }
}

void  checkWin(){
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (boardBack[i][j] == '1' ) {
                count1++;
            }
            else if(boardBack[i][j] == '2' ){
                count2++;
            }
        }
    }

    if(count1 == 0 && count2 == 0){
        printf("!!!! Draw!!!!");
        displayBoard();
        start = 0;
    }
    else if(count1 == 0){
        printf("!!!! Plyer 2 WIN !!!!");
        displayBoard();
        start = 0;
    }
    else if(count2 == 0){
        printf("!!!! Plyer 1 WIN !!!!");
        displayBoard();
        start = 0;
    }
}

void  clearXPosition(){
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == 'X' ) {
                board[i][j] = ' ';
            }
        }
    }
   
}

void eatAgentJ(int row,int column,int rowE,int columnE){
    if(board[row][column] == 'Q' && board[rowE][columnE] == 'J'){
        
        if (j1 == 1 && boardBack[row][column] == '2'){
            j1--;
            // printf("J11 : %d\n",j1);
        }
        else if(j2 == 1 && boardBack[row][column] == '1'){
            j2--;
            // printf("J21 : %d\n",j2);
        }
        else if(boardBack[row][column] == '1' && j1 == 0){
            j1++;
            board[rowE][columnE] = board[row][column];
            board[row][column] = ' ';
            boardBack[rowE][column] = boardBack[row][column];
            boardBack[row][column] = ' ';
         //    printf("J12 : %d\n",j1);
            
         }
         else if (boardBack[row][column] == '2' && j2 == 0){
             j2++;
             board[rowE][columnE] = board[row][column];
             board[row][column] = ' ';
             boardBack[rowE][column] = boardBack[row][column];
             boardBack[row][column] = ' ';
             // printf("J22 : %d\n",j2);
        }
       else{
            board[rowE][column] = board[row][column];
            board[row][column] = ' ';
            boardBack[rowE][column] = boardBack[row][column];
            boardBack[row][column] = ' ';
            // printf("else1");
       }     
    }
    else{
            // board[rowE][columnE] = board[row][column];
            board[rowE][columnE] = board[row][column];
            board[row][column] = ' ';
            boardBack[rowE][columnE] = boardBack[row][column];
            boardBack[row][column] = ' ';
            // printf("else2");
    }
}


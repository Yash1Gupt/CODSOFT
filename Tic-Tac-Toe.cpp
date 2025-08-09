#include<bits/stdc++.h>
using namespace std;
int currentplayer;
char currentmarker;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
void drawboard() {
    cout <<" "<< board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<< " \n";
    cout << "---|---|---\n";
    cout <<" "<< board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<< " \n";
    cout <<"---|---|---\n";
    cout <<" "<< board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<< " \n";
}


bool placemarker(int slot) {
    int row=(slot-1)/3;
    int col=(slot-1)%3;
    
    if(board[row][col]!='X' && board[row][col]!='O'){
        board[row][col]=currentmarker;
        return true;
    }
    else{
        return false;
    }
}

int winner() {
    for(int i=0;i<3;i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return currentplayer;
        }
    }
    for(int i=0;i<3;i++){
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            return currentplayer;
        }
    }
    
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        return currentplayer;
    }
    if(board[2][0]==board[1][1] && board[1][1]==board[0][2]){
        return currentplayer;
    }
    return 0;
}

void swapPlayerandMarker() {
    if(currentplayer == 1){
        currentplayer = 2;
    } else {
        currentplayer = 1;
    }
    
    if(currentmarker == 'X'){
        currentmarker = 'O';
    } else {
        currentmarker = 'X';
    }
}

void game() {
    cout <<"Player 1, choose your marker - X OR O: ";
    char markerp1;
    cin >>markerp1;
    if (markerp1 != 'X' && markerp1 != 'O') {
        cout << "Invalid marker choice. Defaulting to 'X'.\n";
        markerp1 = 'X';
    }
    
    char markerp2 = (markerp1 == 'X') ? 'O' : 'X';
    cout << "Player 2's marker will be " << markerp2 << ".\n";

    currentplayer = 1;
    currentmarker = markerp1;

    drawboard();
    int playerwon = 0;
    
    for(int i=0;i<9;i++){
        cout << "\nIt's Player " << currentplayer << "'s turn. Enter your slot: ";
        int slot;
        cin>> slot;
        if(slot<1 || slot>9){
            cout <<"That's not a valid slot! You can try again.\n";
            i--; 
            continue;
        }
        if(!placemarker(slot)){
            cout << "Invalid Slot! That slot is already taken.\n";
            i--; 
            continue;
        }
        
        drawboard();
        playerwon = winner();
        if(playerwon != 0){
            cout << "\nCongratulations! Player " << playerwon << " won!\n";
            return; 
        }
        swapPlayerandMarker();
    }
    if (playerwon == 0) {
        cout << "\nThe game is a draw!\n";
    }
}
int main() {
    game();
    return 0;
}

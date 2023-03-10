#include<iostream>
#include<bits/stdc++.h>
using namespace std;


char mat[3][3] = { {'0', '1', '2'}, {'3', '4', '5'}, {'6', '7', '8'} };
bool flag=true;
void matrix() {
    cout << "  +-----+-----+-----+\n";
    cout << "  |     |     |     |\n";
    cout << "  |  " << mat[0][0] << "  |  " << mat[0][1] << "  |  " << mat[0][2] << "  |\n";
    cout << "  |     |     |     |\n";
    cout << "  +-----+-----+-----+\n";
    cout << "  |     |     |     |\n";
    cout << "  |  " << mat[1][0] << "  |  " << mat[1][1] << "  |  " << mat[1][2] << "  |\n";
    cout << "  |     |     |     |\n";
    cout << "  +-----+-----+-----+\n";
    cout << "  |     |     |     |\n";
    cout << "  |  " << mat[2][0] << "  |  " << mat[2][1] << "  |  " << mat[2][2] << "  |\n";
    cout << "  |     |     |     |\n";
    cout << "  +-----+-----+-----+\n";
}

void player(char user){
    bool validMove=false;
    int position;
    while(!validMove){
        cout<<"Enter position in number: ";
        cin>>position;
        int rem=position%3;
        int diff=position/3;
        if(mat[diff][rem]>='0' && mat[diff][rem]<='8'){
            mat[diff][rem]=user;
            validMove=true;
        }
        else{
            cout<<"Re-Enter position: ";
        }

    }
}

bool isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat[i][j] >= '0' && mat[i][j]<='8') {
                return false;
            }
        }
    }
    return true;
}

void computer(char pc){
    bool validMove=false;

    while(!validMove){
        int row=rand()%3;
        int col=rand()%3;
        if(mat[row][col]>='0' && mat[row][col]<='8'){
            mat[row][col]=pc;
            cout<<"Computer made its move!"<<endl;
            validMove=true;
        }
        else if(isBoardFull()){
            cout<<"\nMatch tied!\n";
            flag=false;
            break;
        }
    }

}

bool isWinner(char symbol){
    for(int i=0;i<3;i++){
        if(mat[i][0]==symbol && mat[i][1]==symbol && mat[i][2]==symbol)
            return true;
        if(mat[0][i]==symbol && mat[1][i]==symbol && mat[2][i]==symbol)
            return true;
    }
    if(mat[0][0]==symbol && mat[1][1]==symbol && mat[2][2]==symbol)
        return true;
    if(mat[0][2]==symbol && mat[1][1]==symbol && mat[2][0]==symbol)
        return true;
    return false;
}



void playGame(){
    char user='O';
    char pc='X';
    matrix();

    while(true && flag ){
        player(user);
        if(isWinner(user)){
            cout<<"\nYou won!\n";
            break;
        }
        computer(pc);
        if(flag)
            matrix();
        if(isWinner(pc)){
            cout<<"\nComputer won!\n";
            break;
        }
    }
    if(isWinner(user))
        matrix();
}


int main(){

    cout<<"Press the number(0-8) for insert 'O' at the position"<<endl;
    playGame();

}

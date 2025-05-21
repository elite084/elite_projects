#include<bits/stdc++.h>
using namespace std;

bool check_win(char tttbox[3][3], char player){
    for(int i=0;i<3;i++){
        if(tttbox[i][0] == player  && tttbox[i][1] == player && tttbox[i][2] == player){
            return true;
        }
        else if(tttbox[0][i] == player  && tttbox[1][i] == player && tttbox[2][i] == player){
            return true;
        }
    }
    if(tttbox[0][0] == player  && tttbox[1][1] == player && tttbox[2][2] == player){
        return true;
    }else if(tttbox[0][2] == player  && tttbox[1][1] == player && tttbox[2][0] == player){
        return true;
    }
    return false;
}

void print(char tttbox[3][3]){
    cout << "-------------" << endl;
    for(int i=0;i<3;i++){
        cout << "|" ;
        for(int j=0;j<3;j++){
            cout << tttbox[i][j] << "|";
        }
        cout << endl;
    }
    cout << "-------------" << endl;
}

int main(){
    char tttbox[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    char player = 'X';
    int play_turn = 0;
    int r,c;
    bool invalid = false;
    for(play_turn;play_turn < 9;play_turn++){
        cout << "player " << player << " enter row,col" << endl;
        cin >> r >> c;
        if(tttbox[r][c] != ' ' || r < 0 || r > 2 || c < 0 || c > 2){
            invalid = true; 
            cout << "invalid input" << endl;
            play_turn--;
        }else{
            tttbox[r][c] = player;
        }
        if(check_win(tttbox,player)){
            print(tttbox);
            cout << "player " << player << " won" << endl;
            return 0;
        }else{
            if(!invalid){
                if(player == 'X'){
                    player = 'O';
                }else{
                    player = 'X';
                }
            }
        }
    }
    print(tttbox);
    if(play_turn == 9 && !check_win(tttbox,'X') && !check_win(tttbox,'O')){
        cout << "it is draw" << endl;
    }


    return 0;
}

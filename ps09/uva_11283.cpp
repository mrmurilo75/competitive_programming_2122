#include <iostream>
#include <cstdio>
#include <cstring>

#define DBG2 false
#define dbg2 if(DBG2)cout
#define DBG false
#define dbg if(DBG)cout

using namespace std;


int N, D, score, w_len;
bool done;

char board[6][6], word[18];
bool b_visited[6][6];

bool dfs(int x, int y, int cur_len){
    if(DBG) for(int i=0; i<cur_len; i++) cout<<"\t";
    dbg << "["<< x <<" "<< y <<"] ";

    if(board[x][y] != word[cur_len] || b_visited[x][y]) {
        dbg << "false" << endl;
        return false;
    }

    if(cur_len+1 >= w_len) {
        dbg << "true" << endl;
        return true;
    }

    b_visited[x][y] = true;
    cur_len++;

    for(int xi=-1; xi<=1; xi++)
        for(int yi=-1; yi<=1; yi++)
            if(dfs( (x +xi), (y +yi), cur_len ))
                return true;

    dbg << endl;
    return false;
}

//  length         =  0 1 2 3 4 5 6 7  8  9 10 11 12 13 14 15 16
int points_board[] = {0,0,0,1,1,2,3,5,11,11,11,11,11,11,11,11,11};

void print_board() {
    for(int i=0; i<6; i++) {
        for(int j=0; j<6; j++)
            dbg << "\t" << (int)board[i][j];
        dbg <<endl;
    }
}


int main(){

    cin >> N;
    dbg2 << N <<endl;

    for(int n=1; n<=N; n++) {
        memset(board, 0, sizeof board);
        score = 0;

        cin >> (char*)&(board[1][1]) >> (char*)&(board[2][1]) >> (char*)&(board[3][1]) >> (char*)&(board[4][1]);
        board[1][5] = board[2][5] = board[3][5] = board[4][5] = 0;
        if(DBG2) print_board();


        cin >> D;
        dbg2 << D << endl;

        while(D--) {
            memset(b_visited, false, sizeof b_visited);

            cin >> word;
            dbg2 << word << " ";
            dbg2 << endl;

            w_len = strlen(word);
            dbg << w_len <<endl; 

            done = false;
            for(int i=1; i<5 && !done; i++) {
                for(int j=1; j<5; j++) {
                    dbg << "["<< i <<" "<< j <<"]"<<endl;

                    if(board[i][j] == word[0] && dfs(i, j, 0)) {
                        score += points_board[w_len];

                        done = true;
                        break;
                    }
                }
            }


        }
        cout << "Score for Boggle game #" << n << ": " << score << endl;
    }
}


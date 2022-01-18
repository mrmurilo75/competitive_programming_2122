#include <iostream>
#include <cstdio>

#include <string>

#define DBG false
#define dbg if(DBG)cout

#define MAX_LEN 1000001

using namespace std;
 
int T, S_len;
 
string S;

int jump[MAX_LEN];
 
void preprocess() {
    jump[0] = -1;

    int cur = jump[0];

    for(int i=1; i<S_len; i++) {
        while(cur != -1 && S[i] != S[cur +1])
            cur = jump[cur];

        if(S[i] == S[cur +1])
            jump[i] = (++cur);
        else
            jump[i]= -1;
    }
}

int main() {
 
    cin >> T;
    dbg << T <<endl;

    for(int t=1; t<=T; t++) {

        cin >> S_len;
        cin >> S;
        dbg << S <<" "<< S_len <<endl;

        preprocess();

        if(DBG) for(int i=0; i<S_len; i++) cout<<"   "<< ( (jump[i] <0 || (jump[i] >10 && i<10))? " " : "" ) << i;
        dbg << endl;
        if(DBG) for(int i=0; i<S_len; i++) cout<<" < "<< jump[i];
        dbg << endl;

        cout << "Test case #" << t << endl;

        for(int i=1; i<S_len; i++) {
            int period_len = i - jump[i];
            int period = (i+1) / period_len;

            dbg << "\t"<< i+1 <<" \% "<< period_len <<" = \t" << (i+1)%period_len <<endl;
            dbg << "      i+1  \% period_len  = \t" << (i+1)%period_len <<endl;

            if( !((i+1)%period_len) && period >= 2 && jump[i] != -1)
                cout << (i+1) <<" "<< period <<endl;
            //}
        }

        cout<<endl;
    }
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

#define max(a, b) ( (a < b)? b : a )
#define min(a, b) ( (a > b)? b : a )

#define DBG false

using namespace std;

int N;
string s;
int cur=0, top=0, bottom=0;


void update_top() {
    top = max(top, cur);
}

void update_bottom() {
    bottom = min(bottom, cur);
}

int main(){

    //input
    scanf("%d", &N);
    if(DBG)cout << N << endl;
    cin >> s;
    if(DBG)cout << s << endl;

    //process
    for(int i=0; i<N-1; i++) {
        switch(s[i]) {
            case '+': if(s[i+1] != '-') cur++; update_top(); break;
            case '-': if(s[i+1] == '-') cur--; update_bottom(); break;
            case '=': if(s[i+1] == '-') cur--; break;
            default: exit(EXIT_FAILURE);
        }
    }

    if(DBG)cout << 1+top-bottom <<" = 1+ "<< top  <<" - "<< bottom <<endl;

    char out[1+top-bottom][N+1];
    memset(out, '.', sizeof out);

    int net = 0-bottom;
    for(int i=0; i<N; i++) {
        if(DBG)cout << s[i] <<endl;
        switch(s[i]) {
            case '+': 
                    if(DBG)cout << s[i] <<endl;
                    if(DBG)cout << top <<" "<< bottom <<" "<< net <<  endl;

                    out[net][i] = '/'; net++; 

                    if(DBG) {
                        cout << top <<" "<< bottom <<" "<< net <<  endl;
                        for(int i=top-bottom; i>0; i--) {
                            out[i][N] = '\0';
                            cout << out[i] << "\n";
                        }
                        out[0][N] = '\0';
                        cout << out[0] << endl;
                        cout<<endl;
                    }
                      break;
            case '-':
                    if(DBG)cout << s[i] <<endl;
                    if(DBG)cout << top <<" "<< bottom <<" "<< net <<  endl;

                    if(i>0)net--; out[net][i] = '\\';

                    if(DBG) {
                        cout << top <<" "<< bottom <<" "<< net <<  endl;
                        for(int i=top-bottom; i>0; i--) {
                            out[i][N] = '\0';
                            cout << out[i] << "\n";
                        }
                        out[0][N] = '\0';
                        cout << out[0] << endl;
                        cout<<endl;
                    }
                      break;
            case '=': 
                    if(DBG)cout << s[i] <<endl;
                    if(DBG)cout << top <<" "<< bottom <<" "<< net <<  endl;

                    out[net][i] = '_';

                    if(DBG) {
                        cout << top <<" "<< bottom <<" "<< net <<  endl;
                        for(int i=top-bottom; i>0; i--) {
                            out[i][N] = '\0';
                            cout << out[i] << "\n";
                        }
                        out[0][N] = '\0';
                        if(DBG)cout << out[0] << endl;
                        if(DBG)cout<<endl;
                    }
                      break;
            default: exit(EXIT_FAILURE);
        }
    }
    

    //output
    for(int i=top-bottom; i>0; i--) {
        out[i][N] = '\0';
        cout << out[i] << "\n";
    }
    out[0][N] = '\0';
    cout << out[0] << endl;



}


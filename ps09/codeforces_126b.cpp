#include <iostream>
#include <cstdio>

#include <string>

#define DBG false
#define dbg if(DBG)cout

#define MAX_LEN 1000001

using namespace std;


string T;
int jump[MAX_LEN], last, result;

void preprocess(){
    jump[0] = -1;

    int cur = jump[0];

    for(int i=1; i<T.length(); i++) {
        while(cur != -1 && T[i] != T[cur +1])
            cur = jump[cur];

        if(T[i] == T[cur +1])
            jump[i] = (++cur);
        else
            jump[i]= -1;
    }

}

int main() {

    cin>> T;
    dbg << T <<endl;

    preprocess();

    if(DBG) for(int i=0; i<T.length(); i++) cout<<" < "<< jump[i];

    last = jump[T.length()-1];
    result = jump[last];

    if(last == -1) {
        cout << "Just a legend" <<endl;
        return 0;
    }

    for(int i=1; i < T.length() -1; i++)
        if(jump[i] == last)
            result = last;

    cout << ((result == -1)? "Just a legend" : T.substr(0, result+1)) << endl;

}

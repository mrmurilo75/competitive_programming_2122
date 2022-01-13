#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>

#define IS_DBG false
#define DBG if(IS_DBG)cout

using namespace std;

int N, T;
set< string > results;

int main(){
    //input
    cin >> N;
    DBG << N <<endl;
    while(N--) {
        results.clear();

        DBG << endl;

        int C_size;
        cin >> C_size;
        int T = C_size/2;
        char C[C_size];
        cin >> C;
        DBG << T <<" "<< C <<endl;

        //process

        int A_size = T+1;
        char A[A_size], B[A_size];
        A[T] = '\0'; B[T] = '\0';

        DBG << endl;
        for(int i=0; i<C_size; i++) {
            if(i<T) {
                memcpy(A,   &(C[i-1]), i);
                memcpy(&(A[i]), &(C[i+1]), T-i);
                memcpy(B,  &(C[T+1]), T);

            } else if(i == T) {
                memcpy(A,   C, i);
                memcpy(B,  &(C[T+1]), T);

            } else if(i < C_size-1) {

                memcpy(A,       C,     T);
                memcpy(B,       &(C[i-1]), (i-T));
                memcpy(&(B[i-T]), &(C[i+1]), T-(i-T));
            } else {
                memcpy(A,   C, T);
                memcpy(B,  &(C[T]), T);
            }

            DBG << i << " "<< A <<"\t"<< B <<endl;
            if(strcmp(A, B) == 0) 
                results.emplace(string (A));
            if(results.size() > 1)
                    break;
        }

        //output
        if(IS_DBG)for(string s : results) {
            DBG << s <<endl;
        }
        if(results.empty())
            cout << "IMPOSSIBLE" << endl;
        else if (results.size() > 1)
            cout << "NOT UNIQUE" << endl;
        else
            cout << *(results.begin()) << endl;
    }

}


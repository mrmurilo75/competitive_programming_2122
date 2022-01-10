#include <iostream>
#include <cstdio>

#define IN_POSSIBLE 128

using namespace std;

int N;
char substr[3], dev_null;
vector<char> vertices[IN_POSSIBLE];

int main(){
    /*
    for(int i=0; i<IN_POSSIBLE; i++) 
        vertices.clear();
    */

    //*
    int NN;
    scanf("%d", &NN);
    while(NN--) {
    cout << NN << endl;
    // */

    scanf("%d", &N);
    cout << N << endl;
    while(N-- && cin.good()) {
        cin >> substr[0] >> substr[1] >> substr[2];

        cout << substr << endl;

        vertices[s[0]].emplace_back(substring[1]);
        vertices[s[1]].emplace_back(substring[2]);
    }
    cout << endl;

    for(int i=0; i<IN_POSSIBLE; i++)
        if( vertices[i].size() % 2 )
            uneven.insert(i);

    if(uneven.size() > 2) {
        cout << "NO" <<endl;
        return;
    }



    //*
    }
    // */

}


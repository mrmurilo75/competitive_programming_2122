#include<iostream>

using namespace std;

int N;
int main() {
    cin >> N;

    int plat[N];
    int n=0;
    cin >> plat[n];
    for(n=1; n<N; n++) {
        cin >> plat[n];
        if(plat[n] <= plat[n-1])
            break;
    }
    cout << plat[n-1] << endl;
}

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>

#define DBG false
#define dbg if(DBG)cout

using namespace std;

int N, Q;
map<int, vector<int> > inds;
int main(){

    cin >> N >> Q;

    for(int n=0, i; n<N; n++) {
        cin >> i;
        inds[i].emplace_back(n);
    }

    for(int q=0, x, k; q<Q; q++) {
        cin >> x >> k;
        try {
            vector<int> &r = inds.at(x);
            cout << r.at(k-1) +1 << endl;
        } catch (const std::out_of_range& oor) {
            cout << "-1" <<endl;
        }
    }

}


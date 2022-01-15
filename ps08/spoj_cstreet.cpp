#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>
#include <map>
#include <set>

#define DBG false
#define dbg if(DBG)cout

using namespace std;

int T, P, N, M;
uint a, b, w, result, r_size;
vector< pair<uint, uint> > edges;
vector<uint> llink, l_size;
set<uint> remaining;
map< uint, map<uint, uint> > weights;

uint find(uint x) {
    dbg<<"find "<<x;
    while (x != llink[x]) {
        x = llink[x];
        dbg<<" > "<<x;
    }

    dbg<<" = "<<x<<endl;
    return x;
}

bool same(uint a, uint b) {
    return find(a) == find(b);
}

void unite(uint a, uint b) {
    try {
        if(weights.at(a).at(b)) {
            uint a2 = find(a), b2 = find(b);

            dbg<<"un "<< a2 <<" "<< b2;

            if(l_size[a2] < l_size[b2]) swap(a2,b2);

            result += weights.at(a).at(b);
            r_size ++;

            dbg <<" = "<< result <<" "<< r_size <<endl;

            l_size[a2] += l_size[b2];
            llink[b2] = a2;
        }
    } catch (out_of_range &e) {
    }
}

bool comparator(pair<uint, uint> pa, pair<uint, uint> pb) {
    return weights[pa.first][pa.second] < weights[pb.first][pb.second];
}

int main(){

    cin >> T;
    dbg << T << endl;

    while(T--) {

        result =0;
        r_size =0;
        llink.clear();
        l_size.clear();

        cin >> P >> N >> M;
        dbg << P <<" "<< N <<" "<< M << endl;

        for(int n=0; n<=N; n++) {
            llink.emplace_back(n);
            l_size.emplace_back(1);
            weights[0][0] = 0;
        }

        dbg<<endl;
        while(M--) {
            cin >> a >> b >> w;
            dbg << a <<" "<< b <<" "<< w <<endl;

            weights[a][b] = w;
            weights[b][a] = w;
            edges.emplace_back(a, b);
        }

        sort(edges.begin(), edges.end(), comparator);

        for(auto & e : edges) {
            a = e.first;
            b = e.second;

            dbg <<"\t"<< a <<" "<< b <<" "<< weights[a][b] <<endl;

            if(!same(a, b) && r_size != N) unite(a, b);
        }

        dbg << endl;
        cout << result * P <<endl;
    }

}


#include <iostream>
#include <cstdio>
#include <climits>
#include <utility>
#include <vector>
#include <tuple>
#include <set>

#define DBG true
#define dbg if(DBG)cout

using namespace std;

int T, N, M, A, B, W;
vector< tuple<int, int, int> > edges;
vector< set< pair<int, int> > > distances;

int main(){

    cin >> T;
    dbg <<"T "<< T <<endl;
    while(T--) {
        edges.clear();
        distances.clear();

        cin >> N;
        dbg <<"N "<< N << endl;

        dbg <<"A\tW\tB"<<endl;
        for(int n=0; n<N; n++) {
            cin >> A >> W >> B;
            dbg << A <<"\t"<< W <<"\t"<< B <<endl;

            edges.emplace_back(A, W, B);
        }

        cin >> M;
        dbg <<"M "<< M <<endl;

        /*
        distances[x] = 0;
        for (int i = 1; i <= n-1; i++) {
            for (auto e : edges) {
                int a, b, w;
                tie(a, b, w) = e;
                distances[b] = min(distances[b], distances[a]+w);
            }
        }
        // */

    }

}


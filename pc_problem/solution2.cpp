#include <iostream>
#include <cstdio>
#include <climits>
#include <utility>
#include <vector>
#include <tuple>

#define DBG true
#define dbg if(DBG)cout

using namespace std;

int T, N, A, B, W;
vector< tuple<int, int, int> > edges;
vector< int > distances;

int main(){

    cin >> T;
    dbg <<"T "<< T <<endl;
    while(T--) {

        cin >> N;
        dbg <<"N "<< N << endl;

        dbg <<"A\tW\tB"<<endl;
        for(int n=0; n<N; n++) {
            cin >> A >> W >> B;
            dbg << A <<"\t"<< W <<"\t"<< B <<endl;

            edges.emplace_back(A, W, B);
        }

        /*
        distances[0] = 0;
        for(int n=0; n<N; n++) {
            for(auto e : edges) {
                tie(A, W, B) = e;
                distances[B] = min(distance[B], distances[A]+W);
            }
        }
        // */

    }

}


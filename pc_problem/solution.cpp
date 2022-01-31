#include <iostream>
#include <cstdio>
#include <climits>
#include <utility>
#include <vector>
#include <tuple>

#define DBG true
#define dbg if(DBG)cout

using namespace std;

int T, N, M, A, B, W, max_b;
vector< tuple<int, int, int> > edges;
vector< vector< pair<int, int> > > distances;

bool compare(pair< int, int > & a, pair< int, int > & b) {
    return (a.first != b.first)? a.first < b.first : a.second > b.second;
}

int main(){

    cin >> T;
    dbg <<"T "<< T <<endl;
    while(T--) {
        edges.clear();
        distances.clear();
        max_b = 0;

        cin >> N;
        dbg <<"N "<< N << endl;

        dbg <<"A\tW\tB"<<endl;
        for(int n=0; n<N; n++) {
            cin >> A >> W >> B;
            dbg << A <<"\t"<< W <<"\t"<< B <<endl;

            edges.emplace_back(A, W, B);
            max_b = max(max_b, B);
        }
        cin >> M;
        dbg <<"M "<< M <<endl;

        dbg <<"max B " << max_b <<endl;
        for(int b=0; b<max_b; b++) {
            distances.emplace_back();
            distances[b].emplace_back(INT_MAX, INT_MAX);
        }

        // Bellman-ford but
        //      for each of the possible paths going thru a negative path you need to check if it is within limit of 
        /*
        distances[0][0] = make_pair(0, 0);
        for(int n=0; n<N; n++) {
            for(auto e : edges) {
                tie(A, W, B) = e;
                int jumps = distance[A -1]
                if(W > 0)
                    distances[b](distances[a]+w);
            }
        }
        // */

    }

}


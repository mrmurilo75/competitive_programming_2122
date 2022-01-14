#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <queue>
#include <climits>
#include <cstring>
#include <stack>

#define DBG true
#define dbg if(DBG)cout

using namespace std;

vector< vector< pair<int, int> > > adj;
vector< int > distances;
vector< stack <int> > paths;

const int INF = INT_MAX;
void djikstra(int start, vector< vector< pair<int, int> > > & adj, vector< int > & distances, vector< stack <int> > & paths) {
    bool processed[distances.size() +1] = {false};
    priority_queue< pair< int, int > > q;

    fill(distances.begin(), distances.end(), INF);

    distances[start] = 0;
    q.push({0,start});

    while (!q.empty()) {
        int a = q.top().second;
        q.pop();

        if (processed[a]) continue;
        processed[a] = true;

        for (auto u : adj[a]) {
            int v = u.first, w = u.second;
            if (distances[a]+w < distances[v]) {
                distances[v] = distances[a]+w;
                paths[v].pop();
                paths[v].push(a);
                q.push({-distances[v],v});
            }
        }
    }

}

int N, M, start, dest, u, v, p;

int main(){

    cin >> N >> M;
    dbg << N <<" "<< M <<endl;

    while(N && M) {
        adj.clear();
        distances.clear();
        paths.clear();

        cin >> start >> dest;
        dbg << start <<" "<< dest <<endl;

        for(int n=0; n<N; n++)
            adj.emplace_back();

        for(int m=0; m<M; m++) {
            cin >> u >> v >> p;

            adj[u].emplace_back(v, p);

            dbg << u <<" - "<< p <<" -> "<< v<<endl;
        }





        cin >> N >> M;
        dbg << N <<" "<< M <<"\n"<< endl;
    }

}


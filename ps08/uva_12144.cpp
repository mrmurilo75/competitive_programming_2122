#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <queue>
#include <climits>
#include <cstring>

#define DBG true
#define dbg if(DBG)cout

using namespace std;

const int INF = INT_MAX;
void djikstra(int start, vector< vector< pair<int, int> > > & adj, vector< int > & distances) {
    bool processed[distances.size() +1] = {false};
    priority_queue< pair< int, int > > q;

    fill(distances.begin(), distances.end(), INF);
    // for (int i = 0; i <= distances.size(); i++) distances[i] = INF;

    distances[start] = 0;
    q.push({0,start});

    while (!q.empty()) {
        int a = q.top().second;
        q.pop();

        if (processed[a]) continue;
        processed[a] = true;

        for (auto u : adj[a]) {
            int b = u.first, w = u.second;
            if (distances[a]+w < distances[b]) {
                distances[b] = distances[a]+w;
                q.push({-distances[b],b});
            }
        }
    }

}

int main(){

}


#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <queue>
#include <climits>
#include <cstring>
#include <stack>
#include <vector>
#include <map>

#define DBG2 (true && DBG)
#define DBG  false
#define dbg2 if(DBG && DBG2)cout
#define dbg  if(DBG)cout

using namespace std;

int N, M, start, dest, u, v, p;

vector< map<int, int> > adj;
vector< int > distances;
vector< stack < pair<int,int> > > paths;

void print_path(stack< pair<int,int> > path, int i) {
    if(DBG) {
        cout <<" "<< i<<endl;
        while(!path.empty()){ 
            pair<int, int> p = path.top();
            cout  <<"'-> "<< p.second << endl;
            path.pop();
        }
    }
}

const int INF = INT_MAX;
void djikstra(int start, vector< map<int, int> > & adj, vector< int > & distances, vector< stack < pair<int, int> > > & paths) {
    bool processed[distances.size() +1] = {false};
    priority_queue< pair< int, int > > q;

    fill(distances.begin(), distances.end(), INF);

    distances[start] = 0;
    q.push({0,start});

    while (!q.empty()) {
        if(DBG && DBG2) {
            cout << endl;
            for(int d : distances) cout << d << endl;
        }

        int u = q.top().second;
        q.pop();

        if(DBG && DBG2)  {
            cout << endl;
            for(int i=0; i<N; i++)
                for(pair<int, int> p : adj[i]) 
                    cout <<" "<< i <<" - "<< p.second <<" -> "<< p.first << endl;
        }

        if (processed[u]) 
            continue;
        processed[u] = true;

        for (auto p : adj[u]) {
            int v = p.first, w = p.second;
            dbg<<endl;
            if(DBG) print_path(paths[u], u);

            if (distances[u]+w < distances[v]) {
                distances[v] = distances[u]+w;
                if(!paths[v].empty()) paths[v].pop();
                paths[v].emplace(u, v);
                q.emplace(-distances[v],v);
            }
            else if (distances[u]+w == distances[v]) {
                paths[v].emplace(u, v);
            }
        }
    }
    if(DBG) {
        cout << endl;
        for(int d : distances) cout << d << endl;

        for(int i=0; i<N; i++)
            print_path(paths[i], i);
        cout <<"---"<< endl;
    }

}

void trace_back(stack< pair<int,int> > path) {
        while(!path.empty()) {
            pair<int,int> cur = path.top();
            path.pop();

            adj[cur.first].erase(cur.second);

            trace_back(paths[cur.first]);
        }
}

int main(){

    cin >> N >> M;
    dbg << N <<" "<< M <<endl;

    while(N && M) {
        bool shortest = true;
        adj.clear();
        paths.clear();
        distances.clear();

        cin >> start >> dest;
        dbg << start <<" "<< dest <<endl;

        for(int n=0; n<N; n++) {
            adj.emplace_back();
            paths.emplace_back();
            distances.emplace_back();
        }

        for(int m=0; m<M; m++) {
            cin >> u >> v >> p;

            adj[u][v] = p;

            dbg2 << u <<" - "<< p <<" -> "<< v<<endl;
        }
        dbg << endl;

        djikstra(0, adj, distances, paths);

        if(shortest) { 
            trace_back(paths[dest]);
            shortest = false;
        }

        djikstra(0, adj, distances, paths);

        cout << ( (distances[dest] != INT_MAX)? distances[dest] : -1) <<endl;

        cin >> N >> M;
        dbg <<"_______\n"<< N <<" "<< M << endl;
    }

}


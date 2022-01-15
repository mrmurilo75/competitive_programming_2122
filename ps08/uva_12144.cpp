#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <queue>
#include <climits>
#include <cstring>
#include <vector>
#include <map>

#define DBG  false
#define dbg  if(DBG)cout

using namespace std;

int N, M, start, dest, u, v, p;

vector< map<int, int> > adj;
vector< int > distances;
vector< multimap<int, int> > parents;

void print_path(int i) {
    if(DBG) {
        cout <<" "<< i<<endl;
        for(auto p : parents[i]){ 
            cout <<" '-> "<< p.second <<" (" << p.first<< ")\n\t";
            print_path(p.second);
        }
        cout <<endl;
    }
}

const int INF = INT_MAX;
void djikstra(int start, vector< map<int, int> > & adj, vector< int > & distances, vector< multimap<int, int> > & parents) {
    bool processed[distances.size() +1] = {false};
    priority_queue< pair<int, int> > q;

    fill(distances.begin(), distances.end(), INF);

    distances[start] = 0;
    q.push({0,start});

    while (!q.empty()) {
        if(DBG) {
            cout << endl;
            for(int d : distances) cout << d << endl;
        }

        int from = q.top().second;
        q.pop();

        print_path(dest);

        if (processed[from]) 
            continue;
        processed[from] = true;

        for (auto p : adj[from]) {
            int to = p.first, w = p.second;

            if (distances[from]+w < distances[to]) {
                distances[to] = distances[from]+w;
                parents[to].emplace(distances[from]+w, from);

                q.emplace(-distances[to],to);
            }
            else if (distances[from]+w == distances[to]) {
                parents[to].emplace(distances[from]+w, from);
            }
        }
    }
    if(DBG) {
        cout << endl;
        for(int d : distances) cout << d << endl;

        for(int i=0; i<N; i++)
            print_path(i);
        cout <<"---"<< endl;
    }

}

void trace_back(int to) {
    dbg << "tracing" <<endl;

    multimap<int,int> & path = parents[to]; 

    auto smallest = (*path.begin());
    for(auto p : parents[to]) {
        if(p.first != smallest.first) return;

        adj[p.second].erase(to);
        dbg << "adj[ "<< p.second <<" ].er( "<<to<<" )  "<<adj[p.second].count(to)<<endl;

        trace_back(p.second);
    }
}

int main(){

    dbg << "start" << endl;

    cin >> N >> M;
    dbg << N <<" "<< M <<endl;

    while(N && M) {
        adj.clear();
        parents.clear();
        distances.clear();

        cin >> start >> dest;
        dbg << start <<" "<< dest <<endl;

        for(int n=0; n<N; n++) {
            adj.emplace_back();
            parents.emplace_back();
            distances.emplace_back();
        }

        for(int m=0; m<M; m++) {
            cin >> u >> v >> p;

            adj[u][v] = p;

            dbg << u <<" - "<< p <<" -> "<< v<<endl;
        }
        dbg << endl;

        djikstra(start, adj, distances, parents);

        dbg << "end first dijk"<<endl;

        trace_back(dest);

        parents.clear();
        distances.clear();
        for(int n=0; n<N; n++) {
            parents.emplace_back();
            distances.emplace_back();
        }

        djikstra(start, adj, distances, parents);

        dbg <<"output: ";
        cout << ( (distances[dest] != INT_MAX)? distances[dest] : -1) <<endl;

        cin >> N >> M;
        dbg <<"_______\n"<< N <<" "<< M << endl;
    }

}


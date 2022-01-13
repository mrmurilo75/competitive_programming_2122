#include <iostream>
#include <cstdio>
#include <climits>
#include <utility>
#include <set>
#include <vector>


#define DBG false
#define dbg if(DBG)cout

#define MATRIX_SIZE 1001
#define hash(a, b)  (M * a + b)
#define unhash(t)   ((t%M), ((t-(t%M))/M))

using namespace std;

int C, N, M;
int p[4][2]={  {-1,  0},
               { 1,  0},
               { 0, -1},
               { 0,  1}};

void dbg_print(vector<int> &d) {
    if(DBG) {
        for(int a : d){
            cout << a << " ";
        }
        cout << endl;
    }
}

//djikstra from cp-algorithms.com

//edges w/  verts     (to,  cost)
vector<     vector< pair<int, int> > > adj;

int dijkstra(int from, int final_to) {
    int n = adj.size();

    vector<int> distance, path;
    distance.assign(n, INT_MAX);
    path.assign(n, -1);

    distance[from] = 0;

    multiset<pair<int, int>> que;
    que.insert({0, from});
    while (!que.empty()) {
        int v = que.begin()->second;
        que.erase(que.begin());

        for (auto edge : adj[v]) {
            dbg_print(distance);
            int to = edge.first;
            int len = edge.second;

            if (distance[v] + len < distance[to]) {
                que.erase({distance[to], to});
                distance[to] = distance[v] + len;
                path[to] = v;
                que.insert({distance[to], to});
            }
        }
    }

    return *(--(distance.end()));
}

int main() {

    // input
    scanf("%d", &C);
    dbg << C << endl;

    while(C--) {
        adj.clear();

        scanf("%d%d", &N, &M);
        dbg << N <<" x "<< M << endl;

        int cost[N][M];

        for(int n=0; n<N; n++) {
            for(int m=0; m<M; m++) {
                scanf("%d", &(cost[n][m]));
                dbg << hash(n,m) << "  h(" << n << "," << m << ") " << cost[n][m] << endl;
            }
        }

        for(int n=0; n<N; n++) {
            for(int m=0; m<M; m++) {
                dbg << hash(n,m) << endl;
                adj.emplace_back();

                for(int i=0; i<4; i++) {
                    int a = n +p[i][0], b = m +p[i][1];
                    if(a < 0 || a > N-1)
                        continue;
                    if(b < 0 || b > M-1)
                        continue;

                    adj[hash(n,m)].emplace_back( (hash(a,b)), cost[a][b] );

                    dbg << "\t" << hash(a,b) << "|" << cost[a][b];
                }
                dbg << endl;

            }
        }

        // process

        cout << dijkstra(hash(0,0), hash(N-1, M-1)) +cost[0][0] << endl;
    }
    return 0;
}


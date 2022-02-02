#include <iostream>
#include <cstdio>
#include <climits>
#include <utility>
#include <vector>
#include <tuple>
#include <set>
#include <cstdlib>
#include <ctime>

#define T_MIN   0
#define T_MAX   101
#define N_MIN   0
#define N_MAX   1000
#define A_MIN   1
#define A_MAX   1001
#define B_MIN   1
#define B_MAX   1001
#define W_MIN (-500)
#define W_MAX   501

using namespace std;

int T, N, A, B, W;
vector< tuple<int, int, int> > edges;
vector< int > distances;
set< int > nodes;

bool vec_differs(vector< int > & a, vector< int > & b) {
    for(int i=0; i<a.size(); i++)
        if(a[i] != b[i])
            return true;
    return false;
}

int main(){
    srand(time(0));

    int T_out = (rand() % T_MAX) + T_MIN;
    cout << T_out << "\n";

    T = T_out;
    while(T--) {
        edges.clear();
        distances.clear();
        nodes.clear();

        int N_out = (rand() % N_MAX) + N_MIN;
        cout << N <<"\n";

        N = N_out;
        for(int n=0; n<N; n++) {
            int A_out, W_out, B_out;
            A_out = (rand() % A_MAX) + A_MIN;
            W_out = (rand() % W_MAX) + W_MIN;
            B_out = (rand() % B_MAX) + B_MIN;
            cout << A << " " << W << " " << B << "\n";

            A = A_out; W = W_out; B = B_out;

            edges.emplace_back(A, W, B);
            if(!nodes.count(A))
                nodes.emplace(A);
            if(!nodes.count(B))
                nodes.emplace(B);
        }

        for(int n=0; n<nodes.size()+1; n++) distances.emplace_back(INT_MAX);

        distances[1] = -1;

        for(int n=2; n<nodes.size()+1; n++) {
            for(auto e : edges) {
                tie(A, W, B) = e;
                distances[B] = min(distances[B], distances[A]+W);
            }
        }
        
        vector< int > distances_BF = distances; // make a copy of distances after running bellman-ford

        // run it one more time and see if any path can be smaller to check for negative loops
        for(auto e : edges) {
            tie(A, W, B) = e;
            distances[B] = min(distances[B], distances[A]+W);
        }
        if( vec_differs(distances_BF, distances) )
            cerr << "YES" <<endl;
        else
            cerr << "NO" <<endl;

    }

}


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

    cin >> T;
    dbg <<"T "<< T <<endl;
    while(T--) {
        edges.clear();
        distances.clear();
        nodes.clear();

        cin >> N;
        dbg <<"N "<< N << endl;

        dbg <<"A\tW\tB"<<endl;
        for(int n=0; n<N; n++) {
            cin >> A >> W >> B;
            dbg << A <<"\t"<< W <<"\t"<< B <<endl;

            edges.emplace_back(A, W, B);
            if(!nodes.count(A))
                nodes.emplace(A);
            if(!nodes.count(B))
                nodes.emplace(B);
        }

        for(int n=0; n<nodes.size()+1; n++) distances.emplace_back(INT_MAX);

        distances[1] = -1;

        for(int n=2; n<nodes.size()+1; n++) {
            dbg << n <<endl;
            for(auto e : edges) {
                tie(A, W, B) = e;
                distances[B] = min(distances[B], distances[A]+W);
                dbg << "\t" << A <<" "<< W <<" "<< B <<" = \t"<< distances[B] <<endl; 
            }
        }
        dbg << endl;
        
        vector< int > distances_BF = distances; // make a copy of distances after running bellman-ford

        // run it one more time and see if any path can be smaller to check for negative loops
        for(auto e : edges) {
            tie(A, W, B) = e;
            distances[B] = min(distances[B], distances[A]+W);
            dbg << "\t" << A <<" "<< W <<" "<< B <<" = \t"<< distances[B] <<endl; 
        }
        if( vec_differs(distances_BF, distances) )
            cout << "YES" <<endl;
        else
            cout << "NO" <<endl;

    }

}


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cfloat>
#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <list>

#define DBG false
#define dbg if(DBG)cout

#define MAX_DIST 30

using namespace std;

int N, M;
double distances[MAX_DIST];
map< string, int > currencies_i;
list< tuple< int, int, double > > edges;

int main(){


    // memset(distances, DBL_MAX, sizeof distances);
    // redone w/ for after reading N

    scanf("%d", &N);
    dbg << N << endl;

    for(int C = 1; N; C++) {
        currencies_i.clear();
        edges.clear();

        for(int n=0; n<N; n++) {
            string s;
            // scanf("%s\n", s);
            cin >> s;
            dbg << s <<" " << currencies_i.size() <<endl;

            currencies_i.emplace(s, currencies_i.size());
        }

        scanf("%d", &M);
        dbg << M << endl;

        for(int m=0; m<M; m++) {
            string a, b;
            double w;
            cin >> a >> w >> b;
            dbg << a <<" "<< w <<" "<< b <<endl;

            edges.emplace_back( (int)(currencies_i[a]), (int)(currencies_i[b]), w);
        }

        // Bellman-Ford as in the book 'Competitive Programmer'

        for(int i=0; i<N; i++) distances[i]=DBL_MIN;

        if(DBG){ 
            for(int i=0; i< N; i++ ) cout<< distances[i] <<" ";
            cout<<endl;
        }

        distances[0] = 1;
        bool reduced = true;
        for (int i = 0; i < N; i++) {
            if(!reduced) break;

            reduced = false;
            for (auto e : edges) {
                int a, b; 
                double w;
                tie(a, b, w) = e;
                dbg << a <<" - "<< w <<" -> "<< b <<endl;
                if(distances[a]*w > distances[b]) {
                    reduced =true;
                    distances[b] = distances[a]*w;
                }
                //distances[b] = max(distances[a]*w, distances[b]);
                if(DBG){ 
                    for(int i=0; i< N; i++ ) cout<<"\t"<< distances[i];
                    cout<<endl;
                }
            }
        }
        if(DBG){ 
            for(int i=0; i< N; i++ ) cout<< distances[i] <<" ";
            cout<<endl;
        }

        cout << "Case " << C <<": "<< ((distances[0]>1)? "Yes" : "No") <<endl;


        scanf("%d", &N);
        dbg <<"\n" << N << endl;
    }

}


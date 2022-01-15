#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue> 
#include <utility>
#include <set>

#define DBG false
#define dbg if(DBG)cout

#define MAX_N  1000001
#define MAX_NN 10000001

using namespace std;


long operationA(long cur, long a) {
    return cur * a;
}

long operationB(long cur) {
    dbg << cur <<endl;

    long pot = pow(10, (long)log10(cur));
    long firstDigit = (long) (cur % 10);
    long res = cur/10 + firstDigit * pot;

    dbg << firstDigit <<" "<< res <<endl;

    return ((res<MAX_NN)? res : 0);
}

int main(){
    set<long> visited;

    long a, N;

    dbg << "start" <<endl;

    cin >> a >> N;
    long x=1, max_N = N*100;

    if(x == N) {
        cout << 0 << endl;
        return 0;
    }

    queue< pair<long, int> > q;
    q.emplace(x, 1);

    long cur_res;
    while(!q.empty()) {
        pair<long,int> cur = q.front();
        q.pop();

        dbg << cur.first <<" "<< cur.second <<endl;

        if(visited.count(cur.first))
            continue;
        visited.insert(cur.first);

        cur_res = operationA(cur.first, a);
        if(cur_res == N) {
            cout << cur.second <<endl;
            return 0;
        }
        if(cur_res > max_N)
            q.emplace(cur_res, cur.second +1);

        if(cur.first > 10) {
            dbg << cur.first <<" is >10 ----"<<endl;
            cur_res = operationB(cur.first);

            if(cur_res && cur_res == N) {
                cout << cur.second <<endl;
                return 0;
            }

            if(cur_res > max_N)
                q.emplace(cur_res, cur.second +1);
        }
    }
    cout << "-1" << endl;
}


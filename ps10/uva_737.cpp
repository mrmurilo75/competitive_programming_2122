#include <iostream>
#include <cstdio>
#include <climits>

#define DBG false
#define dbg if(DBG)cout

using namespace std;

int T;
long long x, y, z, l, min_x, min_y, min_z, max_x, max_y, max_z, result;

int main() {

    cin >> T;
    dbg << T << endl;
    while(T) {

        max_x = LLONG_MAX;
        max_y = LLONG_MAX;
        max_z = LLONG_MAX;

        min_x = LLONG_MIN;
        min_y = LLONG_MIN;
        min_z = LLONG_MIN;


        while(T--) {
            cin >> x >> y >> z >> l;
            dbg << x <<" "<< y <<" "<< z <<" "<< l <<endl;

            min_x = max(min_x, x);
            min_y = max(min_y, y);
            min_z = max(min_z, z);
            dbg <<"max\t"<< min_x <<" "<< min_y <<" "<< min_z <<endl;

            max_x = min(max_x, x + l);
            max_y = min(max_y, y + l);
            max_z = min(max_z, z + l);
            dbg <<"min\t"<< max_x <<" "<< max_y <<" "<< max_z <<endl;
        }

        result = (max_x - min_x) * (max_y - min_y) * (max_z - min_z);

        cout << ( (result > 0)? result : 0 ) <<endl;

        cin >> T;
    }
}


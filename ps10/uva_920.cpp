#include <iostream>
#include <cstdio>
#include <cmath>
#include <utility>
#include <vector>
#include <algorithm>

#define DBG false
#define dbg if(DBG)cout

using namespace std;

double euclidean_distance(pair<int, int> & a, pair<int, int> & b) {
    return sqrt((double)(a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

string to_str(pair< int, int > & p) {
    cout << "("<< p.first <<" "<< p.second <<")";
    return "";
}

double calculate_piece(pair< int, int > & higher, pair< int, int > & high_base, pair< int, int > & cut) {
    dbg << "\tpiece: "<< to_str(higher) <<" "<< to_str(high_base) <<" "<< to_str(cut);

    double result = euclidean_distance(higher, high_base) * ( (double)(higher.second - cut.second) / (higher.second - high_base.second) );  // we take only the percentage of the size that matters

    dbg <<" = " << result << endl;

    return result;
}

int C, N;
vector< pair<int, int> > points;
pair< int, int > cur_max;
double result;
int main() {

    cin >> C;
    dbg << C << endl;
    while(C--) {

        points.clear();
        cur_max = make_pair(0, 0);
        result = 0;

        cin >> N;
        dbg << N << endl;
        for(int i=0, x, y; i<N; i++) {
            cin >> x >> y;
            dbg << "  " << x << " " << y << endl;
            points.emplace_back(x, y);
        }

        sort(points.begin(), points.end());
        if(DBG) {
            cout << "sorted" <<endl;
            for(auto & p : points)
                cout << p.first <<" "<< p.second <<endl;
        }

        for(int i= N-2; i>=0; i--) {
            auto & p = points[i], prev = points[i +1];
            if(p.second > cur_max.second) {
                result += calculate_piece(p, prev, cur_max);
                cur_max = p;
            }
        }

        printf("%.2f\n", result);
    }
}


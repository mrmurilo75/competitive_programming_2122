#include <iostream>
#include <cstdio>
#include <utility>
#include <cmath>
#include <vector>
#include <string>
#include <set>

#define DBG false
#define dbg if(DBG)cout

#define get_start(vec)  vec.first
#define get_end(vec)  vec.second
#define get_x(p)        p.first
#define get_y(p)        p.second

#define flip(b) (b = !b)

using namespace std;

typedef pair< double, double > point;
typedef pair< pair<double, double>, pair<double, double> > vecAB;

double determinant(point & A, point & B) {
    return A.first * B.second - A.second * B.first;
}

bool is_in_path(vecAB & AB, double x) {
    return (AB.first.first < x && AB.second.first > x) || (AB.second.first < x && AB.first.first > x);
}

point * get_intersection(point * result, vecAB & AB, vecAB & CD) {
    if(!is_in_path(AB, CD.first.first)) {
        result->first = result->second = -1;
        return result;
    }


    point x_diff = make_pair( get_x(get_start(AB)) - get_x(get_end(AB)), get_x(get_start(CD)) - get_x(get_end(CD)) ),
            y_diff = make_pair( get_y(get_start(AB)) - get_y(get_end(AB)), get_y(get_start(CD)) - get_y(get_end(CD)) );

    double det = determinant(x_diff, y_diff);

    if(!det) {
        result->first = result->second = -1;
        return result;
    }

    point det_p = make_pair(determinant(AB.first, AB.second), determinant(CD.first, CD.second));

    result->first = (determinant(det_p, x_diff) / det);
    result->second = (determinant(det_p, y_diff) / det);
    return result;

    /*
def line_intersection(AB, CD):
    xdiff = A_x - B_x, C_x - D_x
    ydiff = A_y - B_y, C_y - D_y

    def det(a, b):
        return a[0] * b[1] - a[1] * b[0]

    div = det(xdiff, ydiff)
    if div == 0:
       raise Exception('lines do not intersect')

    d = (det(*AB), det(*CD))
    x = det(d, xdiff) / div
    y = det(d, ydiff) / div
    return x, y
    */
}

double euclidean_distance(point & a, point & b) {
    return sqrt((double)(a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

string to_str(point & p) {
    cout << "("<< p.first <<" "<< p.second <<")";
    return "";
}

string vec_to_str(vecAB & ab) {
    cout << to_str(ab.first) <<"->"<< to_str(ab.second);
    return "";
}

int T, N, tresh, eval_x;
double px, py, max_y, result;
vector< point > points;
vecAB path;
set< double > intersections;

int main(){

    cin >> T;
    dbg << T << endl;
    while(T--) {
        points.clear();
        max_y = 0;
        intersections.clear();
        result = 0;

        cin >> N;
        dbg << N <<endl;
        for(int n=0; n<N; n++) {
            cin >> px >> py;

            points.emplace_back(px, py);
            max_y = max(max_y, py);

            dbg << to_str(points[n]) <<endl;
        }
        //dbg <<"max_y " << max_y <<endl;

        cin >> tresh >> eval_x;
        dbg << "tresh " << tresh <<"\neval "<< eval_x <<endl;

        path = make_pair(make_pair(eval_x, 0), make_pair(eval_x, max_y));
        dbg <<"path "<< vec_to_str(path) <<endl;

        for(int n=1; n<=N; n++) {
            vecAB cur;
            if(n == N)
                cur = make_pair(points[n-1], points[0]);
            else
                cur = make_pair(points[n-1], points[n]);
            dbg << vec_to_str(cur) <<endl;

            point intersection = make_pair(-1, -1);
            get_intersection(&intersection, cur, path );
            dbg <<"\t"<< to_str(intersection) <<endl;

            if( intersection.first < 0 || intersection.second < 0 ) continue;

            dbg <<"\tY" <<endl;
            intersections.emplace(intersection.second);

        }
        dbg<<endl;

        for(auto cur = intersections.begin();
                cur != intersections.end();) {
            auto start = cur++, end = cur++;

            if(start == intersections.end() || end == intersections.end())
                break;

            dbg << result << " += " << *end <<" - "<< *start <<endl;

            result += *end - *start;
        }
        dbg << result <<endl;

        cout << ( (result >= tresh)? "YES" : "NO" ) << endl;

    }

}


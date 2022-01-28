/*
 * a brute force solution would be to get each of the lines that make a vertice and then for e
 *
 */
#include <iostream>
#include <cstdio>
#include <utility>

#define DBG true
#define dbg if(DBG)cout

#define get_start(vec)  vec.first
#define get_end  (vec)  vec.second
#define get_x(p)        p.first
#define get_y(p)        p.second
#define flip(b) (b = !b)

using namespace std;

typedef pair< double, double > point;
typedef pair< pair<double, double>, pair<double, double> > vecAB;

point get_intersection(vecAB & AB, vecAB CD) {
    /*
def line_intersection(line1, line2):
    xdiff = (line1[0][0] - line1[1][0], line2[0][0] - line2[1][0])
    ydiff = (line1[0][1] - line1[1][1], line2[0][1] - line2[1][1])

    def det(a, b):
        return a[0] * b[1] - a[1] * b[0]

    div = det(xdiff, ydiff)
    if div == 0:
       raise Exception('lines do not intersect')

    d = (det(*line1), det(*line2))
    x = det(d, xdiff) / div
    y = det(d, ydiff) / div
    return x, y
    */
/*
    const double A_x = AB.first.first,
                A_y = AB.first.second,
                B_x = AB.second.first,
                B_y = AB.second.second,
                C_x = CD.first.first,
                C_y = CD.first.second,
                D_x = CD.second.first,
                D_y = CD.second.second;

    double AB_x_diff = (A_x - B_x

    double a = B_x * (C_y - A_y)       - B_y * (C_x - A_x),
           b = B_x * (C_y + D_y - A_y) - B_y * (C_x + D_x - A_x),
           c = D_x * (A_y - C_y)       - D_y * (A_x - C_x),
           d = D_x * (A_y + B_y - C_y) - D_y * (A_x  + B_x - C_x);

    return (a*b <= 0) && (c*d <= 0);
*/
    return make_pair(0.0, 0.0);
}

bool is_in_vec(vecAB & AB, point & p) {
    return lines_cross(AB, make_pair(p,p));
}

double euclidean_distance(point & a, point & b) {
    return sqrt((double)(a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

string vec_to_str(vecAB & ab) {
    cout << to_str(ab.first) <<"->"<< to_str(ab.second);
    return "";
}

string to_str(point & p) {
    cout << "("<< p.first <<" "<< p.second <<")";
    return "";
}

int T, N, tresh, eval_x;
double px, py, max_y, result;
vector< point > points;
vecAB path;
set< double > intersections;
bool b;

int main(){

    cin >> T;
    dbg << T << endl;
    while(T--) {
        points.clear();
        max_y = 0;
        intersections.clear();
        b = true;
        result = 0;

        cin >> N;
        dbg << N <<endl;
        for(int n=0; n<N; n++) {
            cin >> px >> py;

            points.emplace_back(px, py);
            max_y = max(max_y, py);

            dbg << to_str(points[n]);
        }

        cin >> tresh >> eval_x;
        dbg << "tresh " << tresh <<"\neval "<< eval_x <<endl;

        path = make_pair(make_pair(eval_x, 0), make_pair(eval_x, max_y));
        intersections.emplace(0.0);
        intersections.emplace(max_y);

        for(int n=1; n<N; n++) {
            point intersection = get_intersection( make_pair(points[n-1], points[n]), path );

            if( intersection.first < 0 || intersection.second < 0 ) continue;

            intersections.emplace(intersection.second);

        }

        for(auto *cur = intersections.begin();
                cur != intersections.end();) {
            auto *prev = cur;
            cur++;
            if(cur == intersections.end())
                break;

            if(flip(b))
                result += *cur - *prev;
        }

        cout << ( (result >= tresh)? "YES" : "NO" ) << endl;

    }

}


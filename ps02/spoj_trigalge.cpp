#include <iostream>
#include <cmath>

using namespace std;

int main(){
        int cases;
        cin >> cases;
        while(cases--) {
                int a, b, c;
                cin >> a >> b >> c;
		long double ad = (long double) a, bd = (long double) b, cd = (long double) c;
                long double result = cd / ad, jump = bd / 2.0;
                while(true) {
                        long double sine = sin(result), cur = ad*result + bd*sine, se = cd - cur;
                        if( se >= -0.00000001 && se < 0.00000001 )
                                break;
                        if(se < 0)
                                result -= jump;
                        else
                                result += jump;
                        jump /= 2.0;
                }
                printf("%.10Lg", result);
                cout << endl;
        }

}


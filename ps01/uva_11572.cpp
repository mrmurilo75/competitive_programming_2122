#include <iostream>
#include <map>

using namespace std;

int main(){

    // input
	int tests;

	cin >> tests;
	while(tests--) {
		int amount_sf, size_sf;

		cin >> amount_sf;
		int sfId[ (size_sf = amount_sf +1) ], cur_begin = 1, maximum = 0, cur_sf_pos;
		map<int, int> sfId_to_lastPos;

		for(cur_sf_pos = 1; cur_sf_pos < size_sf; cur_sf_pos++) {

			cin >> sfId[cur_sf_pos];

    // process
			if( !sfId_to_lastPos[ sfId[cur_sf_pos] ] ) {
				// sfId is new
				sfId_to_lastPos[ sfId[cur_sf_pos] ] = cur_sf_pos;
			} else {
				if(sfId_to_lastPos[ sfId[cur_sf_pos] ] >= cur_begin) {
					// is in counting range
					if(maximum < (cur_sf_pos - cur_begin) )
						maximum = (cur_sf_pos - cur_begin);

					cur_begin = sfId_to_lastPos[ sfId[cur_sf_pos] ] +1;
				}

				sfId_to_lastPos[ sfId[cur_sf_pos] ] = cur_sf_pos;
			}

		}

		if(maximum < (cur_sf_pos - cur_begin) )
			maximum = (cur_sf_pos - cur_begin);

    // output
		cout << maximum << endl;
	}
}

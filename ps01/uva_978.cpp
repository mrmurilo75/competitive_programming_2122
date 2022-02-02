#include <iostream>
#include <queue>
#include <utility>

using namespace std;

void battle(short green, short blue, pair<short, short> &result) {
	if(green > blue) {
		result.first = 1;
		result.second = green - blue;
		return;
	} 
	if(blue > green) {
		result.first = 2;
		result.second = blue - green;
		return;
	} 
	result.first = 0;
}

int main(){

    // input
	int tests;

	cin >> tests;
	while(tests--) { 
		int bfs, size_g, size_b;

		cin >> bfs >> size_g >> size_b;
		priority_queue<short> green_powers, blue_powers;

		while(size_g--) {
			short gp;

			cin >> gp;
			green_powers.emplace(gp);
		}

		while(size_b--) {
			short bp;

			cin >> bp;
			blue_powers.emplace(bp);
		}

    // process
		while( !(blue_powers.empty() || green_powers.empty()) ) { 
			int min = (blue_powers.size() < green_powers.size())? blue_powers.size() : green_powers.size(); 

			if(bfs > min) bfs = min;
			pair<short, short> results[bfs];

			for(int i = 0; i < bfs; i++) {
				battle(green_powers.top(), blue_powers.top(), results[i]);
				green_powers.pop(); blue_powers.pop();
			}

			for(int i = 0; i < bfs; i++) {
				if(results[i].first == 1)
					green_powers.push(results[i].second);
				else if (results[i].first == 2)
					blue_powers.push(results[i].second);
				// else both died
			}
		}

    // output
		if(blue_powers.empty()) {
			if(green_powers.empty())
				cout << "green and blue died\n";
			else {
				cout << "green wins\n";
				while( !(green_powers.empty()) ) {
					cout << green_powers.top() << "\n";
					green_powers.pop();
				}
			}
		} else {
			cout << "blue wins\n";
			while( !(blue_powers.empty()) ) {
				cout << blue_powers.top() << "\n";
				blue_powers.pop();
			}
		}
		if(tests)
			cout << endl;
	}

}


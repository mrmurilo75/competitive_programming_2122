#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(){
	int cases;
	cin >> cases;
	while(cases--) {
		int n;
		cin >> n;
		int sf[n + 1], beginning = 1, size = 0, maximum = 0;
		sf[0] = 0;
		map<int, int> last_pos;
		for(int i = 1; i < n +1; i++) {
			cin >> sf[i];
			if(!last_pos[sf[i]]) { // aka last_pos of sf[i] is 0 (NULL) so its new
				last_pos[sf[i]] = i;
				size++;
			} else if (last_pos[sf[i]] >= beginning) { // if sf[i] not new && last_pos of sf[i] is being accounted 
				if(size > maximum)
					maximum = size; // see if current size is a max

				beginning = last_pos[sf[i]] +1; // continue for right after the repetition
				size = i - last_pos[sf[i]]; // update size
			}
		}
		cout << maximum << endl;
	}
}


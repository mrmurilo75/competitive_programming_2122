#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

int max(int a, int b) {
	return (a > b) a : b;
}

int main(){
	int n, q;
	for(cin >> n >> q; n != 0 && cin.good(); cin >> n >> q){
		cout << "n " << n << " q " << q << endl;

		vector<int> values(n);
		unordered_map< int, pair<int, int> > map;

		int in, begin = 0, end = 0;
		cin >> in;
		values[end] = in;
		cout << " " << values[end];
		for(end =1; end < n; end++) {
			cin >> in;
			values[end] = in;
			cout << " " << values[end];

			if(values[end] != values[end-1]) {
				map.emplace(values[end-1], pair<int, int>(begin, end));
				begin = end;
			}
		}
		map.emplace(values[end-1], pair<int, int>(begin, end));

		while(q--) {
			int i, j;
			cin >> i >> j;
			cout << "i " << i << " j " << j << endl;

			int val, val_end, count = 0;
			while(val_end < j) {
				// check the value in i
				val = values[i];
				auto val_range = *(map.find(values));
				val_end = val_range->second;
				
				if(val_end > j)
					val_end = j;

				count = max(val_end - i, count);

				// 	count = i - value(end)
				// repeat for value in value(end) as count2
				// count = max(count, count2)
			}
		}
	}

}


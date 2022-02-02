#include <iostream>
#include <unordered_map>
#include <utility>
#include <queue>

using namespace std;

int main(){

	int len_msg, num_lim, i;

	cin >> len_msg >> num_lim;

	unordered_map< int, tuple<short, short, int> > freq;
	priority_queue< tuple<short, short, int> > heap;

	while( (i = len_msg--) ) {
		int msg;

		cin >> msg;

		if(!freq.count(msg)) {
			freq[msg] = make_tuple(1, i, msg); // count, appearence, number
		} else
			(get<0>(freq[msg]))++;
	}

	for(auto elem : freq)
		heap.push(elem.second);

	int count = get<0>(heap.top()); 

	cout << get<2>(heap.top());

	while(--count)
		cout << " " << get<2>(heap.top());

	heap.pop();

	while(!heap.empty()) {

		for(int count = get<0>(heap.top()); count--; )
			cout << " " << get<2>(heap.top());

		heap.pop();
	}

	cout << endl;
}


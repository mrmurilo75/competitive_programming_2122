#include <iostream>
#include <vector>

using namespace std;

long long calculate_cost(int h_goal,vector<int> &h,vector<int> &c) ;

int main(){
	int cases;
	cin >> cases;
	while(cases--) {
		int n;
		cin >> n;
		vector<int> h(n), c(n);
		long long max = 0, min = 10000;
		for(int i =0; i < n; i++) {
			cin >> h[i];
			if( max < h[i] ) max = h[i];
			if( min > h[i] ) min = h[i];
		}
		for(int i =0; i < n; i++) 
			cin >> c[i];

		while(max > min) {
			long long diff = (max - min);
			if( ! diff%2 ) diff++;
			long long middle = min + diff/2;

			long long m_cost = calculate_cost(middle, h, c);

			long long m_minus = calculate_cost(middle-1, h, c);
			if(m_minus >= m_cost) {
				if(middle != max) {
					long long h_plus = calculate_cost(middle+1, h, c);
					if( h_plus > m_cost) {
						cout << m_cost << endl;
						break;
					}
					min = middle+1;
					continue;
				}
				cout << m_cost << endl;
				break;
			} else if(middle-1 == min) {
				cout << m_minus << endl;
				break;
			} else {
				max = middle-1;
				continue;
			}
		}
		cout << calculate_cost(min, h, c) << endl;
		break;
	}

}

long long calculate_cost(int h_goal,vector<int> &h,vector<int> &c) {
	long long cost =0;
	for(int i =0; i < (int)h.size(); i++)
		cost += abs(h_goal - h[i]) * c[i];
	return cost;
}


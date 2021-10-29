#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int fill_min_dists(int size, vector<int> &input, vector<int> &result);

bool put_cows(int x, vector<int> &dists, int n_cows);

int main(){
	int cases;
	cin >> cases;
	while(cases--) {
		int n_stalls, n_cows;
		cin >> n_stalls >> n_cows;
		int first_stall = 1000000000, last_stall = 0;
		vector<int> stalls_pos(n_stalls, 0), stalls_dists(n_stalls -1, 0);
		for(int i=0; i<n_stalls; i++) {
			cin >> stalls_pos[i];
			if(stalls_pos[i] < first_stall)
				first_stall = stalls_pos[i];
			if(stalls_pos[i] > last_stall)
				last_stall = stalls_pos[i];
		}
		sort(stalls_pos.begin(), stalls_pos.end());
		int min_dist = fill_min_dists(n_stalls, stalls_pos, stalls_dists), 
			max_dist = last_stall - first_stall, 
			middle = min_dist + (max_dist - min_dist)/2;

		/*
		for(int dist : stalls_pos) 
			cout << " " << dist;
		cout << endl;
		for(int dist : stalls_dists) 
			cout << " " << dist;
		cout << endl;
		cout <<"\t"<< min_dist << " " << max_dist << " " << middle << endl;
		*/

		while(min_dist < max_dist) {
			if(put_cows(middle, stalls_dists, n_cows))
				min_dist = middle;
			else
				max_dist = middle - 1;

			if(max_dist - min_dist == 1)
				middle = min_dist + 1;
			else 
				middle = min_dist + (max_dist - min_dist)/2;
		}
		cout << min_dist << endl;
	}

}

bool put_cows(int x, vector<int> &dists, int n_cows) {
	n_cows--;
	int sum = 0;
	for(int dist : dists) {
		sum += dist;
		if(sum < x) 
			continue;

		n_cows--;
		if(!n_cows) 
			return true;
		sum = 0;
	}
	return false;
}

int fill_min_dists(int size, vector<int> &input, vector<int> &result) {
	int min = 1000000000;
	for(int i = 0; i < size -1; i++) {
		result[i] = input[i+1] - input[i];
		if(result[i] < min)
			min = result[i];
	}
	return min;
}


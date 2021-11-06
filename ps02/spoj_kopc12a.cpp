#include <iostream>
#include <vector>

using namespace std;

long long ternary_search(vector<int> &h, vector<int> &c, int min, long long min_cost, int max, long long max_cost, int middle, long long middle_cost) ;

long long calculate_cost(int h_goal,vector<int> &h,vector<int> &c) ;

void eval_bottom(int &cur_bottom, long long &cur_bottom_cost, int eval, long long eval_cost) ;

void middle_up(vector<int> &h, vector<int> &c, int &cur_bottom, long long &cur_bottom_cost, int min, int max, int &middle, long long &middle_cost);

int main(){
	int cases;
	cin >> cases;
	while(cases--) {
		int n;
		cin >> n;
		vector<int> h(n), c(n);
		int max = 0, min = 10000;
		for(int i =0; i < n; i++) {
			cin >> h[i];
			if( max < h[i] ) max = h[i];
			if( min > h[i] ) min = h[i];
		}
		for(int i =0; i < n; i++) 
			cin >> c[i];

	//cout << "min\tmin_cost\tmax\tmax_cost\tmiddle\tmiddle_cost" <<  endl; 

		cout << ternary_search(h,c, min, -1, max, -1, -1, -1) << endl;
	}

}

long long ternary_search(vector<int> &h, vector<int> &c, int min, long long min_cost, int max, long long max_cost, int middle, long long middle_cost) {
	static long long cur_bottom_cost = -1;
	static int cur_bottom = -1;

	//cout << min << "\t" << min_cost  << "\t\t" << max << "\t" << max_cost << "\t\t" << middle  << "\t" <<middle_cost << endl; 
	if(cur_bottom < 0 && middle < 0) { 	// kick start w min n max
		max_cost = calculate_cost(max, h, c), min_cost = calculate_cost(max, h, c);

		cur_bottom = min;
		cur_bottom_cost = min_cost;

		eval_bottom(cur_bottom, cur_bottom_cost, max, max_cost);
		//cout << min << "\t" << min_cost  << "\t\t" << max << "\t" << max_cost << "\t\t" << middle  << "\t" <<middle_cost << endl; 
	}

	if(middle < 0) {
		//cout << " here" << endl;
		//cout << min << "\t" << min_cost  << "\t\t" << max << "\t" << max_cost << "\t\t" << middle  << "\t" <<middle_cost << endl; 
		middle_up(h, c, cur_bottom, cur_bottom_cost, min, max, middle, middle_cost);
		//cout << min << "\t" << min_cost  << "\t\t" << max << "\t" << max_cost << "\t\t" << middle  << "\t" <<middle_cost << endl; 

		return ternary_search(h,c, min, min_cost, max, max_cost, middle, middle_cost);
	}


	if((max - min) <= 3) { 	// end recursion
		eval_bottom(cur_bottom, cur_bottom_cost, max, max_cost);
		eval_bottom(cur_bottom, cur_bottom_cost, min, min_cost);
		if(middle > 0)
			eval_bottom(cur_bottom, cur_bottom_cost, middle, middle_cost);
		else {
			middle_up(h, c, cur_bottom, cur_bottom_cost, min, max, middle, middle_cost);
		}

		if((max - min) == 3 || middle+1 == max)
			eval_bottom(cur_bottom, cur_bottom_cost, middle -1 , calculate_cost(middle-1, h,c));
		if((max - min) == 3 || middle-1 == min)
			eval_bottom(cur_bottom, cur_bottom_cost, middle +1 , calculate_cost(middle+1, h,c));

		long long result = cur_bottom_cost;
		cur_bottom_cost = -1;
		cur_bottom = -1;

		return result;
	}

	int q1, q2;
	long long q1_cost, q2_cost;
	middle_up(h, c, cur_bottom, cur_bottom_cost, min, middle, q1, q1_cost);
	if(cur_bottom == q1)
		return ternary_search(h,c, min, min_cost, middle, middle_cost, q1, q1_cost);
	else
		middle_up(h, c, cur_bottom, cur_bottom_cost, middle, max, q2, q2_cost);
	if(cur_bottom == q2)
		return ternary_search(h,c, middle, middle_cost, max, max_cost, q2, q2_cost);
	if(cur_bottom == middle)
		return ternary_search(h,c, q1, q1_cost, q2, q2_cost, middle, middle_cost);
	if(cur_bottom == min)
		return ternary_search(h,c, min, min_cost, q1, q1_cost, -1, -1);
	if(cur_bottom == max)
		return ternary_search(h,c, q2, q2_cost, max, max_cost, -1, -1);

	return -1; // something failed
}

long long calculate_cost(int h_goal, vector<int> &h, vector<int> &c) {
	long long cost =0;
	for(int i =0; i < (int)h.size(); i++) {
		//cout << cost << " = "<< abs(h_goal - h[i]) << " * " << c[i] <<endl;
		cost += abs(h_goal - h[i]) * c[i];
	}
	//cout << cost << endl;
	return cost;
}

void eval_bottom(int &cur_bottom, long long &cur_bottom_cost, int eval, long long eval_cost) {
	if(eval_cost < cur_bottom_cost) {
		cur_bottom = eval;
		cur_bottom_cost = eval_cost;
	}
}

void middle_up(vector<int> &h, vector<int> &c, int &cur_bottom, long long &cur_bottom_cost, int min, int max, int &middle, long long &middle_cost) {
	int diff = (max - min);
	if( ! diff%2 ) diff++; 		// middle up
	middle = (min + diff/2);

	middle_cost = calculate_cost(middle, h,c);
	//cout<< "mid " << middle << " : " << middle_cost << endl;

	eval_bottom(cur_bottom, cur_bottom_cost, middle, middle_cost);
}

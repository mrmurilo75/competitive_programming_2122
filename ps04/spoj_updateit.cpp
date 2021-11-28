#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct FenwickTree { // Fenwick Tree based on https://cp-algorithms.com/data_structures/fenwick.html#toc-tgt-9
	vector<int> bit;  // binary indexed tree
	int size;

	FenwickTree(int size) {
		this->size = size + 1;
		bit.assign(size + 1, 0);
	}

	int sum(int end) {
		int result = 0;
		for (++end; end > 0 && end < size; end -= end & -end)
			result += bit[end];
		return result;
	}

	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}

	int point_query(int pos) {
		int result = 0;
		for (++pos; pos > 0; pos -= pos & -pos)
			result += bit[pos];
		return result;
	}

	void add(int end, int incr) {
		for (++end; end < size; end += end & -end)
			bit[end] += incr;
	}

	void range_add(int start, int end, int incr) {
		add(start, incr);
		add(end +1, -incr);
	}

	
	void print() {
	for( int i : bit ) cout << " " << i;
	cout << endl; 
	return;
	}
};  // */

int casesT, sizeN, updatesU, startL, endR, valueV, queriesQ, query;

int main() {
	scanf("%d", &casesT);
	//cout << "casesT " << casesT << endl;

	for(int i=1; i <= casesT; i++){
		scanf("%d%d", &sizeN, &updatesU);
		//cout <<"n "<< sizeN <<"\tu "<< updatesU <<endl;

		FenwickTree arr = FenwickTree(sizeN);

		for(int i = 0; i < updatesU; i++) {
			scanf("%d%d%d", &startL, &endR, &valueV);
			//cout <<"l "<< startL <<"\tr "<< endR <<"\tv "<< valueV <<endl;

			arr.range_add(startL, endR, valueV);
		}

		scanf("%d", &queriesQ);
		//cout <<"q "<< queriesQ << endl;

		while(queriesQ--) {
			scanf("%d", &query);
			//cout << query << " -> ";

			printf("%d\n", arr.point_query(query));
		}


	}

}


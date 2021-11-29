#include <cstdio>
#include <cstring>

#define MAX 100009

using namespace std;

long long bit0[MAX], bit1[MAX];  // binary indexed tree
int size;

void FenwickTree(int n) {
	size = n + 1;
	memset(bit0, 0, size + 2);
	memset(bit1, 0, size + 2);
}

void add(long long bit[], int end, int incr) {
	while(end <= size) {
		bit[end] += incr;
		end += end & -end;
	}
}

void range_add(int start, int end, int incr) {
	add(bit0, start, incr);
	add(bit0, end +1, -incr);
	add(bit1, start, incr *(start -1));
	add(bit1, end +1, -incr *end);
}

long long sum(long long bit[], int end) {
	long long result = 0;
	while(end > 0){
		result += bit[end];
		end -= end & -end;
	}
	return result;
}

long long prefix_sum(int pos) {
	return sum(bit0, pos) *pos - sum(bit1, pos);
}

long long range_sum(int start, int end) {
	return prefix_sum(end) - prefix_sum(start -1);
}

int casesT, sizeN, commandsC, startP, endQ, valueV, queryQ, command;

int main() {
	scanf("%d", &casesT);
	//cout << "t " << casesT << endl;

	for(int i=1; i <= casesT; i++){
		scanf("%d%d", &sizeN, &commandsC);
		//cout <<"n "<< sizeN <<"\tc "<< commandsC <<endl;

		FenwickTree(sizeN);

		for(int i = 0; i < commandsC; i++) {
			scanf("%d", &command);
			//cout << command << endl;

			if(!command) {
				scanf("%d%d%d", &startP, &endQ, &valueV);
				//cout <<"l "<< startP <<"\tr "<< endQ <<"\tv "<< valueV <<endl;

				--startP; --endQ;
				range_add( startP, endQ, valueV);
			} else {
				scanf("%d%d", &startP, &endQ);
				//cout << startP <<" "<< endQ << " -> ";

				--startP; --endQ;
				printf("%lld\n", range_sum( startP, endQ));
			}
		}
	}

}


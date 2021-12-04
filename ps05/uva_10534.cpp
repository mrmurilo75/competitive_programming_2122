#include <iostream>
#include <cstring>
#include <list>

#define MAX 10009

#define ABOVE 0
#define BELLOW 1

#define max(a, b) ((a < b)? b : a)
#define min(a, b) ((a < b)? a : b)
#define key(a) (*a).first
#define value(a) (*a).second

using namespace std;

int bs_ceiling(long long value[], int start, int end, long long target) {
	while (end - start > 1) {
		int pos = start + (end - start) / 2;
		if (value[pos] >= target)
			end = pos;
		else
			start = pos;
	}

	return end;
}



long long normal[MAX], reverse[MAX], tail[MAX];
int sizeN, count[2][MAX];

void LIS(long long value[], int size, int placing) {
	memset(tail, 0, sizeof tail);
	int t_size = 1;

	tail[0] = value[0];
	for (int i = 1, res; i < size; i++) {
		res = i;

		if (value[i] < tail[0]) {
			res = 0;
			tail[0] = value[i];
		}

		else if (value[i] > tail[t_size - 1]) {
			res = t_size;
			tail[t_size++] = value[i];
		}

		else
			tail[ (res = bs_ceiling(tail, -1, t_size - 1, value[i])) ] = value[i];

		if( placing == ABOVE )
			count[placing][i] = res +1;
		else
			count[placing][size-1 -i] = res +1;

	}

}

int main() {

	for(cin >> sizeN; cin.good(); cin >> sizeN) {
		//cout << "n " << sizeN <<endl;

		int result =0, waivo =0, i;

		memset(count, 0, sizeof count);
		count[ABOVE][0] = 1;
		count[BELLOW][0] = 1;

		for(i = 0; i < sizeN; i++) {
			cin >> normal[i];
			//cout << i <<" - "<< normal[i] << endl;
			reverse[sizeN-1 -i] = normal[i];

		}

		LIS(normal, sizeN, ABOVE);

		//cout << "BELLOW" << endl;
		LIS(reverse, sizeN, BELLOW);

		//cout << "result" <<endl;
		for(int i=0; i<sizeN; i++) { // get maximum waivo from results
			auto ceiling = count[ABOVE][i], floor = count[BELLOW][i];
			//cout << i <<"\t"<< ceiling <<"\t"<< floor <<"\t";

			waivo = min(ceiling, floor);
			result = max(result, (2* waivo -1) );
			//cout <<"= "<< result <<endl;
		}

		cout << result << endl;
	}
}


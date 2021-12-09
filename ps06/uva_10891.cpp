#include <iostream>
#include <cstring>
#include <limits.h>

#define MAX_SIZE 109
#define LEFT       0
#define RIGHT      1
#define PLAYERA    1
#define PLAYERB  (-1)
#define SUM        0
#define COUNT      1

#define pl(i)      ( ((i) == PLAYERA)? plA : plB )
#define absi(a)    ( ((a) > 0)? (a) : -(a) )


using namespace std;

int sizeN, i, start, endi, res_count_l, res_count_r;
long long arr[MAX_SIZE], result[MAX_SIZE][MAX_SIZE][2][2], plA, plB, sum_l, sum_r;

long long calculate(int * res_count, int start, int end, int side) {
	cout << "calculate( \t" << *res_count <<"\t"<< start <<"\t"<< end <<"\t"<< side << endl;
	int count =0;
	long long cur_sum =0, res =LLONG_MIN;

	if(start == end-1) {
		*res_count = result[start][end][side][COUNT] = 1;
		return result[start][end][side][SUM] = arr[start];
	}

	if(side == LEFT) {
		for(int i =0; i < end; i++) { 
			cur_sum += arr[start +i];
			if(cur_sum > res) {
				res = cur_sum;
				count = i+1;
			}
			result[start][start +i+1][side][SUM] = res;
			result[start][start +i+1][side][COUNT] = count;
			cout << "   res["<< start <<"]["<< start +i+1 <<"]["<< side <<"] = " << res <<" "<< count <<endl;
		}
	} else {
		for(int i =0; start+i < end; i++) {
			cur_sum += arr[end-1 -i];
			if(cur_sum > res) {
				res = cur_sum;
				count = i+1;
			}
			result[end-1 -i][end][side][SUM] = res;
			result[end-1 -i][end][side][COUNT] = count;
			cout << "   res["<< end-1 -i <<"]["<< end <<"]["<< side <<"] = " << res <<" "<< count <<endl;
		}
	}

	*res_count = count;
	return res;
}

long long get_sum(int * res_count, int start, int end, int side) {
	cout << "get_sum(\t" <<"\t"<< start <<"\t"<< end <<"\t"<< side << endl;
	if(result[start][end][side][COUNT]) { // COUNT != 0;
		cout << "   res["<< start <<"]["<< end <<"]["<< side <<"] = " << result[start][end][side][SUM] <<" "<< result[start][end][side][COUNT] <<endl;

		*res_count = result[start][end][side][COUNT];
		return result[start][end][side][SUM];
	}

	result[start][end][side][SUM] = calculate(res_count, start, end, side);
	result[start][end][side][COUNT] = *res_count;

	cout << "   res["<< start <<"]["<< end <<"]["<< side <<"] = " << result[start][end][side][SUM] <<" "<< result[start][end][side][COUNT] <<endl;

	return result[start][end][side][SUM];
}


int main() {

	for(cin >> sizeN; sizeN > 0; cin >> sizeN) {
		cout << sizeN << endl;

		for(i=0; i<sizeN; i++) {
			cin >> arr[i];
			cout << " " << arr[i];
		}
		cout << endl;

		memset(result, 0, sizeof result);

		plA =0; plB =0;
		start = 0; endi = sizeN;

		cout << " play "<< endl;
		//int limiter = 10 ;
		//for( i=PLAYERA; start < endi && limiter-- ; i*=(-1) ) {
		for( i=PLAYERA; start < endi; i*=(-1) ) {
			res_count_l =0;
			res_count_r =0;
			sum_l = get_sum(&res_count_l, start, endi, LEFT);
			cout << "\tsum_l\t= " << sum_l << " " << res_count_l << endl;

			sum_r = get_sum(&res_count_r, start, endi, RIGHT);
			cout << "\tsum_r\t= " << sum_r << " " << res_count_r << endl;

			if(sum_l > sum_r) {
				start += res_count_l;
				pl(i) += sum_l;
				cout << "PL "<<i<<" += " << sum_l <<" = "<< pl(i) <<endl;
			} else {
				endi -= res_count_r;
				pl(i) += sum_r;
				cout << "PL "<<i<<" += " << sum_r <<" = "<< pl(i) <<endl;
			}

		}

		cout << absi( plA - plB ) << endl;
	}

}


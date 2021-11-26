#include <iostream>
#include <cstring>

#define MAX_SIZE 104

using namespace std;

int n_size, n_arr[MAX_SIZE][MAX_SIZE], sum_arr[MAX_SIZE][MAX_SIZE];

int main(){
	cin >> n_size;
	//cout << n_size << endl;

	memset(n_arr, 0, (n_size+2)*(n_size+2));
	memset(sum_arr, 0, (n_size+2)*(n_size+2));

	for(int i=1; i<= n_size; i++) {
		for(int j=1; j<= n_size; j++) {
			cin >> n_arr[i][j];
			//cout <<"\t"<<i<<"\t"<<j<<"\n"<< n_arr[i][j] << "\t";
			sum_arr[i][j] = n_arr[i][j] + sum_arr[i-1][j] + sum_arr[i][j-1] - sum_arr[i-1][j-1];
			//cout << sum_arr[i][j] << endl;
		}
	}

	long result = sum_arr[1][1], best = sum_arr[1][1];
	//cout << "b\tr\ta\tb\tc\td\n" ;
	for(int a=1; a<= n_size; a++) {
		for(int b=1; b<= n_size; b++) {
			for(int c=a+1; c<= n_size; c++) {
				for(int d=b+1; d<=n_size; d++) {
					result = sum_arr[c][d] - sum_arr[a-1][d] - sum_arr[c][b-1] + sum_arr[a-1][b-1];
					if(result ==0 && best >=0) break;
					if(result > best) best = result;
					//cout << best <<"\t"<< result <<"\t"<< a <<"\t"<< b <<"\t"<< c <<"\t"<< d << endl;
				}
			}
		}
	}

	cout << best << endl;

}


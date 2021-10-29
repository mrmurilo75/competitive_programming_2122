#include <iostream>
#include <set>

using namespace std;

int main(){
	int n_days;
	for(cin >> n_days; n_days; cin >> n_days) {
		//cout << "n_days " << n_days << endl;
		multiset<int> urn;
		long long result = 0;
		while(n_days--) {
			int bills_of_day;
			cin >> bills_of_day;
			//cout << "bills_of_day " << bills_of_day << endl;
			while(bills_of_day--) {
				int cur;
				cin >> cur;
				//cout << "\t" << cur << endl;
				urn.insert(cur);
				//cout << "size " << urn.size() << endl;
				//for(auto it : urn)
					//cout << " " << it;
				//cout << endl;
			}
			multiset<int>::iterator high_bill = --(urn.end()), low_bill = urn.begin();
			if(low_bill != urn.end() && high_bill != urn.end()) {
				//cout << *high_bill << " - " << *low_bill << endl;
				result += *(high_bill) - *(low_bill); // no need to safe check against .end() bc of problem garantee
				urn.erase(high_bill);
				urn.erase(low_bill);
			} else {
				//cout << "end()" << endl;
				continue;
			}
		}
		cout << result << endl;
	}
}


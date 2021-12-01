#include <iostream>
#include <cstring>

#define TEXT_MAX 104
#define WORD_MAX 32


using namespace std;

char prop1[TEXT_MAX][WORD_MAX];
char cur_word[WORD_MAX];
char delim[] = "#";

int main(){
	for(cin >> prop1[0]; cin.good(); cin >> prop1[0]) {
		memset(prop1, 0, sizeof prop1);
		memset(cur_word, 0, sizeof cur_word);

		int i =1;
		for(cin >> prop1[i]; strcmp(prop1[i-1], delim) && cin.good(); ++i && cin >> prop1[i]) {
			cout << prop1[i] << endl;
		}
		cout << " ----------------- " << endl;
		
/*
		read_word();
		check_word_in();
		if in: copy to arra words
			/* for prop2 in reverse_order:
			 * 	get_count_of_seq()

// */
	}

}


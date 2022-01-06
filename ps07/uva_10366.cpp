#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <stack>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

int N, W, H;
char states[1024][1024];
char states[1024][1024];

bool sort_states(pair<char, int> a, pair<char, int> b){
    return (a.second == b.second)? a.first<b.first : a.second>b.second;
}

void process_p(stack< pair< int, int > > &stac, pair< int, int > &p, int x, int y, char og) {
    int a = p.first+x, b = p.second+y;

    if(states[a][b] == og) {

        states[a][b] = 0;
        stac.emplace(a, b);
    }
}

void print_state() {
    for(int i=0; i<=H+1; i++) {
        for(int j=0; j<=W+1; j++) {
            if(states[i][j] == 0)
                cout << "0 ";
            else
                cout << states[i][j] << " ";
        }
        cout << endl;
    }
}

void print_count(vector< pair<char, int> > &count) {
    for(int i=0; i<26; i++)
        printf("%c ", 'a' +i);
    for(int i=0; i<26; i++)
        printf("%d ", (count[i]).second );
}

int main() {
    memset(states,      0, sizeof states);

    scanf("%d", &N);
    for(int n=1; n<=N; n++) {
        scanf("%d%d ", &H, &W);
        cout<<H<<" "<<W<<endl;

        for(int i=1; i<=H; i++) 
            for(int j=1; j<=W; j++) 
                cin >> states[i][j];

        print_state();

        vector< pair<int, char> > hash_count(26);
        for(int i=0; i<26; i++)
            hash_count[i] = make_pair('a'+i, 0);

        print_count(hash_count);

        stack< pair<int, int> > stac;

        // printf("i j \tstate \n");
        for(int i=1; i<=H; i++) {
            for (int j=1; j<=W; j++) {
                // printf("ff %d %d \t%c\t%d\n", i, j, states[i][j]);

                if (!states[i][j])
                    continue;

                (hash_count[ states[i][j] -'a' ]).second += 1;
                print_count(hash_count);

                stac.emplace(i, j);
                char og = states[i][j];
                states[i][j] = 0;

                while (!stac.empty()) {
                    pair<int, int> p = stac.top();
                    stac.pop();

                    cout << "processing " << og << endl;
                    print_state();
                    print_count(hash_count);

                    process_p(stac, p, -1,  0, og);
                    process_p(stac, p,  1,  0, og);
                    process_p(stac, p,  0,  1, og);
                    process_p(stac, p,  0, -1, og);
                }

            }
        }

        printf("World #%d\n", n);

        sort(hash_count.begin(), hash_count.end(), sort_states);

        // printf("%d\n", hash_count.size());

        for(int i=0; i<26; i++) {
            pair< int, int > p = hash_count[i];

            if(p.second == 0)
                break;

            printf("%c: %d\n", p.first, p.second);
        }

    }

}

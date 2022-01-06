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
bool visited[1024][1024];

bool sort_states(pair<char, int> a, pair<char, int> b){
    return (a.second == b.second)? a.first<b.first : a.second>b.second;
}

int main() {
    memset(states, 0, sizeof states);
    memset(visited, 0, sizeof visited);

    scanf("%d", &N);
    for(int n=1; n<=N; n++) {
        scanf("%d%d ", &H, &W);
        // cout<<H<<" "<<W<<endl;

        for(int i=1; i<=H; i++) {
            for(int j=1; j<=W; j++) {
                cin >> states[i][j];

                // cout << states[i][j] << " ";
            }
            // cout << endl;
        }

        vector< pair<int, char> > hash_count(26);
        for(int i=0; i<26; i++)
            hash_count[i] = make_pair('a'+i, 0);


        stack< pair<int, int> > stac;

        // printf("i j \tstate\tvisited \n");
        for(int i=1; i<=H; i++) {
            for (int j=1; j<=W; j++) {
                // printf("ff %d %d \t%c\t%d\n", i, j, states[i][j], visited[i][j]);

                if (states[i][j] && !visited[i][j]) {
                    (hash_count[ states[i][j] -'a' ]).second += 1;

                    stac.emplace(i, j);
                    visited[i][j] = true;

                    while (!stac.empty()) {
                        pair<int, int> p = stac.top();
                        stac.pop();

                        for(int s=-1; s<=1; s+=2) {
                            int a = p.first+s, b = p.second;

                            if(states[a][b] && 
                                    !visited[a][b] && 
                                    states[a][b] == states[p.first][p.second]) {

                                visited[a][b] = true;
                                stac.emplace(a, b);
                            }
                        }
                        for(int s=-1; s<=1; s+=2) {
                            int a = p.first, b = p.second+s;

                            if(states[a][b] && 
                                    !visited[a][b] && 
                                    states[a][b] == states[p.first][p.second]) {

                                visited[a][b] = true;
                                stac.emplace(a, b);
                            }
                        }
                    }

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

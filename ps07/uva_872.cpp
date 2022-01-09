#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

map< char, set<char> > constraints;
set<char> variables;
vector< string > results;

// do a recursive DFS keeping tabs if all constraints have been met (when we add a letter we remove if from the constraints lists where applicable, if there are no constraints recursive DFS)
void dfs(string s, set<char> &remaining, map<char, set<char> > &constraints) {
    // cout << s << endl;
    // cout << "re: "; for(char var : remaining) // cout << var << " ";
    // cout << endl;
    if(remaining.empty()) {
        results.emplace_back();
        for(int i=variables.size()-1; i>0; i--) {
            results.back() += s[i];
            results.back() += " ";
        }
        results.back() += s[0];

        return;
    }

    set<char> remaining_case;
    map<char, set<char> > constraints_case;

    for(char var : remaining) {
        // cout << var << " ";
        if(constraints[var].empty()) {
            remaining_case = remaining;

            auto it = remaining_case.find(var);
            if(it == remaining_case.end()) // aka not found
                continue;

            char val = *it;
            remaining_case.erase(val);

            constraints_case = constraints;
            for(char a : remaining) {
                constraints_case[a].erase(var);
            }
            dfs(s + var, remaining_case, constraints_case);

        }
    }
    // cout << "end" << endl;
}

int main(){

    int N;
    scanf("%d", &N);
    // cout << N << endl;
    getchar();

    while(N--) {
        getchar();

        variables.clear();
        for(int i=0; i<26; i++)
            constraints['A'+i].clear();
        results.clear();

        char a, b, c;
        do{ 
            scanf("%c%c", &a, &b);
            // cout << a << b;

            if(a>='A' && a<='Z')
                variables.emplace(a);
        } while (b != '\n');

        do{ 
            scanf("%c<%c%c", &a, &b, &c);
            // cout << a <<"<"<< b << c;

            if(a>='A' && a<='Z')
                constraints[a].insert(b);
        } while( c != '\n');


        dfs("", variables, constraints);

        sort(results.begin(), results.end());

        for(string s : results) {
            cout << s << "\n";
        }
        if(results.empty())
            cout << "NO\n";

        if(N) cout << endl;

    }

}


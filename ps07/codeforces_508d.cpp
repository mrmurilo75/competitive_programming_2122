/*
 * This was a especially difficult one for me, so I need the help of a friend who helped me develop this code based on his previous answer.
 * 
 * */

#include <iostream>
#include <cstdio>

#define IN_POSSIBLE (26+26+10)

#define MAX_IN (200009)


int N;
char s[4];
int bit_index_mapping[MAX_IN], size=0; 
int in_count[MAX_IN], out_count[MAX_IN];

int pre[MAX_IN]={0}, next[MAX_IN]={0}, edge[MAX_IN];

int ans[MAX_IN], answer_total=0, stack[MAX_IN], stack_pos=0;

void add_edge(int u,int v) {
	edge[++size] = v;
	next[size] = pre[u];
	pre[u] = size;
}


int hash_index(char a) {
	if(a>='a' && a<='z') 
        return a-'a' +1;
	if(a>='A' && a<='Z') 
        return a-'A' +27;
	else 
        return a-'0' +26*2+1;	
}

int make_index(char a, char b) {
	return hash_index(a)*63 + hash_index(b);
}

void dfs(int x) {
	for(int p = pre[x]; p; p=next[p]) {
		int v = edge[p];
		pre[x] = next[p];
		stack[++stack_pos] = v; 
		dfs(v);
		return;
	}
}

void fleury(int start) {
    // check if we meet the parity requirements
	int last_index = make_index('9','9');
	int case_out = 0, case_in = 0;
	for(int i=1; i < last_index+1; i++) {
		int parity = in_count[i] - out_count[i];

        if(parity == 0)
            continue;

		if(parity == 1) {
            case_in++;
            continue;
        }
		if(parity == -1) {
            case_out++;
            start=i;
            continue;
        }

        std::cout << "NO" << std::endl;
        return;
	}

    // process
	if ((case_in == 0 && case_out == 0) || (case_in == 1 && case_out == 1)) {
        stack[++stack_pos]=start;
        while (stack_pos) {
            int x=stack[stack_pos];
            if (pre[x]) dfs(x);
            else
            {
                ans[++answer_total]=x;
                stack_pos--;
            }
        }
        
        if (answer_total^(N+1)) {
            std::cout<<"NO\n";
            return;
        }
        std::cout<<"YES\n";
        for(int i=answer_total;i;i--) {
            printf("%c",bit_index_mapping[ans[i]/63]);
        }
        printf("%c\n",bit_index_mapping[ans[1]%63]);

        return;
    }

    std::cout << "NO" << std::endl;
} 

int main() {

    // fill bit_index_mapping
	for(int i='a'; i<='z'; i++) 
        bit_index_mapping[i-'a' +1]=i;
	for(int i='A'; i<='Z'; i++) 
        bit_index_mapping[i-'A' +27]=i;
	for(int i='0'; i<='9'; i++) 
        bit_index_mapping[i-'0' +1+26+26]=i;

    scanf("%d", &N);

	int start=0;

	for(int i=1; i<=N; i++) {
        std::cin >> s;

        int index_a = make_index(s[0], s[1]);
        int index_b = make_index(s[1], s[2]);

		add_edge(index_a, index_b);

		out_count[index_a] ++;
        in_count [index_b] ++;

		start=index_a;
	}


    fleury(start);

}


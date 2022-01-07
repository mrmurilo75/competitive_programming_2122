#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

#define MAX_OUT 10000

#define units(A) (A%10)
#define tens(A) ((A%100)/10)
#define hundreds(A) ((A%1000)/100)
#define thousands(A) (A/1000)

using namespace std;

bool is_prime[MAX_OUT];
bool visited[MAX_OUT];
int parent[MAX_OUT];
int N, A, B;

bool process_digit(int A, queue<int> &q, int digit) {
    // cout <<"d "<< digit << " " << A << " " << endl;

    int p = A;

    int base = digit*10;
    A -= ((A%base)/digit)*digit;      // make digit 0


    for(int i=0; i<10; ++i, A+=digit) {
            // cout <<digit*i<< "\t" << A <<endl;
        if(is_prime[A] && !visited[A]){
            visited[A] = true;
            q.emplace(A);
            parent[A] = p;

            if(A == B) return true;
        }
    }

    return false;
}

void cout_q(queue<int> q) {
    cout << " q ";
    while( !q.empty() ) {
        int cur = q.front();
        q.pop();

        printf(" > %d", cur);
    }
    printf("\n");
}

int bfs(const int count, queue<int> &q) {
    // cout << "bfs "<< count << endl;
    // cout_q(q);

    queue<int> nq;
    while( !q.empty() ) {
        int cur = q.front();
        q.pop();

        if( process_digit(cur, nq,    1) ) return count +1;
        if( process_digit(cur, nq,   10) ) return count +1;
        if( process_digit(cur, nq,  100) ) return count +1;
        if( process_digit(cur, nq, 1000) ) return count +1;

    }

    if( !nq.empty() )
        return bfs(count +1, nq);

    return 0;
}

void print_trace() {
    printf("\t%d\n", B);
    for(int cur = parent[B]; cur != A; cur = parent[cur])
        printf("\t%d\n", cur);
    printf("\t%d\n", A);

}

int main() {
    // calculate primes using Sieve of Eratosthenes (based on https://www.baeldung.com/cs/prime-number-algorithms)
    memset(is_prime, true, sizeof is_prime);
    is_prime[0] = is_prime[1] = false;
    for(int i=2; i*i<MAX_OUT; i++)
        if(is_prime[i])
            for(int j = i*i; j<=MAX_OUT; j+=i)
                is_prime[j] = false;

    // input
    scanf("%d", &N);
    cout << N << endl;
    while(N--) {
        scanf("%d%d", &A, &B);
        cout << A <<" "<< B << endl;

        // process
        memset(visited, false, sizeof visited);
        memset(visited, true, (sizeof(int))*1000);
        queue<int> q;

        visited[A] = true;
        q.emplace(A);
        parent[A] = A;

        int res = 0;

        if(A != B) {
            if( (res = bfs(0, q)) )
                print_trace();

        }

        printf("%d\n", res);

    }

}


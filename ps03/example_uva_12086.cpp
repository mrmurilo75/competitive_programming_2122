// Example solution for UVA 12086
// Pedro Ribeiro (DCC/FCUP)

#include <cstdio>
#include <cstring>

#define MAX		 200005
#define MAX_BUF 16
#define MAX_ST	800005

#define NEUTRAL 0

int n;					 // Number of elements in the segtree
int v[MAX];			// Array of values
int st[MAX_ST];	// Segtree (in this case storing interval sums)

// Merge contents of nodes a and b
int merge(int a, int b) {
	return a+b;
}

// Build initial segtree (in position pos, interval [start,end])
void build(int pos, int start, int end) {
	if (start == end) {
		st[pos] = v[start];
	} else {			
		int middle = start + (end-start)/2;
		build(pos*2, start, middle);
		build(pos*2+1, middle+1, end);
		st[pos] = merge(st[pos*2], st[pos*2+1]);
	}	
}

// Update node x to value r
void update(int pos, int start, int end, int x, int r) {
	if (start>x || end<x) return;
	if (start == end && start==x) {
		st[pos] = r;
	} else {			
		int middle = start + (end-start)/2;
		update(pos*2, start, middle, x, r);
		update(pos*2+1, middle+1, end, x, r);
		st[pos] = merge(st[pos*2], st[pos*2+1]);
	}	
}

// Make a query of interval [x,y]
int query(int pos, int start, int end, int x, int y) {
	if (start>y || end<x) return NEUTRAL;
	if (start>=x && end<=y) return st[pos];
	
	int middle = start + (end-start)/2;
	int a = query(pos*2, start, middle, x, y);
	int b = query(pos*2+1, middle+1, end, x, y);
	return merge(a, b);
}

int main() {
	char op[MAX_BUF];
	int c = 0;

	while (1) {
		scanf("%d", &n);
		if (n==0) break;
		if (c>0) putchar('\n');
		printf("Case %d:\n", ++c);
		for (int i=1; i<=n; i++) scanf("%d", &v[i]);
		
		build(1, 1, n);
		
		while (1) {
			scanf("%s", op);
			if (strcmp(op, "END")==0) break;
			int a, b;
			scanf("%d %d", &a, &b);
			if (op[0]=='M') {
	printf("%d\n", query(1, 1, n, a, b));
			} else {
	update(1, 1, n, a, b);	
			}
		}
	}
	
	return 0;
}


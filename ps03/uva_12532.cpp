#include <cstdio>
#include <vector>
#include <cstring>

template<typename Val, typename SizeOfSize>
class SegmentNode {
public:
	bool update_request;
	Val value;
	SizeOfSize range_start, range_end;
	SegmentNode parent, right, left;

	SegmentNode(SegmentNode right, SegmentNode left) {
		this.right = right;
		this.left = left;
		this.range_start = right.range_start;
		this.range_end = left.range_end;

		this.value = this.compute();
		update_request = false;
	}

	SegmentNode(SizeOfSize position, Val value) {
		this.range_start = position;
		this.range_end = position;
		this.value = value;

		this.right = nullptr;
		this.left nullptr;
		update_request = false;
	}




}

template<typename Val, typename SizeOfSize>
class SegmentTree {
public:
	SizeOfSize size;
	vector< SegmentNode<Val> > leaf_array;
	SegmentNode<Val> root;

	SegmentTree(SizeOfSize size){
		this.size = size;

		leaf_array = new vector<Val>(size);

		root = nullptr;
	}

	bool putLeaf(SizeOfSize position, Val value){
		leaf_array[position] = new SegmentNode<Val>(position, value);
	}

}


int v[MAX];	// Array of values
int st[MAX_ST];	// Segtree (in this case storing interval sums)

int merge(int a, int b) {
	return a+b;
}

void build(int pos, int start, int end) {
	if (start == end) {
		st[pos] = arr[start];
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
	int sizeN, queriesK;

	cin >> sizeN >> queriesK;

	int arr[sizeN];
	for(int i =0; i<sizeN; i++)
		cin >> arr[i];

	char seg_tree[4*sizeN];

	build(0, sizeN);

	while(queriesK){
		cin >> qType;
		if(qType[0] == 'C'){
		} else {
		}
	}
}

/*
	char op[MAX_BUF];
	int c = 0;

	scanf("%d", &sizeN);
	if (c>0) putchar('\n');
	printf("Case %d:\n", ++c);
	for (int i=1; i<=sizeN; i++) scanf("%d", &v[i]);

	build(1, 1, sizeN);

	while (1) {
		scanf("%s", op);
		if (strcmp(op, "END")==0) break;
		int a, b;
		scanf("%d %d", &a, &b);
		if (op[0]=='M') {
			printf("%d\n", query(1, 1, sizeN, a, b));
		} else {
			update(1, 1, sizeN, a, b);	
		}
	}
// */

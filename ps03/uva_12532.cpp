#include <cstdio>
#include <vector>
#include <cstring>

template<typename Val, typename SizeOfSize>
class SegmentNode {
public:
	map<SizeOfSize, Val> update_request;	// update request and value to put
	Val value;
	SizeOfSize range_start, range_end;
	SegmentNode parent, right, left;

	SegmentNode(SegmentNode left, SegmentNode right) {
		this.left = left;
		this.right = right;
		this.range_start = left.range_start; 	// build top to bottom, so left is smaller
		this.range_end = right.range_end;

		this.value = this.compute(left.value, right.value);
		update_request = nullptr;
	}

	SegmentNode(SizeOfSize position, Val value) {
		this.range_start = position;
		this.range_end = position;
		this.value = value;

		this.left nullptr;
		this.right = nullptr;
		update_request = nullptr;
	}

	Val compute(Val a, Val b) {
		return a * b; 		// process
	}

	SegmentNode<Val, SizeOfSize> buildParent(SegmentNode<Val, SizeOfSize> left) {
		return ( this.parent = right.parent = new SegmentNode<Val, SizeOfSize>(left, this) );
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

		// create tree
		queue<SegmentNode> nodeQ[2];

			// second layer created as leaf are inputed
		if(position % 2 && position) {		// making top to bottom, so even numbers are is right
			nodeQ[0].push( leaf_array[position].buildParent(leaf_array[position-1]) );
		}
			// other layers are create on last leaf input [ OBS.: this can be optimized using recursion to create upper layer as leafs are input, and it is garanteed that there will be more leafs than height (2^n > n, duh) but too complicateds ]
		if(position == size-1) {
			if(! (position % 2) )
				nodeQ[0].push( leaf_array[position] );

			char cur = 1, next_layer = 0;
			int qSize, s;
			while( (qSize = nodeQ[next_layer].size()) && qSize != 1 ) {	// cur is garanteed to be empty, if next_layer is only one node it is root
				next_layer = cur;
				cur = 1-cur;
				while( (qSize = nodeQ[cur].size()) ) {
					if(qSize == 1) { 
						nodeQ[next_layer].push(nodeQ[cur].front());
						nodeQ[cur].pop();
						break;
					}
					auto left = nodeQ[cur].front(); nodeQ[cur].pop();
					auto right = nodeQ[cur].front(); nodeQ[cur].pop();
					nodeQ[next_layer].push( leaf_array[position].buildParent(leaf_array[position-1]) );
				}
			}
			this.root = nodeQ[next_layer].front();
		}

	}

	void printLeveld() {
		// print each level on a line

##CONTINUE

	}
	
	bool build(){
	}

	void update(SizeOfSize position, Val new_value) {
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

	SegmentTree<char, int> seg_tree(sizeN);
	for(int i =0; i<sizeN; i++) {
		char input;
		cin >> input;

		if(input) input = ( (input>0)? 1 : -1 );	// input processing

		seg_tree.putLeaf(i, input);
	}
	
	seg_tree.build();

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
 * Note: 
 * 	Lazy updates
 * 	Put a update_pair on root; // each update_pair is <position, new_value>
 * 	when on a query, check if range bounds ceiling/floor are in the update map
 * 	if yes, then you gotta go down and update and so on
 * 	if no, then move update_map into the node that you are NOT descending (and reset this.update_map = nullpttr)
 *
// */

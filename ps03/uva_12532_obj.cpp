#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

template<typename Val, typename SizeOfSize>
class SegmentNode {
public:
	// map<SizeOfSize, Val> update_request;	// update request and value to put
	Val value;
	SizeOfSize range_start, range_end;
	SegmentNode<Val, SizeOfSize> *parent, *right, *left;

	SegmentNode(SizeOfSize start, SizeOfSize end) {
		left = nullptr;
		right = nullptr;
		range_start = start; 	// build top to bottom, so left is smaller
		range_end = end;

		value = compute(left->value, right->value);
	//	update_request = nullptr;
		parent = nullptr;

		cout << "create Node ( ["<< left->range_start << ", " << right->range_end << "] ) = " << (int)value << endl;
	}

	SegmentNode(SegmentNode *left, SegmentNode *right) {
		this->left = left;
		this->right = right;
		range_start = left->range_start; 	// build top to bottom, so left is smaller
		range_end = right->range_end;

		value = compute(left->value, right->value);
	//	update_request = nullptr;
		parent = nullptr;

		cout << "create Node ( ["<< left->range_start << ", " << right->range_end << "] ) = " << (int)value << endl;
	}

	SegmentNode(SizeOfSize position, Val value) {
		range_start = position;
		range_end = position;
		this->value = value;

		left = nullptr;
		right = nullptr;
		parent = nullptr;
	//	update_request = nullptr;

		cout << "create Node ( "<<position<< " )"<< endl;
	}

	Val compute(Val a, Val b) {
		return a * b; 		// process
	}

	SegmentNode<Val, SizeOfSize>* buildParent(SegmentNode<Val, SizeOfSize> *left) {
		cout << " buildParent { ";
		return ( this->parent = ( left->parent = new SegmentNode<Val, SizeOfSize>(left, this) ) );
	}

	string print() {
		cout << "(["<< range_start <<" "<< range_end <<"] "<< (int)value <<")";
		return "";
	}


};
/*
int main(){
	SegmentNode<char, int> *seg_l = new SegmentNode<char, int>(0, 10);
	SegmentNode<char, int> *seg_r = new SegmentNode<char, int>(1, 100);
	SegmentNode<char, int> *seg_ = new SegmentNode<char, int>(seg_l, seg_r);
}
// */


template<typename Val, typename SizeOfSize>
class SegmentTree {
public:
	SizeOfSize size;
	vector< SegmentNode<Val, SizeOfSize>* > *leaf_array;
	SegmentNode<Val, SizeOfSize> *root;

	SegmentTree(SizeOfSize size){
		cout << "create Tree ( "<< size << " )"<< endl;
		this->size = size;

		leaf_array = new vector< SegmentNode<Val, SizeOfSize>* >(size);

		root = nullptr;
	}

	queue< SegmentNode<Val, SizeOfSize>* > nodeQ[2];
	void putLeaf(SizeOfSize position, Val value){
		cout << "put Leaf ( "<< position << ", " << (int)value << " )"<< endl;
		(*leaf_array)[position] = new SegmentNode<Val, SizeOfSize>(position, value);

		/*
		// create tree

			// second layer created as leaf are inputed
		if(position % 2 && position) {		// making top to bottom, so even numbers are is right
			nodeQ[0].push( (*leaf_array)[position]->buildParent((*leaf_array)[position-1]) );
			cout << " = " << (nodeQ[0].back())->print() << endl;
		}
			// other layers are create on last leaf input [ OBS.: this can be optimized using recursion to create upper layer as leafs are input, and it is garanteed that there will be more leafs than height (2^n > n, duh) but too complicateds ]
		if(position == size-1) {
			if(! (position % 2) )
				nodeQ[0].push( (*leaf_array)[position] );

			char cur = 1, next_layer = 0;
			int qSize;
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
					nodeQ[next_layer].push( left->buildParent(right) );
				}
			}
			this->root = nodeQ[next_layer].front();

			printLeveld();
		}
		// */


	}

	void build() {
		root = new SegmentNode<Val, SizeOfSize>(0, size);
		_build_merge(root);
	}

	SegmentNode<Val, SizeOfSize>* _build_merge(SegmentNode<Val, SizeOfSize>* node) {
		SizeOfSize start = node->range_start, end = node->range_end, middle = start + (end - start)/2;
		if(start == end)

		
	}

	void printLeveld() {
		// print each level on a line
		queue< SegmentNode<Val, SizeOfSize>* > nodeQ[2];
		char next_layer = 0, cur = 1;

		nodeQ[next_layer].push(root);

		while( !nodeQ[next_layer].empty() ) {
			next_layer = cur;
			cur = 1-cur;

			while( !nodeQ[cur].empty() ) {
				auto node = nodeQ[cur].front();
				nodeQ[cur].pop();
				if(!node)
					cout << "([n,n],n) ";
				else {
					cout << node->print() << " ";

					nodeQ[next_layer].push(node->left);
					nodeQ[next_layer].push(node->right);
				}
			}
			cout << endl;
		}
	}
	
	void update(SizeOfSize position, Val new_value) {
	}

};

/*

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
// */
//*
int main() {
	int sizeN, queriesK;

	cin >> sizeN >> queriesK;
	cout << sizeN << " " << queriesK << endl;

	SegmentTree<char, int> seg_tree(sizeN);
	for(int i =0; i<sizeN; i++) {
		int input;
		cin >> input;
//		cout << " in: " << input << endl;

		if(input)
			input = ( (input>0)? 1 : -1 );	// input processing

		seg_tree.putLeaf(i, (char)input);
	}
/*
	while(queriesK){
		cin >> qType;
		if(qType[0] == 'C'){
		} else {
		}
	}
} // */
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

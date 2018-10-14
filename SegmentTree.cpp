//Efiicient Segment Tree with only 2*n space
#define lli long long int
const int Max_N = 100000;

class seg_tree {
public:
	vector<lli> tree;
	int n;
	void build(vector<lli> arr) {
		n = arr.size();
		tree.resize(2 * Max_N);
		//leaf nodes
		for (int i = 0; i < n; i++) {
			tree[n + i] = arr[i];
		}
		//for parents
		for (int i = n - 1; i > 0; --i) {
			lli leftChild = tree[i<<1];// i<<1 == 2*i
			lli rightChild = tree[i<<1 | 1]; //i<<1|1 == 2*i+1
			tree[i] = leftChild + rightChild;
			
		}
	}
	void updateTreeNode(int p, int value){
		// set value at position p
		tree[p + n] = value;
		p = p + n;
		// move upward and update parents
		for (int i = p; i > 1; i >>= 1)
			tree[i >> 1] = tree[i] + tree[i ^ 1];
	}
	lli query(int l, int r)
	{
		lli res = 0;
		// loop to find the sum in the range
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1)res += tree[l++];
			if (r & 1)res += tree[--r];
		}
		return res;
	}
	
};

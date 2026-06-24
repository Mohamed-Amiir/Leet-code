class NumArray {
public:
    vector<int> tree;
    vector<int> nums;
    int n;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();

        tree.resize(4 * n);

        build(1, 0, n - 1);
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = nums[start];
            return;
        }

        int mid = (start + end) / 2;

        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void updateTree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;

        if (idx <= mid)
            updateTree(2 * node, start, mid, idx, val);
        else
            updateTree(2 * node + 1, mid + 1, end, idx, val);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    int query(int node, int start, int end, int left, int right) {
        if (right < start || left > end)
            return 0;

        if (left <= start && end <= right)
            return tree[node];

        int mid = (start + end) / 2;

        return query(2 * node, start, mid, left, right) +
               query(2 * node + 1, mid + 1, end, left, right);
    }


    void update(int index, int val) { updateTree(1, 0, n - 1, index, val); }

    int sumRange(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }
};
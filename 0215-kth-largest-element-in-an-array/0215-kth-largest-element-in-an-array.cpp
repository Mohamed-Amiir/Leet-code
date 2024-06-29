class Solution {
public:


int findKthLargest(vector<int>& nums,int pos) {
	priority_queue<int> que;
	for (auto x: nums)
		que.push(x);
	for (int i = 0; i < pos-1; i++) {
		que.pop();
	}
	return que.top();

}
};
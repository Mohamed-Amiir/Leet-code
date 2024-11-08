class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        k = nums.size() - k;
        queue<int>q;
        for (int i = 0; i < nums.size(); i++)
        {
            q.push(nums[i]);
        }
        while (k--) {
            q.push(q.front());
            q.pop();
        }
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = q.front();
            q.pop();
        }
    }

};
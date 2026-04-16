class Solution {
public:
    int bs(vector<int>& input, int& x) {
        int left = 0, right = input.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (input[mid] == x)
                return mid;
            else if (input[mid] > x)
                right = mid-1;
            else
                left = mid+1;
        }
        return -1;
    }
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mp;
        vector<int> result;
        int s = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        for (int x : queries) {
            int n = mp[nums[x]].size();
            vector<int> indc = mp[nums[x]];
            if (n <= 1)
                result.push_back(-1);
            else {
                int next, prev;
                int j = bs(indc,x);
                next = indc[(j + 1) % n];
                prev = indc[((j - 1) + n) % n];
                int nsteps = (next - x + s) % s;
                int psteps = (x - prev + s) % s;
                result.push_back(min(nsteps, psteps));
            }
        }
        return result;
    }
};
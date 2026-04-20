class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size(),result = -1;;
        for (int i = 0; i < n; i++) {
            if(i > 0 && colors[i] == colors[i-1])continue;
            for (int j = n - 1; j >= i; j--) {
                if (colors[i] != colors[j])
                    result = max(result,abs(i - j));
            }
        }
        return result;
    }
};
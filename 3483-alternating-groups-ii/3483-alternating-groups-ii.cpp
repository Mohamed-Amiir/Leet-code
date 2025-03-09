#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int mod(int a, int b) {
        return (a % b + b) % b;
    }

    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        vector<int> valid(n);
        for (int i = 0; i < n; ++i) {
            int next = (i + 1) % n;
            valid[i] = (colors[i] != colors[next]) ? 1 : 0;
        }
        
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + valid[i];
        }
        
        unordered_map<int, bool> visited;
        int result = 0;
        int l = 0;
        int i = 0;
        while (true) {
            if (visited[i])
                break;
            visited[i] = true;
            
            int end = l + k - 2;
            int sum;
            if (end < n) {
                sum = prefix[end + 1] - prefix[l];
            } else {
                int end_mod = end % n;
                sum = (prefix[n] - prefix[l]) + (prefix[end_mod + 1] - prefix[0]);
            }
            if (sum == k - 1) {
                result++;
            }
            
            i = (i + 1) % n;
            l = (l + 1) % n;
        }
        return result;
    }
};
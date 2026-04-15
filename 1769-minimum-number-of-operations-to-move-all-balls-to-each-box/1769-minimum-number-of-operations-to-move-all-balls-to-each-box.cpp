class Solution {
public:
    vector<int> minOperations(string boxes) {
        int s = boxes.size();
        vector<int> result;
        for (int i = 0; i < s; i++) {
            int r = 0;
            for (int j = 0; j < s; j++) {
                if(boxes[j] == '1')
                   r += abs(i-j);
            }
            result.push_back(r);
        }
        return result;
    }
};
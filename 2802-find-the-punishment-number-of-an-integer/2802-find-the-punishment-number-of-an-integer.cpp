class Solution {
public:
void partitionDigits(vector<int>& digits, int index, vector<int>& current, vector<vector<int>>& result) {
    if (index == digits.size()) {  // Base case: all digits are used
        result.push_back(current);
        return;
    }

    int num = 0;  // Store the number as an integer
    for (int i = index; i < digits.size(); ++i) {
        num = num * 10 + digits[i];  // Form number using digits
        
        current.push_back(num);  // Add the number as a partition
        partitionDigits(digits, i + 1, current, result);  // Recur for next parts
        current.pop_back();  // Backtrack
    }
}

vector<vector<int>> getAllPartitions(vector<int>& digits) {
    vector<vector<int>> result;
    vector<int> current;
    partitionDigits(digits, 0, current, result);
    return result;
}

    bool solve(int x) {
        if(x == 1)return true;
        // cout << "NUMBER " << x <<endl; 
        long long y = x * x;
        vector<int> digits, p;
        while (y > 0) {
            int temp = y % 10;
            y = y / 10;
            digits.push_back(temp);
        }

        int n = digits.size();
        reverse(digits.begin(), digits.end()); // Correct the order of digits
        vector<vector<int>> partitions = getAllPartitions(digits);
        for (auto p : partitions) {
            int total = 0;
            for(auto pp : p){
               total += pp;
            }
            if(total == x) return true;
        }
        
        return false;
    }

    int punishmentNumber(int n) {
        int result = 0;
        for(int i = 1 ;i <= n;i++){
            if(solve(i))
            { 
                result += i*i;
            }
        }
        return result;
    }
};
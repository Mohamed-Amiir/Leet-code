class Solution {
public:
    vector<string> result;

    void solve(int idx,
               string& digits,
               unordered_map<char, string>& phone,
               string current) {

        if (idx == digits.size()) {
            result.push_back(current);
            return;
        }

        for (char c : phone[digits[idx]]) {
            current.push_back(c);
            solve(idx + 1, digits, phone, current);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        unordered_map<char, string> phone = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };

        solve(0, digits, phone, "");

        return result;
    }
};
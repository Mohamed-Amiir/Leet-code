#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> getDigits(int n) {
        vector<int> res;
        while (n != 0) {
            int x = n % 10;
            n = n / 10;
            res.push_back(x);
        }
        return res;
    }

    bool isHappy(int n) {
        unordered_set<int> visited; // To track numbers we've seen
        while (n != 1 && !visited.count(n)) {
            visited.insert(n); // Mark the number as visited
            vector<int> digits = getDigits(n);
            int result = 0; // Initialize result
            for (int d : digits) {
                result += d * d;
            }
            n = result; // Update n to the sum of squares of digits
        }
        return n == 1; // If we exit the loop and n is 1, it's a happy number
    }
};

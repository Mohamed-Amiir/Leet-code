class Solution {
public:
string removeOccurrences(string s, string part) {
    size_t pos = s.find(part); // Find the first occurrence
    while (pos != string::npos) {
        s.erase(pos, part.size()); // Remove the substring
        pos = s.find(part); // Search again
    }
    return s;
}

};
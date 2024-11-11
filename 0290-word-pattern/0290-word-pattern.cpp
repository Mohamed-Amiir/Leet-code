#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

class Solution {
public:
    std::vector<std::string> splitWords(const std::string &str) {
        std::vector<std::string> words;
        std::istringstream stream(str);
        std::string word;
        
        while (stream >> word) {
            words.push_back(word);
        }
        
        return words;
    }
    
    bool wordPattern(std::string pattern, std::string s) {
        std::map<char, std::string> mp;
        std::map<std::string, char> reverseMap;
        std::vector<std::string> words = splitWords(s);
        
        // Check if pattern length matches words length
        if (pattern.size() != words.size()) {
            return false;
        }

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            std::string word = words[i];
            
            // Check if mapping for pattern character already exists
            if (mp.count(c)) {
                if (mp[c] != word) return false;
            } else {
                if (reverseMap.count(word) && reverseMap[word] != c) return false;
                mp[c] = word;
                reverseMap[word] = c;
            }
        }
        
        return true;
    }
};

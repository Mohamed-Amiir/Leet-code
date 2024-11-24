class Solution {
public:
    string simplifyPath(string path) {
        stack<std::string> myPath;
    string current;
    for (char c : path) {
        if (c == '/') {
            if (current == "..") {
                if (!myPath.empty()) myPath.pop();
            } else if (!current.empty() && current != ".") {
                myPath.push(current);
            }
            current.clear();
        } else {
            current += c;
        }
    }

    // Handle the last segment
    if (current == "..") {
        if (!myPath.empty()) myPath.pop();
    } else if (!current.empty() && current != ".") {
        myPath.push(current);
    }

    // Construct the simplified path
    string answer;
    while (!myPath.empty()) {
        answer = "/" + myPath.top() + answer;
        myPath.pop();
    }

    return answer.empty() ? "/" : answer;
    }
};
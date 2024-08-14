class Solution {
public:
int romanToInt(string s) {
	map<char, int> roman;
	int result = 0;
	roman['I'] = 1;
	roman['V'] = 5;
	roman['X'] = 10;
	roman['L'] = 50;
	roman['C'] = 100;
	roman['D'] = 500;
	roman['M'] = 1000;
	queue<char> q;
	for (char x : s)
		q.push(x);
	while (!q.empty())
	{
		char temp = q.front();
		q.pop();
		if ((!q.empty() && roman[temp] >= roman[q.front()]) || q.empty())
		{
			result += roman[temp];
		}
		else if (!q.empty() && roman[temp] < roman[q.front()])
		{
			result += roman[q.front()] - roman[temp];
			q.pop();
		}

	}
	return result;
}

};
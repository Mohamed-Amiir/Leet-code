class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        long long tank = 0;
        int n = gas.size();
        if(n == 1 && gas[0] >= cost[0])return 0;
        for (int i = 0; i < n; i++) {
            if (gas[i] > cost[i]) {
                tank += gas[i];
                int j = i;
                while (tank >= cost[j]) {
                    tank -= cost[j];

                    j++;
                    if (j == n)
                        j = 0;
                    if (i == j)
                        return i;
                    tank += gas[j];
                }
                if (i != j) {
                    tank = 0;
                }
            }
        }
        return -1;
    }
};
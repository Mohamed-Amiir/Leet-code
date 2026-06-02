class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int m = landStartTime.size(), n = waterStartTime.size();

        int result = INT_MAX;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // land -> water
                int finishLand = landStartTime[i] + landDuration[i];
                int finishBoth =
                    max(finishLand, waterStartTime[j]) + waterDuration[j];

                result = min(result, finishBoth);

                // water -> land
                int finishWater = waterStartTime[j] + waterDuration[j];
                finishBoth =
                    max(finishWater, landStartTime[i]) + landDuration[i];

                result = min(result, finishBoth);
            }
        }
        return result;
    }
};
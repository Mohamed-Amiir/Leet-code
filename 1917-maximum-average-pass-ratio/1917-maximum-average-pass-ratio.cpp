class Solution {
public:
    double calculateImpact(int pass, long total) {
        double oldRatio = double(pass) / total;
        double newRatio = double(pass + 1) / (total + 1);
        return newRatio - oldRatio;
    };
    
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double result = 0;
        priority_queue<pair<double,pair<int, int>>> maxImpact;

        for(auto x : classes){
            maxImpact.push({calculateImpact(x[0],x[1]),{x[0],x[1]}});
        }
        // Assign extra students to maximize the average pass ratio
        while (extraStudents > 0) {
            auto top = maxImpact.top();
            maxImpact.pop();

            double impact = top.first;
            int pass = top.second.first;
            int total = top.second.second;

            // Assign one extra student to this class
            pass++;
            total++;

            // Recalculate the impact and push the updated class back into the queue
            double newImpact = calculateImpact(pass, total);
            maxImpact.push({newImpact, {pass, total}});

            // Decrement the count of extra students
            extraStudents--;
        }
        while(!maxImpact.empty()){
                double a = maxImpact.top().second.first  ;
                double b = maxImpact.top().second.second  ;
                double x = a/b;
                result += x;
                maxImpact.pop();
        }
        return result / classes.size();
    }
};
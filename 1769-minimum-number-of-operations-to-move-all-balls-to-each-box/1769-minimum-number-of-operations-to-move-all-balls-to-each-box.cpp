class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n  = boxes.size();
        vector<int> pr1(n),pr2(n);
        int c = 0;bool flag = 0;


        int oneCounter = 0;
        if(boxes[0]== '1')oneCounter++;

        pr1[0] = 0;
        for(int i = 1; i < n; i++){
            pr1[i] = pr1[i-1] + oneCounter;
            if(boxes[i] == '1')oneCounter++;
        }

        oneCounter = 0;
        if(boxes[n-1]== '1')oneCounter++;
        pr2[n-1] = 0;

        for(int i = n-2; i >= 0; i--){
           pr2[i] = pr2[i+1] + oneCounter;
           if(boxes[i] == '1')oneCounter++;
        }

        vector<int>result;
        for(int i = 0; i < n;i++){
            result.push_back(pr1[i]+pr2[i]);
        }
        return result;
    }
};
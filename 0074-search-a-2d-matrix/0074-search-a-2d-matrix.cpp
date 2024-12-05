class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        // binary search for the rows
        int start = 0, end = matrix.size()-1,mid;
        bool flag = false;
        while(start <= end){
            mid = start + (end - start)/2;
            if (matrix[mid][0] <= target && matrix[mid][m-1] >= target )
            { 
                if(matrix[mid][0] == target || matrix[mid][m-1] == target) return true;
                flag = true;
                break;
            }        
            if(matrix[mid][0] > target) end = mid-1;
            else if(matrix[mid][0] < target) start = mid+1;
        }


        cout << "mid : " <<mid <<endl;
        if(!flag) return false;


        // binary search at the row
        start = 0 ,end = matrix[mid].size()-1;
        // mid--;
        while(start <= end){
            int mid2 = (end + start)/2 ;
            cout << "start : " << start <<endl;
            cout << "end : " << end <<endl;
            cout << "mid2 : " <<mid2<<endl;
            if(matrix[mid][mid2] == target) return true;

            if(matrix[mid][mid2] > target) end = mid2-1;
            else  start = mid2+1;
        }
        return false;
    }
};
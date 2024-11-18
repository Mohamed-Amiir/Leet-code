class Solution {
public:
    int maxArea(vector<int>& height) {
        int a = 0,z = height.size()-1,result = 0;
        while(a < z){
          if(height[a] > height[z]){
              result = max(result,min(height[a],height[z])*(z-a));
                            z--;
          }
          else {
              result = max(result,min(height[a],height[z])*(z-a));
               a++;
          }
        }
        return result;
    }
};
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,bool> visited;

        for(int x : arr){

            if(visited[x*2] == 1||( x%2==0 && visited[x/2] == 1)) return 1;
            else{
                visited[x] = 1;
            }
        }
        return 0;
    }
};
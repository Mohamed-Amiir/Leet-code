public class Solution {

    public void Merge(int[] nums1, int m, int[] nums2, int n) {

        int i = 0;int j = 0;
        List<int> list  = new(m+n);

        while(i < m && j < n){ 
           if(nums1[i] <= nums2[j]){
            list.Add(nums1[i]);
            i++;
           }else{
             list.Add(nums2[j]);
             j++;
           }
        }
        while(i < m){
            list.Add(nums1[i]);
            i++;
        }
        while(j < n){
            list.Add(nums2[j]);
            j++;
        }
        for(int a = 0 ; a < list.Count;a++){
            nums1[a] = list[a];
        }
    }
}
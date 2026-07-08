public class Solution {

    public void Merge(int[] nums1, int m, int[] nums2, int n) {
        List<int> l = new();

        for(int i = 0 ; i < m ;i++){
          l.Add(nums1[i]);
        }
        for(int i = 0; i < n ;i++){
          l.Add(nums2[i]);
        }
        l.Sort();
        int[] arr = l.ToArray();
        for(int i = 0 ; i < arr.Length;i++){
            nums1[i] = arr[i];
        }
        // nums1 = arr;
    }
}
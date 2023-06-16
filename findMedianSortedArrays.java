class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int i = 0,n = nums1.length;
        int j = 0,m = nums2.length;
        ArrayList<Integer> merged = new ArrayList<>();
        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                merged.add(nums1[i]);
                i++;
            }
            else{
                merged.add(nums2[j]);
                j++;
            }
        }
        while(i<n && j>=m){
            merged.add(nums1[i]);
            i++;
        }
        while(j<m && i>=n){
            merged.add(nums2[j]);
            j++;
        }
        if((n+m)%2!=0){
            int median = (n+m)/2;
            return merged.get(median);
        }
        else{
            int m1 = (n+m)/2;
            int m2 = m1-1;
            double median = merged.get(m1)+merged.get(m2);
            return median/2;

        }
    }
}
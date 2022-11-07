class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int arr[m+n];
        int i=0,j=0,k=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                arr[k] = nums1[i];
                i++;
                k++;
            }
            else{
                arr[k] = nums2[j];
                j++;
                k++;
            }
        }
        while(i<m){
            arr[k++] = nums1[i++];
        }
        while(j<n){
            arr[k++] = nums2[j++];
        }
        nums1.resize(m+n);
        // nums1.clear();
        for(i=0;i<m+n;i++){
            nums1[i] = arr[i];
        }
    }
};
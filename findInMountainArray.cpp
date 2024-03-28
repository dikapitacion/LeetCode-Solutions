/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
 
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 0,r=n-1;
        int start = 0, end = mountainArr.length() - 1;
        int peak;
        while(end != start){
           peak = start + (end - start) / 2;
           if(mountainArr.get(peak) < mountainArr.get(peak + 1) ){
              start = peak + 1;
           }
           else end = peak;
        }
        peak = start;
        while(l<=peak){
            int mid = l+(peak-l)/2;
            int temp = mountainArr.get(mid);
            if(target == temp){
                return mid;
            }
            if(target>temp){
                l = mid+1;
            }
            else{
                peak = mid-1;
            }
        }
        start = peak,end = n-1;
        while(start <= end){
           int targetIndex = start + (end - start) / 2;
           int currentElement = mountainArr.get(targetIndex);
           if(currentElement == target ) return targetIndex;
           else if(currentElement > target){
               start = targetIndex + 1;
           }
           else  end = targetIndex - 1;
        }
        return -1;
    }
};
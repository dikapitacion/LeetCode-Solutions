class KthLargest {
public:
    vector<int> temp;
    int num;

    KthLargest(int k, vector<int>& nums) {
        temp = nums;
        sort(temp.begin(),temp.end());
        num = k;
    }
    
    int add(int val) {
        // temp.push_back(val);
        int left=0,right = temp.size()-1;
        int index = 0;
        while(left<=right){
            int mid = (left+right)/2;
            if(temp[mid]==val){index = mid; break;}
            if(temp[mid]>val){
                right = mid-1;
            }
            else{
                left = mid+1;
                index = left;
            }
        }

        temp.insert(temp.begin()+index,val);
        return temp[temp.size()-num];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
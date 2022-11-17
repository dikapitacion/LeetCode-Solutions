class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ax2-ax1)*(ay2-ay1);
        if(area1<0){area1 = -area1;}
        int area2 = (bx2-bx1)*(by2-by1);  
        if(area2<0){area2 = -area2;}
        vector<int> l1,l2,b1,b2;
        
        int beg = min(ax1,ax2),end = max(ax1,ax2);
        for(int i=beg;i<=end;i++){
            l1.push_back(i);
        }
        
        beg = min(ay1,ay2),end = max(ay1,ay2);
        for(int i=beg;i<=end;i++){
            b1.push_back(i);
        }
        
        beg = min(bx1,bx2),end = max(bx1,bx2);
        for(int i=beg;i<=end;i++){
            l2.push_back(i);
        }
        
        beg = min(by1,by2),end = max(by1,by2);
        for(int i=beg;i<=end;i++){
            b2.push_back(i);
        }
        vector<int> v(l1.size() + l2.size());
        vector<int>::iterator it, st;
  
        it = set_intersection(l1.begin(),
                          l1.end(),
                          l2.begin(),
                          l2.end(),
                          v.begin());
        
        vector<int> v1(b1.size() + b2.size());
        vector<int>::iterator it1, st1;
  
        it1 = set_intersection(b1.begin(),
                          b1.end(),
                          b2.begin(),
                          b2.end(),
                          v1.begin());
        int count1=-1,count2=-1;
        for (st = v.begin(); st != it; ++st){
            count1++;
        }
        for (st1 = v1.begin(); st1 != it1; ++st1){
            count2++;
        }
        int area3;
        if(count1>0 && count2>0){
            area3= count1*count2;
        }
        else{
            area3=0;
        }
         
        return area1+area2-area3;
        }
};
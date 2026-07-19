class Solution {
public:
    int trap(vector<int>& height) {
        int s=0;
        int e=height.size()-1;
        int left=0;
        int right=0;
        int total=0;
        while(s<e){
            left=max(left,height[s]);
            right=max(right,height[e]);

            if(left<right){
                total+=left-height[s];
                s++;
            }else{
                total+=right-height[e];
                e--;
            }
        }
        return total;
    }
};
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile=*max_element(piles.begin(),piles.end());
        for(int k=1;k<=maxPile;k++){
            long long hours=0;

            for(int b:piles){
                hours+=(b+k-1)/k;

            }
            if(hours<=h){
                return k;
            }

        }
        return maxPile;
        
    }
};
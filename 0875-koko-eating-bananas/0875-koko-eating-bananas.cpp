class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left  = 1;
        int right = 0;

        // right = max pile
        for(int i = 0; i < (int)piles.size(); i++){
            if(piles[i] > right) right = piles[i];
        }

        // binary search on answer
        while(left < right){
            int mid = left + (right-left)/2;

            if(canFinish(piles, mid, h)){
                right = mid;      // aur kam speed try karo
            } else {
                left = mid + 1;   // zyada speed chahiye
            }
        }

        return left;
    }

    bool canFinish(vector<int>& piles, int speed, int h){
        int hours = 0;
        for(int i = 0; i < (int)piles.size(); i++){
            // ceil(pile/speed) bina STL
            hours += (piles[i] + speed - 1) / speed;
        }
        return hours <= h;
    }
};
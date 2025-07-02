class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());

        while(left < right)
        {
            int speed = (left + right)/2;
            int hrsSpent = 0;
            for(auto i : piles)
                hrsSpent += i/speed + (i % speed != 0);
                if(hrsSpent <= h)//if this true from speed to n is working 
                //now from speed to 1 we need to check hence reduce the right to speed
                right = speed;
                else left = speed + 1;
        }
        return right;//return left;
    }
};
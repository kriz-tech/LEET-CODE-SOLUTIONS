class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int left = 0, right = n - 1, rmax = 0, lmax = 0;
        int res = 0;
        while(left < right)
        {
            if(h[left] < h[right]){
                if(lmax < h[left]) lmax = h[left];
                else res += (lmax - h[left]);
                ++left;
            }
            else{
                if(rmax < h[right]) rmax = h[right];
                else res+= rmax - h[right];
                --right;
            }
        }
        return res;
    }
};
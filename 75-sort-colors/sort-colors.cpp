class Solution {
public:
/*    void swap(int *p1, int *p2){
        int temp = *p1;
        *p1 = *p2;
        *p2 = temp;
    }*/
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zero = 0, two = n - 1;
        int one = 0;

        while(one <= two){
            if(nums[one] == 0) swap(nums[one++], nums[zero++]);
            else if(nums[one] == 1) one++;
            else swap(nums[one], nums[two--]);
        }
    }
};
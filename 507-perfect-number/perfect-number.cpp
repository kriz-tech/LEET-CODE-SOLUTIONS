class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 1) return false;

        int count = 1, i = 2;

        while(i * i <= num){
            if(num % i == 0){
                count += i;
                if(i != num / i) count += num / i;
            }
            i++;
        }
        return count == num;
    }
};
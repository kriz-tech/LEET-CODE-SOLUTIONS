class FindSumPairs {
public:
    vector<int>n1;
    vector<int>n2;
    unordered_map<int, int>m;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for(auto num : n2)
            m[num]++;
    }
    
    void add(int index, int val) {
        int old_value = n2[index];
        m[old_value]--;
        n2[index] += val;
        m[n2[index]]++;
    }
    
    int count(int tot) {
        int res = 0;
        for(auto a : n1){
            int b = tot - a;
            if(m.count(b)){
                res += m[b];
            }
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
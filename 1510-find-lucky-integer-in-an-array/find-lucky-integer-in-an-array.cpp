class Solution {
public:
    int findLucky(std::vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }

        int lucky = -1;

        for (const auto& entry : freq) {
            if (entry.first == entry.second) {
                lucky = max(lucky, entry.first);
            }
        }

        return lucky;
    }
};

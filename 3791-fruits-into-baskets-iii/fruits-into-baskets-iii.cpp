class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        int blockSize = sqrt(n);
        int blockCount = (n + blockSize - 1) / blockSize;

        vector<int> blockMax(blockCount, 0);
        for (int i = 0; i < n; ++i)
            blockMax[i / blockSize] = max(blockMax[i / blockSize], baskets[i]);

        int unplaced = 0;

        for (int fruit : fruits) {
            bool placed = false;
            for (int block = 0; block < blockCount; ++block) {
                if (blockMax[block] < fruit) continue;

                for (int i = 0; i < blockSize; ++i) {
                    int idx = block * blockSize + i;
                    if (idx >= n) break;

                    if (baskets[idx] >= fruit) {
                        baskets[idx] = 0;
                        // Recompute block max
                        blockMax[block] = 0;
                        for (int j = 0; j < blockSize; ++j) {
                            int pos = block * blockSize + j;
                            if (pos < n) blockMax[block] = max(blockMax[block], baskets[pos]);
                        }
                        placed = true;
                        break;
                    }
                }

                if (placed) break;
            }

            if (!placed) unplaced++;
        }

        return unplaced;
    }
};
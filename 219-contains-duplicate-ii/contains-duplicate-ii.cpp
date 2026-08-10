class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int, int> lastIndex;

        for (int i = 0; i < nums.size(); i++) {
            
            // Have we seen this number before?
            if (lastIndex.find(nums[i]) != lastIndex.end()) {
                
                // Check distance between indices
                if (i - lastIndex[nums[i]] <= k) {
                    return true;
                }
            }

            // Update the latest index
            lastIndex[nums[i]] = i;
        }

        return false;
    }
};
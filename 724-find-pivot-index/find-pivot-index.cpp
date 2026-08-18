class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalWeightOnLeft = 0;
        int totalWeightOnRight = std::accumulate( nums.begin(), nums.end(), 0);
        for(std::size_t i = 0; i < nums.size() ; i++ ){
            int currentWeight = nums[i];
            totalWeightOnRight -= currentWeight;
            if( totalWeightOnLeft == totalWeightOnRight ){
                return i;
            }
            totalWeightOnLeft += currentWeight;
        }
        return -1;
    }
};
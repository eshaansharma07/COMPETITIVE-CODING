class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;

    void backtrack(vector<int>& candidates, int target, int index) {

        if(target == 0) {
            ans.push_back(current);
            return;
        }

        if(target < 0)
            return;

        for(int i = index; i < candidates.size(); i++) {

            current.push_back(candidates[i]);

            // Reuse the same element
            backtrack(candidates, target - candidates[i], i);

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        backtrack(candidates, target, 0);

        return ans;
    }
};
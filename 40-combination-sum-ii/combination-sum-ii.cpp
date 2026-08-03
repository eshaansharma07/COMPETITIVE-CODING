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

            // Skip duplicates at the same level
            if(i > index && candidates[i] == candidates[i - 1])
                continue;

            current.push_back(candidates[i]);

            // Move to the next index (can't reuse the same element)
            backtrack(candidates, target - candidates[i], i + 1);

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0);

        return ans;
    }
};
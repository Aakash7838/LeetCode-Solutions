class Solution {
public:

    vector<vector<int>> ans;
    vector<int>path;

    void solve(int index, vector<int>& candidates, int target){
        if(target == 0){
            ans.push_back(path);
            return;
        }

        for(int i = index; i < candidates.size(); i++){
            if(candidates[i] > target){
                continue;
            }

            path.push_back(candidates[i]);

            solve(i, candidates, target-candidates[i]);

            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0, candidates, target);
        return ans;
    }
};
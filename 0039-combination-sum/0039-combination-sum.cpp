class Solution {
public:
    void findans(int ind, vector<int>&candidates, int target, vector<int>&ds, vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        else if(target<0 || ind == candidates.size()){
            return;
        }
        ds.push_back(candidates[ind]);
        findans(ind, candidates, target - candidates[ind], ds, ans);
        ds.pop_back();
            
        findans(ind+1, candidates, target, ds, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> ds;
        findans(0, candidates, target, ds, ans);
        return ans;
    }
};
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low =0;
        int high = nums.size()-1;
        int mid = low + (high-low)/2;

        if(n==1) return nums[0];

        int ans = INT_MAX;

        while(low<=high){
            if(nums[low]<=nums[mid]){
                ans = min(ans, nums[low]);
                low = mid+1;
            }
            else{
                ans = min(nums[mid], ans);
                high = mid -1;
            }
            mid = low + (high-low)/2;
        }
        return ans;
    }
};
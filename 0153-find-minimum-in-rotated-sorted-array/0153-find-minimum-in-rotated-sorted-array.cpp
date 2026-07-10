class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid = low + (high - low)/2;

        int ans = INT_MAX;
        while(low<=high){
            if(nums[low]<=nums[mid]){
                ans = min(nums[low], ans);
                low=mid+1;
            }
            else if (nums[mid]<=nums[high]){
                ans = min(nums[mid], ans);
                high = mid - 1;
            }
            mid = low + (high - low)/2;
        }
        return ans;
    }
};
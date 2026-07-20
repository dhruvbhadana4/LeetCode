class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int firstsmall = INT_MAX;
        int secondsmall = INT_MAX;

        int firstbig = 0;
        int secondbig = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<firstsmall){
                secondsmall = firstsmall;
                firstsmall = nums[i];
            }
            else if(nums[i]<secondsmall){
                secondsmall = nums[i];
            }

            if(nums[i]>firstbig){
                secondbig = firstbig;
                firstbig = nums[i];
            }
            else if(nums[i]>secondbig){
                secondbig = nums[i];
            }


        }
        return ((firstbig*secondbig)-(firstsmall*secondsmall));
    }
};
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;

        int maxi = 0;
        int mini = INT_MAX;
        while(left<=right){
            mini = min(height[left], height[right]);
            int water =  (mini * (right-left));
            maxi = max(maxi , water);

            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxi;
    }
};
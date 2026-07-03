class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int>mpp;
        vector<int>store;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]==2){
                store.push_back(nums[i]);
            }
        }

        int sum=0 ;

        if(store.size()==0) {
            return 0;
        }
        else if(store.size()==1){
            return store[0];
        }
        else{
            
            for(int i=0;i<store.size();i++){
                sum = sum^store[i];
            }
        }
        
        return sum;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            else{
                int l = i+1, r = nums.size()-1;
                while(l<r){
                    int sum = nums[l] + nums[r];
                    if(sum < -nums[i]) l++;
                    else if(sum  > -nums[i]) r--;
                    else{   
                        while(l<r && (nums[l] == nums[l+1])) l++;
                        while(l<r && (nums[r] == nums[r-1])) r--;
                        ans.push_back({nums[i], nums[l], nums[r]});
                        l++;r--;
                    } 
                }
            }
        }
        return ans;
    }
};
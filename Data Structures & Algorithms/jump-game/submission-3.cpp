class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return true;
        if (nums[0]==0) return false;
        int maxi = nums[0];
        for (int i=1; i<n-1; i++){
            if (maxi<=i && nums[i]==0) return false;
            maxi = max(maxi,i+nums[i]); 
        }
        return true;
    }
};

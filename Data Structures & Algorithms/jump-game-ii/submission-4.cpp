class Solution {
public:

    void add(int  k, int x, vector<int>&tree){
        int n = tree.size()/2;
        k+=n;
        tree[k]=x;
        for(k/=2; k>=1; k/=2){
            tree[k] = min(tree[2*k], tree[2*k + 1]);
        }
    }
    int find(int a, int b, vector<int>&tree){
        int n =  tree.size()/2;
        a+=n, b+=n;
        int mini = INT_MAX;
        while (a<=b){
            if (a%2==1) mini = min(mini, tree[a++]);
            if (b%2==0) mini = min(mini, tree[b--]);
            a/=2, b/=2;
        }
        return mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        int cur = n-1;
        int m = n;
        while (n&(n-1)) {
            nums.push_back(1e9);
            n++;
        }
        vector<int> dp(n,1e9);
        dp[m-1]=0;
        vector<int> tree(2*n);
        for (int i=n; i<2*n; i++) tree[i] = dp[i-n];
        for (int i=n-1; i>=0; i--){
            tree[i] = min(tree[2*i], tree[2*i + 1]);
        }
        

        for (int i=m-2; i>=0; i--){
            if (nums[i]==0) continue;
            int l = i+1, r =  min(i+nums[i], m-1);
            dp[i] = 1 + find(l,r,tree);
            add(i,dp[i],tree);
        }

        return dp[0];
    }
};

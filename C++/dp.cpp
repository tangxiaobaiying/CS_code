#include<iostream>
#include<vector>
using namespace std;
// int dp[6][7];
// int weight[5]={3,2,1,4,5};
// int value[5]={25,20,15,40,50};
int lengthOfLIS(vector<int>& );
int main(){
    vector<int>nums={4,10,4,3,8,9};
    int n=lengthOfLIS(nums);
    cout<<n<<"--------"<<endl;
}
int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int j=0;j<n;j++)
            for(int i=j;i>=0;i--)
            {
                if(i==j){
                    dp[i][j]=1;
                    continue;}
                if(nums[i+1]>nums[i]&&nums[j]<nums[j-1])
                    dp[i][j]=max(dp[i+1][j]+1,dp[i][j-1]);
                else if(nums[i+1]<nums[i]&&nums[j]>nums[j-1])
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]+1);
                else if(nums[i+1]>nums[i]&&nums[j]>nums[j-1])
                    dp[i][j]=max(dp[i+1][j]+1,dp[i][j-1]+1);
                else if(nums[i+1]<=nums[i]&&nums[j]<=nums[j-1])
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        return dp[0][n-1];
}

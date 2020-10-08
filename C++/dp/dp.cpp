#include<iostream>
using namespace std;
int dp_(int i,int j);
int dp[6][7]={0};
int weight[5]={3,2,1,4,5};
int value[5]={25,20,15,40,50};
int main(){
    for(int i=0;i<=4;i++){
        dp[i][6]=dp_(i,6);
        // cout<<dp[i][6]<<endl;
    }   
    cout<<dp[4][6];
}
int dp_(int i,int j){
    if(i<0 || j<0){
        return 0;
    }
    if (dp[i][j]==0){
        if(j>=weight[i])
            return max(dp_(i-1,j-weight[i])+value[i],dp_(i-1,j));
        else
        {
            return dp_(i-1,j);
        }
    }   
    else
    {
        return dp[i][j];
    }
    
}
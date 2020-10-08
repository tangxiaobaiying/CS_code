#include<iostream>
using namespace std;
int dp[6][7];
int weight[5]={3,2,1,4,5};
int value[5]={25,20,15,40,50};
int main(){
    int temp;
    for(int i=1;i<=5;i++){
        temp=6-weight[i];
        if(temp>=0){
            dp[i][6]=max(dp[i-1][6-weight[i]]+value[i],dp[i-1][6]);
        }
        else
        {
            dp[i][6]=dp[i-1][6];
        }
        cout<<i<<"------"<<dp[i][6]<<endl;
    }
    cout<<dp[5][6]<<endl;
}

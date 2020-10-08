#include<iostream>
using namespace std;
int dp_(int i,int j);
int dp[6][7]={0};
int weight[5]={ 3, 2, 1, 4, 5};
int value[5]= {25,20,15,40,50};
int main(){
    for(int i=0;i<=4;i++){
        for(int j=0;j<=5;j++)
           { 
            if(i==0||j==0)
                dp[i][j]=0;
            else
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
           }
    }
    cout<<dp[4][5];
}
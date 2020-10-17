#include<iostream>
using namespace std;
#define MAXINT 10000
int main(){
    int s[6]={0};
    int dis[6][6]={0};
    int v[6]={0};
    for(int i=0;i<6;i++){
        s[i]=MAXINT;
    }
    for(int i=0;i<6;i++)
        for(int j=i;j<6;j++)
            cin>>dis[i][j];
    for(int i=0;i<6;i++)
        for(int j=0;j<6;j++){
            if(!v[j]&&dis[i][j])
                s[j]=min(s[i]+dis[i][j],s[j]);
        }
    for(int i=0;i<6;i++)
        cout<<s[i]<<"\t";
    
}
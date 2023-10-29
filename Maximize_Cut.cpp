#include<bits/stdc++.h>
using namespace std;
int maxm(int a,int b,int c)
{
    return max(a,max(b,c));
}
int cuts(int n,int a,int b,int c)
{
    if(n<0)
        return -1;
    if(n==0)
        return 0;
    int res=maxm(cuts(n-a,a,b,c),cuts(n-b,a,b,c),cuts(n-c,a,b,c));
    if(res==-1)
        return -1;
    return res+1;
}
int cut_tab(int n,int a ,int b,int c)
{
    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=-1;
        if(i-a>=0)
            dp[i]=max(dp[i],dp[i-a]);
        if(i-b>=0)
            dp[i]=max(dp[i],dp[i-b]);
        if(i-c>=0)
            dp[i]=max(dp[i],dp[i-c]);
        if(dp[i]!=-1)
            dp[i]++;
    }
    return dp[n];
}
int cut_mem(int n,int a,int b,int c,vector<int>&dp)
{
    if(dp[n]!=-1)
        return dp[n];
    int x=INT_MIN,y=INT_MIN,z=INT_MIN;
    if(n>=a)
        x=cut_mem(n-a,a,b,c,dp);
    if(n>=b)
        y=cut_mem(n-b,a,b,c,dp);
    if(n>=c)
        z=cut_mem(n-a,a,b,c,dp);
    return dp[n]=1+maxm(x,y,z);
}
int main()
{
    cout<<cuts(3,2,4,2)<<endl;
    cout<<cut_tab(3,2,4,2)<<endl;
    vector<int>dp(1e6+1,-1);
    dp[0]=0;
    cout<<cut_mem(23,11,12,13,dp)<<endl;
}

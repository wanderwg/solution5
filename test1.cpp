//合唱团（动态规划）
#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
int main()
{
    int n,k,d,i,j;
    while(cin>>n)
    {
        vector<int> value(n);
        for(int i=0;i<n;++i)
        {
            cin>>value[i];
        }
        cin>>k>>d;
        vector<vector<long long>> vMax(n,vector<long long>(k+1,0));
        vector<vector<long long>> vMin(n,vector<long long>(k+1,0));
        for(int i=0;i<n;++i)
        {
            vMax[i][1]=value[i];
            vMin[i][1]=value[i];
            for(j=2;j<=k;++j)
            {
                for(int m=max(0,i-d);m<=i-1;++m)
                {
                    vMax[i][j]=max(vMax[i][j],max(vMax[m][j-1]*value[i],vMin[m][j-1]*value[i]));
                    vMin[i][j]=min(vMin[i][j],min(vMax[m][j-1]*value[i],vMin[m][j-1]*value[i]));
                }
            }
        }
        long long max_res = vMax[k - 1][k];
        for (int i = k; i < n; i++){
            max_res = max(max_res, vMax[i][k]);
        }
        cout << max_res << endl;
    }
    return 0;
}
/*
All possible ways

Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.
For eg. if a = 10 and b = 2, only way to represent 10 as -
10 = 1^2 + 3^2 
Hence, answer is 1.
Note : x^y represents x raise to the power y
Inout Format :
Two integers a and b (separated by space)
Output Format :
Count
Constraints :
1 <= a <= 10^5
1 <= b <= 50
Sample Input 1 :
10 2
Sample Output 1 :
1
Sample Input 2 :
100 2
Sample Output 2 :
3
*/

#include <bits/stdc++.h>
using namespace std;

int allWays(int x, int n) {
    
    int i=1,dp[x+1],temp[x+1];
    memset(dp, 0 ,sizeof dp);
    dp[0]=1;
    while(pow(i,n)<=x)
    {
        int a=pow(i,n);
        memset(temp,0,sizeof(temp));
        for(int j=a;j<=x;j++)
        {
            temp[j]=dp[j-a];
        }
        for(int j=0;j<=x;j++)
        {
            dp[j]+=temp[j];
            // cout<<dp[j]<<" ";
        }
        // cout<<endl;
        i++;
    }
    return dp[x];
    
}


int main()
{
    int x, n;
    cin >> x >> n;
    cout << allWays(x, n);
    return 0;
}

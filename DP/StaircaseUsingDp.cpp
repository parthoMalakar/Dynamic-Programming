/*
Code : Staircase using Dp
Send Feedback
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Input format :
Integer n (No. of steps)
Constraints :
n <= 70
Sample Input 1:
4
Sample Output 1:
7
*/


#include<bits/stdc++.h>
using namespace std;

long staircase(int n){
   
    long res[n + 6]; 
    memset(res,0,sizeof res);
    res[0]=1;
    for(int i=0;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
            res[i+j]+=res[i];
    }
  
    return res[n]; 
    
}

int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}

/*
Coin Tower
Send Feedback
Whis and Beerus are playing a new game today . They form a tower of N coins and make a move in alternate turns . Beerus being the God plays first . In one move player can remove 1 or X or Y coins from the tower . The person to make the last move wins the Game . Can you find out who wins the game ?
Input Format :
Contains three value N,X,Y as mentioned in the problem statement
Output Format :
A string containing the name of the winner like “Whis” or “Beerus” (without quotes)
Constraints:
1<=N<=10^6
2<=X<=Y<=50
Sample Input :
 4 2 3
Sample Output :
 Whis
*/
#include<iostream>
#include<string>
using namespace std;
int n,x,y;

int ans[10000000];
string solve(int n, int x, int y)
{    ans[0]=1;
    //1 means a is winning 
    ans[1]=1;
    ans[x]=1;
    ans[y]=1;
    for (int i=2;i<=n;i++){

        if (!ans[i])
        {
            ans[i]=ans[i-1]^1;
            if (i-x>=1)
            {
                ans[i]=max(ans[i],ans[i-x]^1);
            }
            if (i-y>=1)
            {
                ans[i]=max(ans[i],ans[i-y]^1);
            }
        }
    }
    string a;
    if(ans[n])
        a="Beerus";
    else
        a="Whis";
    return a;




}

int main()
{
	cin>>n>>x>>y;
	cout<<solve(n,x,y)<<endl;
}
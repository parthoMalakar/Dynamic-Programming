/*
Longest Increasing Subsequence

Given an array with N elements, you need to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in strictly increasing order.
Input Format
Line 1 : An integer N 
Line 2 : Elements of arrays separated by spaces
Output Format
Line 1 : Length of longest subsequence
Input Constraints
1 <= n <= 10^3
Sample Input :
6
5 4 11 1 16 8
Sample Output 1 :
3
Sample Output Explanation
Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).
Sample Input 2:
3
1 2 2
Sample Output 2 :
2
*/


#include <bits/stdc++.h>
using namespace std;

int lis(int* input, int n) {
	int output[n];
	output[0] = 1;
	for(int i=1;i<n;i++)
	{
	    output[i]=1;
	    for(int j=0;j<i;j++)
	    {
	        if(input[j]<input[i])
	        {
	            output[i]=max(output[i],output[j]+1);
	        }
	    }
	}
	return *max_element(output,output+n);
}

int main(){
    int n;
    cin >> n;
    int arr[100000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << lis(arr, n);
}


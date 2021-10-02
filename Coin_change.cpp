#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    long long int count( int arr[], int n, int sum )
    {
       
        //code here.
        long long int dp[n+1][sum+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(i==0 && j!=0)
                dp[i][j]=0;
                else if(j==0)
                dp[i][j]=1;
                else{
                    if(j-arr[i-1]>=0)
                    {
                        dp[i][j]=dp[i][j-arr[i-1]]+dp[i-1][j];
                    }
                    else
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends

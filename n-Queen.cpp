#include<iostream>
using namespace std;

bool isPossible(int **arr,int n,int pos,int j)
{
    for(int i=0;i<n;i++)
    {
        if(arr[pos][i]==1)
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i][j]==1)
        return 0;
    }
    for(int i=pos+1,j1=j+1;i<n && j1<n;i++,j1++)
    {
        if(arr[i][j1]==1)
        return 0;
    }
    for(int i=pos-1,j1=j+1;i>=0 && j1<n;i--,j1++)
    {
        if(arr[i][j1]==1)
        return 0;
    }
    for(int i=pos-1,j1=j-1;i>=0 && j1>=0;i--,j1--)
    {
        if(arr[i][j1]==1)
        return 0;
    }
    for(int i=pos+1,j1=j-1;i<n && j1>=0;i++,j1--)
    {
        if(arr[i][j1]==1)
        return 0;
    }
    return 1;
}
void nqueen(int **arr,int n,int j)
{
    //Base CAse
    static int flag=0;
    if(j<0)
    {
        flag=1;
        cout<<"[";
        for(int i1=n-1;i1>=0;i1--)
        {
            for(int j1=n-1;j1>=0;j1--)
            {
                if(arr[i1][j1]==1)
                {
                    cout<<j1+1<<" ";
                }
            }
        }
        cout<<"] ";
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(isPossible(arr,n,j,i))
        {
            arr[j][i]=1;
            nqueen(arr,n,j-1);
            arr[j][i]=0;
        }
    }
    
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	if(n==2||n==3)
	cout<<"-1";
	else{
	    int * *arr=new int*[n];
	for(int i=0;i<n;i++)
	{
	    arr[i]=new int[n]; 
	    for(int j=0;j<n;j++)
	    {
	        arr[i][j]=0;
	    }
	}
	nqueen(arr,n,n-1);
	}
	cout<<endl;
	
	}
	return 0;
	
}

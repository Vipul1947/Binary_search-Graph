#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump [],int );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p,n)<<endl;
    }
}
// } Driver Code Ends


/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
int tour(petrolPump p[],int n)
{
    int sum_p=0;
    int sum_d=0;
    int index;
    int q=n;
    int j=0;
    int i=0;
    int flag=0;
     int count=0;
    for (;i<n;i++)
    {
        
        if(p[i].petrol>=p[i].distance&&count==0)
        {
            count++;
            index=i;
        }
        sum_p+=p[i].petrol;
        sum_d+=p[i].distance;
    }
    if(sum_d>sum_p)
    return -1;
    else {
    sum_p=0;
    sum_d=0;
    i=index;
    count=0;
    }
    if(i==n-1)
    return i;
   
    while(i<n)
    {
        sum_p=sum_p+p[i].petrol;
        sum_d=sum_d+p[i].distance;
        if(sum_p>=sum_d)
        {   
            if(count==0)
            index=i;
            count++;
        }
        else
        {
            count=0;
            sum_p=0;
            sum_d=0;
        }
        i++;
    }
    return index;
   //Your code here
   
}

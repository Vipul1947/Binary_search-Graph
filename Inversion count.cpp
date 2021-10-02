class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(int l,int r,int mid,long long arr[])
    {
        long long count=0;
        vector<long long> left(arr+l,arr+mid+1);
        vector<long long> right(arr+mid+1,arr+r+1);
        int i=0,j=0;
        int index=l;
        while(i<=mid-l && j<r-mid)
        {
            if(left[i]<=right[j])
            {
                arr[index]=left[i];
                i++;
            }
            else
            {
                count+=(mid+1-i-l);
                arr[index]=right[j];
                j++;
            }
            
            index++;
        }
        while(i<=mid-l)
        {
            arr[index]=left[i];
            i++;
            index++;
        }
        
        while(j<r-mid)
        {
            arr[index]=right[j];
            j++;
            index++;
        }
        return count;
    }
    long long mergeSort(int l,int r,long long arr[])
    {
        if(l<r)
        {
            int mid=l+(r-l)/2;
            long long count_l=mergeSort(l,mid,arr);
            long long count_r=mergeSort(mid+1,r,arr);
            long long count=merge(l,r,mid,arr);
            return count_l+count_r+count;
        }
        return 0;
    }
    
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        int l=0,r=N-1;
        return mergeSort(l,r,arr);
        
    }

};

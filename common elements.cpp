class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            vector<int> ans;
            int count=0;
            int i=0,j=0,k=0;
            while(i<n1 && j<n2 && k<n3){
                if(A[i]==B[j]&&B[j]==C[k])
                {
                    if(count==0 || ans[count-1]!=A[i])
                    {ans.push_back(A[i]); count++;}
                    i++;
                }
                else if(min(A[i],min(B[j],C[k]))==A[i]){i++;}
                else if(min(A[i],min(B[j],C[k]))==B[j]){j++;}
                else {k++;}
                
            }
        
            return ans;
        }
        

};

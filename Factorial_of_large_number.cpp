class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int> arr(1,1);
        for(int i=2;i<=N;i++)
        {
            int n=arr.size();
            int carry=0;
            for(int j=0;j<n;j++)
            {
                        int num=arr[j]*i;
                        num+=carry;
                        arr[j]=num%10;
                        carry=num/10;
            }
            while(carry)
            {
                arr.push_back(carry%10);
                carry/=10;
            }
        }
        reverse(arr.begin(),arr.end());
        return arr;
    }
};

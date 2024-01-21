#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    long long int arr[n][n];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	         cin >> arr[i][j];
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        sort(arr[i],arr[i]+n);
	    }
	    long long int sum=arr[n-1][n-1];
	    long long int maxup=arr[n-1][n-1],flo=0;
	    for(int i=n-2;i>=0;i--)
	    {
	        long long int max=0;
	        for(int j=n-1;j>=0;j--)
	        {
	            if(arr[i][j]<maxup && arr[i][j]>max)
	            {
	                max=arr[i][j];
	            }
	            
	        }
	        if(max!=0)
	        {
	        maxup=max;
	        sum+=max;
	        }
	        else
	        {
	            flo=1;
	            break;
	        }
	    }
	    if(flo==1)
	    cout << "-1" <<"\n";
	    else
	    cout << sum << "\n";
	    
	}
	return 0;
}
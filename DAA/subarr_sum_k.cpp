#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int maxCrossingSum(vector<int>& arr, int l, int m, int r, int k){
    int maxSum=INT_MIN;
    for(int i=max(l,m-k+1);i<=m;i++){
        int sum=0;
        int end=i+k-1;
        if(end<=r){
            for(int j=i;j<=end;j++){
                sum+=arr[j];
            }
            maxSum=max(maxSum,sum);
        }
    }
    return maxSum;
}

int maxSubarrSum(vector<int> &arr, int l, int r, int k){
    if(r-l+1<k) return INT_MIN;
    if(l==r) return(k==1)?arr[l]:INT_MIN;
    int m=(l+r)/2;
    int leftMax=maxSubarrSum(arr,l,m,k);
    int rightMax=maxSubarrSum(arr,m+1,r,k);
    int crossMax=maxCrossingSum(arr,l,m,r,k);
    return max({leftMax,rightMax,crossMax});
}

int main(){
    int n,k;
    cin>>n>>k;
    vector <int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int result=maxSubarrSum(arr,0,n-1,k);
    cout<<result;
    return 0;
}
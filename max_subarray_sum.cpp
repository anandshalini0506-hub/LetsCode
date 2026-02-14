#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long S;
    cin>>S;
    long long arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long currSum=0;
    int l=0;
    for(int r=0;r<n;r++){
        currSum+=arr[r];
        while(currSum>S && l<=r){
            currSum-=arr[l];
            l++;
        }
        if(currSum==S){
            cout<<l+1<<" "<<r+1;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
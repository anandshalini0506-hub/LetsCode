#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long S;
    cin>>S;
    long long currentSum=0;
    int l=0;
    for(int r=0;r<n;r++){
        currentSum+=arr[r];
        while(currentSum>S && l<=r){
            currentSum-=arr[l];
            l++;
        }
        if(currentSum==S){
            cout<<l+1<<" "<<r+1<<endl;
        }
    }
    cout<<-1;
    return 0;
}
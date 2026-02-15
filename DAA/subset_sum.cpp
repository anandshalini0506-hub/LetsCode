#include <iostream>
#include <vector>
using namespace std;
bool found=false;
void backTrack(vector<int> &arr, int n, int idx, vector<int> &subset, int currentSum, int target){
    for(int i=idx;i<n;i++){
        if(currentSum+arr[i]>target) continue;
        subset.push_back(arr[i]);
        backTrack(arr,n,i+1,subset,currentSum+1,target);

        for(int x:subset){
            cout<<x<<" ";
        }
        cout<<endl;
        if(currentSum+arr[i]==target){
            found=true;
        }
        subset.pop_back();
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    vector<int> subset;
    backTrack(arr,n,0,subset,0,target);
    if(found){
        cout<<"Subset with given sum found"<<target<<endl;
    }
    else{
        cout<<"Not found";
    }
    return 0;
}
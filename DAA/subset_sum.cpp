#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool found=false;
void backtrack(vector<int>& arr, int N, int idx,vector<int> &subset, int sum, int target){
    for(int i=idx;i<N;i++){
        if(sum+arr[i]>target) continue;
        subset.push_back(arr[i]);
        backtrack(arr,N,i+1,subset,sum+arr[i],target);

        for(int x:subset){
            cout<<x<<" ";
        }
        cout<<endl;
        if(sum+arr[i]==target){
            found=true;
        }
        subset.pop_back();
    }
}

int main(){
    int N;
    cin>>N;
    vector <int>arr(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    vector<int>subset(N);
    backtrack(arr,N,0,subset,0,target);
    if(found){
        cout<<"Subset with the given sum is found.";
    }
    else{
        cout<<"Subset with the given sum is not found.";
    }
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
bool found=false;
void backTrack(vector<int> &arr, int N, int idx, vector<int> &subset, int currentSum, int target){
    for(int i=idx;i<N;i++){
        if(currentSum+arr[i]>target) continue;
        subset.push_back(arr[i]);
        backTrack(arr,N,i+1,subset,currentSum+arr[i],target);

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

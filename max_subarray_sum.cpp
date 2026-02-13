#include <iostream>
using namespace std;

int main(){
    int n;
    long long S;
    cin>>S;
    cin>>n;
    long long A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    long long currentSum=0;
    int l=0;
    for(int r=0;r<n;r++){
        currentSum+=A[r];
        while(currentSum>S && l<=r){
            currentSum-=A[l];
            l++;
        }
        if(currentSum==S){
            cout<<l+1<<" "<<r+1<<endl;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
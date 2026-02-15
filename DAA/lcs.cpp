#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int m=s1.length();
    int n=s2.length();
    vector<vector<int>> s(m+1, vector<int>(n+1,0));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                s[i][j]=1+s[i-1][j-1];
            }
            else{
                s[i][j]= max(s[i-1][j], s[i][j-1]);
            }
        }
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            cout<<s[i][j]<<" ";
        }
    }
    cout<<"Length of longest common subsequence "<< s[m][n]<<endl;
    return 0;
}
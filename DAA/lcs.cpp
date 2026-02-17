#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int m=s1.length();
    int n=s2.length();
    vector<vector<int>> s(m+1, vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                s[i][j]=1+s[i-1][j-1];
            }
            else{
                s[i][j]=max(s[i-1][j],s[i][j-1]);
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Lenght of longest common subsequence is "<<s[m][n]<<endl;
    return 0;
}
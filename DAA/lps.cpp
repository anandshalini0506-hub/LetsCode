#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.length();
    int start=0;
    int maxLen=1;
    for(int i=0;i<n;i++){
        int l=i,r=i;
        int len=r-l+1;
        while(l>=0 && r<n && s[l]==s[r]){
            if(len>maxLen){
                maxLen=len;
                start=l;
                cout<<s.substr(start,maxLen);
            }
            l++; r--;
        }
        int l=i,r=i+1;
        int len=r-l+1;
        while(l>=0 && r<n && s[l]==s[r]){
            if(len>maxLen){
                maxLen=len;
                start=l;
                cout<<s.substr(start,maxLen);
            }
            l++; r--;
        }
    }
    cout<<"Longest palindromic substring is :"<<s.substr(start,maxLen);
    return 0;
}
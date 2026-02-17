#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.length();
    int start=0;
    int maxLen=0;
    for(int i=0;i<n;i++){
        int l=i,r=i;
        while(l>=0 && r<n && s[l]==s[r]){
            int len=r-l+1;
            if(len>maxLen){
                maxLen=len;
                start=l;
                cout<<s.substr(start,maxLen)<<endl;
            }
            l--;
            r++;
        }
        int l=i,r=i+1;
        while(l>=0 && r<n && s[l]==s[r]){
            int len=r-l+1;
            if(len>maxLen){
                maxLen=len;
                start=l;
                cout<<s.substr(start,maxLen)<<endl;
            }
            l--;
            r++;
        }
    }
    cout<<"Length of longest palindromic substring "<<s.substr(start,maxLen)<<endl;
    return 0;
}
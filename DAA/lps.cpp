#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.length();
    int start=0;
    int maxlen=1;
    for(int i=0;i<n;i++){
        int l=i,r=i;
        while(l>=0 && r<n && s[l]==s[r]){
            int len=r-l+1;
            if(len>maxlen){
                maxlen=len;
                start=l;
                cout<<s.substr(start,maxlen);
            }
            l++;r--;
        }
        int l=i,r=i+1;
        while(l>=0 && r<n && s[l]==s[r]){
            int len=r-l+1;
            if(len>maxlen){
                maxlen=len;
                start=l;
                cout<<s.substr(start,maxlen);
            }
            l++;r--;
        }
    }
    cout<<"Longest palindromic string"<<s.substr(start,maxlen)<<endl;
    return 0;
}
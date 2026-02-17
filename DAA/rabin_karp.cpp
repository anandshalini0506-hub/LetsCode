#include <iostream>
#include <vector>
#include <string>
using namespace std;

void rabinKarp(const string &text, const string &pat){
    int m=text.length();
    int n=pat.length();
    if(n>m) cout<<"Pattern not found"<<endl;

    int d=10;
    int q=13;
    int patternHash=0;
    int windowHash=0;
    int h=1;
    for(int i=0;i<n-1;i++){
        h=(h*d)%q;
    }
    for(int i=0;i<n;i++){
        patternHash=(d*patternHash+pat[i])%q;
        windowHash=(d*windowHash+text[i])%q;
    }
    for(int i=0;i<=m-n;i++){
        if(patternHash==windowHash){
            bool match=true;
            for(int j=0;j<n;j++){
                if(text[i+j]!=pat[j]){
                    match=false;
                    break;
                }
            }
            if(match){
                cout<<"Pattern found at position "<<i+1<<endl;
                return;
            }
        }
        if(i<m-n){
            windowHash=(d*(windowHash-text[i]*h))%q;
            if(windowHash<0) windowHash+=q;
        }
    }
    cout<<"Pattern not found"<<endl;
}

int main(){
    string text,pattern;
    getline(cin,pattern);
    getline(cin,text);
    rabinKarp(text,pattern);
    return 0;
}
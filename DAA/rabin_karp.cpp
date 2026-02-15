#include <iostream>
#include <string>
using namespace std;

void rabinKarp(const string &text, const string &pattern){
    int m=text.length();
    int n=pattern.length();
    int d=10;
    int q=13;
    if(n>m){
        cout<<"Pattern not found";
    }
    int h=1;
    int patternHash=0;
    int windowHash=0;
    for(int i=0;i<n-1;i++){
        h=(h*d)%q;
    }
    for(int i=0;i<n;i++){
        patternHash=(d*patternHash+pattern[i])%q;
        windowHash=(d*windowHash+text[i])%q;
    }

    for(int i=0;i<=m-n;i++){
        if(patternHash=windowHash){
            bool found=true;
            for(int j=0;j<n;j++){
                if(text[i+j]!=pattern[j]){
                    found=false;
                    break;
                }
            }
            if(found){
                cout<<"Pattern found at"<<i+1<<endl;
                return;
            }
        }
        if(i<m-n){
            windowHash=(d*(windowHash-text[i]*h)+text[i+n])%q;
            if(windowHash<0) windowHash+=q;
        }
    }
    cout<<"Pattern not found";
}

int main(){
    string text,pattern;
    getline(cin,text);
    getline(cin,pattern);
    rabinKarp(text,pattern);
    return 0;
}
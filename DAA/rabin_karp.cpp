#include <iostream>
#include <vector>
using namespace std;

void rabinKarp(const string &text, const string &pattern){
    int m=text.length();
    int n=pattern.length();
    int d=10;
    int q=13;
    if(n<m){
        cout<<"Pattern not found"<<endl;
        return;
    }
    int patternHash=0;
    int windowHash=0;
    int h=1;
    for(int i=0;i<n-1;i++){
        h=(h*d)%q;
    }
    for(int i=0;i<n;i++){
        patternHash=(d*patternHash+pattern[i])%q;
        windowHash=(d*windowHash+text[i])%q;
    }
    for(int i=0;i<=m-n;i++){
        if(patternHash==windowHash){
            bool match=true;
            for(int j=0;j<n;j++){
                if(text[i+j]!=pattern[j]){
                    match=false;
                    break;
                }
            }
            if(match){
                cout<<"Pattern found at index"<<i+1<<endl;
            }
        }
        if(i<n-m){
            windowHash=(d*(windowHash-text[i]*h)+text[i+n])%q;
            if(windowHash<0){
                windowHash+=q;
            }
        }
    }
    cout<<"Pattern not found"<<endl;
}

int main(){
    string text,pattern;
    cout<<"Enter the text: ";
    cin>>text;
    cout<<"Enter the pattern: ";
    cin>>pattern;
    rabinKarp(text,pattern);
    return 0;
}
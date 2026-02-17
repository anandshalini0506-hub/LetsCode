#include <iostream>
#include <string>
using namespace std;

void search(const string &pat, const string &text){
    int m=pat.length();
    int n=text.length();
    for(int i=0;i<=n-m;i++){
        int j;
        for(int j=0;j<m;j++){
            if(text[i+j]!=pat[j]) break;
        }
        if(j==m) cout<<"Pattern found at index "<<i<<endl;
    }
}

int main(){
    string text,pattern;
    getline(cin,text);
    getline(cin,pattern);
    search(pattern,text);
    return 0;
}
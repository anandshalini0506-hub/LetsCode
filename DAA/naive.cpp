#include <iostream>
#include <string>
using namespace std;

void search(const string &text, const string &pattern){
    int m=pattern.length();
    int n=text.length();
    for(int i=0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++){
            if(text[i+j]!=pattern[j]) break;
        }
        if(j==m){
            cout<<"Pattern found at: "<<i<<endl;
        }
    }
}

int main(){
    string text,pattern;
    getline(cin,text);
    getline(cin,pattern);
    search(text,pattern);
    return 0;
}
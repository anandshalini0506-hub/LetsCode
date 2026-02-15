#include <iostream>
#include <string>
using namespace std;

void search(const string &pat, const string &text){
    int m=pat.length();
    int n=text.length();
    for(int i=0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++){
            if(text[i+j]!=pat[j]){
                break;
            }
        }
        if(j==m){
            cout<<"Pattern found at length"<<i<<endl;
        }
    }
}

int main(){
    string pattern, text;
    getline(cin,pattern);
    getline(cin,text);
    search(pattern,text);
    return 0;
}
#include <iostream>
#include <string>
using namespace std;

void search(string &pat, string &txt){
    int M=pat.length();
    int N=txt.length();
    for(int i=0;i<=N-M;i++){
        int j;
        for(int j=0;j<M;j++){
            if(txt[i+j]!=pat[j]){
                break;
            }
        }
        if(j==M){
            cout<<"Pattern found at index "<<i<<"\n";
        }
    }
}

int main(){
    string txt,pat;
    getline(cin,txt);
    getline(cin,pat);
    search(pat,txt);
    return 0;
}

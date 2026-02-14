#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Meeting{
    int start,end;
};

bool compare(Meeting a, Meeting b){
    return a.end<b.end;
}

int main(){
    int n;
    cin>>n;
    vector<int> start(n),end(n);
    for(int i=0;i<n;i++){
        cin>>start[i];
    }       
    for(int i=0;i<n;i++){
        cin>>end[i];
    }
    vector<Meeting> meetings(n);
    for(int i=0;i<n;i++){
        meetings[i]={start[i],end[i]};
    }
    sort(meetings.begin(),meetings.end(),compare);
    cout<<meetings[0].start<<" "<<meetings[0].end<<"\n";
    int lastEnd=meetings[0].end;
    for(int i=1;i<n;i++){
        if(meetings[i].start>=lastEnd){
            cout<<meetings[i].start<<" "<<meetings[i].end<<"\n";
            lastEnd=meetings[i].end;
        }
    }
    return 0;
}
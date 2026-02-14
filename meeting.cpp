#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Meeting{
    int start,end;
};

bool compare(Meeting a,Meeting b){
    return a.end<b.end;
}

int main(){
    int n;
    cin>>n;
    vector<int>start(n),end(n);
    for(int i=0;i<n;i++){
        cin>>start[i];
    }
    for(int i=0;i<n;i++){
        cin>>end[i];
    }
    vector<Meeting> meeting(n);
    for(int i=0;i<n;i++){
        meeting[i]={start[i],end[i]};
    }
    sort(meeting.begin(),meeting.end(),compare);
    int last_End=meeting[0].end;
    cout<<meeting[0].start<<" "<<meeting[0].end<<endl;
    for(int i=1;i<n;i++){
        if(meeting[i].start>=last_End){
            cout<<meeting[i].start<<" "<<meeting[i].end<<endl;        
            last_End=meeting[i].end;
        }
    }
    cout<<-1;
    return 0;
}
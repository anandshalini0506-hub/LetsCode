#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity{
    int start,finish,index;
};

bool compare(Activity a, Activity b){
    return a.finish<b.finish;
}

int main(){
    int n;
    cin>>n;
    vector <int> start(n),finish(n);
    for(int i=0;i<n;i++){
        cin>>start[i];
    }
    for(int i=0;i<n;i++){
        cin>>finish[i];
    }
    vector<Activity> activity(n);
    for(int i=0;i<n;i++){
        activity[i].start=start[i];
        activity[i].finish=finish[i];
        activity[i].index=i;
    }
    sort(activity.begin(),activity.end(),compare);
    vector<int> result(n);
    int finish_Last=activity[0].finish;
    result.push_back(activity[0].index);
    for(int i=0;i<n;i++){
        if(activity[i].start>=finish_Last){
            result.push_back(activity[i].index);
            finish_Last=activity[i].finish;
        }
    }
    sort(result.begin(),result.end());
    for(int res:result){
        cout<<res<<" ";
    }
    return 0;
}
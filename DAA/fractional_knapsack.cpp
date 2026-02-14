#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<double> &a, vector<double> &b){
    double r1=a[1]/a[0];
    double r2=b[1]/b[0];
    return r1>r2;
}

double fractionalKnapsack(vector<vector<double>>&items, double W){
    sort(items.begin(),items.end(),compare);
    double totalProfit=0.0;
    int n=items.size();
    for(int i=0;i<n;i++){
        if(W==0) break;
        int weight=items[i][0];
        int profit=items[i][1];
        if(weight<=W){
            cout<<weight<<" "<<profit<<"\n";
            totalProfit+=profit;
            W-=weight;
        }
        else{
            double fraction=W/weight;
            double takenProfit=profit*fraction;
            totalProfit+=takenProfit;
            cout<<weight<<" "<<totalProfit<<"\n";
            W=0;
        }
    }
    return totalProfit;
}

int main(){
    int n;
    cin>>n;
    double W;
    cin>>W;
    vector<double> wt(n);
    vector<double> profit(n);
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    for(int i=0;i<n;i++){
        cin>>profit[i];
    }
    vector<vector<double>> items(n,vector<double>(2));
    for(int i=0;i<n;i++){
        items[i][0]=wt[i];
        items[i][1]=profit[i];
    }
    double totalProfit=fractionalKnapsack(items,W);
    return 0;
}
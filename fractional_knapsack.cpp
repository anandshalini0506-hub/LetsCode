#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int> &a, vector<int> &b){
    double r1=a[1]/a[0];
    double r2=b[1]/b[0];
    return r1>r2;
}

double fractionalKnapsack(vector<vector<double>>& items, double W){
    sort(items.begin(),items.end(),compare);
    double totalProfit=0.0;

    for(int i=0;i<items.size();i++){
        if(W==0) break;

        double weight=items[i][0];
        double profit=items[i][1];
        if(weight<=W){
            cout<<(int)weight<<" "<<profit<<"\n";
            totalProfit+=items[i][1];
            W-=weight;
        }
        else{
            double fraction=W/weight;
            double takenProfit=fraction*profit;
            cout<<W<<" "<<takenProfit<<"\n";
            totalProfit+=takenProfit;
            W==0;
        }
    }
    return totalProfit;
}

int main(){
    int n;
    double W;
    cin>>n;
    cin>>W;
    vector<int> weight(n);
    vector<double> profit(n);
    vector<vector<double>> items(n,vector<double>(n));
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    for(int i=0;i<n;i++){
        cin>>profit[i];
    }
    for(int i=0;i<n;i++){
        items[i][0]=weight[i];
        items[i][1]=profit[i];
    }
    double totalProfit=fractionalKnapsack(items,W);
    cout<<"Total profit: "<<totalProfit;
    return 0;
}
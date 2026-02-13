#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<double>&a, vector<double>&b){
    double r1=a[1]/a[0];
    double r2=b[1]/b[0];
    return r1>r2;
}

double fractionalKnapsack(vector<vector<double>>&items, double W){
    sort(items.begin(),items.end(),compare);
    double totalValue=0.0;
    for(int i=0;i<items.size();i++){
        if(W==0) break;
        double weight=items[i][0];
        double value=items[i][1];
        if(weight<=W){
            totalValue+=value;
            W-=weight;
        }
        else{
            double frac=W/weight;
            double takenProfit=frac*value;
            cout<<"Weight taken: "<<frac*weight<<" Value taken: "<<takenProfit<<endl;
            totalValue+=takenProfit;
            W=0;
        }
    }
    return totalValue;
}

int main(){
    int n;
    cin>>n;
    vector<int> weight(n);
    vector<double>value(n);
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    double W;
    cin>>W;
    vector<vector<double>>items(n,vector<double>(2));
    for(int i=0;i<n;i++){
        items[i][0]=weight[i];
        items[i][1]=value[i];
    }
    double totalValue=fractionalKnapsack(items,W);
    cout<<"Total value in Knapsack: "<<totalValue<<endl;
    return 0;
}
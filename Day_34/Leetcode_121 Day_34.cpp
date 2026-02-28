#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution{
	public:
		int maxProfit(vector<int>& prices){
			int minPriceDay = INT_MAX;
			int maxProfit = INT_MIN;
			for(int i=0; i<prices.size(); i++){
				if(prices[i] < minPriceDay){
					minPriceDay = prices[i];
				}
				int profit = prices[i]-minPriceDay;
				if(profit > maxProfit){
					maxProfit  =  profit;
				}
			}
			return maxProfit;
		}
};
int main(){
	vector<int>V = {7,6,4,3,1};
	Solution obj;
	cout<<endl<<obj.maxProfit(V);
	return 0;
}

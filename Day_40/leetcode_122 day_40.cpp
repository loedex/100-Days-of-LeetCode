#include<iostream>
using namespace std;
#include<vector>
class Solution{
	public:
		int maxProfit(vector<int>& prices){
			int profit = 0;
			for(int i=1; i<prices.size(); i++){
				if(prices[i]>prices[i-1]){
					profit+=(prices[i]-prices[i-1]);
				}
			}
			return profit;
		}
};
int main(){
	vector<int>V={7,1,5,3,6,4};
	Solution obj;
	cout<<endl<<obj.maxProfit(V);
	return 0;
}
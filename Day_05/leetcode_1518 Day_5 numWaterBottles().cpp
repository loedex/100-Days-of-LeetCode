#include<iostream>
using namespace std;
class Solution{
	public:
		int numWaterBottles(int numBottles, int numExchange){
			int totalDrink = numBottles;
			int emptyBottles = numBottles;
			while(emptyBottles >= numExchange){
				totalDrink+= emptyBottles/numExchange;
				emptyBottles = (emptyBottles/numExchange) + (emptyBottles%numExchange);
			}
			return totalDrink;
		}
};
int main(){
	Solution obj;
	cout<<endl<< "Total Drinked Bottles : " <<obj.numWaterBottles(9,3);
	return 0;
}

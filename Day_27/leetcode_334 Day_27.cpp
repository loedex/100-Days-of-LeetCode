#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<math.h>
class Solution{
	public: 
	bool increasingTriplet(vector<int>& nums){
		int first =  INT_MAX;
		int second = INT_MAX;
		int third = INT_MAX;
		
		for(int i = 0; i<nums.size(); i++){
			
			if(nums[i] <= first){
				first = nums[i];
			} else if( nums[i] <= second){
				second = nums[i];
			} else if( (nums[i] > first) && (nums[i] > second)){
				return true;
			}
		}
		return false;
	}
};
int main(){
	vector<int> V = {2,1,5,0,4,6};
	Solution obj;
	cout<<endl<<"\t"<<obj.increasingTriplet(V);
	return 0;
}
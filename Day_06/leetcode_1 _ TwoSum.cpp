#include<iostream>
using namespace std;
#include<vector>
#include <unordered_map>
class Solution{
	public:
		vector<int> twoSum(vector<int>& nums , int target){
			unordered_map<int,int>mp;
			for(int i=0; i<nums.size(); i++){
				int complement = target - nums[i];
				if(mp.find(complement) != mp.end()){
					return {mp[complement],i};
				}
				mp[nums[i]] = i;
			}
			return {};
		}
};
int main(){
	vector<int>V = {3,3};
	int t = 6;
	Solution obj;
	vector<int> Result = obj.twoSum(V,t);
	cout<<Result[0]<<"\t"<<Result[1];
	return 0;
}
#include<iostream>
using namespace std;
#include <bits/stdc++.h>
class Solution{
	public:
		vector<int> targetIndices(vector<int>& nums, int target){
			
			int lessCount = 0;
			int equalCount = 0;
			
			for(int i : nums){
				if(i< target){
					lessCount ++;
				}
				if(i == target){
					equalCount ++;
				}
			}
			if(equalCount == 0){
				return {};
			}
			
			vector<int> result;
			for(int i = 0; i<equalCount; i++){
				result.push_back(lessCount+i);
			}
			return result;
		}
};
int main(){
	vector<int>V = {1,2,5,2,3};
	int tar = 5;
	Solution obj;
	vector<int>res = obj.targetIndices(V,tar);
	for(auto i : res){
		cout<<i<<"\t";
	}
	return 0;
}

#include<iostream>
using namespace std;
#include<vector>
class Solution{
	public:
		vector<int> searchRange(vector<int>& nums, int target){
			int left = 0;
			int right = nums.size()-1;
			vector<int>res (2,-1);
			
			while(left<=right){
				int mid = (left+right)/2;
				
				if(nums[mid]==target){
					res[0]=mid;
					right = mid-1;
				}
				else if(nums[mid]<target){
					left = mid+1;
				}
				else{
					right = mid-1;
				}
			}
			if(res[0]==-1){
				return res;
			}
			
			left = 0;
			right = nums.size()-1;
			while(left<=right){
				int mid = (left+right)/2;
				if(nums[mid] == target){
					res[1] = mid;
					left = mid+1;
				}
				else if(nums[mid]<target){
					left = mid+1;
				}
				else{
					right = mid-1;
				}
				
			}
			return res;
		}
};
int main(){
	int t = 6;
	vector<int> V = {};
	Solution obj;
	vector<int> r = obj.searchRange(V,t);
	for(auto i : r){
		cout<<i<<"\t";
	}
	return 0;
}

#include<iostream>
using namespace std;
#include<vector>
class Solution{
	public:
		vector<int> sortColors(vector<int>& nums){
			int low = 0;
			int mid = 0;
			int high = nums.size()-1;
			
			while(mid <= high){
				if(nums[mid] == 2){
					swap(nums[mid],nums[high]);
					high--;
				}
				else if(nums[mid] == 0){
					swap(nums[mid],nums[low]);
					mid++;
					low++;
				}
				else if(nums[mid] == 1){
					mid++;
				}
			}
			return nums;
		}
};
int main(){
	vector<int>V = {2,0,2,1,1,0};
	Solution obj;
	vector<int>res = obj.sortColors(V);
	for(auto i : res){
		cout<<i<<"\t";
	}
	return 0;
}

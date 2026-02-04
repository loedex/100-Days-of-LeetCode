#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution{
	public:
		vector<int> sortedSquares(vector<int>& nums){
			int left = 0;
			int right = nums.size()-1;
			vector<int>result;
			while(left<=right){
				if((nums[left]*nums[left]) > (nums[right]*nums[right])){
					result.push_back((nums[left]*nums[left]));
					left++;
				}
				else{
					result.push_back((nums[right]*nums[right]));
					right--;
				}
			}
			reverse(result.begin(), result.end());
			return result;
		}
};
int main(){
	vector<int>V={-7,-3,2,3,11};
	Solution obj;
	vector<int> r = obj.sortedSquares(V);
	for(auto i:r){
		cout<<i<<"\t";
	}
	return 0;
}

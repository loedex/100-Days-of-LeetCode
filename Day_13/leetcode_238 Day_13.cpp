#include<iostream>
using namespace std;
#include<vector>
class Solution{
	public:
		vector<int> productExceptSelf(vector<int>& nums){
			int n = nums.size();
			vector<int>answer(n,1);
			
			// Calculate Prefix Product for each element
			int prefixProduct = 1;
			for(int i=0; i<n; i++){
				answer[i] = prefixProduct;
				prefixProduct *= nums[i];
			}
			
			//Calculate Suffix Product for each element
			int suffixProduct = 1;
			for(int i=n-1; i>=0; i--){
				answer[i]*=suffixProduct;
				suffixProduct *= nums[i];
			}
			return answer;
		}
};
int main(){
	vector<int>V = {-1,1,0,-3,3};
	Solution obj;
	vector<int>r = obj.productExceptSelf(V);
	for(auto i : r){
		cout<<i<<"\t";
	}
	return 0;
}
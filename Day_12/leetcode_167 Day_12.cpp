#include<iostream>
using namespace std;
#include<vector>
class Solution{
	public:
		vector<int> twoSumII(vector<int>& numbers, int target){
			int left = 0;
			int right = numbers.size()-1;
			while(left<right){
				if((numbers[left]+numbers[right])<target){
					left++;
				}
				else if((numbers[left]+numbers[right])>target){
					right--;
				}
				else{
					return {left+1,right+1};
				}
			}
			return {};
		}
};
int main(){
	vector<int>V = {-1,0};
	int t = -1;
	Solution obj;
	vector<int> r = obj.twoSumII(V,t);
	for(auto i: r){
		cout<<i<<"\t";
	}
	return 0;
}

#include<iostream>
using namespace std;
#include<vector>
class Solution{
	public:
		int singleNumber(vector<int>& nums){
			int result = 0;
			for(int num : nums){
				result = result ^ num;
			}
			return result;
		}
};
int main(){
	vector<int>V={4,1,2,1,4,5,2};
	Solution obj;
	cout<<obj.singleNumber(V);
	return 0;
}

#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution{
	public:
		vector<int> addToArrayForm(vector<int>& num, int k){
			vector<int> result;
			int carry = 0;
			int i = num.size()-1;
			
			while(i>=0 || k>0){
				int digitFromNum = (i>=0)? num[i] : 0;
				int digitFromK = k%10;
				
				int sum = digitFromNum + digitFromK + carry;
				
				result.push_back(sum%10);
				carry = sum/10;
				
				k = k/10;
				i--;
			}
			if(carry>0){
				result.push_back(carry);
			}
			reverse(result.begin(), result.end());
			return result;
		}
};
int main(){
	vector<int> V = {2,1,5};
	Solution obj;
	vector<int> r = obj.addToArrayForm(V,806);
	for(auto i:r){
		cout<<i<<"\t";
	}
	return 0;
}

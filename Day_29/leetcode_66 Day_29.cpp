#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution{
	public:
		vector<int> plusOne(vector<int>& digits){
			for(int i = digits.size()-1; i>=0; i--){
				if(digits[i] < 9){
					digits[i]++;
					return digits;
				}
				digits[i] = 0;
			}
			//if control reaches here, it means all given digits are 9s.
			digits.insert(digits.begin(),1);
			return digits;
		}
};
int main(){
	vector<int>dig = {3,2,9};
	Solution obj;
	vector<int>res = obj.plusOne(dig);
	for(int i : res){
		cout<<i<<"\t";
	}
	return 0;
}

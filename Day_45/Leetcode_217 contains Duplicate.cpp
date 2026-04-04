#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<unordered_set>
class Solution{
	public:
		bool containsDuplicate(vector<int>& nums){
			unordered_set<int> s;
			for(int num : nums){
				if(s.count(num)){
					return true;
				}else{
					s.insert(num);
				}
			}
			return false;
		}
};
int main(){
	vector<int>V={1,2,3,4};
	Solution obj;
	bool res = obj.containsDuplicate(V);
	if(res){
		cout<<"Contains Duplicate";
	}else{
		cout<<"No Duplicate";
	}
	return 0;
}
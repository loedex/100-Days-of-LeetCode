#include<iostream>
using namespace std;
#include<unordered_set>
#include<vector>
class Solution{
	public:
		int numJewelsInStones(string jewels, string stones){
			unordered_set<char> jewelSet;
			for(int i : jewels){
				jewelSet.insert(i);
			}
			int count = 0;
			for(int i : stones){
				if(jewelSet.count(i)){
					count++;
				}
			}
			return count;
		}
};
int main(){
	string j = "aA";
	string s = "aAAbbbb";
	Solution obj;
	cout<<"Number of Jewels in Stones : "<<obj.numJewelsInStones(j,s);
	return 0;
}


#include<iostream>
using namespace std;
#include<vector>
#include<math.h>
class Solution{
	public:
		int bulbSwitch(int n){
			return sqrt(n);
		}
};
int main(){
	Solution obj;
	cout<<obj.bulbSwitch(1);
	return 0;
}
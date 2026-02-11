#include<iostream>
using namespace std;
class Solution{
	public:
		bool Find(int n);
};
bool Solution::Find(int n){
	if(n<=0){
		return false;
	}
	int x=1162261467;
	if(x%n==0){
		return true;
	}
	return false;
}
int main(){
	int n;
	cout<<"Enter Number: ";
	cin>>n;
	Solution obj;
	bool R=obj.Find(n);
	if(!R){
		cout<<"\nReturned False.";
	}
	else{
		cout<<"\nReturned True.";
	}
	return 0;
}
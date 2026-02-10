#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
	public:
		int Find(vector<int>&V,int target);
};
int Solution::Find(vector<int>&V,int target){
	int left,right,mid;
	left=0;
	right=V.size()-1;
	while(left<=right){
		mid=(left+right)/2;
		if(target==V[mid]){
			return mid;
		}
		else if(left==right){
			if(target<V[left]){
				return left;
			}
			else{
				return right+1;
			}
		}
		else if(target<V[mid]){
			right=mid-1;
		}
		else if(target>V[mid]){
			left=mid+1;
		}
	}
	return 0;
}
int main(){
	int size,target;
	cout<<"Enter Size: ";
	cin>>size;
	vector<int>V(size);
	for(int i=0;i<size;i++){
		cout<<"Enter "<<i+1<<" value: ";
		cin>>V[i];
	}
	cout<<"\n Enter Target: ";
	cin>>target;
	Solution obj;
	int n=obj.Find(V,target);
	cout<<"Returned Value: "<<n;
	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int64_t fast_pairwisep(const vector<int64_t> &nums){
	int n = nums.size();
	int index_forskipping = 0;
	int index_forskipping2 = 0;
	int64_t max = 0;
	int64_t max2 = 0;
	for(int i=0;i<n;i++){
		//cout<<nums[i]<<"\n";
		if(i<n/2){
			if(nums[i]>max){
				max=nums[i];
				index_forskipping = i;
			}
		}else{
			if(nums[i]>max2){
				max2=nums[i];
				index_forskipping2 = i;
			}
		}
	}
	if(max > max2){
		for(int i=0;i<n/2;i++)
			if(i !=index_forskipping)
				if(nums[i]>max2) max2=nums[i];
	}else if( max < max2){
		for(int i=n/2;i<n;i++)
			if(i !=index_forskipping2)
				if(nums[i]>max) max=nums[i];
	}
	return max*max2;
}

int main(void){
	int n,m;
	int64_t ans;
	cin >> n;
	//cin >> m;
	vector<int64_t> nums(n);
	for(int i=0;i<n;i++)
		cin >> nums[i];
	ans = fast_pairwisep(nums);
	cout<<ans<<"\n";
	return 0;
}

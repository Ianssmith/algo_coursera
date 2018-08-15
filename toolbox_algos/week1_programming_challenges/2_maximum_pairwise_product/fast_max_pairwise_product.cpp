#include <iostream>
#include <vector>

using namespace std;

int64_t fast_pairwisep(const vector<int64_t> &nums){
	int n = nums.size();
	int index_forskipping = 0;
	int64_t max = 0;
	int64_t max2 = 0;
	for(int i=0;i<n;i++){
		if(nums[i]>max){
			max=nums[i];
			index_forskipping = i;
		}
	}
	for(int i=0;i<n;i++)
		if(i !=index_forskipping)
			if(nums[i]>max2 && nums[i]<=max) max2=nums[i];
	return max*max2;
}

int main(void){
	int n;
	cin >> n;
	vector<int64_t> nums(n);
	for(int i=0;i<n;i++)
		cin >> nums[i];
	int64_t ans = fast_pairwisep(nums);
	cout<<ans;
	return 0;
}

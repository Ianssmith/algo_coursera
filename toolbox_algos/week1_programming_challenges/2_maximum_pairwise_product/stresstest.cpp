#include <iostream>
#include <vector>

using namespace std;

int64_t MaxPairwiseProduct(const vector<int64_t>& numbers) {
  int64_t result = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
	//cout<<numbers[i]<<"\n";
    for (int j = i + 1; j < n; ++j) {
      if (numbers[i] * numbers[j] > result) {
        result = numbers[i] * numbers[j];
      }
    }
  }
  return result;
}

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

void stresstest(int N, int64_t M){
	vector<int64_t> nums(N);
	for(int i=0;i<N;i++){
		nums[i] = rand() % M;
		//cout<<nums[i]<<" ";
	}
	int64_t ans = fast_pairwisep(nums);
	//cout<<"next\n";
	int64_t ans2 = MaxPairwiseProduct(nums);
	if(ans == ans2) cout<<"OK "<<ans<<"\n";
	else cout<<"Wrong answer: "<<ans<<", "<<ans2<<"\n";
}


int main(void){
	int n,m;
	cin >> n;
	n = rand() % n;
	cin >> m;
	while(true) stresstest(n,m);
	/* test for a large vector
		n = 2e+5;
		vector<int> nums(n);
		for(int i=0;i<=n;i++)
			nums[i] = i+1;
	*/
	return 0;
}

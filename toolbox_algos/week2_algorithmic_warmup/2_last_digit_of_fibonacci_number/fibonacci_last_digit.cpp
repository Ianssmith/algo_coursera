#include <iostream>
#include <vector>

using namespace std;

int64_t get_fibonacci_last_digit_faster(int n) {
	vector<int64_t> nums(n+1);
	for(int i=0;i<n+1;i++){
		if (i <= 1){
			nums[i] = i;
		} else {
			//nums[i] = (nums[i-1]+nums[i-2])%10;
			nums[i] = (nums[i-1]+nums[i-2])%10;
		}
	}
	return nums.back();
}	
		/* naive version
 	   int64_t previous = 0;
 	   int64_t current  = 1;

 	   for (int64_t i = 0; i < n - 1; ++i) {
 	       int64_t tmp_previous = previous;
 	       previous = current;
 	       current = (tmp_previous + current) % 10;
 	   }

 	   return current;
 	   */

int main() {
    int n;
    cin >> n;
    int64_t c = get_fibonacci_last_digit_faster(n);
    cout << c << '\n';
}

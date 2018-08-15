#include <iostream>
#include <cassert>

// The following code calls a naive algorithm for computing a Fibonacci number.
//
// What to do:
// 1. Compile the following code and run it on an input "40" to check that it is slow.
//    You may also want to submit it to the grader to ensure that it gets the "time limit exceeded" message.
// 2. Implement the fibonacci_fast procedure.
// 3. Remove the line that print64_ts the result of the naive algorithm, comment the lines reading the input,
//    uncomment the line with a call to test_solution, compile the program, and run it.
//    This will ensure that your efficient algorithm returns the same as the naive one for small values of n.
// 4. If test_solution() reveals a bug in your implementation, debug it, fix it, and repeat step 3.
// 5. Remove the call to test_solution, uncomment the line with a call to fibonacci_fast (and the lines reading the input),
//    and submit it to the grader.

using namespace std;

int64_t fibonacci_naive(int64_t n) {
    if (n <= 1)
        return n;

    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int64_t fibonacci_fast(int64_t n) {
	int64_t nums[n+1];
	for (int64_t i=0;i<=n;i++){
		if(i<2){
			 nums[i] = i;
		} else {
			nums[i] = nums[i-1]+nums[i-2];
		}
		//cout<<nums[i]<<endl;
	}
    return nums[(sizeof(nums)/sizeof(nums[0]))-1];
}

void test_solution() {
    assert(fibonacci_fast(3) == 2);
	//int64_t a = fibonacci_fast(3);
    assert(fibonacci_fast(10) == 55);
    for (int64_t n = 2; n < 20; ++n)
        assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
    int64_t n = 0;
    std::cin >> n;

    //std::cout << fibonacci_naive(n) << '\n';
    //test_solution();
    std::cout << fibonacci_fast(n) << '\n';
    return 0;
}

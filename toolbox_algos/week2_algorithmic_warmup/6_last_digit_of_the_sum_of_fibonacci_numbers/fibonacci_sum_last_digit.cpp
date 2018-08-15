#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
        sum += current;
    }

    return sum % 10;
}

//long long fibonacci_sum_fast(long long n) {
int fibonacci_sum_fast(long long n) {
	//std::vector<int64_t> vec(n+1);

	if (n<=1) return n;

	volatile int vec[n+1];
	long long sum = 0;

	//std::cout<<"n is : "<<n<<"\n";
	//std::cout<<"size of vec is : "<<vec.size()<<"\n";
	for(long long i=0;i<=n;i++){
		if(i<2){
			vec[i] = i;
			sum += i;
		}else{
			vec[i] = (vec[i-1]+vec[i-2])%10;
			sum += vec[i];
		//std::cout<<"loop counter at: "<<i<<"\n";
		}
	}
	return sum%10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n)<<'\n';
    std::cout << fibonacci_sum_fast(n)<<'\n';
}

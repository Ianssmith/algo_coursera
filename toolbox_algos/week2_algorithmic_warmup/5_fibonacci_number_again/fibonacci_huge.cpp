#include <iostream>
#include <vector>
#include <chrono>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%m;
    }

    //return current % m;
    return current;
}

long long get_fibonacci_huge_faster(long long n, long long m) {
    if (n <= 1) return n;
	long long vec[n+1];
	for(long long i=0;i<=n;i++){
		if(i<2){
			vec[i] = i;
		}else{
			vec[i] = (vec[i-1]+vec[i-2])%m;
		}
	}
	return vec[(sizeof(vec)/sizeof(vec[0]))-1];
}

long long fibfaster(long long n, long long m) {
    if (n <= 1) return n;
	long long vec[n+1];
	for(long long i=0;i<=100;i++){
		if(i<2){
			vec[i] = i;
		}else{
			vec[i] = (vec[i-1]+vec[i-2])%m;
		}
		std::cout<<vec[i]%1000<<'\n';
	}
	return 0;

}

int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
	std::chrono::time_point<std::chrono::system_clock> start, stop;

	/*
	start = std::chrono::system_clock::now();
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
	stop = std::chrono::system_clock::now();
	std::cout<<"Naive computation took: "<<((std::chrono::duration_cast<std::chrono::microseconds>)(stop-start)).count()<<" microseconds\n";
	*/

	//start = std::chrono::system_clock::now();
    std::cout << get_fibonacci_huge_faster(n, m) << '\n';
	//stop = std::chrono::system_clock::now();
	//std::cout<<"faster computation took: "<<((std::chrono::duration_cast<std::chrono::microseconds>)(stop-start)).count()<<" microseconds\n";
	
	/*
	start = std::chrono::system_clock::now();
    std::cout << fibfaster(n, m) << '\n';
	stop = std::chrono::system_clock::now();
	std::cout<<"fasterer computation took: "<<((std::chrono::duration_cast<std::chrono::microseconds>)(stop-start)).count()<<" microseconds\n";
	*/

	return 0;
}

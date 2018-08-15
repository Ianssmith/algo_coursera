#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = (next + current)%10;
        current = new_current;
    }

    return sum % 10;
}

long long fibfast(long long from, long long to) {
	long long vec[to+1];
    long long sum = 0;

    for (long long i = 0; i <= to; ++i) {
		if(i<2) vec[i] = i;
		else{
			vec[i] = (vec[i-1]+vec[i-2])%10;
		}
        if (i >= from) sum += vec[i];
    }

    return sum % 10;
}


int main() {
    long long from, to;
    std::cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << fibfast(from, to) << '\n';
}

#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  long long maxval = LLONG_MIN;
  long long maxclicks = LLONG_MIN;
  int tmp = 0;
  for(int i=0;i<a.size();i++){
	for(int j=i;j<a.size();j++){
		if(a[j]>maxval){
			 tmp = a[i];
			 a[i] = a[j];
			 a[j] = tmp;
			 maxval = a[i];
		}
		if(b[j]>maxclicks){
			 tmp = b[i];
			 b[i] = b[j];
			 b[j] = tmp;
			 maxclicks = b[i];
		}
	}
	maxval = LLONG_MIN;
	maxclicks = LLONG_MIN;
  }
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}

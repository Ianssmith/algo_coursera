#include <iostream>
//#include <chrono>

//using namespace std;


//long long lcm_naive(int a, int b) {
int64_t lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return (int64_t)l;

  return (int64_t) a * b;
  //return (long long) a * b;
}

int gcd_euclid(int a, int b){
	if(b==0){
		return a;
	}else{
		int a_ = a%b;
		return gcd_euclid(b,a_);
	}
	return -1;
}

int64_t lcm_faster(int a, int b){
	if(a == 1) return b;
	if(b==1) return a;
	int64_t gcd = gcd_euclid(a,b);
	if(gcd == 1) return (int64_t)a*b;

	int64_t base;
	int64_t test;
	if(a>b){
		base = b;
		test = a;
	}else if(a<b){
		base = a;
		test = b;
	}else{
		return a;
	}
	for(int i=2;i<=base;i++){
		if((int64_t)(i*test)%base == 0){
			return (int64_t)i*test;
		}
	}
	return -1;
}

int64_t lcm_muchfaster(int64_t a, int64_t b){
	return b*(a/gcd_euclid(a,b));
}

int main() {
	//chrono::time_point<chrono::system_clock> start, stop;
  int a, b;
  std::cin >> a >> b;

	/*
	start = chrono::system_clock::now();
  std::cout << lcm_naive(a, b) << std::endl;
	stop = chrono::system_clock::now();
	cout<<"Naive computation took: "<<((chrono::duration_cast<chrono::microseconds>)(stop-start)).count()<<" microseconds\n";
	*/

	//start = chrono::system_clock::now();
  //std::cout << lcm_faster(a, b) << std::endl;
	//stop = chrono::system_clock::now();
	//cout<<"\"Faster\" computation took: "<<((chrono::duration_cast<chrono::microseconds>)(stop-start)).count()<<" microseconds\n";

	//start = chrono::system_clock::now();
  std::cout << lcm_muchfaster(a, b) << std::endl;
	//stop = chrono::system_clock::now();
	//cout<<"\"Much Faster\" computation took: "<<((chrono::duration_cast<chrono::microseconds>)(stop-start)).count()<<" microseconds\n";

  return 0;
}

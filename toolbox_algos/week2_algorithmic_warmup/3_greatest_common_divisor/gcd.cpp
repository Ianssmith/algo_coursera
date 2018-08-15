#include <iostream>
//#include <chrono>

using namespace std;

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
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

int main() {
	int a, b;
	//chrono::time_point<chrono::system_clock> start, stop;
	cin >> a >> b;

	/*
	start = chrono::system_clock::now();
	cout << gcd_naive(a, b) << endl;
	stop = chrono::system_clock::now();
	cout<<"Naive computation took: "<<((chrono::duration_cast<chrono::microseconds>)(stop-start)).count()<<" microseconds\n";
	cout<<"\n";
	*/

	//fprintf(stdout,"%d microseconds",((chrono::duration_cast<chrono::microseconds>)(stop-start)).count());

	//start = chrono::system_clock::now();
	cout << gcd_euclid(a, b) << endl;
	//stop = chrono::system_clock::now();
	//cout<<"Euclid computation took: "<<((chrono::duration_cast<chrono::microseconds>)(stop-start)).count()<<" microseconds\n";

	//fprintf(stdout,"%d microseconds",((chrono::duration_cast<chrono::microseconds>)(stop-start)).count());

  return 0;
}

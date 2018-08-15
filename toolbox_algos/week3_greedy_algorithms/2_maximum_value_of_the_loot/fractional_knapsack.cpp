#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(double capacity, vector<double> weights, vector<double> values) {
  double value = 0.0;
  double maxvr = 0.0;
  double maxindex = 0;
  double totalweights = 0;
  //while(capacity > 0){
	do {
	for(double i=0;i<weights.size();i++){
		totalweights+=weights[i];
		if(weights[i] > 0 && (values[i]/weights[i]) > maxvr ){
			maxvr = (double)values[i]/weights[i];
			maxindex = i;
		}
	}
	if(capacity >= weights[maxindex]){
		capacity -=weights[maxindex];
		totalweights-=weights[maxindex];
		weights[maxindex] = 0;
		value+=(double)values[maxindex];
	}else{
		return value += (double)maxvr*capacity;
	}
	maxvr = 0;
  }while(capacity>0 && totalweights>capacity);



  
  // write your code here

  return value;
}

int main() {
  double n;
  double capacity;
  std::cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);
  for (double i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
	//std::cout<<values[i]<<'\n';
	//std::cout<<weights[i]<<'\n';

  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}

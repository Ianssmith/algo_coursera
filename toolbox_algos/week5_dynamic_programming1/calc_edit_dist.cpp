#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using std::vector;
/*
vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}
*/

vector<int> optimal_sequence(int n) {
	vector<int> opcounts;
	//opcounts.back() = n;
	vector<int> calc;
	int total = 1;
	int basenode = 1;

	//starting at 1
	int firstnode = 0;
	int currentnode = 1;
	int nextnode = currentnode+1;
	opcounts.push_back(firstnode);
	opcounts.push_back(0);
	//opcounts.push_back(nextnode);
	calc.push_back(total);
	while(currentnode < n){
		nextnode = currentnode+1;
		opcounts.push_back(INT_MAX);
			int numops3 = 0;
			int numops2 = 0;
			//int numops = 0;
			if(nextnode%3 == 0){
				if(nextnode/3 >= 1){
					numops3 = opcounts[nextnode/3]+1;
				}
			}
			if(nextnode%2 == 0){
				if(nextnode/2 >= 1){
					numops2 = opcounts[nextnode/2]+1;
				}
			}
			int numops = opcounts[nextnode-1]+1;
			if(numops3){
				if(numops2){
					if(numops3 < numops2){
						if(numops3 < numops) numops = numops3;
					} else{
						if(numops2 < numops) numops = numops2;
					}
				}else{
						if(numops3 < numops) numops = numops3;
				}
			}else if (numops2){
						if(numops2 < numops) numops = numops2;
			}

			if(numops < opcounts[nextnode]) opcounts[nextnode] = numops;
			//total+=opcounts[currentnode];
			//calc.push_back(total);
		currentnode++;
	}
	return opcounts;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}

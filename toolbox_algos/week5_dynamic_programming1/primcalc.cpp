#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using std::vector;

vector<vector<int>> opcodes;
vector<int> opcoderow;

vector<int> optimal_sequence(int n) {
	if(n == 1){
		 vector<int> a = {1};
		 return a;
	}
	vector<int> opcounts(n+1);
	vector<int> opcodes;
	//Starting at 1 fill vectors 1st 3 positions manually as they are static
	////I do this because the lecture pseudocode uses an unusual array starting base.
	opcodes.push_back(0);
	opcodes.push_back(0);
	opcodes.push_back(1);

	opcounts[0] = 0;
	opcounts[1] = 0;
	opcounts[2] = 1;
	//starting with 3rd node ie finding least calculations to obtain 3 starting with 1
	int currentnode = 3;
	int prevnode;

	while(currentnode <= n){
		//Set default value for kind of operation (*3, *2, or +1)
		int opcode = 1;
		//Set current operation count to default to the previous nodes calculation count +1
		opcounts[currentnode] = opcounts[currentnode-1]+1;
		//Check other operations for better fit
		//If the current number is divisible by 2 check to see if the optimal calculation count for it is quicker (less than) the calculation count for just adding one to the previous number
		if(currentnode%2 ==0){
			//Using prevnode as index to retrieve optimal calculations to find the current number/2
			prevnode = (currentnode/2);
			if(opcounts[prevnode]+1 < opcounts[currentnode]){
				opcounts[currentnode] = opcounts[prevnode]+1 ;
				opcode = 2;
			}
		}
		if(currentnode%3 == 0){
			prevnode = (currentnode/3);
			if(opcounts[prevnode]+1 < opcounts[currentnode]){
				opcounts[currentnode] = opcounts[prevnode]+1;
				opcode = 3;
			}
		}
		opcodes.push_back(opcode);
		currentnode++;
	}

	//Identifying the intermediate numbers calculated on the path to n
	int k = n;
	int stepback = opcodes[k];
	vector<int> res;
	//Add n to the result vector
	res.push_back(n);
	//The last and best operation code for each number is saved in the opcodes vector
	//Using the opcode we backtrack through the opcodes vector executing the inverse of the opposite calculation and add the result into the result vector.
	for(int i=0;i<opcounts[n];i++){
		if(stepback >1){
			k=k/stepback;
		}else{
			k=k-1;
		}
		stepback = opcodes[k];
		res.push_back(k);
	}

	std::reverse(res.begin(),res.end());
	return res;
}

int main() {
	int n;
	std::cin >> n;
	opcoderow.push_back(0);
	opcoderow.push_back(0);
	vector<int> sequence = optimal_sequence(n);
	std::cout << sequence.size() - 1 << std::endl;
	for (size_t i = 0; i < sequence.size(); ++i) {
		std::cout << sequence[i] << " ";
	}
}

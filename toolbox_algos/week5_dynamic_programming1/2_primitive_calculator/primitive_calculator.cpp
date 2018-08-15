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

vector<vector<int>> opcodes;
vector<int> opcoderow;
//vector<int> alignment(vector<int>);

vector<vector<int>> alignment( vector<int> &opcodevec, vector<int> &opcountvec ){
	std::cout<<"opcode vector: " <<opcodevec.size()<<'\n';
	std::cout<<"opcount vector: " <<opcountvec.size()<<'\n';

	vector<vector<int>> opcodematrix;
	int counter = 0;
	for(int i=0;i<opcountvec.size();i++){
		vector<int> opcoderow;
		for(int j=0;j<opcountvec[i];j++){
			opcoderow.push_back(opcodevec[counter]);
			counter++;
		}
		opcodematrix.push_back(opcoderow);
	}
	return opcodematrix;
}

//vector<int> optimal_sequence(int n, vector<int> *opc) {
vector<int> optimal_sequence(int n) {
	if(n == 1){
		 vector<int> a = {1};
		 return a;
		 }
	//vector<int> opcounts;
	vector<int> opcounts(n+1);
	//opcounts.back() = n;
	vector<int> calc;
	vector<int> opcodes;
	opcodes.push_back(0);
	opcodes.push_back(0);
	opcodes.push_back(1);
	int total = 1;
	//int basenode = 1;

	//starting at 1
	opcounts[0] = 0;
	opcounts[1] = 0;
	opcounts[2] = 1;
	//int firstnode = 0;
	//int currentnode = 1;
	int currentnode = 3;

	//int nextnode = currentnode+1;
	int prevnode;
	//opcounts.push_back(firstnode);
	//opcounts.push_back(0);
	//opcounts.push_back(nextnode);
	calc.push_back(total);
	while(currentnode <= n){
		//nextnode = currentnode+1;
		//opcounts.push_back(INT_MAX);
		int opcode = 1;
		//int numops3 = 0;
		//int numops2 = 0;
		//int numops = 0;

		opcounts[currentnode] = opcounts[currentnode-1]+1;
		//opcounts.push_back( opcounts[currentnode]+1 );
		if(currentnode%2 ==0){
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

		/*
		if(nextnode%3 == 0){
			//if(nextnode/3 >= 1){
				//std::cout<< "caught at r3 with nextopcount of: "<< nextnode<<'\n';
				numops3 = opcounts[nextnode/3]+1;
			//}
		}
		if(nextnode%2 == 0){
			//if(nextnode/2 >= 1){
				//std::cout<< "caught at r2 with nextopcount of: "<< nextnode<<'\n';
				numops2 = opcounts[nextnode/2]+1;
			//}
		}
		//std::cout<< "did not catch at nextopcount of: "<< nextnode<<'\n';
		int numops = opcounts[nextnode-1]+1;

		if(numops3>0){
			if(numops2>0){
				if(numops3 < numops2){
					if(numops3 < numops){
						numops = numops3;
						opcode = 3;
					}else{
						opcode = 1;
					}
				} else{
					if(numops2 < numops){
						numops = numops2;
						opcode = 2;
					}else{
						opcode = 1;
					}
				}
			}else{
				if(numops3 < numops){
					numops = numops3;
					opcode = 3;
				}else{
					opcode = 1;
				}
			}
		}else if (numops2>0){
			if(numops2 < numops){
				numops = numops2;
				opcode = 2;
			}else{
				opcode = 1;
			}
		}

*/
		//if(numops < opcounts[nextnode]){
			//opcounts[nextnode] = numops;
			opcodes.push_back(opcode);
		//}


		//total+=opcounts[currentnode];
		//calc.push_back(total);
		currentnode++;

	}

	int k = n;
	int stepback = opcodes[k];
	//int stepback = opcodes.back();
	//std::cout<<"opcode vec size: "<<opcodes.size()<<'\n';
	//std::cout<<"opcount vec size: "<<opcounts.size()<<'\n';
	
	//std::cout<<" val of k: "<<k<<'\n';
	//for(int i=0;i<opcodes.size();i++){
		//std::cout<<"opcode values are: "<<opcodes[i]<<'\n';
	//}

	vector<int> res;
	res.push_back(n);
	//while(k>=2){
	for(int i=0;i<opcounts[n];i++){
		if(stepback >1){
			//k/=stepback;
			k=k/stepback;
		}else{
			//k-=stepback;
			k=k-1;
			//k=k-1;
		}
		stepback = opcodes[k];
		res.push_back(k);
		//stepback = opcodes[k-1];
		//res.push_back(k+1);
	}

std::reverse(res.begin(),res.end());

	return res;
	//return opcounts;
}

int main() {
	int n;
	std::cin >> n;
	opcoderow.push_back(0);
	opcoderow.push_back(0);
	//vector<int> sequence = optimal_sequence(n,&opcoderow);
	vector<int> sequence = optimal_sequence(n);
	//vector<vector<int>> res = alignment(opcoderow,sequence);
	std::cout << sequence.size() - 1 << std::endl;
	//for (size_t i = 0; i < opcoderow.size(); ++i) {
	//std::cout<<opcoderow[i]<<'\n';
	//}
	for (size_t i = 0; i < sequence.size(); ++i) {
		std::cout << sequence[i] << " ";
	}
}

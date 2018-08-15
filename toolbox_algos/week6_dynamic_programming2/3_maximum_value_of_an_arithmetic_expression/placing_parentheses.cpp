#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <climits>

using std::vector;
using std::string;
using std::max;
using std::min;

//testcase:
//5-8+7*4-8+9
//length 10 chars

struct minmax{
	long long min;
	long long max;
};

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

/*
struct minmax compute_minmax(long long i, long long j, char op){
	struct minmax mm;
	mm.min = INT_MIN;
	mm.max = INT_MIN;
	for(int k=i;k<j;k++){
		int a = eval(
}
*/


long long get_maximum_value(const string &exp) {
	long long MAX;
	int opcount = 0;
	int numcount = 0;
  char ops[(exp.size()/2)];
  char nums[(exp.size()/2)+1];
  for(int i=0;i<exp.size();i++){
	  if(i%2 == 0){
		  nums[numcount] = exp[i];
		  numcount++;
	  }else{
		  ops[opcount] = exp[i];
		  opcount++;
	  }
  }
  //std::cout<<"operations are "<<ops<<'\n';
  //std::cout<<"numbers are "<<nums<<'\n';
	//int nops = ops.size();
	int n=(exp.size()/2)+1;
	//int n=exp.size()-1;
	vector<long long> row(n,0);
	vector<vector<long long>> m(n,row);
	vector<vector<long long>> M(n,row);
	for(int i=0;i<n;i++){
		m[i][i] = nums[i]-'0';
		M[i][i] = nums[i]-'0';
	}
	long long min = LLONG_MAX;
	long long max = LLONG_MIN;
		for(int s=0;s<n;s++){
			for(int i=0;i<n-s;i++){
	min = LLONG_MAX;
	max = LLONG_MIN;
				int j = i+s;
				//struct minmax mm = compute_minmax(i,j,ops[s]);
				for(int k=i;k<j;k++){

					long long a = eval(M[i][k],M[k+1][j],ops[k]);
					long long b = eval(M[i][k],m[k+1][j],ops[k]);
					long long c = eval(m[i][k],M[k+1][j],ops[k]);
					long long d = eval(m[i][k],m[k+1][j],ops[k]);

					if(a<min) min = a;
					if(b<min) min = b;
					if(c<min) min = c;
					if(d<min) min = d;

					if(a>max) max = a;
					if(b>max) max = b;
					if(c>max) max = c;
					if(d>max) max = d;

					M[i][j] = max;
					m[i][j] = min;
				}
			}
		}
		/*
		for(int k=0;k<n;k++){
			for(int t=0;t<n;t++){
				std::cout<<M[k][t]<<' ';
			}
			std::cout<<'\n';
		}
		for(int k=0;k<n;k++){
			for(int t=0;t<n;t++){
				std::cout<<m[k][t]<<' ';
			}
			std::cout<<'\n';
		}
		*/
	return M[0].back();
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';

}


					/*
					int a=0,b=0,c=0,d=0;
					if(ops[k] == '+'){
						a = M[i][k]+M[k+1][j];
						b = M[i][k]+m[k+1][j];
						c = m[i][k]+M[k+1][j];
						d = m[i][k]+m[k+1][j];
					}else if(ops[k] == '-'){
						a = M[i][k]-M[k+1][j];
						b = M[i][k]-m[k+1][j];
						c = m[i][k]-M[k+1][j];
						d = m[i][k]-m[k+1][j];
					}else if(ops[k] == '*'){
						a = M[i][k]*M[k+1][j];
						b = M[i][k]*m[k+1][j];
						c = m[i][k]*M[k+1][j];
						d = m[i][k]*m[k+1][j];
					}else {
						std::cout<<"operation error\n";
					}
					*/

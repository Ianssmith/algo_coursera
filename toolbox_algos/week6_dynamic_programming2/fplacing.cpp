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

struct minmax compute_minmax(vector<vector<int>> &m, vector<vector<int>> &M, long long i, long long j, char op){
	struct minmax mm;
	mm.min = INT_MIN;
	mm.max = INT_MIN;
		for(int k=i;k<j;k++){
			int MAX;
			int MIN;
			//int a=0,b=0,c=0,d=0;
			int a = eval(M[i][k],M[k+1][j],op);
			int b = eval(M[i][k],m[k+1][j],op);
			int c = eval(m[i][k],M[k+1][j],op);
			int d = eval(m[i][k],m[k+1][j],op);
			/*
			if(op == '+'){
				a = M[i][k]+M[k+1][j];
				b = M[i][k]+m[k+1][j];
				c = m[i][k]+M[k+1][j];
				d = m[i][k]+m[k+1][j];
			}else if(op == '-'){
				a = M[i][k]-M[k+1][j];
				b = M[i][k]-m[k+1][j];
				c = m[i][k]-M[k+1][j];
				d = m[i][k]-m[k+1][j];
			}else if(op == '*'){
				a = M[i][k]*M[k+1][j];
				b = M[i][k]*m[k+1][j];
				c = m[i][k]*M[k+1][j];
				d = m[i][k]*m[k+1][j];
			}else {
				std::cout<<"operation error\n";
			}
				*/
			if(a<mm.min) mm.min = a;
			if(b<mm.min) mm.min = b;
			if(c<mm.min) mm.min = c;
			if(d<mm.min) mm.min = d;

			if(a>mm.max) mm.max = a;
			if(b>mm.max) mm.max = b;
			if(c>mm.max) mm.max = c;
			if(d>mm.max) mm.max = d;

			//M[i][j] = max;
			//m[i][j] = min;
		}
		return mm;
}

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
	int i;
	int n=(exp.size()/2);
	//vector<struct minmax> matrix(n);
	vector<int> row(n,0);
	vector<vector<int>> m(n,row);
	vector<vector<int>> M(n,row);
	for(i=0;i<n;i++){
		m[i][i] = nums[i]-'0';
		M[i][i] = nums[i]-'0';
	}
	//int min = INT_MAX;
	//int max = INT_MIN;
		for(int s=0;s<n;s++){
			for(int i=0;i<n-s;i++){
				int j = i+s;
				struct minmax mm = compute_minmax(m, M, i,j,ops[s]);
				m[i][j] = mm.min;
				M[i][j] = mm.max;
			}
		}
	return M[0].back();
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';

}


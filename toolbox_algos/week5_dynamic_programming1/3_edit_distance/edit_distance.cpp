#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

int edit_distance(const string &str1, const string &str2) {
	vector<int> a(str2.size()+1);
	vector<vector<int>> res(str1.size()+1,a);
	for(int i=1;i<=str1.size();i++){
		res[i][0] = i;
	}
	for(int j=1;j<=str2.size();j++){
		res[0][j] = j;
	}

	for(int j=1;j<=str2.size();j++){
		for(int i=1;i<=str1.size();i++){
			int ins = res[i][j-1]+1;
			int del = res[i-1][j]+1;
			int mat = res[i-1][j-1];
			int mis = res[i-1][j-1]+1;
			if(str1[i-1] == str2[j-1]){
				if(ins<=del){
					if(ins<=mat){
						res[i][j] = ins;
					}else{
						res[i][j] = mat;
					}
				}else if(del<=mat){
					res[i][j] = del;
				}else{
					res[i][j] = mat;
				}
			}else{
				if(ins<=del){
					if(ins<=mis){
						res[i][j] = ins;
					}else{
						res[i][j] = mis;
					}
				}else if(del<=mis){
					res[i][j] = del;
				}else{
					res[i][j] = mis;
				}
			}
		}
	}
	
	return res[str1.size()][str2.size()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}

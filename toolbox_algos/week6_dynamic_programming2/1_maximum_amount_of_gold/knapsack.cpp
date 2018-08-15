#include <iostream>
#include <vector>

using std::vector;

int ow(int bag_weight, const vector<int> &weights) {
	//vector<int> row(bag_weight+1,0);
	//vector<vector<int>> matrix(weights.size()+1,row);
	vector<int> row(weights.size()+1,0);
	vector<vector<int>> matrix(bag_weight+1,row);
	for(int w=1;w<=bag_weight;w++){
		for(int i=1;i<=weights.size();i++){
	//for(int i=1;i<=bag_weight;i++){
		//for(int w=1;w<=weights.size();w++){
			matrix[w][i] = matrix[w][i-1];
			if(weights[i-1] <= w){
				int val = matrix[w-weights[i-1]][i-1]+weights[i-1];
				if(matrix[w][i] < val){
					matrix[w][i] = val;
				}
			}
		}
	}

	return matrix.back().back();
}
int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  //std::cout << optimal_weight(W, w) << '\n';
  std::cout << ow(W, w) << '\n';
}

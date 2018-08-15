#include <iostream>

int get_change(int m) {
	//write your code here
	int coins[3] = {10,5,1};
	int n = 0,sum = 0;
	while(m>0){
		for(int i=0;i<3;i++){
			if(m%coins[i] == 0){
				sum+=coins[i];
				m-=coins[i];
				n+=1;
				break;
			}
		}
	}
	return n;
}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
}

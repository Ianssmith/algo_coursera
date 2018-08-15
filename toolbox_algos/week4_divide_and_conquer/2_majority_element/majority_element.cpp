#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;


int get_majority_element(vector<int> &a, int left, int right) {
	if (left == right) return -1;
	if (left + 1 == right) return a[left];
	int mid = left+(right-left)/2;
	int max = 0;
	int current = -1;
	int count = 0;
	for(int i=0;i<right;i++){
		if(a[i] == current){
			count++;
			if(count > max) max = count;
		}else{
			current = a[i];
			count = 1;
		}
	}
	if(max>mid)return 1;

	
	//if(a[0] == a[mid]) return 1;
	//if(a[mid-1] == a.back()) return 1;
	//if(a[0] == a[mid]) return a[0];
	//if(a[mid-1] == a.back()) return a[mid];

	//vector<int> b = mysort(a, left, mid);
	//vector<int> c = mysort(a,mid,right);
	//if(c[0] == c.back()){
	//for(int i=0;i<b.size();i++)
	//if(c[0] == b[i]) return 1;
	return -1;
	//}
}

void mymerge(vector<int> &b, int l, int r){
	int i, j, k;
	int mid = l+(r-l)/2;
	int split1 = mid-l+1;
	int split2 =  r-mid;

	vector<int> leftarr(split1), rightarr(split2);

	for(i=0; i<split1; i++)
		leftarr[i] = b[l+i];
	for(j=0; j<split2; j++)
		rightarr[j] = b[mid+j+1];
		//rightarr[j] = b[mid+j];

	i = 0;
	j = 0;
	k = l;
	while(i<split1 && j<split2){
		if(leftarr[i] <= rightarr[j]){
			b[k] = leftarr[i];
			i++;
		}else{
			b[k] = rightarr[j];
			//b[k] = rightarr[j+1];
			j++;
		}
		k++;
	}

	while(i<split1){
		b[k] = leftarr[i];
		i++;
		k++;
	}

	while(j<split2){
		b[k] = rightarr[j];
		//b[k] = rightarr[j+1];
		j++;
		k++;
	}

}

void mysort(vector<int> &a, int l, int r){
	//if(a.size() == 1) return a;
	int mid = l+(r-l)/2;
	if(l<r){
		mysort(a, l, mid);
		mysort(a, mid+1, r);
		mymerge(a, l, r);
	}
}


int naive_majority(vector<int> &a){
	for(int i=0;i<a.size();i++){
		int current = a[i];
		int count = 0;
		for(int j=0;j<a.size();j++)
			if(a[j] == current)
				count+=1;
		if (count > a.size()/2) return a[i];
	}
	return -1;
}


int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	mysort(a,0,a.size()-1);
	std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
	//std::cout << "faster: "<<(get_majority_element(a, 0, a.size()) != -1) << '\n';

	//std::cout << "faster: "<<get_majority_element(a, 0, a.size()) << '\n';
	//std::cout << "naive: "<< naive_majority(a) << '\n';

	//for(int i=0;i<a.size();i++){
	//std::cout << "faster: "<< a[i] << '\n';
	//}

}

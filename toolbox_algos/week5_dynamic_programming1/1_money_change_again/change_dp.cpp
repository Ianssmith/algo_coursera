#include <iostream>
#include <climits>
#include <vector>

struct llentry{
	int val;
	struct llentry *next;
	struct llentry *prev;
};

struct llentry *addentry (struct llentry *llp, int value){
	while(llp->next != NULL)
		llp = llp->next;

		llp->next = (struct llentry *)malloc(sizeof(struct llentry));

		if(llp->next !=NULL)
			(llp->next)->val = value;
			(llp->next)->next = (struct llentry *) NULL;
			(llp->next)->prev = llp;
		return llp->next;
}

//retrieves the list item "numbacks" items previously in the list
struct llentry *backtrack(struct llentry *currentp, int numbacks){
	struct llentry *lastval = currentp;
	for(int i=0;i<numbacks;i++){
		lastval = lastval->prev;
	}
	return lastval;
}


// linked list version
int get_change(int m) {
  int coins[3] = {1,3,4};
  //struct llentry *head = NULL, *newp, *currentp;
  struct llentry *head = NULL, *newentry, *preventry;
  head = (struct llentry *)malloc(sizeof(struct llentry));
  if(head != NULL) head->val = 0;
  else std::cout<<"head allocation faild.\n";
  for(int i=1;i<=m;i++){
	  newentry = addentry(head,INT_MAX);
	  if(newentry == NULL) std::cout<<"New entry allocation failed.\n";
	  preventry = newentry->prev;
	  for(int j=0;j<sizeof(coins)/sizeof(int);j++){
		if(i>=coins[j]) {
			////inline version of backtrack function
			/*
			struct llentry *lastval = newentry;
			for(int k=0;k<coins[j];k++){
				lastval = lastval->prev;
			}
			*/
			struct llentry *preventry = backtrack(newentry,coins[j]);
			int numcoins = preventry->val + 1;

			if( numcoins < newentry->val) newentry->val = numcoins;
		}
	  }
  }
  while(head->next != NULL) head = head->next;
  //return head->val / 4;
  return head->val ;
}

/*
//vector version
int get_change(int m) {
  std::vector<int> coins = {1,3,4};
  std::vector<int> minnumcoins = {0};
  for(int i=1;i<=m;i++){
	  minnumcoins.push_back(INT_MAX);
	  for(int j=0;j<coins.size();j++){
		  if (i>=coins[j]){
			  int numcoins = (minnumcoins[i-coins[j]])+1;
			  if(numcoins < minnumcoins[i]) minnumcoins[i] = numcoins;
		  }
	  }
  }
  return minnumcoins.back();
}

*/

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

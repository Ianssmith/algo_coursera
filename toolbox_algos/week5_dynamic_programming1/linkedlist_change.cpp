#include <iostream>
#include <climits>

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

//Retrieves the list item "numbacks" items previously in the list
struct llentry *backtrack(struct llentry *currentp, int numbacks){
	struct llentry *lastval = currentp;
	for(int i=0;i<numbacks;i++){
		lastval = lastval->prev;
	}
	return lastval;
}


// Linked list version
int get_change(int m) {
  int coins[3] = {1,3,4};
  //Create head of list starting at 0
  struct llentry *head = NULL, *newentry, *preventry;
  head = (struct llentry *)malloc(sizeof(struct llentry));
  if(head != NULL) head->val = 0;
  else std::cout<<"head allocation faild.\n";
  //Cycle through amount of money "m" and add a new list entry for each
  for(int i=1;i<=m;i++){
	  newentry = addentry(head,INT_MAX);
	  if(newentry == NULL) std::cout<<"New entry allocation failed.\n";
	  for(int j=0;j<sizeof(coins)/sizeof(int);j++){
	    //For each possible coin value if the amount is > the coin
		if(i>=coins[j]) {
			//backtrack the linked list 
			preventry = backtrack(newentry,coins[j]);
			int numcoins = preventry->val + 1;
			//std::cout<< "previous coin min count was: "<<numcoins <<" for money value of "<< i <<'\n';
			if( numcoins < newentry->val) newentry->val = numcoins;
		}
	  }
  }
  while(head->next != NULL) head = head->next;
  return head->val ;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

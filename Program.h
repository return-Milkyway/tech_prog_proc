
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

 	struct poslov 
	{
	  	char a[20];
	 	char b[20];
 	};
 
 	struct aphorism 
	{
		 char x[20];
		 char y[20];	 
  	};
  	
	struct mudr {
	enum  key{APHORISM, POSLOV};
	key k;    
	union { 
			aphorism a;
			poslov p;
		};
	};
	
	 struct container
 	{
 		mudr *cont;
 		struct container *next;
 	};
 	
 	struct container* In(container *lst,ifstream &ifst);
	void In(aphorism &a, ifstream &ifst);
	void In(poslov &p, ifstream &ifst);
	///
	int num_prep_aphorism(aphorism &a);
	int num_prep_poslov(poslov &p);
	int num_prep_mudr(mudr &m);
	///////
	bool Compare(mudr* first,mudr*second);
	void Sort(container* c);
	 struct container * swap(struct container *lst1, struct container *lst2, struct container *head);
	//////
	mudr* In(ifstream &ifst);
	void Out(poslov &p, ofstream &ofst);
	void Out(aphorism &a,ofstream &ofst);
	void Out(mudr &s, ofstream &ofst);
	void Out(container *lst,ofstream &ofst);
	struct container *  Init();
	struct container *  Init2(mudr  *a);
	struct container * Clear(container *lst);

 	



 

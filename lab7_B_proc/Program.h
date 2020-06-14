#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

struct poslov {
	char strana[20];
	char text[20];
};
	
struct zagad {
	char vopros[20];
	char otvet[20];
};
 	
struct aphorism {
	char author[20];
	char text[20];	 
};
  	
struct mudr {
	enum  key{APHORISM, POSLOV,ZAGAD};
	key k;  
	int mark;  
	union { 
		aphorism a;
		poslov p;
		zagad z;
	};
};
	
struct container {
	mudr *cont;
	struct container *next;
};
 	
int In(container *lst,ifstream &ifst);
void In(aphorism &a, ifstream &ifst);
void In(poslov &p, ifstream &ifst);
void In(zagad &z, ifstream &ifst);
mudr* In(ifstream &ifst);
void Out(poslov &p, ofstream &ofst);
void Out(aphorism &a,ofstream &ofst);
void Out(zagad &z, ifstream &ifst);
void Out(mudr &s, ofstream &ofst);
void Out(container *lst,ofstream &ofst);
struct container *  Init();
struct container *  Init2(mudr  *a);
struct container * Clear(container *lst);	
int Num_prep_aphorism(aphorism &a);
int Num_prep_poslov(poslov &p);
int Num_prep_mudr(mudr &m);
void Num_prep(container *lst,ofstream &ofst);
int Num_prep_zagad(zagad &z);
bool Compare(mudr *first,mudr *second);
void Sort(container *c);
struct container * Swap(struct container *lst1, struct container *lst2, struct container *head);
void Out_only_aphorism(container *lst,ofstream &ofst);

void MultiMethod(container *c, ofstream &ofst);


 

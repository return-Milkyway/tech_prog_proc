#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;
const int SIZE = 20;

struct proverb {
	char country[SIZE];
	char text[SIZE];
};
	
struct riddle {
	char question[SIZE];
	char answer[SIZE];
};
 	
struct aphorism {
	char author[SIZE];
	char text[SIZE];	 
};
  	
struct wisdom {
	enum  key {APHORISM, PROVERB, RIDDLE};
	key type_struct;  
	int mark;  
	union { 
		aphorism aphor;
		proverb prov;
		riddle ridd;
	};
};
	
struct container {
	wisdom *item_with_wisdom;
	struct container *next;
};
 	
int In(container *storehouse_of_wisdom, ifstream &ifst);
void In(aphorism &aphor, ifstream &ifst);
void In(proverb &prov, ifstream &ifst);
void In(riddle &ridd, ifstream &ifst);
wisdom* In(ifstream &ifst);
void Out(proverb &prov, ofstream &ofst);
void Out(aphorism &aphor, ofstream &ofst);
void Out(riddle &ridd, ofstream &ofst);
void Out(wisdom &item_with_wisdom, ofstream &ofst);
void Out(container *storehouse_of_wisdom, ofstream &ofst);
struct container *  Init();
struct container *  Init2(wisdom  *aphor);
struct container * Clear(container *storehouse_of_wisdom);	
int Num_prep_aphorism(aphorism &aphor);
int Num_prep_proverb(proverb &prov);
int Num_prep_wisdom(wisdom &item_with_wisdom);
void Num_prep(container *storehouse_of_wisdom, ofstream &ofst);
int Num_prep_riddle(riddle &ridd);
bool Compare(wisdom *first, wisdom *second);
void Sort(container *storehouse_of_wisdom);
struct container * Swap(struct container *storehouse_of_wisdom_1, struct container *storehouse_of_wisdom_2, struct container *head);
void Out_only_aphorism(container *storehouse_of_wisdom, ofstream &ofst);
void MultiMethod(container *storehouse_of_wisdom, ofstream &ofst);


 

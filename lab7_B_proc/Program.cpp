#include "Program.h"
#include <string>

int In(container *storehouse_of_wisdom, ifstream &ifst){
	struct container *last = Init2(In(ifst));
	if (last -> item_with_wisdom == 0) {
		return 0;
	}
	struct container *next_wisdom;
	next_wisdom = storehouse_of_wisdom -> next; 
	storehouse_of_wisdom -> next = last; 
	last -> next = next_wisdom; 
		  
	while(!ifst.eof()) {			
		struct container *new_wisdom = Init2(In(ifst));
		if (new_wisdom -> item_with_wisdom == 0){
			return 0;
		}
		
		struct container *next_wisdom;		  
		next_wisdom = last -> next; 
		last -> next = new_wisdom;
		new_wisdom -> next = next_wisdom;
		last = new_wisdom;
	}
	return(1);
}
 	
void In(aphorism &aphor, ifstream &ifst) {
	char str[SIZE];
	ifst.get();
	ifst.getline(aphor.author, sizeof(str)).eof();
	ifst.getline(aphor.text, sizeof(str)).eof();
}
 
void In(riddle &ridd, ifstream &ifst) {
	char str[SIZE];
	ifst.get();
	ifst.getline(ridd.question, sizeof(str)).eof();
	ifst.getline(ridd.answer, sizeof(str)).eof();
}
 
void In(proverb &prov, ifstream &ifst) {
	char str[SIZE];
	ifst.get();
	ifst.getline(prov.country, sizeof(str)).eof();
	ifst.getline(prov.text, sizeof(str)).eof();
}
 
wisdom * In(ifstream &ifst) {
	wisdom *item_with_wisdom;
	string type_struct;
	ifst >> type_struct;
	if (type_struct == "Aphorism"){
		item_with_wisdom = new wisdom;
		item_with_wisdom -> type_struct = wisdom::key::APHORISM;
		In(item_with_wisdom -> aphor, ifst);
	} else if (type_struct == "Proverb"){
		item_with_wisdom = new wisdom;
		item_with_wisdom -> type_struct = wisdom::key::PROVERB;
		In(item_with_wisdom -> prov, ifst);
	} else if (type_struct == "Riddle"){
		item_with_wisdom = new wisdom;
		item_with_wisdom -> type_struct = wisdom::key::RIDDLE;
		In(item_with_wisdom -> ridd, ifst);
	} else {
		return 0;
	}
	ifst >> item_with_wisdom -> mark;	
	return item_with_wisdom;
}
 
void Out(proverb &prov, ofstream &ofst) {
	ofst << "It is Proverb: country = "
	<< prov.country << ", text = " << prov.text << endl;
}
 
void Out(riddle &ridd, ofstream &ofst) {
	ofst << "It is Riddle: question = "
	<< ridd.question << ", answer = " << ridd.answer << endl;
}

void Out(aphorism &aphor, ofstream &ofst) {
	ofst << "It is Aphorism: author = " << aphor.author
	<< ", text = " << aphor.text << endl;
}
 
void Out(wisdom &item_with_wisdom, ofstream &ofst) {
	
	switch(item_with_wisdom.type_struct) {
		case wisdom::key::APHORISM:
			Out(item_with_wisdom.aphor, ofst);
			break;
		case wisdom::key::PROVERB:
			Out(item_with_wisdom.prov, ofst);
			break;
		case wisdom::key::RIDDLE:
			Out(item_with_wisdom.ridd, ofst);
			break;
		default:
		ofst << "Incorrect wisdom!" << endl;
	}
	
	if ((item_with_wisdom.mark > 10) || (item_with_wisdom.mark < 0)){
		ofst << "Incorrect reviw" << endl;
		return;
	}
	
	ofst << "Mark = " << item_with_wisdom.mark << endl;
}
 
void Out(container *storehouse_of_wisdom, ofstream &ofst) {
	
	if(storehouse_of_wisdom -> next == storehouse_of_wisdom){
		ofst << "None" << endl;
		return;
	}
	
	struct container *prov;
	prov = storehouse_of_wisdom -> next;
	
	int count = 0;
	do {
		count = count + 1;
		prov = prov -> next; 
	} while (prov != storehouse_of_wisdom); 
	ofst<<"Container contains " << count << " elements." << endl;
	
	prov = storehouse_of_wisdom -> next;
	do {
		wisdom *item = prov -> item_with_wisdom;
		Out(*item, ofst);
		prov = prov -> next; 
	} while (prov != storehouse_of_wisdom); 
}

void Num_prep(container *storehouse_of_wisdom,ofstream &ofst) {
 
	if(storehouse_of_wisdom->next==storehouse_of_wisdom){
		ofst << "None" << endl;
		return;
	}
	struct container *prov;
	prov = storehouse_of_wisdom -> next;
	int num = 0;
	do {
		num = num + 1;
		prov = prov -> next; 
	} while (prov != storehouse_of_wisdom); 
	ofst<<"Container contains " << num 	<< " elements." << endl;
	prov = storehouse_of_wisdom->next;
	do {
		wisdom *item_with_wisdom = prov -> item_with_wisdom;
		Out(*item_with_wisdom, ofst);
		ofst << "Num znakov prepinania = " << Num_prep_wisdom(*item_with_wisdom) << endl;
		prov = prov -> next; 
	} while (prov != storehouse_of_wisdom); 
}

struct container *  Init() {
	struct container *storehouse_of_wisdom = new container;
	storehouse_of_wisdom -> next = storehouse_of_wisdom; 
	return storehouse_of_wisdom;
}

struct container *  Init2(wisdom  *aphor) {
	struct container *storehouse_of_wisdom = new container;
	storehouse_of_wisdom -> item_with_wisdom = aphor;
	storehouse_of_wisdom -> next = storehouse_of_wisdom; 
	return storehouse_of_wisdom;
}

struct container * Clear(container *storehouse_of_wisdom) {
	struct container *prov;
	prov = storehouse_of_wisdom -> next;
	do {
		struct container *temp;
		temp = prov;
		while (temp -> next != prov) { 
			temp = temp -> next;
		}
		temp -> next = prov -> next; 
		prov = prov -> next; // next node
	} while (prov != storehouse_of_wisdom); 
}

int Num_prep_wisdom(wisdom &item_with_wisdom) {
	switch(item_with_wisdom.type_struct){
		case wisdom::key::APHORISM:
			return Num_prep_aphorism(item_with_wisdom.aphor);
		case wisdom::key::PROVERB:
			return Num_prep_proverb(item_with_wisdom.prov);
		case wisdom::key::RIDDLE:
			return Num_prep_riddle(item_with_wisdom.ridd);
		default:
			return 0;
	}
}

int Num_prep_aphorism(aphorism &aphor) {
	int num = 0;
	for(int count = 0; count < SIZE; count++){
		if (aphor.text[count] == '\0'){
			break;
		}
		if ((aphor.text[count] == ',' ) || (aphor.text[count] == '.') || (aphor.text[count] == '!') || (aphor.text[count] == '?') || (aphor.text[count] == ':') || (aphor.text[count] == '-') || (aphor.text[count] == ';')){
			num++;
		}
	}
	return num;
}

int Num_prep_proverb(proverb &prov) {
	int num = 0;
	for(int count = 0; count < SIZE; count++){
		if (prov.text[count] == '\0'){
			break;
		}
		if ((prov.text[count] == ',' ) || (prov.text[count] == '.') || (prov.text[count] == '!') || (prov.text[count] == '?') || (prov.text[count] == ':') || (prov.text[count] == '-') || (prov.text[count] == ';')){
			num++;
		}
	}
	return num;
}

int Num_prep_riddle(riddle &ridd) {
	int num = 0;
	for(int count = 0; count < SIZE; count++){
		if (ridd.answer[count] == '\0'){
			break;
		}
		if ((ridd.answer[count] == ',' ) || (ridd.answer[count] == '.') || (ridd.answer[count] == '!') || (ridd.answer[count] == '?') || (ridd.answer[count] == ':') || (ridd.answer[count] == '-') || (ridd.answer[count] == ';')){
			num++;
		}
	}
	return num;
}

bool Compare(wisdom *first, wisdom *second) {
	return(Num_prep_wisdom(*first) < Num_prep_wisdom(*second));
}

void Sort(container* storehouse_of_wisdom) {
	struct container *prov;
	prov = storehouse_of_wisdom -> next;
	
	int num = 0;
	do {
		num = num + 1;
		prov = prov -> next; 
	} while (prov != storehouse_of_wisdom); 
	
	prov = storehouse_of_wisdom -> next; 
	for (int count3 = 0; count3 < num; count3++){
		for (int count2 = 0; count2 < num; count2++){
			prov = storehouse_of_wisdom -> next;		
			if(Compare(prov -> item_with_wisdom, prov -> next -> item_with_wisdom)){
				storehouse_of_wisdom = Swap(prov, prov -> next, storehouse_of_wisdom);
				for(int tmp=0; tmp < count2; tmp++){
					prov = prov -> next;
				}		
	 		}	
		}
	}
}

struct container * Swap(struct container *storehouse_of_wisdom_1, struct container *storehouse_of_wisdom_2, struct container *head) {
	struct container *prev1, *prev2, *next1, *next2;
	prev1 = head;
	prev2 = head;
	while (prev1 -> next != storehouse_of_wisdom_1) // find previous node storehouse_of_wisdom_1 
    	prev1 = prev1 -> next;
	while (prev2 -> next != storehouse_of_wisdom_2) // find previous node storehouse_of_wisdom_2 
    	prev2 = prev2 -> next;
	next1 = storehouse_of_wisdom_1 -> next; // node next storehouse_of_wisdom_1 
	next2 = storehouse_of_wisdom_2 -> next; // node next storehouse_of_wisdom_2 
	if (storehouse_of_wisdom_2 == next1) {	
    	storehouse_of_wisdom_2 -> next = storehouse_of_wisdom_1;
    	storehouse_of_wisdom_1 -> next = next2;
    	prev1 -> next = storehouse_of_wisdom_2;
	}
	else if (storehouse_of_wisdom_1 == next2) {
    	storehouse_of_wisdom_1 -> next = storehouse_of_wisdom_2;
    	storehouse_of_wisdom_2 -> next = next1;
    	prev2 -> next = storehouse_of_wisdom_2;
	}
	else {
    	prev1 -> next = storehouse_of_wisdom_2;
    	storehouse_of_wisdom_2 -> next = next1;
    	prev2 -> next = storehouse_of_wisdom_1;
		storehouse_of_wisdom_1 -> next = next2;
	}
	if (storehouse_of_wisdom_1 == head)
		return(storehouse_of_wisdom_2);
	if (storehouse_of_wisdom_2 == head)
		return(storehouse_of_wisdom_1);
		
	return(head);
}
 
void Out_only_aphorism(container *storehouse_of_wisdom, ofstream &ofst) { 
	
	if(storehouse_of_wisdom -> next == storehouse_of_wisdom) {
		ofst << "None" << endl;
		return;
	}
	struct container *prov;
	prov = storehouse_of_wisdom -> next;
	int num = 0;
	do {
		num = num + 1;
		prov = prov -> next; 
	} while (prov != storehouse_of_wisdom); 
	
	prov = storehouse_of_wisdom -> next;
	do {
		wisdom *item = prov-> item_with_wisdom;
		if (item -> type_struct == wisdom::APHORISM) {
			Out(*item, ofst);
		}
		prov = prov -> next; 
	} while (prov != storehouse_of_wisdom); 
}


void MultiMethod(container *storehouse_of_wisdom, ofstream &ofst) {
	ofst << "Multimethod." << endl;
	struct container *prov;
	struct container *p2;
	
	prov = storehouse_of_wisdom -> next;
	int num = 0;
	do {
	    num = num + 1;
	    prov = prov -> next; 
	} while (prov != storehouse_of_wisdom); 
	prov = storehouse_of_wisdom -> next; 
	
	for (int count3 = 0; count3 < num; count3++) {	
		p2 = storehouse_of_wisdom -> next;
			for(int tmp = 0; tmp < count3; tmp++) {
				p2 = p2 -> next;
			}	
		for (int count2 = count3; count2 < num; count2++) {
			switch( prov -> item_with_wisdom -> type_struct) {
 				case wisdom::APHORISM:
 					switch(p2 -> item_with_wisdom -> type_struct) {
 						case wisdom::PROVERB:
 							ofst << "APHORISM and PROVERB." << endl;
 							break;
						case wisdom::APHORISM:
 							ofst << "APHORISM and APHORISM." << endl;
 							break;
 						case wisdom::RIDDLE:
 							ofst << "APHORISM and ZAGADKA." << endl;
 							break;
 						default:
 							ofst << "Unknown type" << endl;
 					}
	 		}
			switch(prov -> item_with_wisdom -> type_struct) {
 				case wisdom::PROVERB:
 					switch(p2 -> item_with_wisdom -> type_struct) {
 						case wisdom::PROVERB:
 							ofst << "PROVERB and PROVERB." << endl;
 							break;
						case wisdom::APHORISM:
 							ofst << "PROVERB and APHORISM." << endl;
 							break;
 						case wisdom::RIDDLE:
 							ofst << "PROVERB and ZAGADKA." << endl;
 							break;
 						default:
 							ofst << "Unknown type" << endl;
 					}
	 		}
	 		switch(prov -> item_with_wisdom -> type_struct) {
 				case wisdom::RIDDLE:
 					switch(p2 -> item_with_wisdom -> type_struct) {
 						case wisdom::PROVERB:
 							ofst << "ZAGADKA and PROVERB." << endl;
 							break;
						case wisdom::APHORISM:
 							ofst << "ZAGADKA and APHORISM." << endl;
 							break;
 						case wisdom::RIDDLE:
 							ofst << "ZAGADKA and ZAGADKA." << endl;
 							break;
 						default:
 							ofst << "Unknown type" << endl;
 					}
	 		}
	 		Out(*(prov -> item_with_wisdom), ofst);
 			Out(*(p2 -> item_with_wisdom), ofst);
 			p2 = p2 -> next;
		}
		prov = prov -> next;
	}
}

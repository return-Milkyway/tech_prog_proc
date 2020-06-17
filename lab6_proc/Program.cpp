#include "Program.h" 
int In(container *head,ifstream &ifst){
	struct container *last = Init2(In(ifst));
	if (last->cont==0){
		return 0;
	}
	struct container *tmp;
	tmp = head->next; 
	head->next = last; 
	last->next = tmp; 	  
	while(!ifst.eof()) {			
		struct container *newItem = Init2(In(ifst));
		if (newItem->cont==0){
			return 0;
		}
		struct container *tmp;		  
		tmp = last->next; 
		last->next = newItem;
		newItem->next = tmp;
		last=newItem;
	}
	return(1);
}
 	
void In(aphorism &a, ifstream &ifst) {
	char str[20];
	ifst.get();
	ifst.getline(a.author, sizeof(str)).eof();
	ifst.getline(a.text, sizeof(str)).eof();
}
 
void In(zagad &z, ifstream &ifst) {
	char str[20];
	ifst.get();
	ifst.getline( z.vopros, sizeof(str)).eof();
	ifst.getline(z.otvet, sizeof(str)).eof();
}
 
void In(poslov &p, ifstream &ifst) {
	char str[20];
	ifst.get();
	ifst.getline( p.strana, sizeof(str)).eof();
	ifst.getline(p.text, sizeof(str)).eof();
}
 
mudr * In(ifstream &ifst) {
	mudr *mudrost;
	int k;
	ifst >> k;
	switch(k) {
		case 1:
			mudrost = new mudr;
			mudrost->k = mudr::key::APHORISM;
			In(mudrost->a, ifst);
			break;
		case 2:
			mudrost = new mudr;
			mudrost->k = mudr::key::POSLOV;
			In(mudrost->p, ifst);
			break;
		case 3:
			mudrost = new mudr;
			mudrost->k = mudr::key::ZAGAD;
			In(mudrost->z, ifst);
			break;
		default:
			return 0;
	}
	ifst >> mudrost->mark;	
	return mudrost;
}
 
void Out(poslov &p, ofstream &ofst) {
	ofst << "It is Poslovica: Strana = "
	<< p.strana << ", text = " << p.text << endl;
}
 
void Out(zagad &z, ofstream &ofst) {
	ofst << "It is Zagadka: Vopros = "
	<< z.vopros << ", otvet = " << z.otvet << endl;
}

void Out(aphorism &a, ofstream &ofst) {
	ofst << "It is Aphorism: Author = " << a.author
	<< ", text = " << a.text << endl;
}
 
void Out(mudr &mudrost, ofstream &ofst) {
	switch(mudrost.k) {
		case mudr::key::APHORISM:
			Out(mudrost.a, ofst);
			break;
		case mudr::key::POSLOV:
			Out(mudrost.p, ofst);
			break;
		case mudr::key::ZAGAD:
			Out(mudrost.z, ofst);
			break;
		default:
		ofst << "Incorrect phrase!" << endl;
	};
	if ((mudrost.mark>10) || (mudrost.mark<0)){
		ofst << "Incorrect reviw"<<endl;
		return;
	}
	ofst << "Mark ="<<mudrost.mark <<endl;
}
 
void Out(container *head,ofstream &ofst) {
	
	if(head->next==head){
		ofst<<"none"<<endl;
		return;
	}
	struct container *p;
	p = head->next;
	int num=0;
	do {
		num=num+1;
		p = p->next; 
	} while (p != head); 
	ofst<<"Container contains " << num 	<< " elements." << endl;
	p = head->next;
	do {
		mudr *mudrost=p->cont;
		Out(*mudrost,ofst);
		p = p->next; 
	} while (p != head); 
}

void Num_prep(container *head,ofstream &ofst) {
 
	if(head->next==head){
		ofst<<"none"<<endl;
		return;
	}
	struct container *p;
	p = head->next;
	int num=0;
	do {
		num=num+1;
		p = p->next; 
	} while (p != head); 
	ofst<<"Container contains " << num 	<< " elements." << endl;
	p = head->next;
	do {
		mudr *mudrost=p->cont;
		Out(*mudrost,ofst);
		ofst<<"Num znakov prepinania = "<<Num_prep_mudr(*mudrost)<<endl;
		p = p->next; 
	} while (p != head); 
}

struct container *  Init() {
	struct container *c = new container;
	c->next = c; 
	return c;
}

struct container *  Init2(mudr  *mudrost) {
	struct container *c = new container;
	c->cont = mudrost;
	c->next = c; 
	return c;
}

struct container * Clear(container *lst) {
	struct container *p;
	p=lst->next;
	do {
		struct container *temp;
		temp = p;
		while (temp->next != p) { 
			temp = temp->next;
		}
		temp->next = p->next; 
		p = p->next;
	} while (p != lst);
}

int Num_prep_mudr(mudr &mudrost) {
	switch(mudrost.k){
		case mudr::key::APHORISM:
			return Num_prep_aphorism(mudrost.a);
		case mudr::key::POSLOV:
			return Num_prep_poslov(mudrost.p);
		case mudr::key::ZAGAD:
			return Num_prep_zagad(mudrost.z);
		default:
			return 0;
	}
}

int Num_prep_aphorism(aphorism &a) {
	int num=0;
	for(int count=0;count<20;count++){
		if (a.text[count]=='\0'){
			break;}
		if ((a.text[count]==',' ) || (a.text[count]=='.') || (a.text[count]=='!') || (a.text[count]=='?') || (a.text[count]==':') || (a.text[count]=='-') || (a.text[count]==';')){
			num++;
		}
	}
	return num;
}

int Num_prep_poslov(poslov &p) {
	int num=0;
	for(int count=0;count<20;count++){
		if (p.text[count]=='\0'){
			break;
		}
		if ((p.text[count]==',' ) || (p.text[count]=='.') || (p.text[count]=='!') || (p.text[count]=='?') || (p.text[count]==':') || (p.text[count]=='-') || (p.text[count]==';')){
			num++;
		}
	}
	return num;
}

int Num_prep_zagad(zagad &z) {
	int num=0;
	for(int count=0;count<20;count++){
		if (z.otvet[count]=='\0'){
			break;
		}
		if ((z.otvet[count]==',' ) || (z.otvet[count]=='.') || (z.otvet[count]=='!') || (z.otvet[count]=='?') || (z.otvet[count]==':') || (z.otvet[count]=='-') || (z.otvet[count]==';')){
			num++;
		}
	}
	return num;
}

bool Compare(mudr *first,mudr *second) {
	return(Num_prep_mudr(*first)<Num_prep_mudr(*second));
}

void Sort(container* c) {
	struct container *p;
	p = c->next;
	int num=0;
	do {
		num=num+1;
		p = p->next; 
	} while (p != c); 
	p = c->next; 
	for (int count3=0;count3<num;count3++){
		for (int count2=0;count2<num;count2++){
			p=c->next;		
			if(Compare(p->cont, p->next->cont)){
				c=Swap(p,p->next,c);
				for(int tmp=0;tmp<count2;tmp++){
					p=p->next;
				}		
	 		}	
		}
	}
}

struct container * Swap(struct container *lst1, struct container *lst2, struct container *head) {
	struct container *prev1, *prev2, *next1, *next2;
	prev1 = head;
	prev2 = head;
	while (prev1->next != lst1)
    	prev1 = prev1->next;
	while (prev2->next != lst2)
    	prev2 = prev2->next;
	next1 = lst1->next;
	next2 = lst2->next;
	if (lst2 == next1) {	
    	lst2->next = lst1;
    	lst1->next = next2;
    	prev1->next = lst2;
	}
	else if (lst1 == next2) {
    	lst1->next = lst2;
    	lst2->next = next1;
    	prev2->next = lst2;
	}
	else {
    	prev1->next = lst2;
    	lst2->next = next1;
    	prev2->next = lst1;
		lst1->next = next2;
	}
	if (lst1 == head)
		return(lst2);
	if (lst2 == head)
		return(lst1);
	return(head);
}
 
void Out_only_aphorism(container *lst,ofstream &ofst) { 
	if(lst->next==lst){
		ofst<<"none"<<endl;
		return;
	}
	struct container *p;
	p = lst->next;
	int num=0;
	do {
		num=num+1;
		p = p->next; 
	} while (p != lst); 
	p = lst->next;
	do {
		mudr *s=p->cont;
		if (s->k==mudr::APHORISM){
			Out(*s,ofst);
		}
		p = p->next; 
	} while (p != lst); 
}

bool FileIsExist(string filePath) {
    bool isExist = false;
    std::ifstream fin(filePath.c_str());
    if(fin.is_open())
        isExist = true;
    fin.close();
    return isExist;
}

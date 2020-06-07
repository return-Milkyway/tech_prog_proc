#include "Program.h"
using namespace std;
	 
struct container* In(container *lst,ifstream &ifst){
		struct container *last = Init2(In(ifst));
		struct container *tmp;
		tmp = lst->next; 
		lst->next = last; 
		last->next = tmp; 	  
	while(!ifst.eof()) {			
		  struct container *newItem = Init2(In(ifst));
		  struct container *tmp;		  
		  tmp = last->next; 
		  last->next = newItem;
		  newItem->next = tmp;
		  last=newItem;
		}
		return(last);
	}
 	
void In(aphorism &a, ifstream &ifst) {
 char str[20];
 ifst.get();
 ifst.getline( a.x, sizeof(str)).eof();
 ifst.getline(a.y, sizeof(str)).eof();
 }
 
  void In(poslov &p, ifstream &ifst){
 	char str[20];
	ifst.get();
 	ifst.getline( p.a, sizeof(str)).eof();
 	ifst.getline(p.b, sizeof(str)).eof();
 }
 
 mudr* In(ifstream &ifst){
 	mudr *sp;
 	int k;
 	ifst >> k;
 	switch(k) {
 		case 1:
 			sp = new mudr;
 			sp->k = mudr::key::APHORISM;
 			In(sp->a, ifst);
 			return sp;
 		case 2:
 			sp = new mudr;
 			sp->k = mudr::key::POSLOV;
 			In(sp->p, ifst);
 			return sp;
 		default:
 		return 0;
 	}
 }
 
 void Out(poslov &p, ofstream &ofst){
	ofst << "It is Poslovica: Strana = "
	 << p.a << ", text = " << p.b << endl;
 }
 
  void Out(aphorism &a, ofstream &ofst) {
 	ofst << "It is Aphorism: Author = " << a.x
	<< ", text = " << a.y << endl;
 }
 
 void Out(mudr &s, ofstream &ofst) {
	 switch(s.k) {
	 	case mudr::key::APHORISM:
	 		Out(s.a, ofst);
	 		break;
	 	case mudr::key::POSLOV:
	 		Out(s.p, ofst);
	 		break;
	 	default:
	 		ofst << "Incorrect figure!" << endl;
 	};
 	
 };
 
 void Out(container *lst,ofstream &ofst){ 
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
	  ofst<<"Container contains " << num 	<< " elements." << endl;
  	p = lst->next;
	  do {
	    mudr *s=p->cont;
	    Out(*s,ofst);
	    ofst<<"������ ���������� = "<<num_prep_mudr(*s)<<endl;
	    p = p->next; 
	  } while (p != lst); 
}

struct container *  Init(){
	struct container *c = new container;
  c->next = c; 
  return c;
}
struct container *  Init2(mudr  *a) {
  struct container *c = new container;
  c->cont = a;
  c->next = c; 
  return c;
}

 struct container * Clear(container *lst){
	struct container *p;
	p=lst->next;
  do 
  {
	struct container *temp;
	temp = p;
	while (temp->next != p) { 
			temp = temp->next;
		}
  	temp->next = p->next; 
	p = p->next; // ������� � ���������� ����
  } while (p != lst); // ������� ��������� ������
}


int num_prep_mudr(mudr &m){
	switch(m.k){
		case mudr::key::APHORISM:
			return num_prep_aphorism(m.a);
		case mudr::key::POSLOV:
			return num_prep_poslov(m.p);
		default:
			return 0;
	}
}

int num_prep_aphorism(aphorism &a){
	int num=0;
	for(int count=0;count<20;count++){
		if (a.y[count]=='\0'){
		break;}
		if ((a.y[count]==',' ) || (a.y[count]=='.') || (a.y[count]=='!') || (a.y[count]=='?') || (a.y[count]==':') || (a.y[count]=='-') || (a.y[count]==';')){
		num++;
		}
	}
	return num;
}
int num_prep_poslov(poslov &p){
	int num=0;
	for(int count=0;count<20;count++){
		if (p.b[count]=='\0'){
		break;}
		if ((p.b[count]==',' ) || (p.b[count]=='.') || (p.b[count]=='!') || (p.b[count]=='?') || (p.b[count]==':') || (p.b[count]=='-') || (p.b[count]==';')){
		num++;
		}
	}
	return num;
}
 
 /////
bool Compare(mudr* first,mudr* second){
	return(num_prep_mudr(*first)<num_prep_mudr(*second));
	
}
 void Sort(container* c){
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
			for(int tmp=0;tmp<count2;tmp++){p=p->next;}			
			if(Compare(p->cont, p->next->cont)){
	 			c=swap(p,p->next,c);
	 		}	
		}
	  }
 }
 	
 struct container * swap(struct container *lst1, struct container *lst2, struct container *head)
{
  // ���������� ����� ������ ������
  struct container *prev1, *prev2, *next1, *next2;
  prev1 = head;
  prev2 = head;
  while (prev1->next != lst1) // ����� ���� ��������������� lst1
    prev1 = prev1->next;
  while (prev2->next != lst2) // ����� ���� ��������������� lst2
    prev2 = prev2->next;
  next1 = lst1->next; // ���� ��������� �� lst1
  next2 = lst2->next; // ���� ��������� �� lst2
  if (lst2 == next1)
  {	
    // ������������ �������� ����
    lst2->next = lst1;
    lst1->next = next2;
    prev1->next = lst2;
  }
  else if (lst1 == next2)
  {
    // ������������ �������� ����
    lst1->next = lst2;
    lst2->next = next1;
    prev2->next = lst2;
  }
  else
  {
    // ������������ ��������� ����
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
 
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
	p = p->next; // переход к следующему узлу
  } while (p != lst); // условие окончания обхода

}

 
 
 
 

#include <iostream>
#include <sstream>
#include <fstream>
//#include "unit_tests.h"
#include "qtest.h"
using namespace std;

void run_tests4(){
	test_size_after_add4();
	test_link_in_container();
	test_read_write_sort_num_prep();
	test_filter();
}

void test_size_after_add4(){
	container *container_test = Init();//head
	container *p;
	mudr *m = new mudr();
	//Podschet(ne schitaem head)
	p = container_test->next;
	int num=0;
	while(p != container_test){
	    num=num+1;
	    p = p->next; 
	} 
	assert(num == 0);
	//Dobavim v container 1 elem
	struct container *last = Init2(m);
	struct container *tmp;
	tmp = container_test->next; 
	container_test->next = last; 
	last->next = tmp;

	p = container_test->next;
	num=0;
	while(p != container_test){
	    num=num+1;
	    p = p->next; 
	} 
	///////////////////////////
	assert(num == 1);
	
	struct container *newItem = Init2(m);	  
	tmp = last->next; 
	last->next = newItem;
	newItem->next = tmp;
	last=newItem;
	p = container_test->next;
	num=0;
	while(p != container_test){
	    num=num+1;
	    p = p->next; 
	} 
	assert(num == 2);
	
	cout << "Success final - test size after add"<<endl;
}

void test_link_in_container(){
	container *container_test = Init();
	mudr *mudr1 = new mudr();
	mudr *mudr2 = new mudr();
	mudr *mudr3 = new mudr();
	mudr** m_arr;
	m_arr[0]=mudr2;
	m_arr[1]=mudr3;
	
	
	struct container *last = Init2(mudr1);
	struct container *tmp;
	tmp = container_test->next; 
	container_test->next = last; 
	last->next = tmp;
	int i=0;
	while(i<2) {			
		  struct container *newItem = Init2(m_arr[i]);
		  struct container *tmp;		  
		  tmp = last->next; 
		  last->next = newItem;
		  newItem->next = tmp;
		  last=newItem;
		  i++;
	}
	
	assert(mudr1 == container_test->next->cont);
	assert(mudr2 == container_test->next->next->cont);
	assert(mudr3 == container_test->next->next->next->cont);
	
	cout << "Success final - test link in container" << endl;
}


void test_read_write_sort_num_prep(){
	ifstream ifst_test("test/in.txt");
	ofstream ofst_test("test/out.txt");
	string input = "test/in.txt";
	string output = "test/out.txt";

	string correct ="Container contains 2 elements.\n"
					"It is Aphorism: Author = Aphorism2, text = Aphorism_text2,..\n"
					"Mark =4\n"
					"Num znakov prepinania = 3\n"
					"It is Aphorism: Author = Aphorism1, text = Aphorism_text1,,\n"
					"Mark =5\n"
					"Num znakov prepinania = 2\n";

	container *container_test = Init();
	In(container_test, ifst_test);
	Sort(container_test);
	num_prep(container_test, ofst_test);
	
	ifstream in_file(output);
	stringstream buff;
	buff << in_file.rdbuf();
	string result_in_file = buff.str();
	
	assert(result_in_file == correct);
	cout << "Success final - test sort read num prep" << endl;
}

void test_filter(){
	ifstream ifst_test("test/in_filt.txt");
	ofstream ofst_test("test/out_filt.txt");
	string input = "test/in_filt.txt";
	string output = "test/out_filt.txt";

	string correct ="It is Aphorism: Author = Aphorism2, text = Aphorism_text2,..\n"
					"Mark =4\n"
					"It is Aphorism: Author = Aphorism1, text = Aphorism_text1,,\n"
					"Mark =5\n";

	container *container_test = Init();
	In(container_test, ifst_test);
	Sort(container_test);
	Out_only_aphorism(container_test, ofst_test);
	ifstream in_file(output);
	stringstream buff;
	buff << in_file.rdbuf();
	string result_in_file = buff.str();
	
	assert(result_in_file == correct);
	cout << "Success final - test filtred " << endl;
}

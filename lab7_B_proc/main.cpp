#include "Program.h"

int main(int argc, char* argv[]) {
	
	if(argc != 3) {
		cout << "Incorrect command line! "
		"Waited: command infile outfile" << endl;
		return(1);
	}
	
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	
	container* storehouse_of_wisdom;
	storehouse_of_wisdom = Init();
	
	int tmp = 1;
	tmp = In(storehouse_of_wisdom, ifst);
	
	if(tmp == 0){
		cout << "Incorrect input" << endl;
		return 0;
	}
	
	ofst << "Filled sorted container. " << endl;
	MultiMethod(storehouse_of_wisdom, ofst);
	
	Clear(storehouse_of_wisdom);
	cout << "Success final program" << endl;
	
	return 0;
}


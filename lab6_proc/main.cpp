#include "Program.h"
int main(int argc, char* argv[]) {
	if(argc !=3) {
		cout << "incorrect command line! "
		"Waited: command infile outfile" << endl;
		return(1);
	}
	if(FileIsExist(argv[1])){}
	else{
		cout << "File is not exist!\n";
		return 1;
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	cout << "Start"<< endl;
	container* c;
	c = Init();
	int tmp = 1;
	tmp = In(c, ifst);
	if(tmp == 0){
		cout << "Problems with input file" << endl;
		return 0;
	}
	ofst << "Filled sorted container. " << endl;
	Sort(c);
	Num_prep(c, ofst);
	ofst << "Only aphorism " << endl;
	Out_only_aphorism(c, ofst);
	Clear(c);
	ofst << "Empty container. " << endl;
	Out(c, ofst);
	cout << "All good! \n Complete"<< endl;
	return 0;
}


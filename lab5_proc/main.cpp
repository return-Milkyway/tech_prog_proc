
#include "Program.h"
//using namespace std;
int main(int argc, char* argv[]) {
	if(argc !=3) 
		{
		cout << "incorrect command line! "
		"Waited: command infile outfile" << endl;
		return(1);
		}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
//ifstream ifst("in.txt");
//ofstream ofst("ot.txt");
	cout << "Start"<< endl;
	container* c;
	c= Init();
	int tmp=1;
	tmp=In(c, ifst);
	if(tmp==0){
		cout<<"incorrect input"<<endl;
		return 0;
	}
	ofst << "Filled sorted container. " << endl;
	Sort(c);
	//Out(c, ofst);
	num_prep(c, ofst);
	ofst << "Only aphorism " << endl;
	Out_only_aphorism(c, ofst);
	Clear(c);
	ofst << "Empty container. " << endl;
	Out(c, ofst);
	cout << "Stop"<< endl;
	return 0;
}


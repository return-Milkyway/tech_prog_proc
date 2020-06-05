
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
	cout << "Start"<< endl;
	container* c;
	 c= Init();
	In(c, ifst);
	 ofst << "Filled container. " << endl;
	//Out(c, ofst);
	Clear(c);
	 ofst << "Empty container. " << endl;
	Out(c, ofst);
	cout << "Stop"<< endl;
	return 0;
}


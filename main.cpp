#include "lexicalanalyzer.h"



using namespace std;


int main(int argc, const char* argv[]){
	
	lexicalanalyzer analyzed;
	
	ifstream in;
	//in.open(argv[1]);
	in.open("C:\\Users\\Nicholas\\Desktop\\goodtest.txt");
	if (!in.is_open()) {
		return 1;
	};

	analyzed.analyze(in);


	in.close();
	return 0;
}

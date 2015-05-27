#include "lexicalanalyzer.h"



using namespace std;


int main(int argc, const char* argv[]){
	
	lexicalanalyzer analyzed;
	
	ifstream in;
	//in.open(argv[1]);
	in.open("d:\Documents\BYU\Current Classes\CS236\Project2\test.txt");
	if (!in.is_open()) {
		return 1;
	};

	analyzed.analyze(in);


	in.close();
	return 0;
}

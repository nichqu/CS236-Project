#pragma once
#include "lexicalanalyzer.h"
#include "datalog.h"



using namespace std;



int main(int argc, const char* argv[]){
	
	lexicalanalyzer analyzed;
	vector<token*> tokenlist;
	datalog parsed;

	ifstream in;
	//in.open(argv[1]);
	//in.open("d:\\Documents\\BYU\\Current Classes\\CS236\\Project2\\CS236 Project\\goodtest.txt");
	in.open("C:\\Users\\Nicholas\\Source\\Repos\\CS236-Project\\goodtest.txt");
	if (!in.is_open()) {
		return 1;
	};

	analyzed.analyze(in, tokenlist);
	try {
		
		parsed.parse(tokenlist);
	}
	catch (int e) {
		
		cout << "Failure!\n";
		tokenlist[e]->tostring();

	}
	in.close();
	return 0;
}

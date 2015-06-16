#pragma once
#include "lexicalanalyzer.h"
#include "datalog.h"



using namespace std;



int main(int argc, const char* argv[]){
	
	lexicalanalyzer analyzed;
	vector<token*> tokenlist;
	

	ifstream in;
	//in.open(argv[1]);
	//in.open("d:\\Documents\\BYU\\Current Classes\\CS236\\Project2\\CS236 Project\\atest.txt");
	in.open("C:\\Users\\Nicholas\\Source\\Repos\\CS236-Project\\atest.txt");
	if (!in.is_open()) {
		return 1;
	};

	analyzed.analyze(in, tokenlist);
	datalog parsed(tokenlist);
	try {
		
		parsed.parse();
	}
	catch (string e) {
		
		cout << "Failure!\n" << e;

	}
	in.close();
	return 0;
}

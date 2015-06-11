#pragma once
#include "schemes.h"
#include "facts.h"
#include "rules.h"
#include "queries.h"
#include "token.h"
#include <iterator>
#include <vector>

using namespace std;

class datalog {

private:

	vector<token*>::iterator tokens;

public:
	datalog (vector<token*> &tokenlist) {
		tokens = tokenlist.begin();
	};

	void match(states tname, vector<token*>::iterator tokens) {

		if (tname == (*tokens)->name) {
			++tokens;
			
		}
		else {
			string temp = (*tokens)->tostring();
			throw temp;
			
		}

	}

	void parse() {
		match(SCHEMES, tokens);
		match(colon, tokens);
		



	};
};
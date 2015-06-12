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
	schemes* schemeobject;
	queries* queryobject;
	facts* factobject;
	rules* ruleobject;

public:
	datalog (vector<token*> &tokenlist) {
		tokens = tokenlist.begin();
		schemeobject = new schemes();
		queryobject = new queries();
		factobject = new facts();
		ruleobject = new rules();

	};

	void match(states tname, vector<token*>::iterator& tokens) {

		if (tname == (*tokens)->name) {
			++tokens;
			
		}
		else {
			string temp = (*tokens)->tostring();
			throw temp;
			
		}

	}

	string tostring() {
		string dstring;

		cout << "Success!\n";
		schemeobject->tostring();
		factobject->tostring();
		ruleobject->tostring();
		queryobject->tostring();

	}


	void parse() {
		match(SCHEMES, tokens);
		match(colon, tokens);
		if (!schemeobject->schemelist(tokens)) {
			string temp = (*tokens)->tostring();
			throw temp;
		}
		if (!factobject->factlist(tokens)) {
			string temp = (*tokens)->tostring();
			throw temp;
		}
		

		tostring();

	};
};
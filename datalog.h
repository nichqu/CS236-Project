#pragma once
#include "schemes.h"
#include "facts.h"
#include "rules.h"
#include "queries.h"
#include "token.h"
#include <iterator>

using namespace std;
template <class type>
class datalog {

private:
	schemes schemeobject;
	facts factobject;
	rules ruleobject;
	queries queryobject;
	int tokencount;

public:
	datalog(vector<token*> &tokenlist) {
		schemeobject = new schemes();
		factobject = new facts();
		ruleobject = new rules();
		queryobject = new queries();
		tokencount = 0;
		iterator tokens = tokenlist.begin;
	}

	bool match(states tname, tokens) {

		if (tname == temp->name) {
			ctoken++;
			return true;
		}
		else {
			throw tokens;
		}

	}

	void parse() {
		match(SCHEMES, tokens);
		match(colon, tokens)
		



	};
};
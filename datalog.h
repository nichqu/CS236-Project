#pragma once
#include "schemes.h"
#include "facts.h"
#include "rules.h"
#include "queries.h"
#include "token.h"

using namespace std;

class datalog {

private:
	schemes schemeobject;
	facts factobject;
	rules ruleobject;
	queries queryobject;

public:
	
	void parse(vector<token*> &tokenlist) {
		//schemeobject = new schemes();



	};
};
#pragma once
#include "predicates.h"

class rules {
private:
	int rulecount = 0;
	vector<predicate*> predlist;
public:

	void tostring() {
		string rulestring;
		for (int i = 0; i < list.size(); i++) {

			rulestring += list[i];

		}
		cout << "Rules(" << rulecount << "):\n" << rulestring;
		//return schemestring;

	}

};
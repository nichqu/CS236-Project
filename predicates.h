#pragma once
#include "parameter.h"

class predicate {

private:
	predicate* head;
	


public:

	predicate() {}
	~predicate() {}

	bool predicatelist(vector<token*>::iterator tokens) {

		if (predicatefunc(tokens)) {
			if (commafunc(tokens)) {
				if (predicatelist(tokens)) {
					return true;
				}
			}
		}

	}


	bool predicatefunc(vector<token*>::iterator tokens) {

		if (identifier(tokens)) {
			return true;
		}

	}

};

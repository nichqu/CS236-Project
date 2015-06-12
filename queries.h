#pragma once
#include "predicates.h"


class queries {

private:
	int querycount = 0;
	vector<predicate*> predlist;
public:

	void tostring() {
		string querystring;
		for (int i = 0; i < list.size(); i++) {

			querystring += list[i];

		}
		cout << "Queries(" << querycount << "):\n" << querystring;
		//return schemestring;

	}


};
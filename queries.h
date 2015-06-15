#pragma once
#include "predicates.h"


class queries {

private:
	int querycount = 0;
	vector<string> list;
	predicate* predicates;
public:
	queries() {

		predicates = new predicate();

	}
	void tostring() {
		string querystring;
		for (int i = 0; i < list.size(); i++) {

			querystring += list[i];

		}
		cout << "Queries(" << querycount << "):\n" << querystring;
		//return schemestring;

	}

	bool querylist(vector<token*>::iterator &tokens) {
		if (query(tokens)) {
			if (querylist(tokens)) {
				return true;
			}
			return true;
		}

		return false;
	}

	bool query(vector<token*>::iterator &tokens) {

		//wrong need predicate funtion....
		if(predicatefunc(tokens)){
			if(qmarkfunc(tokens)){
			return true;
			}
		}		
		//string temp = (*tokens)->tostring();
		//throw temp;
		return false;
	}
	
	bool predicatefunc(vector<token*>::iterator &tokens){
		
		if (predicates->predicatelist(tokens)) {
			list.push_back(predicates->tostring());
			querycount++;
			return true;

		}
		string temp = (*tokens)->tostring();
		throw temp;
	}
	
	bool qmarkfunc(vector<token*>::iterator &tokens){
		
		if (qmark == (*tokens)->name) {
			list.push_back((*tokens)->value);
			++tokens;
			return true;
		}
		string temp = (*tokens)->tostring();
		throw temp;
		return false;
		
	}

	
};

#pragma once
#include "predicates.h"


class rules {
private:
	int rulecount = 0;
	vector<string> list;
	predicate* predicates;
public:
	rules() { predicates = new predicate(); }
	~rules() {}
	void tostring() {
		string rulestring;
		for (int i = 0; i < list.size(); i++) {

			rulestring += list[i];

		}
		cout << "Rules(" << rulecount << "):\n" << rulestring;
		//return schemestring;

	}
	bool rulelist(vector<token*>::iterator &tokens) {
		
		if (QUERIES == (*tokens)->name) {
			return true;
		}
		if (rule(tokens)) {
			if (rulelist(tokens)) {
				return true;
			}
			return true;
		}

		return false;
	}

	bool rule(vector<token*>::iterator &tokens) {

		if (headpredicate(tokens)) {
			if (colondash(tokens)) {
				if (predicateslist(tokens)) {
					if (periodfunc(tokens)) {
						rulecount++;
						return true;
					}
				}
				string temp = (*tokens)->tostring();
				throw temp;

			}
		}
		return true;
	}

	bool predicateslist(vector<token*>::iterator &tokens) {

		if (predicates->predicatelist(tokens)) {
			list.push_back(predicates->tostring());
			return true;

		}
		string temp = (*tokens)->tostring();
		throw temp;

	}

	bool headpredicate(vector<token*>::iterator &tokens) {
		
		if (predicates->predicatelist(tokens)) {
			list.push_back(predicates->tostring());
			return true;

		}
		string temp = (*tokens)->tostring();
		throw temp;
		return false;
	}

	bool fstring(vector<token*>::iterator &tokens) {
		//add to domain
		if (STRING == (*tokens)->name) {
			list.push_back((*tokens)->value);
			++tokens;
			return true;
		}
		else {
			string temp = (*tokens)->tostring();
			throw temp;
			return false;
		}
	}

	bool identifier(vector<token*>::iterator &tokens) {

		if (ID == (*tokens)->name) {
			list.push_back((*tokens)->value);
			++tokens;
			return true;
		}
		if (QUERIES == (*tokens)->name) {
			return false;
		}
		else {
			string temp = (*tokens)->tostring();
			throw temp;
			return false;
		}
	}

	bool idlist(vector<token*>::iterator &tokens) {

		if (identifier(tokens)) {
			if (commafunc(tokens)) {
				if (idlist(tokens)) {
					return true;
				}
			}
			return true;
		}
		else if (QUERIES == (*tokens)->name) {
			return false;
		}
		string temp = (*tokens)->tostring();
		throw temp;
		return false;

	}

	bool l_paren(vector<token*>::iterator &tokens) {
		if (lparen == (*tokens)->name) {
			list.push_back((*tokens)->value);
			++tokens;
			return true;
		}
		string temp = (*tokens)->tostring();
		throw temp;
		return false;
	}

	bool r_paren(vector<token*>::iterator &tokens) {

		if (rparen == (*tokens)->name) {
			list.push_back((*tokens)->value);
			++tokens;
			return true;
		}
		string temp = (*tokens)->tostring();
		throw temp;
		return false;
	}

	bool commafunc(vector<token*>::iterator& tokens) {

		if (comma == (*tokens)->name) {
			list.push_back((*tokens)->value);
			++tokens;
			return true;
		}
		string temp = (*tokens)->tostring();
		throw temp;
		return false;
	}

	bool periodfunc(vector<token*>::iterator &tokens) {

		if (period == (*tokens)->name) {
			list.push_back((*tokens)->value);
			list.push_back("\n");
			++tokens;
			return true;
		}
		else {

			string temp = (*tokens)->tostring();
			throw temp;
			return false;

		}
	}

	bool colondash(vector<token*>::iterator &tokens) {

		if (colon_dash == (*tokens)->name) {
			list.push_back(" ");
			list.push_back((*tokens)->value);
			list.push_back(" ");
			++tokens;
			return true;
		}
		else {

			string temp = (*tokens)->tostring();
			throw temp;
			return false;

		}
	}

};
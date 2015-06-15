#pragma once
#include "parameter.h"

//template <typename t>

class predicate {

private:
	parameter* parameters;
	vector<string> list;

public:

	predicate() {
		parameters = new parameter();
	}
	~predicate() {}

	string tostring() {

		string schemestring;
		for (int i = 0; i < list.size(); i++) {

			schemestring += list[i];

		}

		return schemestring;

	}

	bool predicatelist(vector<token*>::iterator &tokens) {

		if (predicatefunc(tokens)) {
			if (commafunc(tokens)) {
				if (predicatelist(tokens)) {
					return true;
				}
			}
			return true;
		}
		return false;
	}


	bool predicatefunc(vector<token*>::iterator &tokens) {

		if (identifier(tokens)) {
			if (l_paren(tokens)) {
				if (parameters->parameterlist(tokens)) {
					list.push_back(parameters->tostring());
					if (r_paren(tokens)) {
						return true;
					}
				}
			}
		}
		return false;
	}

	bool identifier(vector<token*>::iterator &tokens) {

		if (ID == (*tokens)->name) {
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

	bool commafunc(vector<token*>::iterator& tokens) {

		if (comma == (*tokens)->name) {
			list.push_back((*tokens)->value);
			++tokens;
			return true;
		}
		else if (colon_dash == (*tokens)->name) {
			return false;
		}
		else if (period == (*tokens)->name) {
			return false;
		}
		else if (qmark == (*tokens)->name) {
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
			list.push_back("\n");
			return true;
		}
		string temp = (*tokens)->tostring();
		throw temp;
		return false;
	}

};

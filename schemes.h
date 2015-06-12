#pragma once
#include <vector>

using namespace std;

class schemes {
private:
	vector<string> list;
	int schemecount = 0;

public:
	schemes() {}
	~schemes() {}
	void tostring() {
		string schemestring;
		for (int i = 0; i < list.size(); i++) {

			schemestring += list[i];

		}
		cout << "Schemes(" << schemecount << "):\n" << schemestring;
		//return schemestring;

	}

	bool schemelist(vector<token*>::iterator &tokens) {
		if (scheme(tokens)) {
			if (schemelist(tokens)) {
				return true;
			}
			return true;
		}
		string temp = (*tokens)->tostring();
		throw temp;
		return false;
	}

	bool scheme(vector<token*>::iterator &tokens) {

		if (identifier(tokens)) {
			if (l_paren(tokens)) {
				if (idlist(tokens)) {
					if (r_paren(tokens)) {
						
						schemecount++;
						return true;
						
					}
				}
			}
		}
		string temp = (*tokens)->tostring();
		throw temp;
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

	bool idlist(vector<token*>::iterator &tokens) {

		if (identifier(tokens)) {
			if (commafunc(tokens)) {
				if (idlist(tokens)) {
					return true;
				}
			}
			return true;
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



};
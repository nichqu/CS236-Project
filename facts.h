#pragma once


class facts {
private:
	int factcount = 0;
	vector<string> list;

public:

	void tostring() {
		string factstring;
		for (int i = 0; i < list.size(); i++) {

			factstring += list[i];

		}
		cout << "Facts(" << factcount << "):\n" << factstring;
		//return schemestring;

	}

	bool factlist(vector<token*>::iterator &tokens) {
		if (fact(tokens)) {
			if (factlist(tokens)) {
				return true;
			}
			return true;
		}
		
		return false;
	}

	bool fact(vector<token*>::iterator &tokens) {
		if (ID == (*tokens)->name) { list.push_back("  "); }
		if (identifier(tokens)) {
			if (l_paren(tokens)) {
				if (stringlist(tokens)) {
					if (r_paren(tokens)) {
						if (periodfunc(tokens)) {
							factcount++;
							return true;
						}
					}
				}
			}
		}
		
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
		else if (RULES == (*tokens)->name) {
			return false;
		}
		else {
			string temp = (*tokens)->tostring();
			throw temp;
			return false;
		}
	}

	bool stringlist(vector<token*>::iterator &tokens) {

		if (fstring(tokens)) {
			if (commafunc(tokens)) {
				if (stringlist(tokens)) {
					return true;
				}
			}
			return true;
		}
		
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
		else if (rparen == (*tokens)->name) {
			return false;
		}
		string temp = (*tokens)->tostring();
		throw temp;
		return false;
	}

	bool periodfunc(vector<token*>::iterator &tokens) {

		if (period == (*tokens)->name) {
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



};
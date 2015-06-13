#pragma once



class queries {

private:
	int querycount = 0;
	vector<string> list;
public:

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

		if (identifier(tokens)) {
			if (l_paren(tokens)) {
				if (stringlist(tokens)) {
					if (r_paren(tokens)) {

						querycount++;
						return true;

					}
				}
			}
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
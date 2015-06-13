#pragma once
#include <vector>
#include <iterator>
#include "token.h"

using namespace std;

class parameter {
private:
	vector<string> list;



public:
	//parameterlist and string or id
	parameter(){}
	~parameter(){}

	bool parameterlist(vector<token*>::iterator &tokens) {

		if (Parameter(tokens)) {
			if (commafunc(tokens)) {
				if (parameterlist(tokens)) {
					return true;
				}
			}
			
		}
		
		return false;

	}

	bool Parameter(vector<token*>::iterator &tokens) {

		if (stringid(tokens)) {

			return true;

		}

	}

	bool stringid(vector<token*>::iterator &tokens) {

		if (STRING == (*tokens)->name || ID == (*tokens)->name) {

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
		else if (STRING == (*tokens)->name || ID == (*tokens)->name || rparen == (*tokens)->name) {

			return false;

		}
		string temp = (*tokens)->tostring();
		throw temp;
		return false;
	}
};
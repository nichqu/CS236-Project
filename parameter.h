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
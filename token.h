#pragma once
#include <iostream>


using namespace std;
enum states { start, period, comma, qmark, lparen, rparen, colon, colon_dash, SCHEMES, FACTS, RULES, QUERIES, ID, STRING, WHITESPACE, UNDEFINED, endn, COMMENT };
const char* statenames[] = { "START", "PERIOD", "COMMA", "Q_MARK", "LEFT_PAREN", "RIGHT_PAREN", "COLON", "COLON_DASH", "SCHEMES", "FACTS", "RULES", "QUERIES", "ID", "STRING", "WHITESPACE", "UNDEFINED", "EOF", "COMMENT" };


class token {
private:
	int ctoken = 0;
public:
		states name;
		string tokentype;
		int linenum;

		token(states iname, string ivalue, int iline){
			name = iname;
			tokentype = ivalue;
			linenum = iline;
			
		};
	
	void tostring(){
	
		cout << "(" << statenames[name] << ",\"" << tokentype << "\"," << linenum << ")\n"; 
		
	};
	
	bool match(states tname, vector<token*> &tokenlist) {

		if (tname == tokenlist[ctoken]->name) {
			ctoken++;
			return true;
		}
		else {
			throw ctoken;
		}

	}
	
	
	
	
};
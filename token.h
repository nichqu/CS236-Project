#pragma once
#include <iostream>
#include <sstream>


using namespace std;
enum states { start, period, comma, qmark, lparen, rparen, colon, colon_dash, SCHEMES, FACTS, RULES, QUERIES, ID, STRING, WHITESPACE, UNDEFINED, endn, COMMENT };
const char* statenames[] = { "START", "PERIOD", "COMMA", "Q_MARK", "LEFT_PAREN", "RIGHT_PAREN", "COLON", "COLON_DASH", "SCHEMES", "FACTS", "RULES", "QUERIES", "ID", "STRING", "WHITESPACE", "UNDEFINED", "EOF", "COMMENT" };


class token {
private:
	
public:
		states name;
		string value;
		int linenum;

		token(states iname, string ivalue, int iline){
			name = iname;
			value = ivalue;
			linenum = iline;
			
		};
	
	string tostring(){
		stringstream os;
		string temp;

		os << "(" << statenames[name] << ",\"" << value << "\"," << linenum << ")\n"; 
		os >> temp;

		return temp;
	};
	
	
	
	
	
	
};
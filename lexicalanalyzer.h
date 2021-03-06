#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "token.h"

using namespace std;
//enum states {start, period, comma, qmark, lparen, rparen, colon, colon_dash, SCHEMES, FACTS, RULES, QUERIES, ID, STRING, WHITESPACE, UNDEFINED, endn, COMMENT};



class lexicalanalyzer {
	private:
	string line;
	int linenum = 0;
	char c;
	int i;
	int tokens = 0;

	states cstate;
	public:
	
	
	void analyze(ifstream &in, vector<token*> &tokenlist){
	cstate = start;

	while (cstate != endn){

		getline(in, line);
		linenum++;
		i = 0;
		while (line[i] != NULL){

			c = line[i];
			if (cstate == start){
				if (c == ','){
					cstate = comma;
					token *temp = new token(comma, ",", linenum);
					tokenlist.push_back(temp);
					
					//cout << tokenlist[tokens-1] << endl;
					
					//cout << "(COMMA,\",\"," << linenum << ")\n";
					tokens++;
					cstate = start;
				}
				
				else if (c == '.'){
					cstate = period;
					token *temp = new token(period, ".", linenum);
					tokenlist.push_back(temp);
					//cout << &tokenlist[tokens-1] << endl;
					//cout << "(PERIOD,\".\"," << linenum << ")\n";
					tokens++;
					cstate = start;
				}

				else if (c == '?'){
					cstate = qmark;
					token *temp = new token(qmark, "?", linenum);
					tokenlist.push_back(temp);
					//cout << &tokenlist[tokens-1] << endl;
					//cout << "(Q-MARK,\"?\"," << linenum << ")\n";
					tokens++;
					cstate = start;
				}
				else if (c == '('){
					cstate = lparen;
					token *temp = new token(lparen, "(", linenum);
					tokenlist.push_back(temp);
					//cout << &tokenlist[tokens-1] << endl;
					//cout << "(LEFT_PAREN,\"(\"," << linenum << ")\n";
					tokens++;
					cstate = start;
				}
				else if (c == ')'){
					cstate = rparen;
					token *temp = new token(rparen, ")", linenum);
					tokenlist.push_back(temp);
					//cout << &tokenlist[tokens-1] << endl;
					//cout << "(RIGHT_PAREN,\")\"," << linenum << ")\n";
					tokens++;
					cstate = start;
				}
				else if (c == ':'){
					if (line[i + 1] == '-'){
						cstate = colon_dash;
						token *temp = new token(colon_dash, ":-", linenum);
						tokenlist.push_back(temp);
						//cout << &tokenlist[tokens-1] << endl;
						//cout << "(COLON_DASH,\":-\"," << linenum << ")\n";
						tokens++;
						i++;
						cstate = start;
					}
					else{
						cstate = colon;
						token *temp = new token(colon, ":", linenum);
						tokenlist.push_back(temp);
						//cout << &tokenlist[tokens-1] << endl;
						//cout << "(COLON,\":\"," << linenum << ")\n";
						tokens++;
						cstate = start;
					}
				}
				
				else if (c == '\''){
					cstate = STRING;
					string temp1;
					int templine;
					temp1+=line[i];
					i++;
					templine = linenum;
					
					do {

						temp1 += line[i];
						if (line[i] == NULL) {
							getline(in, line);
							temp1 += "\n";
							linenum++;
							i = -1;
						}
						i++;
						if (in.eof()) {
							cstate = endn;
							tokens++;

							break;
						}
						cstate = STRING;
						if (line[i] == '\'' && line[i+1] == '\'') {
							bool b = true;
						while (b == true) {
								temp1 += line[i];
								i++;
								if (line[i] != '\'' && line[i - 1] == '\'') {
									b = false;
								}
								
							}
							//cstate = start;
						}
						if (line[i] == NULL && line[i-1] == '\'') {
							cstate = start;
							
							break;
						}
						

					} while (line[i] != '\'');
					
					
					if(cstate == STRING){
						temp1 += line[i];
						i++;
					}
					else {
						temp1 += line[i];
						cstate = STRING;
					}
					if (in.eof()){
						token *temp = new token(UNDEFINED, temp1, templine);
						tokenlist.push_back(temp);
						//cout << "(UNDEFINED,\"" << temp1 << "\"," << templine << ")\n";
						break;
					}
					token *temp = new token(STRING, temp1 , templine);
					tokenlist.push_back(temp);
					//cout << "(STRING,\"" << temp1 << "\"," << templine << ")\n";
					tokens++;
					//cstate = start;
					
				}

				else if (c == '#'){
					int templine = 0;
					string temp;
					templine = linenum;
					cstate = COMMENT;

					if (line[i + 1] == '|'){

						do  {
							temp.push_back(line[i]);
							if (line[i] == NULL){
								getline(in, line);
								linenum++;
								i = -1;
							}
							i++;
							if (in.eof() && line[i] == NULL){
								cstate = endn;
								tokens++;

								break;
							}
						} while (line[i] != '#');
						temp.push_back(line[i]);
						i++;
					}
					else {
						while (line[i] != NULL){
							temp.push_back(line[i]);
							i++;

						}
					}
					if (in.eof()){
						//token *tempt = new token("UNDEFINED", temp , templine);
						//tokenlist.push_back(tempt);
						//cout << "(UNDEFINED,\"" << temp << "\"," << templine << ")\n";
						break;
					}
					tokens++;
					//token *tempt = new token("COMMENT", temp , templine);
					//tokenlist.push_back(tempt);
					//cout << "(COMMENT,\"" << temp << "\"," << templine << ")\n";

				}

				else if (isalpha(c)){
					string temp;
					while (line[i] != ' ' && line[i] != ',' && line[i] != '(' && line[i] != ')' && line[i] != '?' && line[i] != '\'' && !ispunct(line[i]) && line[i] != NULL) {
						temp.push_back(line[i]);
						i++;
					}
					if (temp == "Schemes"){
						cstate = SCHEMES;
						token *tempt = new token(SCHEMES, "Schemes" , linenum);
						tokenlist.push_back(tempt);
						//cout << "(SCHEMES,\"Schemes\"," << linenum << ")\n";
						tokens++;

					}
					else if (temp == "Facts"){
						cstate = FACTS;
						token *tempt = new token(FACTS, "Facts", linenum);
						tokenlist.push_back(tempt);
						//cout << "(FACTS,\"Facts\"," << linenum << ")\n";
						tokens++;

					}
					else if (temp == "Rules"){
						cstate = RULES;
						token *tempt = new token(RULES, "Rules", linenum);
						tokenlist.push_back(tempt);
						//cout << "(RULES,\"Rules\"," << linenum << ")\n";
						tokens++;

					}
					else if (temp == "Queries"){
						cstate = QUERIES;
						token *tempt = new token(QUERIES, "Queries", linenum);
						tokenlist.push_back(tempt);
						//cout << "(QUERIES,\"Queries\"," << linenum << ")\n";
						tokens++;

					}
					else{
						cstate = ID;
						token *tempt = new token(ID, temp , linenum);
						tokenlist.push_back(tempt);
						//cout << "(ID,\"" << temp << "\"," << linenum << ")\n";
						tokens++;

					}

				}

				else if (!isspace(c)) {
					string temp;
					temp.push_back(c);
					cstate = UNDEFINED;
					token *tempt = new token(UNDEFINED, temp , linenum);
					tokenlist.push_back(tempt);
					//cout << "(UNDEFINED,\"" << c << "\"," << linenum << ")\n";
					tokens++;
					cstate = start;

				}
			}
			if (cstate == start){
				i++;
			}
			else{
				cstate = start;
			}
		}
		if (in.eof()){
			cstate = endn;
			tokens++;
		}
	}

	token *tempt = new token(endn, "EOF", linenum);
	tokenlist.push_back(tempt);
	//cout << "(EOF,\"\"," << linenum << ")\n";
	//cout << "Total Tokens = " << tokens << endl;
	};
};

#include <iostream>

using namespace std;


class token {
	private:
		string name;
		string tokentype;
		int linenum;
		
	public:
		
		token(string iname, string ivalue, int iline){
			name = iname;
			ivalue = tokentype;
			iline = linenum;
			
		};
	
	void tostring(){
	
		cout << "(" << name << ",\"" << tokentype << ",\"" << linenum << ")\n"; 
		
	};
	
	
	
	
	
};
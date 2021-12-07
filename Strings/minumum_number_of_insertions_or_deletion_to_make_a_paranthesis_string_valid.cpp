
#include <iostream>
using namespace std;

string MinEdits(string p){
	int open=0;
	string bp="";
	for(char c:p){
		if(c=='(')
			open++;
		else if(c==')'){
			if(open==0)
				bp += "(";
			else
				open--;
		}
		bp += c;
	}
	while(open--)
		bp += ")";
	return bp;
}

int main() {
	string p = "(()";
	cout<<MinEdits(p)<<endl;
	return 0;
}
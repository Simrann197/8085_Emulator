#include "../HeaderFiles/tools.h"

bool validityData(string str){
	if(str.length()!=2)	return false;
	for(int i=0;i<str.length();i++){
		if((str[i]>='A'&&str[i]<='F')||(str[i]>='0'&&str[i]<='9'))	continue;
		else return false;
	}
	return true;
}
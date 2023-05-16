#ifndef _BRANCHING_H
#define _BRANCHING_H
#include "header.h"

string JMP(string, string[], bool[]);
/*All other jump statements require program counter to be passed as an 
	argument as to find the next possible location possible*/
/*Second argument is the address in program counter*/

string JC(string, string, string[],bool[]);
string JNC(string, string, string[],bool[]);
string JZ(string, string, string[],bool[]);
string JNZ(string, string, string[],bool[]);

#endif
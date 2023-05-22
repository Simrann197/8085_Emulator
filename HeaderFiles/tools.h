#ifndef _TOOLS_H
#define _TOOLS_H
#include "header.h"

bool validityAddress(string);
string hexAdd(string,string,bool[],bool);
string hexSub(string,string,bool[],bool);
void hexToDecimal(string,int[]);
bool validityRegisters(string);
bool validityRegisterPair(string);
bool validityData(string);
int registerNumber(string);
bool validityFile(string);
string increaseAddress(string);
string complement(string);
int operationSize(string);
string execution(string, string[], bool[], map<string,string>&,string);
string updatedAddress(string,map<string,string>&);
string execution(string command, string Registers[], bool flag[], map<string,string>&memory,string programCounter);
void executionDebugger(string pc, map<string, string> &Memory, vector<string> &sequence, bool flag[], string registers[]);
void executionNormal(string pc, map<string, string> &Memory, vector<string> &sequence, bool flag[], string registers[]);
string hexSub16bit(string arg1,string arg2,bool flag[],bool carry);
void display(string registers[],bool flags[]);

#endif

//https://github.com/Hardik3296/8085simulator/tree/master
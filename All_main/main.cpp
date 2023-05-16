#include "../HeaderFiles/Arithmetic.h"
#include "../HeaderFiles/branching.h"
#include "../HeaderFiles/header.h"
#include "../HeaderFiles/load.h"
#include "../HeaderFiles/logical.h"
#include "../HeaderFiles/tools.h"

// class simulator8085
// {
// private:
//      map<string,string> Memory;
//      vector<string>sequence;
//      string start;
//      string pc;
//      bool flag[5];
//      string registers[7];
// public :
// 	simulator8085(){
// 		for(int i = 0;i<7;i++)
// 			registers[i] = "NULL";
		
// 		for(int i=0;i<8;i++)
// 			flag[i] = false;
		
// 		start = "";
// 		pc = "";
// 	}
//     void input()
//     {
//         cout<<"\nEnter the starting address:\n";
//         cin>>start;
//         pc = start;
//         if(!validityAddress(start)){
			
// 			cout<<"The memory you entered either does not exist or is reserved by the system\nPlease re-enter the program from a new memory location\nThe program will quit\n";
// 			exit(1);
// 		}
//         sequence.push_back(start);
//     }
//     void programFileWithDebugger(char* filename)
//     {
//         ifstream input;
// 		input.open(filename);
// 		if(input.fail() == true){
			
// 			cout<<"You have entered an invalid filename\nThe prorgam will quit\n";
// 			exit(0);
// 		}
// 		string line;
// 		while(1)
// 		{
// 		    getline(input,line);
// 			if(validityFile(line))
// 			{
//                 Memory[pc]=line;
// 				pc=updatedAddress(pc,Memory);
// 				if(line=="HLT")
// 					break; 
// 				sequence.push_back(pc);
// 			}
// 			else{
				
// 				cout<<"Error: "<<line<<"\n";
// 				cout<<"You have entered an incorrect statement\nThe program will quit\n"<<endl;
// 				exit(0);
// 			}
// 		}
// 		executionDebugger(start,Memory,sequence,flag,registers);
//     }
//     void onlyProgramFile(char* filename)
//     {
//         ifstream input;
//         input.open(filename);
//         if(input.fail() == true){
			
// 			cout<<"You have entered an invalid filename\nThe prorgam will quit\n";
// 			exit(0);
// 		}
//         string line;
//         while(1)
//         {
//             getline(input,line);
//             if(validityFile(line))
//             {
//                 Memory[pc]=line;
//                 pc=updatedAddress(pc,Memory);
//                 if(line=="HLT")
// 					break;
//                 sequence.push_back(pc);
// 			}else{
				
// 				cout<<"Error: "<<line<<"\n";
// 				cout<<"You have entered an incorrect statement\nThe program will quit\n"<<endl;
// 				exit(0);
// 			}
//         }
//         executionNormal(start,Memory,sequence,flag,registers);
//     }
//     void onlyDebugger()
//     {
// 		cin.ignore();
//         cout<<"\nStart typing your code from here:\n";
// 		while(1)
// 		{
// 			cout<<">> "<<pc<<" ";
// 			string line;
// 			getline(cin,line);
// 			if(validityFile(line))
// 			{
// 			   	Memory[pc]=line;
// 				pc=updatedAddress(pc,Memory);
// 				if(line == "HLT"){
// 					break;
// 				sequence.push_back(pc);
// 				}
// 			}
// 			else{
				
// 				cout<<"Error: "<<line<<"\n";
// 				cout<<"You have entered an incorrect statement\nThe program will quit\n"<<endl;
// 				exit(0);
// 			}
// 		}
// 		executionDebugger(start,Memory,sequence,flag,registers);
//     }
//     void noInput()
//     {
// 		cin.ignore();
//         string line;
//         cout<<"\nStart typing your code from here:\n";
// 		while(1)
// 		{
// 			cout<<">> "<<pc<<" ";
// 			getline(cin,line);
// 			if(validityFile(line))
// 			{
// 			 	Memory[pc]=line;
// 				pc=updatedAddress(pc,Memory);
// 				if(line=="HLT")
// 					break;
// 				sequence.push_back(pc);
// 			}else{
				
// 				cout<<"Error: "<<line<<"\n";
// 				cout<<"You have entered an incorrect statement\nThe program will quit\n"<<endl;
// 				exit(0);
// 			}
// 		}
// 		executionNormal(start,Memory,sequence,flag,registers);
//     }
// };

// int main(int argc,char* argv[])
// {
//     simulator8085 machine;
//     machine.input();
//     if(argc==2)
//     {
// 	if(strcmp(argv[1],"--debugger")==0)
//         {
//             machine.onlyDebugger();
//         }
//         else
//         {
//             machine.onlyProgramFile(argv[1]);
//         }
//     }
//     else if(argc==1)
//     {
//         machine.noInput();
//     }
//     else if(argc==3)
//     {
// 	machine.programFileWithDebugger(argv[1]);
//     }
// }

class simulator8085
{
public :
     map<string,string> Memory;
     vector<string>sequence;
     string start;
     string pc;
     bool flag[5];
     string registers[7];
	simulator8085(){
		for(int i = 0;i<7;i++)
			registers[i] = "NULL";
		
		for(int i=0;i<8;i++)
			flag[i] = false;
		
		start = "";
		pc = "";
	}
    void input()
    {
        cout<<"\nEnter the starting address:\n";
        cin>>start;
        pc = start;
        if(!validityAddress(start)){
			
			cout<<"The memory you entered either does not exist or is reserved by the system\nPlease re-enter the program from a new memory location\nThe program will quit\n";
			exit(1);
		}
        sequence.push_back(start);
    }
    void programFileWithDebugger(char* filename)
    {
        ifstream input;
		input.open(filename);
		if(input.fail() == true){
			
			cout<<"You have entered an invalid filename\nThe prorgam will quit\n";
			exit(0);
		}
		string line;
		while(1)
		{
		    getline(input,line);
			if(validityFile(line))
			{
                Memory[pc]=line;
				pc=updatedAddress(pc,Memory);
				if(line=="HLT")
					break; 
				sequence.push_back(pc);
			}
			else{
				
				cout<<"Error: "<<line<<"\n";
				cout<<"You have entered an incorrect statement\nThe program will quit\n"<<endl;
				exit(0);
			}
		}
		executionDebugger(start,Memory,sequence,flag,registers);
    }
    void onlyProgramFile(char* filename)
    {
        ifstream input;
        input.open(filename);
        if(input.fail() == true){
			
			cout<<"You have entered an invalid filename\nThe prorgam will quit\n";
			exit(0);
		}
        string line;
        while(1)
        {
            getline(input,line);
            if(validityFile(line))
            {
                Memory[pc]=line;
                pc=updatedAddress(pc,Memory);
                if(line=="HLT")
					break;
                sequence.push_back(pc);
			}else{
				
				cout<<"Error: "<<line<<"\n";
				cout<<"You have entered an incorrect statement\nThe program will quit\n"<<endl;
				exit(0);
			}
        }
        executionNormal(start,Memory,sequence,flag,registers);
    }
    void onlyDebugger()
    {
		cin.ignore();
        cout<<"\nStart typing your code from here:\n";
		while(1)
		{
			cout<<">> "<<pc<<" ";
			string line;
			getline(cin,line);
			if(validityFile(line))
			{
			   	Memory[pc]=line;
				pc=updatedAddress(pc,Memory);
				if(line == "HLT"){
					break;
				sequence.push_back(pc);
				}
			}
			else{
				
				cout<<"Error: "<<line<<"\n";
				cout<<"You have entered an incorrect statement\nThe program will quit\n"<<endl;
				exit(0);
			}
		}
		executionDebugger(start,Memory,sequence,flag,registers);
    }
    void noInput()
    {
		cin.ignore();
        string line;
        cout<<"\nStart typing your code from here:\n";
		while(1)
		{
			cout<<">> "<<pc<<" ";
			getline(cin,line);
			if(validityFile(line))
			{
			 	Memory[pc]=line;
				pc=updatedAddress(pc,Memory);
				if(line=="HLT")
					break;
				sequence.push_back(pc);
			}else{
				
				cout<<"Error: "<<line<<"\n";
				cout<<"You have entered an incorrect statement\nThe program will quit\n"<<endl;
				exit(0);
			}
		}
		executionNormal(start,Memory,sequence,flag,registers);
    }
	void displayMemory(string address)
    {
        cout << "Enter -1 to exit this mode" << endl;
        while (1)
        {
            if (Memory[address].length() == 0)
                Memory[address] = "00";
            cout << address << " : " << Memory[address] << " : ";
            string updation;
            cin >> updation;
            if (updation == "-1")
                break;
            if (validityData(updation))
            {
                if (updation != "-1")
                    Memory[address] = updation;
            }
            else
            {
                cout << "Invalid data value" << endl;
                exit(0);
            }
            increaseAddress(address);
        }
    }
};

int main()
{
    simulator8085 machine;
    cout << "Enter the mode you want to open" <<endl
             << "--------------------------------------------------------------------------------------------------------------------------------------"<<endl
             << " A - To Enter the code" << " M - To access the memory" << " G - To run the code" << " D - To enter debugger mode"<< " X - To exit the program" <<endl
             << "--------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    while (1)
    {
        cout << "Enter the mode you want to open" <<endl;
        string mode;
        cin >> mode;
        if (mode == "X")
            break;
        if (mode == "M")
        {
            cout << "Enter the memory address you want to check" << endl;
            string address;
            cin >> address;
            machine.displayMemory(address);
        }
        else if(mode == "D"){
            executionDebugger(machine.pc,machine.memory,machine.flags,machine.registers);
        }
        else if (mode == "A")
        {
            machine.input();
            if(machine.readFile())  cout << "Successfully read the code from the file"<< endl <<"             -------------\n"<<"             | No errors |" <<endl <<"             -------------"<< endl;
        }
        else if (mode == "G")
        {
            executeInstructions(machine.pc, machine.accumulator, machine.registers, machine.memory, machine.flags);
            display(machine.accumulator,machine.registers,machine.flags);
            cout<<"Executed the code successfully"<<endl;
        }
        else
        {
            cout << "Enter a valid mode Restart the machine" << endl;
        }
        cout<<endl;
    }
    return 0;
}
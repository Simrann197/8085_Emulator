#include "../HeaderFiles/Arithmetic.h"
#include "../HeaderFiles/branching.h"
#include "../HeaderFiles/header.h"
#include "../HeaderFiles/load.h"
#include "../HeaderFiles/logical.h"
#include "../HeaderFiles/tools.h"

class simulator8085
{
public:
    map<string, string> Memory;
    vector<string> sequence;
    string start;
    string pc;
    bool flag[5];
    string registers[7];
    simulator8085()
    {
        for (int i = 0; i < 7; i++)
            registers[i] = "00";

        for (int i = 0; i < 8; i++)
            flag[i] = false;

        start = "";
        pc = "";
    }
    void input()
    {
        cout << "\nEnter the starting address:\n";
        cin >> start;
        pc = start;
        if (!validityAddress(start))
        {

            cout << "The memory you entered either does not exist or is reserved by the system\nPlease re-enter the program from a new memory location\nThe program will quit\n";
            exit(1);
        }
        sequence.push_back(start);
    }
    void onlyProgramFile(string filename)
    {
        ifstream input;
        input.open(filename);
        if (input.fail() == true)
        {

            cout << "You have entered an invalid filename\nThe prorgam will quit\n";
            exit(0);
        }
        string line;
        while (1)
        {
            getline(input, line);
            if (validityFile(line))
            {
                Memory[pc] = line;
                pc = updatedAddress(pc, Memory);
                if (line == "HLT")
                    break;
                sequence.push_back(pc);
            }
            else
            {

                cout << "Error: " << line << "\n";
                cout << "You have entered an incorrect statement\nThe program will quit\n"
                     << endl;
                exit(0);
            }
        }
        executionNormal(start, Memory, sequence, flag, registers);
    }
    void onlyDebugger()
    {
        cin.ignore();
        cout << "\nStart typing your code from here:\n";
        while (1)
        {
            cout << ">> " << pc << " ";
            string line;
            getline(cin, line);
            if (validityFile(line))
            {
                Memory[pc] = line;
                pc = updatedAddress(pc, Memory);
                if (line == "HLT")
                {
                    break;
                }
                sequence.push_back(pc);
            }
            else
            {

                cout << "Error: " << line << "\n";
                cout << "You have entered an incorrect statement\nThe program will quit\n"
                     << endl;
                exit(0);
            }
        }
        executionDebugger(start, Memory, sequence, flag, registers);
    }
    void noInput()
    {
        cin.ignore();
        string line;
        cout << "\nStart typing your code from here:\n";
        while (1)
        {
            cout << ">> " << pc << " ";
            getline(cin, line);
            if (validityFile(line))
            {
                Memory[pc] = line;
                pc = updatedAddress(pc, Memory);
                if (line == "HLT")
                    break;
                sequence.push_back(pc);
            }
            else
            {

                cout << "Error: " << line << "\n";
                cout << "You have entered an incorrect statement\nThe program will quit\n"
                     << endl;
                exit(0);
            }
        }
        executionNormal(start, Memory, sequence, flag, registers);
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
            address = increaseAddress(address);
        }
    }
};

int main()
{
    simulator8085 machine;
    machine.input();
    cout << "Enter the mode you want to open" << endl
         << "------------------------------------------------" << endl
         << " A - To Run the code with file" <<endl 
         << " M - To access the memory" <<endl
         << " G - To enter the code in terminal" <<endl
         << " X - To exit the program" <<endl 
         << " D - Debugger" <<endl
         << "-------------------------------------------------" << endl;
    while (true)
    {
        char choice;
        cout << "Enter the mode >> ";
        cin >> choice;
        if (choice == 'X')
            break;
        if (choice == 'A')
        {
            string fileName;
            cout<<"Enter the file name >> ";
            cin>>fileName;
            machine.onlyProgramFile(fileName);
            display(machine.registers,machine.flag);
        }
        else if (choice == 'G')
        {
            machine.noInput();
            display(machine.registers,machine.flag);
        }
        else if (choice == 'M')
        {
            cout << "Enter the memory Address >>";
            string address;
            cin >> address;
            if (validityAddress(address))
                machine.displayMemory(address);
            else
                cout << "Enter a valid address" << endl;
        }
        else if (choice == 'D')
        {
            machine.onlyDebugger();
        }
    }
}
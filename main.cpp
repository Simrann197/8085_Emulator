#include "../8085_Emulator/HeaderFiles/header.h"
class Emulator
{
private:
    map<string, string> memory;
    bool flag[5];
    string reg[7];
    string pc;

public:
    Emulator()
    {
        flag[5] = {false};
        reg[7] = {NULL};
    }
    void readFile()
    {
        ifstream data_file("input.txt");
        string data;
        if (!data_file.is_open())
        {
            cout<<"File not Found";
            exit(0);
        }
        else
        {
            string data;
            while (getline(data_file, data))
            {
                cout << data <<"\n";
            }
            data_file.close();
        }
    }
};
int main()
{
    Emulator machine;
    int start;
    cout << "Press 1 to  start the machine : ";
    cin >> start;
    if(start)
    machine.readFile();
    // while (1)
    // {
    //     char choice;
    //     cout << "Press A to write code /t Press G to execute /t Press M to input data in to the memory /t Press X to exit the program";
    //     cin >> choice;
    //     switch (choice)
    //     {
    //     case 'A':
    //     {
    //         char address;
    //         cout << "Enter an address from where you want to start the code";
    //         cin >> address;
    //         if (address.size() != 4)
    //         {
    //             cout << "Address is invalid";
    //             exit(0);
    //         }
    //         machine.pc = address;
    //         break;
    //     }
    //     case 'G':
    //     {
    //         executeProgram();
    //         break;
    //     }
    //     case 'M':
    //     {
    //         machine.display();
    //         break;
    //     }
    //     case 'X':
    //     {
    //         exit(0);
    //     }
    //     }
    // }
}
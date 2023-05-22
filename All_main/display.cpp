#include "../HeaderFiles/header.h"
#include "../HeaderFiles/tools.h"

void display(string registers[],bool flags[])
    {
        cout << setw(2) << "All the registers currently" << endl;
        cout <<"-----------------------------------------------------------------------"<<endl;
        cout << setw(2) << "| A:   " << setw(3) << registers[0] << "|";
        cout << setw(2) << " B:   " << setw(3) << registers[1] << "|";
        cout << setw(2) << " C:   " << setw(3) << registers[2] << "|";
        cout << setw(2) << " D:   " << setw(3) << registers[3] << "|";
        cout << setw(2) << " E:   " << setw(3) << registers[4] << "|";
        cout << setw(2) << " H:   " << setw(3) << registers[5] << "|";
        cout << setw(2) << " L:   " << setw(3) << registers[6] << "|" <<endl;
        cout <<"-----------------------------------------------------------------------"<<endl;
        cout << "All the Flags currently" << endl;
        cout <<"----------------------------------------------------------------------------"<<endl;
        cout << setw(2) << "| Sign :" << setw(3) << flags[0] << " |";
        cout << setw(2) << "| Zero :" << setw(3) << flags[1] << " |";
        cout << setw(2) << "| Axuiliary Carry:" << setw(3) << flags[3] << " |";
        cout << setw(2) << "| Parity:" << setw(3) << flags[5] << " |";
        cout << setw(2) << "| Carry:" << setw(3) << flags[7] << " |" <<endl;
        cout <<"----------------------------------------------------------------------------"<<endl;
        cout << endl;
    }
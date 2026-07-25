#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int choice;
    string username, password;
    string storedUser, storedPass;

    cout << "======================================" << endl;
    cout << "   Login & Registration System" << endl;
    cout << "======================================" << endl;

    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice)
    {
        case 1:
        {
            cout << "\n----- Registration -----" << endl;

            cout << "Enter Username: ";
            cin >> username;

            cout << "Enter Password: ";
            cin >> password;

            ofstream file("users.txt", ios::app);
            file << username << " " << password << endl;
            file.close();

            cout << "\nRegistration Successful!" << endl;
            break;
        }

        case 2:
        {
            cout << "\n----- Login -----" << endl;

            cout << "Enter Username: ";
            cin >> username;

            cout << "Enter Password: ";
            cin >> password;

            ifstream file("users.txt");

            bool found = false;

            while(file >> storedUser >> storedPass)
            {
                if(username == storedUser && password == storedPass)
                {
                    found = true;
                    break;
                }
            }

            file.close();

            if(found)
                cout << "\nLogin Successful!" << endl;
            else
                cout << "\nInvalid Username or Password!" << endl;

            break;
        }

        case 3:
            cout << "\nThank you! Exiting Program..." << endl;
            break;

        default:
            cout << "\nInvalid Choice!" << endl;
    }

    return 0;
}

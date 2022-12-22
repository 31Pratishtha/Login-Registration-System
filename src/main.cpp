#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// verify logged in or not
bool IsloggedIn()
{
    string username, password, un, pw;

    cout << "Enter username :";
    cin >> username;

    cout << "Enter password :";
    cin >> password;

    ifstream infile;
    infile.open("data.txt");
    getline(infile, un); // reading username
    getline(infile, pw); // reading password

    infile.close();

    if (un == username && pw == password)
        return true; // that the user is valid and can log in
    else
        return false;
}

int main()
{
    int choice;

    cout << "1: Register" << endl
         << "2: Login" << endl
         << "Your choice: ";
    cin >> choice;
    if (choice == 1)
    {
        string username, password;

        cout << "select a username :";
        cin >> username;
        cout << "select a password :";
        cin >> password;

        ofstream file;
        file.open("data.txt");

        // register the details in file
        file << username << endl
             << password;
        file.close();

        // returning main so that we can login again
        main();
    }

    else if (choice == 2)
    {
        bool status = IsloggedIn();

        if (!status) // user not logged in
        {
            cout << "Invalid user name password :" << endl;
            system("PAUSE");

            return 0;
        }
        else
        {
            cout << "Successfully Logged in" << endl;
            system("pause");
            return 1;
        }
    }
}

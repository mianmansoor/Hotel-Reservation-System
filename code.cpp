// Hotel Reservation System in C++
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <conio.h>

using namespace std;

struct HOTL
{
    int NUMBER = 1; // space in rooms
    int fill = 0; // room is filled or not
    char CUS_NAMES[3][10]; // customer names
};

class hotel
{
    HOTL TITLE[3][9];
    string registeredUsers[10][2];  // Array to store registered usernames and passwords
    int numRegisteredUsers = 0;  // Track the number of registered users

public:
    hotel()
    {
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 9; y++)
            {
                TITLE[x][y].NUMBER = 1;
            }
        }
    }

    // Function to register a new user
    void userRegistration()
    {
        string username, password;

        system("cls");

        cout << "\n\n\n\n\n\t\t\t\t\t--------------------------------------\n";
        cout << "\t\t\t\t\t| Welcome to Hotel Reservation System |";
        cout << "\n\t\t\t\t\t--------------------------------------\n\n";

        cout << "\n\n*************************\n";
        cout << "      REGISTRATION        \n";
        cout << "*************************\n";

        cout << "\n Enter a username: ";
        cin >> username;

        // Check if the username already exists
        for (int i = 0; i < numRegisteredUsers; i++)
        {
            if (registeredUsers[i][0] == username)
            {
                throw "Username already exists. Please choose a different username.";
            }
        }

        cout << " Enter a password: ";
        password = "";
        char ch;
        while ((ch = _getch()) != '\r') {  // Read characters until Enter is pressed
            if (ch == '\b') {  // Handle Backspace character
                if (!password.empty()) {
                    cout << "\b \b";  // Move the cursor back, overwrite with a space, move the cursor back again
                    password.pop_back();
                }
            }
            else {
                password += ch;
                cout << "*";
            }
        }

        // Add the new user to the registeredUsers array
        registeredUsers[numRegisteredUsers][0] = username;
        registeredUsers[numRegisteredUsers][1] = password;
        numRegisteredUsers++;

        // Save user registration data to file
        saveUserRegistrationToFile();

        cout << "\n User registration successful.";

        system("cls");
    }

    // Function to save user registration data to file
    void saveUserRegistrationToFile()
    {
        //File in which user registration are saved
        ofstream file("user_registration.txt", ios::app);

        if (!file)
        {
            throw "Error opening the file.";
        }

        file << registeredUsers[numRegisteredUsers - 1][0] << "," << registeredUsers[numRegisteredUsers - 1][1] << endl;

        file.close();
    }

    // Function to load user registration data from file
    void loadUserRegistrationFromFile()
    {
        //File from which user data is load
        ifstream file("user_registration.txt");

        if (!file)
        {
            throw "Error opening the file.";
        }

        string line;

        while (getline(file, line))
        {
            size_t pos = line.find(",");
            string username = line.substr(0, pos);
            string password = line.substr(pos + 1);
            registeredUsers[numRegisteredUsers][0] = username;
            registeredUsers[numRegisteredUsers][1] = password;
            numRegisteredUsers++;

            if (numRegisteredUsers >= 10)
            {
                throw "Maximum number of registered users exceeded.";
            }
        }

        file.close();
    }


    // Function to authenticate a user login
    bool userLogin()
    {
        string username, password;

        system("cls");

        cout << "\n\n\n\n\n\t\t\t\t\t--------------------------------------\n";
        cout << "\t\t\t\t\t| Welcome to Hotel Reservation System |";
        cout << "\n\t\t\t\t\t--------------------------------------\n\n";

        cout << "\n\n*************************\n";
        cout << "      USER LOGIN        \n";
        cout << "*************************\n";
        cout << "\n Enter the username: ";
        cin >> username;

        cout << " Enter the password: ";
        password = "";
        char ch;
        while ((ch = _getch()) != '\r') {  // Read characters until Enter is pressed
            if (ch == '\b') {  // Handle Backspace character
                if (!password.empty()) {
                    cout << "\b \b";  // Move the cursor back, overwrite with a space, move the cursor back again
                    password.pop_back();
                }
            }
            else {
                password += ch;
                cout << "*";
            }
        }

        // Check if the entered username and password match a registered user
        for (int i = 0; i < numRegisteredUsers; i++)
        {
            if (registeredUsers[i][0] == username && registeredUsers[i][1] == password)
            {
                return true;  // Authentication successful
            }
        }

        return false;  // Authentication failed
    }

    // Function to Display hotel status
    void display()
    {
        int y = 0, z = 0, w = 0;

        for (int x = 0; x < 48; x++)
        {
            cout << "--";
        }
        cout << "\n ";

        for (int x = 1; x < 4; x++)
        {
            cout << "| Floor number : " << x << " \t\t";
        }
        cout << "|\n";

        for (int x = 0; x < 48; x++)
        {
            cout << "--";
        }
        cout << "\n ";

        for (int y = 0; y < 9; y++)
        {
            if (TITLE[0][y].fill != TITLE[0][y].NUMBER && TITLE[0][y].NUMBER != 0)
            {
                cout << "| room no : " << y + 1;
                cout << "->Vacant space->" << TITLE[0][y].NUMBER;
            }
            else
            {
                cout << "| room no : " << y + 1;
                cout << "->Present ";
            }

            if (TITLE[1][y].fill != TITLE[1][y].NUMBER && TITLE[1][y].NUMBER != 0)
            {
                cout << "\t | room no : " << y + 1;
                cout << "->Vacant space->" << TITLE[1][y].NUMBER;
            }
            else
            {
                cout << " \t | room no : " << y + 1;
                cout << "->Present ";
            }

            if (TITLE[2][y].fill != TITLE[2][y].NUMBER && TITLE[2][y].NUMBER != 0)
            {
                cout << "\t | room no : " << y + 1;
                cout << "->Vacant space->" << TITLE[2][y].NUMBER << "| ";
            }
            else
            {
                cout << "\t | room no : " << y + 1;
                cout << "->Present | ";
            }

            cout << "\n ";
        }

        cout << "\n ";

        for (int x = 0; x < 48; x++)
        {
            cout << "--";
        }

        cout << "\n ";
    }

    // Function to book room
    void book()
    {
        int user_floor, user_room, roomType;

        cout << "\n\n*************************\n";
        cout << "      ROOM TYPES        \n";
        cout << "*************************\n";
        cout << "1. Standard" << endl;
        cout << "2. Deluxe" << endl;
        cout << "3. Suite" << endl;
        cout << "*************************\n";

        cout << "Enter the room type (1-3): ";
        cin >> roomType;

        cout << "\n";

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cancel();
        }

        if (roomType < 1 || roomType > 3)
        {
            cout << "Invalid room type. Please enter a number between 1 and 3." << endl;
            return;
        }

        cout << "\n Enter the floor number [1-3]: ";
        cin >> user_floor;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cancel();
        }

        if (user_floor < 1 || user_floor > 3)
        {
            throw "Invalid floor number.";
        }

        cout << " Enter the room number [1-9]: ";
        cin >> user_room;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cancel();
        }

        if (user_room < 1 || user_room > 9)
        {
            throw "Invalid room number.";
        }

        HOTL& room = TITLE[user_floor - 1][user_room - 1];

        if (room.fill != room.NUMBER)
        {
            cout << " Enter customer name: ";
            cin.ignore();
            cin.getline(room.CUS_NAMES[room.fill], 10);

            room.fill++;

            cout << "\nBooking your room...";

            cout << "\n Room booked successfully.";
        }
        else
        {
            throw "Room is already booked.";
        }
    }

    // Function to cancel booking
    void cancel()
    {
        int user_floor, user_room;

        cout << "\n Enter the floor number [1-3]: ";
        cin >> user_floor;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cancel();
        }

        if (user_floor < 1 || user_floor > 3)
        {
            throw "Invalid floor number.";
        }

        cout << " Enter the room number [1-9]: ";
        cin >> user_room;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cancel();
        }

        if (user_room < 1 || user_room > 9)
        {
            throw "Invalid room number.";
        }

        HOTL& room = TITLE[user_floor - 1][user_room - 1];

        if (room.fill != 0)
        {
            room.fill--;
            cout << "\n Room booking is cancelling...";

            cout << "\n\n Room booking canceled successfully.";
        }
        else
        {
            throw "No booking found for the room.";
        }
    }

    // Function to save data to file
    void saveDataToFile()
    {
        //File in which rooms status is stored
        ofstream file("hotel_data.txt");

        if (!file)
        {
            throw "Error opening the file.";
        }

        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 9; y++)
            {
                HOTL& room = TITLE[x][y];
                file << room.NUMBER << endl;
                file << room.fill << endl;

                for (int i = 0; i < room.fill; i++)
                {
                    file << room.CUS_NAMES[i] << endl;
                }
            }
        }
        file.close();

        cout << "Data is saving to file...";

        cout << "\n\nData saved to file successfully.";
    }

    // Function to load data from file
    void loadDataFromFile()
    {
        //File from which room status is load
        ifstream file("hotel_data.txt");

        if (!file)
        {
            throw "Error opening the file.";
        }

        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 9; y++)
            {
                HOTL& room = TITLE[x][y];
                file >> room.NUMBER;
                file >> room.fill;
                file.ignore(numeric_limits<streamsize>::max(), '\n');

                for (int i = 0; i < room.fill; i++)
                {
                    file.getline(room.CUS_NAMES[i], 10);
                }
            }
        }
        file.close();
        cout << "Data is loading from file...";

        cout << "\n\nData loaded from file successfully.";
    }

    // Function to display admnin panel
    void adminPanel()
    {
        int choice;

        while (true)
        {
            cout << "\n\n*************************\n";
            cout << "      ADMIN PANEL        \n";
            cout << "*************************\n";
            cout << " 1. Display hotel status\n";
            cout << " 2. Save data to file\n";
            cout << " 3. Load data from file\n";
            cout << " 4. Exit\n";
            cout << "*************************\n";

            cout << " Enter your choice: ";
            cin >> choice;

            cout << "\n";

            if (cin.fail())
            {
                cin.clear();

                cout << "\nInvalid input. Please try again.\n";

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                system("cls");

                cout << "\n\n\n\n\n\t\t\t\t\t--------------------------------------\n";
                cout << "\t\t\t\t\t| Welcome to Hotel Reservation System |";
                cout << "\n\t\t\t\t\t--------------------------------------\n\n";

                adminPanel();
            }
            switch (choice)
            {
            case 1:
                display();
                break;
            case 2:
                saveDataToFile();
                break;
            case 3:
                loadDataFromFile();
                break;
            case 4:
                cout << "\nExiting admin panel...\n";

                system("cls");

                return;
                return;
                return;
                return;
                return;

            default:
                cout << "\nInvalid choice. Please try again.\n";

                system("cls");

                cout << "\n\n\n\n\n\t\t\t\t\t--------------------------------------\n";
                cout << "\t\t\t\t\t| Welcome to Hotel Reservation System |";
                cout << "\n\t\t\t\t\t--------------------------------------\n\n";

                adminPanel();
            }
        }
    }

    // Function for admin login
    void adminlogin()
    {

        string username, password;

        system("cls");

        cout << "\n\n\n\n\n\t\t\t\t\t--------------------------------------\n";
        cout << "\t\t\t\t\t| Welcome to Hotel Reservation System |";
        cout << "\n\t\t\t\t\t--------------------------------------\n\n";

        cout << "\n\n*************************\n";
        cout << "      ADMIN PANEL        \n";
        cout << "*************************\n";

        cout << "\n Enter the username: ";
        cin >> username;

        cout << " Enter the password: ";
        password = "";
        char ch;
        while ((ch = _getch()) != '\r') {  // Read characters until Enter is pressed
            if (ch == '\b') {  // Handle Backspace character
                if (!password.empty()) {
                    cout << "\b \b";  // Move the cursor back, overwrite with a space, move the cursor back again
                    password.pop_back();
                }
            }
            else {
                password += ch;
                cout << "*";
            }
        }

        system("cls");

        cout << "\n\n\n\n\n\t\t\t\t\t--------------------------------------\n";
        cout << "\t\t\t\t\t| Welcome to Hotel Reservation System |";
        cout << "\n\t\t\t\t\t--------------------------------------\n\n";

        if (username == "mansoor" && password == "1234")
        {
            adminPanel();
        }
        else
        {
            cout << "invalid username or password";

            adminlogin();
        }
    }

    // Function to display user panel
    void userPanel()
    {
        int choice;

        system("cls");

        cout << "\n\n\n\n\n\t\t\t\t\t--------------------------------------\n";
        cout << "\t\t\t\t\t| Welcome to Hotel Reservation System |";
        cout << "\n\t\t\t\t\t--------------------------------------\n\n";

        while (true)
        {
            cout << "\n\n*************************\n";
            cout << "      USER PANEL        \n";
            cout << "*************************\n";
            cout << " 1. Display hotel status\n";
            cout << " 2. Book a room\n";
            cout << " 3. Cancel booking\n";
            cout << " 4. Exit\n";
            cout << "*************************\n";

            cout << " Enter your choice: ";
            cin >> choice;

            cout << "\n";

            if (cin.fail())
            {
                cin.clear();

                cout << "\nInvalid input. Please try again.\n";

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                system("cls");

                cout << "\n\n\n\n\n\t\t\t\t\t--------------------------------------\n";
                cout << "\t\t\t\t\t| Welcome to Hotel Reservation System |";
                cout << "\n\t\t\t\t\t--------------------------------------\n\n";

                userPanel();
            }

            switch (choice)
            {
            case 1:
                display();
                break;
            case 2:
                try
                {
                    book();
                }
                catch (const char* message)
                {
                    cout << "\nError: " << message << endl;
                }
                break;
            case 3:
                try
                {
                    cancel();
                }
                catch (const char* message)
                {
                    cout << "\nError: " << message << endl;
                }
                break;
            case 4:
                cout << "\nExiting user panel...\n";

                system("cls");

                return;
                return;
                return;
                return;
                return;
                return;
            default:
                cout << "\nInvalid choice. Please try again.\n";

                system("cls");

                cout << "\n\n\n\n\n\t\t\t\t\t--------------------------------------\n";
                cout << "\t\t\t\t\t| Welcome to Hotel Reservation System |";
                cout << "\n\t\t\t\t\t--------------------------------------\n\n";

                userPanel();
            }
        }
    }
};

int main()
{
    system("color de");

    hotel H;
    int choice;

    // Load user registration data from file
    H.loadUserRegistrationFromFile();

    while (true)
    {
        cout << "\n\n\n\n\n\t\t\t\t\t--------------------------------------\n";
        cout << "\t\t\t\t\t| Welcome to Hotel Reservation System |";
        cout << "\n\t\t\t\t\t--------------------------------------\n\n";

        cout << "\n\n*************************\n";
        cout << " 1. Admin Panel\n";
        cout << " 2. User Panel\n";
        cout << " 3. Register a new user\n";
        cout << " 4. Exit\n";
        cout << "*************************\n";

        cout << " Enter your choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();

            cout << "\nInvalid input. Please try again.\n";

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            main();
        }

        switch (choice)
        {
        case 1:
            H.adminlogin();
            break;
        case 2:
            if (H.userLogin())
            {
                H.userPanel();
            }
            else
            {
                cout << "\nAuthentication failed. Please try again.\n";

                system("cls");
            }
            break;
        case 3:
            try
            {
                H.userRegistration();
            }
            catch (const char* message)
            {
                cout << "\nError: " << message << endl;
            }
            break;
        case 4:
            cout << "\nExiting program...\n";

            cout << "\nProgram Exited.\n";


            return 0;
        default:
            cout << "\nInvalid choice. Please try again.\n";

            system("cls");

            main();
        }
    }

    return 0;
}
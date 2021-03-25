#include <iostream>
#include <iomanip>
#include <string>
#include "Hotel.h"


using namespace std;

/************************************************************************
*******************   FORMATTING FUNCTIONS   ****************************
*************************************************************************
*/

void printMenu()
{
    cout << endl;
    cout << setw(70) << "*******************************" << endl;
    cout << setw(66) << "HOTEL MANAGEMENT SYSTEM" << endl;
    cout << setw(70) << "*******************************" << endl << endl;

    cout << setw(53) << "1. Book A Room" << endl;
    cout << setw(58) << "2. Customer Records" << endl;
    cout << setw(55) << "3. Rooms Alotted" << endl;
    cout << setw(54) << "4. Edit Records" << endl;
    cout << setw(56) << "5. Delete Records" << endl;
    cout << setw(55) << "6. Make Payments" << endl;
    cout << setw(46) << "7. Exit" << endl;

    cout << endl;

    cout << setw(58) << "Enter your Choice: ";
}

void bookScreen(Hotel h)
{
    cout << endl;
    cout << setw(70) << "*******************************" << endl;
    cout << setw(60) << "BOOK A ROOM" << endl;
    cout << setw(70) << "*******************************" << endl;

    cout << endl;

    h.printAvailableRooms();
}

void recordScreen(Hotel h)
{
    cout << endl;
    cout << setw(70) << "*******************************" << endl;
    cout << setw(63) << "CUSTOMER RECORDS" << endl;
    cout << setw(70) << "*******************************" << endl;

    cout << endl;

}

void bookedRoomsScreen(Hotel h)
{
    cout << endl;
    cout << setw(70) << "*******************************" << endl;
    cout << setw(61) << "ALLOCATED ROOMS" << endl;
    cout << setw(70) << "*******************************" << endl;

    cout << endl;

    h.printBookedRooms();
}

void editRecordsScreen(Hotel h)
{
    cout << endl;
    cout << setw(70) << "*******************************" << endl;
    cout << setw(61) << "EDIT RECORDS" << endl;
    cout << setw(70) << "*******************************" << endl;

    cout << endl;

}

void deleteRecordsScreen(Hotel h)
{
    cout << endl;
    cout << setw(70) << "*******************************" << endl;
    cout << setw(61) << "DELETE RECORDS" << endl;
    cout << setw(70) << "*******************************" << endl;

    cout << endl;

}


/************************************************************************
**********************   MAIN RUNNING FUNCTION   ************************
*************************************************************************
*/

int main()
{
    Hotel hotelOne(10);
    int menuChoice;

    string cell, lastNm, addy;
    string x;
    

    // int rmNum, int cellNum, int n, string lastName, string Addy

    printMenu();

    cin >> menuChoice;

    while(cin)
    {
        if (menuChoice == 1)
        {
            cout << endl;
            bookScreen(hotelOne);
            cout << endl;

            hotelOne.bookRoom();

            cout << endl;

            cout << setw(60) << "Room Booked!" << endl;
            cout << setw(75) << "Thank you for choosing to stay with us!" << endl;

        } else if (menuChoice == 2)
        {
            recordScreen(hotelOne);

            hotelOne.printCustomerRecords();

            cout << endl;
            cout << setw(67) << "ENTER 'x' TO EXIT RECORDS: ";

            cin >> x;

        } else if (menuChoice == 3)
        {
            bookedRoomsScreen(hotelOne);
            cout << endl;
            cout << setw(72) << "ENTER 'x' TO EXIT ALLOCATED ROOMS: ";

            cin >> x;
            
        } else if (menuChoice == 4)
        {
            editRecordsScreen(hotelOne);

            hotelOne.printCustomerRecords();
            
            cout << endl;

            cout << setw(95) << "ENTER THE NAME OF THE RECORDS YOU WOULD LIKE TO EDIT OR ENTER 'x' TO EXIT: ";

            cin >> lastNm;

            if (x != "x")
            {
                editRecordsScreen(hotelOne);

                hotelOne.printRecord(lastNm);

                cout << endl;

                hotelOne.editRecords(lastNm);

                cout << endl << setw(70) << "ALL CHANGES HAVE BEEN SAVED!" << endl;

                cout << endl;

                cout << setw(70) << "ENTER 'x' TO EXIT RECORDS: ";

                cin >> x;
            }

            

        } else if (menuChoice == 5)
        {
            deleteRecordsScreen(hotelOne);

            hotelOne.printCustomerRecords();
            cout << endl;

            cout << setw(95) << "ENTER THE NAME OF THE RECORDS YOU WOULD LIKE TO DELETE OR ENTER 'x' TO EXIT: ";

            cin >> lastNm;

            if (lastNm != "x")
            {
                deleteRecordsScreen(hotelOne);

                hotelOne.printRecord(lastNm);

                cout << setw(70) << endl << "ARE YOU SURE YOU WOULD LIKE TO DELETE THE " << lastNm << " FAMILY RECORD? Y/N: ";

                cin >> x;

                if (x == "Y" || x == "y")
                {
                hotelOne.deleteRecord(lastNm);
                cout << setw(65) << "DELETING..." << endl << endl;
                cout << setw(60) << "THE RECORD HAS BEEN DELETED" << endl;
                }
            }
        } else if (menuChoice == 6)
        {
            cout << endl;
            cout << setw(70) << "*******************************" << endl;
            cout << setw(60) << "MAKE A PAYMENT" << endl;
            cout << setw(70) << "*******************************" << endl;

            cout << endl;

            hotelOne.printBookedRooms();

            cout << endl;

            hotelOne.makePayment();

            hotelOne.printRecord(lastNm);

            cout << endl << setw(65) << "YOUR PAYMENT HAS BEEN MADE! THANK YOU!";
            
        } else if (menuChoice == 7)
        {
            return 0;
        } else {
            cout << setw(50) << "PLEASE ENTER A VALID NUMBER" << endl << endl;
        }

        printMenu();
        cin >> menuChoice;
    }

    cout << "THANK YOU FOR CHOOSING TO STAY WITH US!" << endl << endl;
    return 0;
}
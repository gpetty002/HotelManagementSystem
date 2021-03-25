#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <iomanip>
#include <string>


using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::setw;

class Room
{
    private:
        int roomNum;
        string party_Cell;
        int nights;
        int roomBill;
        string party_LastName;
        string party_Addy;
        bool status;
    
    public:
        Room(int rmNum) : roomNum(rmNum), status(false)
        {
        }
        Room(int rmNum, string cellNum, int n, string lastName, string Addy) : roomNum(rmNum), party_Cell(cellNum), 
        nights(n), roomBill(205*nights), party_LastName(lastName), party_Addy(Addy), status(true)
        {
        }
        int getRoomNum()
        {
            return roomNum;
        }
        string getCell()
        {
            return party_Cell;
        }
        string getName()
        {
            return party_LastName;
        }
        string getAddress()
        {
            return party_Addy;
        }
        bool getStatus()
        {
            return status;
        }
        int getTotalBill()
        {
            return roomBill;
        }
        void changeRoomNum(int n)
        {
            roomNum = n;
        }
        void changeRoomPrice(int n)
        {
            roomBill = n;
        }
        void changeLastName(string ln)
        {
            party_LastName = ln;
        }
        void changeCell(string c)
        {
            party_Cell = c;
        }
        void changeAddy(string a)
        {
            party_Addy = a;
        }
        void changeNights(int n)
        {
            nights = n;
        }

        void roomInfo()
        {
            if (status)
            {
                cout << setw(80) << "------------------------------------------------" << endl;
                cout << setw(50) << "Room: " << roomNum << " Last Name: " << party_LastName << endl;
                cout << setw(53) << "Cell: " << party_Cell << endl;
                cout << setw(50) << "Address: " << party_Addy << endl;
                cout << setw(60) << "Total Bill: $" << roomBill << endl;
                cout << setw(80) << "------------------------------------------------" << endl;
            } else {
                cout << setw(80) << "------------------------------------------------" << endl;
                cout << endl;
                cout << setw(50) << "Room: " << roomNum << " Status: Available" << endl;
                cout << endl;
                cout << setw(80) << "------------------------------------------------" << endl;
            }
        }
        void customerRecord()
        {
            cout << setw(80) << "------------------------------------------------" << endl;
            cout << setw(50) << "Room: " << roomNum << " Last Name: " << party_LastName << endl;
            cout << setw(53) << "Cell: " << party_Cell << endl;
            cout << setw(50) << "Address: " << party_Addy << endl << endl;
            cout << setw(48) << "Status: ";

            if (status)
            {
                cout << "Currently Guesting With Us" << endl;
            } else {
                cout << "Has Finished Stay" << endl;
            }
            cout << setw(60) << "Total Bill: $" << getTotalBill() << endl;
            cout << setw(80) << "------------------------------------------------" << endl;
        }
        Room& operator=(const Room &room)
        {
            roomNum = room.roomNum;
            party_Cell = room.party_Cell;
            party_LastName = room.party_LastName;
            nights = room.nights;
            party_Addy = room.party_Addy;
            status = room.status;
            roomBill = room.roomBill;

            return *this;
        }
};
#endif
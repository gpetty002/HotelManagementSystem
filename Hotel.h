#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>
#include "Room.h"

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::setw;
using std::vector;
using std::partition;

// Predicate Function to Separate Available and Non-Available Rooms
bool availablility(Room r1)
{
    return r1.getStatus() == true;
}

class Hotel
{
    private:
        vector<Room> rooms;
        vector<Room> records;
        int availableRms;

    public:
        Hotel(int n) : availableRms(n)
        {
            for (int i = 0; i < n; i++)
            {
                rooms.push_back(Room(i));
            }
        }
        int getAvailableRms()
        {
            return availableRms;
        }
        
        void editRecords(string l_nm)
        {
            int x;

            cout << setw(61) << "1. Room Number" << endl; 
            cout << setw(67) << "2. Cell Phone Number" << endl;
            cout << setw(59) << "3. Last Name" << endl;
            cout << setw(62) << "4. Home Address" << endl;
            cout << setw(64) << "5. Nights Staying" << endl;

            cout << endl;

            cout << setw(67) << "ENTER A NUMBER TO EDIT: ";

            cin >> x;
            
            for (size_t i = 0; i != records.size(); i++)
            {
                if (l_nm == records[i].getName())
                {
                    if (x == 1)
                    {
                        int nm;
                        cout << endl << setw(67) << "Enter a New Room Number: ";
                        cin >> nm;
                        records[i].changeRoomNum(nm);

                    } else if (x == 2)
                    {
                        string c;
                        cout << endl << setw(71) << "Enter a New Cell Phone Number: ";
                        cin >> c;
                        records[i].changeCell(c);

                    } else if (x == 3)
                    {
                        string l;
                        cout << endl << setw(56) << "Enter a New Last Name: ";
                        cin >> l;
                        records[i].changeLastName(l);
                        

                    } else if (x == 4)
                    {
                        cin.ignore();
                        string ad1;
                        cout << endl << setw(65) << "Enter a New Address: ";
                        getline(cin, ad1);
                        records[i].changeAddy(ad1);

                        /*
                            cout << setw(60) << "Last Name: ";
                            cin >> lastnm;
                            cin.ignore();

                            cout << setw(60) << "Home Address: ";
                            getline(cin, address);
                        */

                    } else if (x == 5)
                    {
                        int num1;
                        cout << endl << setw(670) << "Enter Nights Stayed/Staying: ";
                        cin >> num1;
                        records[i].changeNights(num1);
                    }
                }
                
            }

            // cout << setw(70) << "ALL CHANGES HAVE BEEN SAVED!" << endl;
              
        }
        void deleteRecord(string lnm)
        {
            for (vector<Room>::iterator iter = records.begin(); iter != records.end(); ++iter)
            {
                if (iter->getName() == lnm)
                {
                    records.erase(iter);
                    break;
                }
            }
        }
        void printAvailableRooms()
        {
            cout << setw(60) << "Available Rooms: " << getAvailableRms() << endl;

            for (size_t i = 0; i != rooms.size(); i++)
            {
                if (rooms[i].getStatus() == false)
                {
                    rooms[i].roomInfo();
                }
                
            }
        }
        void printBookedRooms()
        {
            vector<Room> bookedRooms;

            for (size_t i = 0; i != rooms.size(); i++)
            {
                    if (rooms[i].getStatus())
                    {
                        rooms[i].roomInfo();
                        bookedRooms.push_back(rooms[i]);
                    }
            }
            if (bookedRooms.empty())
            {
                cout << setw(80) << "All rooms are currently available. Book a room!!!" << endl;
            } 
            
        }
        void printRooms()
        {
            cout << setw(60) << "Available Rooms: " << getAvailableRms() << endl;

            // partition(rooms.begin(), rooms.end(), availablility);

            for (size_t i = 0; i != rooms.size(); i++)
            {
                rooms[i].roomInfo();
            }
        }
        void printCustomerRecords()
        {
            if (records.empty())
            {
                cout << setw(90) << "There are currently no records in our program. Book some rooms!!!" << endl;
            } else {
                for (size_t i = 0; i != records.size(); i++)
                {
                    records[i].customerRecord();
                }
            }
            
            
        }
        void printRecord(string lnm)
        {
            for (size_t i = 0; i != records.size(); i++)
            {
                if (records[i].getName() == lnm)
                {
                    records[i].customerRecord();
                }
            }
        }
        void makePayment()
        {
            int payment;
            string ln;

            cout << setw(85) << "ENTER THE LAST NAME OF THE ROOM YOU'D LIKE TO MAKE A PAYMENT TO: ";
            cin >> ln;

            cout << endl << setw(73) << "ENTER THE AMOUNT YOU'D LIKE TO PAY: ";
            cin >> payment;

            cout << endl << setw(60) << "PROCESSING..." << endl;
    
            for (size_t i = 0; i != rooms.size(); i++)
            {
                if (rooms[i].getName() == ln)
                {
                    rooms[i].changeRoomPrice(rooms[i].getTotalBill()-payment);
                }
            }
                
        }
        // int rmNum, int cellNum, int n, string lastName, string Addy


        // Book a Room using the Room Class Assignment Operator
        void bookRoom()
        {
            int rm, n;
            string cell, lastnm, address;

            cout << setw(60) << "Room Number: ";
            cin >> rm;

            cout << setw(60) << "Cell Phone Number: ";
            cin >> cell;

            cout << setw(60) << "Last Name: ";
            cin >> lastnm;
            cin.ignore();

            cout << setw(60) << "Home Address: ";
            getline(cin, address);

            cout << setw(60) << "Nights Staying: ";
            cin >> n;
            
            for (size_t i = 0; i != rooms.size(); i++)
            {
                if (i == rm)
                {
                    rooms[i] = Room(rm, cell, n, lastnm, address);
                    records.push_back(rooms[i]);
                    availableRms--;
                }
            }
        }
};

#endif 


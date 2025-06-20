#include<iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

bool isValidPhone(long long phone) {
    return (phone >= 1000000000LL && phone <= 9999999999LL);
}

bool isValidAge(int age) {
    return ( age>0 && age<100);
}

bool isValidName(const string& name) {
    if (name.empty()) return false;

    for (char c : name) {
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }

    return true;
}

bool isValidDestination(const string& destination) {
    if (destination.empty()) return false;

    for (char c : destination) {
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return true;
}





class Booking {

    
    string passengerName;
    long long int PhoneNo;
    int seatNo;
    string destination;
    int age;
    int bookingID;
    
    public:
    Booking(){

    }

    Booking(long long int PhoneNo , string destination , int bookingID , int age , int seatNo , string passengerName) {
        this-> PhoneNo = PhoneNo;
        this-> destination = destination;
        this-> bookingID = bookingID;
        this-> age = age;
        this-> passengerName = passengerName;
        this-> seatNo = seatNo;
    }

   void inputDetails() {
    do {
    cout << "Enter Booking ID: ";
    cin >> bookingID;

    if (bookingID <= 0) {
        cout << "Invalid Booking ID . Enter Again : ";
    } else {
        break;
    }
} while (true);

    do {
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, passengerName);

    if (!isValidName(passengerName)) {
        cout << "Invalid name! . Enter Again : "<<" "<<endl;;
    } else {
        break;
    }
} while (true);
    
    do {
        cout << "Enter Phone Number: ";
        cin >> PhoneNo;

        if (!isValidPhone(PhoneNo)) {
            cout << "Invalid Phone Number! Try Again : " ;
        } else {
            break;
        }
    } while (true); 

    
    do {
        cout << "Enter Age: ";
        cin >> age;

        if (!isValidAge(age)) {
            cout << "Invalid Age!.Try Again : ";
        } else {
            break;
        }
    } while (true); 


    do {
    cout << "Enter Destination: ";
    cin.ignore();
    getline(cin, destination);


    if (!isValidDestination(destination)) {
        cout << "Invalid destination . Enter Again : ";
    } else {
        break;
    }
} while (true);

     do {
    cout << "Enter Seat Number: ";
    cin >> seatNo;

    if (seatNo <= 0) {
        cout << "Invalid seat number! .Enter Again :" << endl;
    }
    else {
        break;
    }
} while (true);
   }  


    void saveToFile() {
        bookingID = getNextID();
        ofstream file("bookings.txt", ios::app);
        file << bookingID << "," << passengerName << "," << destination << "," << seatNo << endl;
        file.close();
        cout << "Booking added successfully!" << endl;
    }

    static int getNextID() {
        ifstream file("bookings.txt");
        string line;
        int lastID = 0;
        while (getline(file, line)) {
            stringstream ss(line);
            string idStr;
            getline(ss, idStr, ',');
            lastID = stoi(idStr);
        }
        file.close();
        return lastID + 1;
    }

    static void showAllBookings() {
        ifstream file("bookings.txt");
        string line;
        cout << "\n--- All Bookings ---\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }

    static void cancelBooking(int id) {
        ifstream file("bookings.txt");
        ofstream temp("temp.txt");
        string line;
        bool found = false;

        while (getline(file, line)) {
            stringstream ss(line);
            string idStr;
            getline(ss, idStr, ',');
            if (stoi(idStr) != id) {
                temp << line << endl;
            } else {
                found = true;
            }
        }

        file.close();
        temp.close();
        remove("bookings.txt");
        rename("temp.txt", "bookings.txt");

        if (found)
            cout << "Booking cancelled successfully." << endl;
        else
            cout << "Booking ID not found." << endl;
    }

    static void editBooking(int id) {
        ifstream file("bookings.txt");
        ofstream temp("temp.txt");
        string line;
        bool found = false;

        while (getline(file, line)) {
            stringstream ss(line);
            string idStr;
            getline(ss, idStr, ',');
            if (stoi(idStr) == id) {
                found = true;
                Booking b;
                b.bookingID = id;
                cout << "Enter new details:\n";
                b.inputDetails();
                temp << b.bookingID << "," << b.passengerName << "," << b.destination << "," << b.seatNo << "\n";
            } else {
                temp << line << endl;
            }
        }

        file.close();
        temp.close();
        remove("bookings.txt");
        rename("temp.txt", "bookings.txt");

        if (found)
            cout << "Booking updated successfully." << endl;
        else
            cout << "Booking ID not found." << endl;
    }
        
          
};




int main(){
   
   
   
}

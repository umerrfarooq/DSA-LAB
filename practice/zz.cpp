#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

// Class to represent a Flight
class Flight {
public:
    int flightNumber;
    string source;
    string destination;
    int totalSeats;
    int availableSeats;
    vector<int> seats;  // Array to represent seat availability (0: available, 1: booked)

    Flight(int flightNum, string src, string dest, int totalSeats) {
        flightNumber = flightNum;
        source = src;
        destination = dest;
        this->totalSeats = totalSeats;
        availableSeats = totalSeats;
        seats.resize(totalSeats, 0);  // Initially all seats are available
    }

    // Function to display flight details
    void displayFlightDetails() const {
        cout << "Flight Number: " << flightNumber << "\nSource: " << source << "\nDestination: " << destination
             << "\nAvailable Seats: " << availableSeats << "/" << totalSeats << endl;
    }

    // Function to display seat arrangement
    void displaySeats() const {
        cout << "Seats (0: Available, 1: Booked): ";
        for (int i = 0; i < totalSeats; i++) {
            cout << seats[i] << " ";
        }
        cout << endl;
    }
};

// Class to represent a Passenger
class Passenger {
public:
    int passengerID;
    string name;
    int flightNumber;
    int seatNumber;

    Passenger(int id, string pname, int flightNum, int seatNum) {
        passengerID = id;
        name = pname;
        flightNumber = flightNum;
        seatNumber = seatNum;
    }

    // Function to display passenger details
    void displayPassengerDetails() const {
        cout << "Passenger ID: " << passengerID << "\nName: " << name << "\nFlight Number: " << flightNumber
             << "\nSeat Number: " << seatNumber + 1 << endl;  // Seat number is shown 1-indexed
    }
};

// Hash map to store flights and passengers
unordered_map<int, Flight> flights;
unordered_map<int, Passenger> passengers;

// Function to add a flight
void addFlight(int flightNumber, string source, string destination, int totalSeats) {
    Flight flight(flightNumber, source, destination, totalSeats);
    flights[flightNumber] = flight;
    cout << "Flight added successfully.\n";
}

// Function to book a seat on a flight for a passenger
void bookSeat(int passengerID, string name, int flightNumber) {
    if (flights.find(flightNumber) == flights.end()) {
        cout << "Flight not found.\n";
        return;
    }

    Flight& flight = flights[flightNumber];

    // Check if there are available seats
    if (flight.availableSeats == 0) {
        cout << "No seats available on this flight.\n";
        return;
    }

    // Find an available seat and assign it
    int seatNumber = -1;
    for (int i = 0; i < flight.totalSeats; i++) {
        if (flight.seats[i] == 0) {  // Available seat
            seatNumber = i;
            flight.seats[i] = 1;  // Mark seat as booked
            flight.availableSeats--;
            break;
        }
    }

    // Create Passenger with arguments and add to map
    Passenger passenger(passengerID, name, flightNumber, seatNumber);
    passengers[passengerID] = passenger;
    cout << "Seat booked successfully. Seat number: " << seatNumber + 1 << endl;
}

// Function to cancel a seat booking for a passenger
void cancelSeat(int passengerID) {
    if (passengers.find(passengerID) == passengers.end()) {
        cout << "Passenger not found.\n";
        return;
    }

    Passenger& passenger = passengers[passengerID];
    Flight& flight = flights[passenger.flightNumber];

    // Free the seat
    flight.seats[passenger.seatNumber] = 0;
    flight.availableSeats++;

    // Remove passenger from the passengers map
    passengers.erase(passengerID);
    cout << "Seat booking cancelled successfully.\n";
}

// Function to display all available flights
void displayAllFlights() {
    if (flights.empty()) {
        cout << "No flights available.\n";
        return;
    }

    for (const auto& pair : flights) {
        const Flight& flight = pair.second;
        flight.displayFlightDetails();  // Call the const version
        cout << "------------------------" << endl;
    }
}

// Function to display passenger details by ID
void displayPassengerDetails(int passengerID) {
    if (passengers.find(passengerID) == passengers.end()) {
        cout << "Passenger not found.\n";
        return;
    }

    passengers[passengerID].displayPassengerDetails();
}

// Main function to interact with the system
int main() {
    int choice;
    do {
        cout << "Airline Reservation System\n";
        cout << "1. Add Flight\n";
        cout << "2. Book Seat\n";
        cout << "3. Cancel Seat\n";
        cout << "4. Display All Flights\n";
        cout << "5. Display Passenger Details\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int flightNumber, totalSeats;
            string source, destination;
            cout << "Enter Flight Number: ";
            cin >> flightNumber;
            cin.ignore();  // Clear input buffer
            cout << "Enter Source: ";
            getline(cin, source);  // Use getline for string input
            cout << "Enter Destination: ";
            getline(cin, destination);  // Use getline for string input
            cout << "Enter Total Seats: ";
            cin >> totalSeats;
            addFlight(flightNumber, source, destination, totalSeats);
        } else if (choice == 2) {
            int passengerID, flightNumber;
            string name;
            cout << "Enter Passenger ID: ";
            cin >> passengerID;
            cin.ignore();  // Clear input buffer
            cout << "Enter Name: ";
            getline(cin, name);  // Use getline to accept a full line (including spaces)
            cout << "Enter Flight Number: ";
            cin >> flightNumber;
            bookSeat(passengerID, name, flightNumber);
        } else if (choice == 3) {
            int passengerID;
            cout << "Enter Passenger ID: ";
            cin >> passengerID;
            cancelSeat(passengerID);
        } else if (choice == 4) {
            displayAllFlights();
        } else if (choice == 5) {
            int passengerID;
            cout << "Enter Passenger ID: ";
            cin >> passengerID;
            displayPassengerDetails(passengerID);
        }

    } while (choice != 6);

    return 0;
}

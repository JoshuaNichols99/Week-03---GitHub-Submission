// Week 03 - Programming Assignment.cpp from Joshua Nichols
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <cassert>

using namespace std;

const double SHIPUSA = 6.00;
const double SHIPCAN = 8.00;
const double SHIPAUS = 10.00;
const double SHIPMARS = 75.00;
// Constants double float numbers that get rid if magic numbers.
const double ZERO = 0.00, TWO = 2.00 , THREE = 3.00, FOUR = 4.00, SIX = 6.00, SEVEN = 7.00 , TEN = 10.00 , TWENTY = 20.00;
const double FIFTY = 50.00, FIFTYPONE = 50.01, ONEH = 100.00, ONEHPONE = 100.01, ONEFIFTYH = 150.00;
const double  THREEHFIVE = 350.00, FIVEH = 500.00, SEVENH = 700.00, EIGHTH = 800.00, ONETH = 1000.00, ONETHPONE = 1000.01;
int main() {
    string itemName = "";
    char fragile;
    double shipmentCost = 0.00;
    double orderTotal = 0.00;
    string userFragileInput = "";
    string destination = "";
    //Creates the Order.text file like instructed.
    ofstream outFile;
    outFile.open("Order.txt");
    if (!outFile) {
        exit(1);
    }
    // Displays the programs task to the user.
    outFile << setw(50) << setfill('.') << "" << endl;
    cout << setw(50) << setfill('.') << "" << endl;
    outFile << "ITCS 2530 - Programming Assignment for week #3" << endl;
    cout << "ITCS 2530 - Programming Assignment for week #3" << endl;
    outFile << setw(50) << setfill('.') << "" << endl; outFile << endl; outFile << endl;
    cout << setw(50) << setfill('.') << "" << endl; cout << endl; cout << endl;
    // Request user input to process algorithm data. 
    cout << "Please enter the item name (no spaces)" << setw(11) << setfill('.') << "" << ":"; cin >> itemName;
    outFile << "Please enter the item name (no spaces)" << setw(11) << setfill('.') << "" << ":" << itemName << endl;
    cout << "Is the item fragile? (y=yes/n=no)" << setw(16) << setfill('.') << "" << ":"; cin >> userFragileInput;
    outFile << "Is the item fragile? (y=yes/n=no)" << setw(16) << setfill('.') << "" << ":" << userFragileInput << endl;
    if (userFragileInput.size() != 1) {
        outFile << endl; cout << endl;
        outFile << "Invalid entry, exiting" << endl;
        cout << "Invalid entry, exiting" << endl;
        outFile << "Press any key to continue . . ." << endl;
        cout << "Press any key to continue . . ." << endl;
        outFile.close();
        exit(1);
    }
    fragile = userFragileInput.at(0);
    // Determines wheather to give user an logical error or not.
    if (fragile != 'Y' && fragile != 'y' && fragile != 'N' && fragile != 'n') {
        outFile << endl; cout << endl;
        outFile << "Invalid entry, exiting" << endl;
        cout << "Invalid entry, exiting" << endl;
        outFile << "Press any key to continue . . ." << endl;
        cout << "Press any key to continue . . ." << endl;
        outFile.close(); 
        exit(1);
    }
    cout << "Please enter your order total" << setw(20) << setfill('.') << "" << ":"; cin >> orderTotal;
    outFile << "Please enter your order total" << setw(20) << setfill('.') << "" << ":" << orderTotal << endl;
    cout << "Please enter destination. (usa/can/aus/mars)" << setw(10) << setfill('.') << "" << ":";
    cin >> destination; cout << endl;
    outFile << "Please enter destination. (usa/can/aus/mars)" << setw(10) << setfill('.') << "" << ":";
    outFile << destination; outFile << endl;
    // Converts lowercase destination to uppercase destination.
    destination = (destination == "usa") ? "USA" : destination;
    destination = (destination == "can") ? "CAN" : destination;
    destination = (destination == "aus") ? "AUS" : destination;
    destination = (destination == "mars") ? "MARS" : destination;
    // Determines wheather to give user an logical error or not.
    if (destination != "USA" && destination != "CAN" && destination != "AUS" && destination != "MARS") {
        outFile << "Invalid entry, exiting" << endl;
        cout << "Invalid entry, exiting" << endl;
        outFile << "Press any key to continue . . ." << endl;
        cout << "Press any key to continue . . ." << endl;
        outFile.close(); 
        exit(1);
    }
    // United States of America's shipping cost algorithm.
    if (destination == "USA") {
        if (orderTotal <= FIFTY) {
            orderTotal += SHIPUSA;
            shipmentCost = SHIPUSA;
        }
        else if (orderTotal >= FIFTYPONE && orderTotal <= ONEH) {
            orderTotal += (SHIPUSA + TEN);
            shipmentCost = (SHIPUSA + THREE);
        }
        else if (orderTotal >= ONEHPONE && orderTotal <= ONEFIFTYH) {
            orderTotal += (SHIPUSA + SIX);
            shipmentCost = (SHIPUSA + SIX);
        }
    }
    // Canada's shipping cost algorithm.
    if (destination == "CAN") {
        if (orderTotal <= FIFTY) {
            orderTotal += SHIPCAN;
            shipmentCost = SHIPCAN;
        }
        else if (orderTotal >= FIFTYPONE && orderTotal <= ONEH) {
            orderTotal += (SHIPCAN + FOUR);
            shipmentCost = (SHIPCAN + FOUR);
        }
        else if (orderTotal >= ONEHPONE && orderTotal <= ONEFIFTYH) {
            orderTotal += (SHIPCAN + SEVEN);
            shipmentCost = (SHIPCAN + SEVEN);
        }
    }
    // Australia's shipping cost algorithm.
    if (destination == "AUS") {
        if (orderTotal <= FIFTY) {
            orderTotal += SHIPAUS;
            shipmentCost = SHIPAUS;
        }
        else if (orderTotal >= FIFTYPONE && orderTotal <= ONEH) {
            orderTotal += (SHIPAUS + FOUR);
            shipmentCost = (SHIPAUS + FOUR);
        }
        else if (orderTotal >= ONEHPONE && orderTotal <= ONEFIFTYH) {
            orderTotal += (SHIPAUS + SEVEN);
            shipmentCost = (SHIPAUS + SEVEN);
        }
    }
    // Mars of America's shipping cost algorithm.
    if (destination == "MARS") {
        if (orderTotal <= FIFTY) {
            orderTotal += SHIPMARS;
            shipmentCost = SHIPMARS;
        }
        else if (orderTotal >= FIFTYPONE && orderTotal <= ONEH) {
            orderTotal += (SHIPMARS + TEN);
            shipmentCost = (SHIPMARS + TEN);
        }
        else if (orderTotal >= ONEHPONE && orderTotal <= ONEFIFTYH) {
            orderTotal += (SHIPMARS + TWENTY);
            shipmentCost = (SHIPMARS + TWENTY);
        }
    }
    // Determines weather or not to add fragile cost to order total.
    switch (fragile) {
    case 'Y':
    case 'y':
        if (orderTotal > THREEHFIVE) {
            shipmentCost += TWO;
            orderTotal += TWO;
            break;
        }
        else if (orderTotal < THREEHFIVE) {
            orderTotal += TWO;
            shipmentCost += TWO;
            break;
        }
    case 'N':
    case 'n':
        if (orderTotal > THREEHFIVE) {
            shipmentCost = ZERO;
            break;
        }
        else if (orderTotal < THREEHFIVE) {
            shipmentCost = ZERO;
            break;
        }
    default:
        outFile << "Invalid entry, exiting" << endl;
        cout << "Invalid entry, exiting" << endl;
        outFile << "Press any key to continue . . ." << endl;
        cout << "Press any key to continue . . ." << endl;
        outFile.close(); exit(1);
        break;
    }
    // Outputs algorithm data from user and ends program.
    cout << "Your item is" << setw(28) << setfill('.') << "" << itemName << endl;
    outFile << "Your item is" << setw(28) << setfill('.') << "" << itemName << endl;
    cout << "Your shipping cost is" << setw(19) << setfill('.') << "" << "$" << setprecision(2) << fixed << shipmentCost << endl;
    outFile << "Your shipping cost is" << setw(19) << setfill('.') << "" << "$" << setprecision(2) << fixed << shipmentCost << endl;
    cout << "You are shipping to" << setw(21) << setfill('.') << "" << destination << endl;
    outFile << "You are shipping to" << setw(21) << setfill('.') << "" << destination << endl;
    cout << "Your total shipping costs are" << setw(11) << setfill('.') << "" << "$" << setprecision(2) << fixed << orderTotal << endl;
    outFile << "Your total shipping costs are" << setw(11) << setfill('.') << "" << "$" << setprecision(2) << fixed << orderTotal << endl;
    cout << endl; outFile << endl;
    outFile << setw(50) << setfill('-') << "Thank You!" << endl; outFile << endl;
    cout << setw(50) << setfill('-') << "Thank You!" << endl; cout << endl;
    outFile << "Press any key to continue . . ." << endl;
    cout << "Press any key to continue . . ." << endl;
    outFile.close();
}
/* The order of operations maybe a messy, but still functions as instructed in assignment. Code still works!
Used exit function instead of assert function because it was much easier to comprend than assert function.
Creating the program took longer then expected, espically when figuring out how to create Order.txt file.
Had to look through powerpoints, videos, and other resourceful websites to help me visualize what the program looks like.
*/
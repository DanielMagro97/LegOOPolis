#include <iostream>

#include "CSVReader.h"
#include "Quarry.h"
#include "City.h"
#include "Contractors/Bob.h"
#include "Contractors/Peter.h"
#include "Contractors/Jane.h"

using namespace std;

// function which frees memory on exit
void garbageCollection(Quarry quarry, City city);

// Launcher
int main(int argc, char **argv) {

    // if the input file argument is not specified, exit the program.
    if (argc < 2){
        cout << "Usage: lego <input filename>" << endl;
        return 0;
    }

    // Declaring the object quarry as an instance of the Class Quarry;
    Quarry quarry;

    // Declaring the object city as an instance of the City class
    City city;

    // integer which stores how many buildings were requested to be built by the input file
    int numberOfRequestedBuildings = 0;

    try {
        CSVReader reader(argv[1]);
        vector<string> vec;

        while (reader.readLine(vec)) {
            if (vec.size() == 2){
                // converting the user inputted number to an integer
                int amount;
                try {
                    amount = stoi(vec[1]);
                } catch (std::invalid_argument&) {
                    std::cout << "Invalid Input! Exiting" << std::endl;
                    garbageCollection(quarry, city);
                    exit(1);
                }

                // determining what the current line of the input file states
                if (vec[0] == "bricks") {
                    cout << "Adding Bricks to Quarry" << endl;
                    if (amount < 1){
                        cout << "Quantity of bricks should be between "
                                "1 and 100, setting number of bricks to 1" << endl;
                        amount = 1;
                    } else if (amount > 100){
                        cout << "Quantity of bricks should be between "
                                "1 and 100, setting number of bricks to 100" << endl;
                        amount = 100;
                    }
                    quarry.fillQuarry(PieceType::brick, amount);
                } else if (vec[0] == "doors"){
                    cout << "Adding Doors to Quarry" << endl;
                    if (amount < 1){
                        cout << "Quantity of doors should be between "
                                "1 and 100, setting number of doors to 1" << endl;
                        amount = 1;
                    } else if (amount > 100){
                        cout << "Quantity of doors should be between "
                                "1 and 100, setting number of doors to 100" << endl;
                        amount = 100;
                    }
                    quarry.fillQuarry(PieceType::door, amount);
                } else if (vec[0] == "windows"){
                    cout << "Adding Windows to Quarry" << endl;
                    if (amount < 1){
                        cout << "Quantity of windows should be between "
                                "1 and 100, setting number of doors to 1" << endl;
                        amount = 1;
                    } else if (amount > 100){
                        cout << "Quantity of windows should be between "
                                "1 and 100, setting number of doors to 100" << endl;
                        amount = 100;
                    }
                    quarry.fillQuarry(PieceType::window, amount);
                } else if (vec[0] == "1storeyhouse"){
                    cout << "Building One Storey House(s)" << endl;
                    if (amount > 0) {
                        numberOfRequestedBuildings += amount;
                        Bob contractor;
                        try {
                            for (int i = 0; i < amount; ++i) {
                                city.city->insertAtEnd(contractor.buildOneStoreyHouse(&quarry));
                            }
                        } catch (exception& notEnoughPiecesException) {
                            std::cout << notEnoughPiecesException.what() << std::endl;
                        }
                    }
                } else if (vec[0] == "2storeyhouse"){
                    cout << "Building Two Storey House(s)" << endl;
                    if (amount > 0) {
                        numberOfRequestedBuildings += amount;
                        Bob contractor;
                        try {
                            for (int i = 0; i < amount; ++i) {
                                city.city->insertAtEnd(contractor.buildTwoStoreyHouse(&quarry));
                            }
                        } catch (exception& notEnoughPiecesException) {
                            std::cout << notEnoughPiecesException.what() << std::endl;
                        }
                    }
                } else if (vec[0] == "church"){
                    cout << "Building Church(es)" << endl;
                    if (amount > 0) {
                        numberOfRequestedBuildings += amount;
                        Peter contractor;
                        try {
                            for (int i = 0; i < amount; ++i) {
                                city.city->insertAtEnd(contractor.buildChurch(&quarry));
                            }
                        } catch (exception& notEnoughPiecesException) {
                            std::cout << notEnoughPiecesException.what() << std::endl;
                        }
                    }
                } else if (vec[0] == "hospital"){
                    cout << "Building Hospital(s)" << endl;
                    if (amount > 0) {
                        numberOfRequestedBuildings += amount;
                        Jane contractor;
                        try {
                            for (int i = 0; i < amount; ++i) {
                                city.city->insertAtEnd(contractor.buildHospital(&quarry));
                            }
                        } catch (exception& notEnoughPiecesException) {
                            std::cout << notEnoughPiecesException.what() << std::endl;
                        }
                    }
                } else if (vec[0] == "university"){
                    cout << "Building University(ies)" << endl;
                    if (amount > 0) {
                        numberOfRequestedBuildings += amount;
                        Jane contractor;
                        try {
                            for (int i = 0; i < amount; ++i) {
                                city.city->insertAtEnd(contractor.buildUniversity(&quarry));
                            }
                        } catch (exception& notEnoughPiecesException) {
                            std::cout << notEnoughPiecesException.what() << std::endl;
                        }
                    }
                // In case of invalid input: perform garbage collection and exit the program
                } else {
                    cout << "Please check the format of the input file! Exiting" << endl;
                    garbageCollection(quarry, city);
                    exit(1);
                }
            }
        }
    }
    catch (ifstream::failure &e) {
        cout << "Exception! " << e.what() << endl;
    }
    catch (...) {
        cout << "Exception!" << endl;
    }

    // Displaying city description
    cout << endl;
    cout << "Number of Requested Buildings: " << numberOfRequestedBuildings << endl;
    cout << "Number of Completed Buildings: " << city.city->getSize() << endl;
    double percentageCompleted = ((double) (city.city->getSize()) / (double) (numberOfRequestedBuildings))*100;
    cout << "Percentage Completed: " << percentageCompleted << "%" << endl;
         //<< (double) ((city.city->getSize()/numberOfRequestedBuildings)*100) << "%" << endl;
    cout << endl;

    cout << "List of Buildings completed:" << endl;
    cout << "\tHouses: " << (city.numberOfBuildingsInCity(BuildingType::onestoreyhouse)
                         + city.numberOfBuildingsInCity(BuildingType::twostoreyhouse)) << endl;
    cout << "\tChurches: " << city.numberOfBuildingsInCity(BuildingType::church) << endl;
    cout << "\tHospitals: " << city.numberOfBuildingsInCity(BuildingType::hospital) << endl;
    cout << "\tUniversities: " << city.numberOfBuildingsInCity(BuildingType::university) << endl;

    // Calling the method which frees any allocated memory
    garbageCollection(quarry, city);

    return 0;
}

void garbageCollection(Quarry quarry, City city){
    for (int i = 0; i < city.city->getSize(); i++) {
        delete(city.city->getNodeAtIndex(i).data);
    }

    quarry.quarry->deleteLinkedList();
    city.city->deleteLinkedList();

    delete (quarry.quarry);
    delete(city.city);
}

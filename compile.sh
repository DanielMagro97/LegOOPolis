#! /bin/bash

g++ -std=c++11 -Wall -o lego \
	LegOOPolis/Main.cpp \
	LegOOPolis/CSVReader.cpp \
	LegOOPolis/Quarry.cpp \
	LegOOPolis/City.cpp \
	LegOOPolis/Builders/OneStoreyHouseBuilder.cpp \
	LegOOPolis/Builders/TwoStoreyHouseBuilder.cpp \
	LegOOPolis/Builders/ChurchBuilder.cpp \
	LegOOPolis/Builders/HospitalBuilder.cpp \
	LegOOPolis/Builders/UniversityBuilder.cpp \
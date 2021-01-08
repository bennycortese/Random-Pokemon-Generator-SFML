#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <map>


using namespace std;

class PokemonData {
	vector <string> ourPokemonNames;
	vector <string> allPokemonNamesWithFileTypes;
public:
	PokemonData();
	void readTheNames();
	vector<string> returnTheList();
	int theSize();
	void printAllTheNames();
	void linkTheFileTypes();
	vector<string> returnFileNameList();
};
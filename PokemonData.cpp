#include "PokemonData.h"

PokemonData::PokemonData() {
	readTheNames();
	linkTheFileTypes();
}

void PokemonData::readTheNames() {
	ifstream thePokemonInput;
	string theName;
	thePokemonInput.open("Datasets/pokemon.csv");
	getline(thePokemonInput, theName); // Really just theLine here, clearing out the first row which has the file reading information
	while (!thePokemonInput.eof())
	{
		getline(thePokemonInput, theName, ','); // grab name
		ourPokemonNames.push_back(theName);
		getline(thePokemonInput, theName); // throw away the rest of the line
	}
}

vector<string> PokemonData::returnTheList() {
	return ourPokemonNames;
}


int PokemonData::theSize() {
	return ourPokemonNames.size();
}

void PokemonData::printAllTheNames() {
	for (int i = 0; i < theSize(); i++) {
		cout << ourPokemonNames.at(i) << endl;
	}
}

void PokemonData::linkTheFileTypes() {
	if (theSize() > 721) {
		for (int i = 0; i < 721; i++)
		{
			allPokemonNamesWithFileTypes.push_back("images/pokemonImages/" + ourPokemonNames.at(i) + ".png");
		}
		for (int i = 721; i < theSize(); i++)
		{
			allPokemonNamesWithFileTypes.push_back("images/pokemonImages/" + ourPokemonNames.at(i) + ".jpg");
		}
	}
	else {
		for (int i = 0; i < theSize(); i++)
		{
			allPokemonNamesWithFileTypes.push_back("images/pokemonImages/" + ourPokemonNames.at(i) + ".png");
		}
	}
}

vector<string> PokemonData::returnFileNameList() {
	return allPokemonNamesWithFileTypes;
}	

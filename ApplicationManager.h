#pragma once

#include "PokemonData.h"
#include <SFML/Graphics.hpp>

class ApplicationManager {
	PokemonData theDataSet;

	int width = 1210;
	int height = 908;

	int dataSetSize = theDataSet.theSize();

	sf::Texture backgroundTexture;
	sf::Sprite theBackground;
	sf::Texture buttonTexture;
	sf::Sprite theButton;
	sf::Texture buttonTextTexture;
	sf::Sprite theButtonText;
	vector<sf::Texture> thePokemonTextures;
	sf::Sprite theCurrentPokemon;


public:
	ApplicationManager();
	void loadTheBackground();
	void loadTheButton();
	void loadTheButtonText();
	void loadThePokemonSprites();
	void loadAllSprites();
	void setTheSpritePositions();
	void randomPokemonImage();
};
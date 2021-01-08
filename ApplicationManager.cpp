#include "ApplicationManager.h"

ApplicationManager::ApplicationManager() {
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(1210, 908), "Random Pokemon!");
    loadAllSprites();
    setTheSpritePositions();
    while (window.isOpen())
    {
        sf::Vector2i position = sf::Mouse::getPosition(window);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized)
            {
                width = event.size.width;
                height = event.size.height;
            }
            if (event.type == sf::Event::MouseButtonPressed && position.x >= float(width / 4) && position.y >= float(height / 1.4) && position.x <= float(width / 4) + 631 && position.y <= float(height / 1.4) + 91)
            {
                if (event.mouseButton.button == sf::Mouse::Left) 
                {
                    randomPokemonImage();
                }
            }
        }

        window.clear();
        window.draw(theBackground);
        window.draw(theButton);
        window.draw(theButtonText);
        window.draw(theCurrentPokemon);
        window.display();
    }
}

void ApplicationManager::loadTheBackground() {
    backgroundTexture.loadFromFile("images/background.jpg");
    theBackground.setTexture(backgroundTexture);
}

void ApplicationManager::loadTheButton() {
    buttonTexture.loadFromFile("images/ButtonBar.png");
    theButton.setTexture(buttonTexture);
}

void ApplicationManager::loadTheButtonText() {
    buttonTextTexture.loadFromFile("images/RandomPokemon.png");
    theButtonText.setTexture(buttonTextTexture);
}

void ApplicationManager::loadThePokemonSprites() {
    for (int i = 0; i < dataSetSize; i++)
    {
        sf::Texture tempTexture;
        tempTexture.loadFromFile(theDataSet.returnFileNameList().at(i));
        thePokemonTextures.push_back(tempTexture);
    }
    randomPokemonImage();
}

void ApplicationManager::loadAllSprites() {
    loadTheBackground();
    loadTheButton();
    loadTheButtonText();
    loadThePokemonSprites();
}

void ApplicationManager::setTheSpritePositions() {
    theButton.move(sf::Vector2f(float(width/4),float(height/1.4)));
    theButtonText.move(sf::Vector2f(float(width / 4), float(height / 1.4)));
    theCurrentPokemon.move(sf::Vector2f(float(width / 2), float(height / 2)));
}

void ApplicationManager::randomPokemonImage() {
    theCurrentPokemon.setTexture(thePokemonTextures.at(rand() % dataSetSize));
}
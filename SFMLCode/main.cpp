#include <SFML/Graphics.hpp>
#include "Personaje.h"

//director->escenas->actor
//                  ->fondo


int main()
{

                                        //X  //Y
    sf::RenderWindow window(sf::VideoMode(950, 300), "Shoot The Enemy");
    window.setFramerateLimit(60);



    //PJ
    Personaje Player;
    Player.setPosition(0,177);
    sf::Sprite imagen;
    sf::Texture tex;
    tex.loadFromFile("map.jpg");
    imagen.setTexture(tex);


    //GameLoop
    while (window.isOpen())
    {
        //Pool Event
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //INPUT


        //UPDATE
        Player.update();


        //DRAW -- show
        window.clear();
        window.draw(imagen);
        window.draw(Player);

        //Presentacion o preparacion

        //Display - flip
        window.display();
    }

    return 0;
}

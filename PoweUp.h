#ifndef POWEUP_H_INCLUDED
#define POWEUP_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "Colisionable.h"

class PowerUp : public sf::Drawable //public Colisionable
{
private:

     sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f _velocidad;

public:

    PowerUp(){

    _texture.loadFromFile("PowerUP.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height/2);

    }
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void Respawn();
 //   sf::FloatRect getBounds()const override;
};
void PowerUp::update()
{
}

void PowerUp::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite,states);
}

void PowerUp::Respawn(){
_sprite.setPosition(std::rand()%700 + _sprite.getGlobalBounds().width,std::rand()%500 + _sprite.getGlobalBounds().height );
}

/*bool PowerUp:: sf ::FloatRect PowerUp::getBounds()const
{
    return _sprite.getGlobalBounds();
}*/
#endif // POWEUP_H_INCLUDED


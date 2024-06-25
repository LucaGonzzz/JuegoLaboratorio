#ifndef PERSONAJE_H_INCLUDED
#define PERSONAJE_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Colisionable.h"

class Personaje : public sf::Drawable //public Colisionable
{
private:
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f _velocidad;
public:
    Personaje();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    void setPosition(float x, float y);
//    sf::FloatRect getBounds()const override;
};
//////////////////////Texture/////////////////////

Personaje::Personaje()
{
    _velocidad= {3,3};
    _texture.loadFromFile("Jorge2.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width/6,_sprite.getGlobalBounds().height );

}

//////////////////////TextureEnd/////////////////////
void Personaje::update()
{
    _velocidad= {0,0};
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))

            {
                _velocidad.y=-3;
            }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        _velocidad.x=-3;
    }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                _velocidad.y=3;
            }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        _velocidad.x=3;
    }
    ////////QUE EL PERSONAJE MIRE A DONDE CORRA//////////////
    _sprite.move(_velocidad);
    if(_velocidad.x<0)
    {
        _sprite.setScale(-1,1);
    }
    else if(_velocidad.x>0)
    {
        _sprite.setScale (1,1);
    }

    //////QUE EL PERSONAJE NO SALGA DE LA PANTALLA//////
    if (_sprite.getGlobalBounds().left < 0) {
        _sprite.setPosition(_sprite.getOrigin().x, _sprite.getPosition().y);
    }
    if (_sprite.getGlobalBounds().top < 0) {
        _sprite.setPosition(_sprite.getPosition().x, _sprite.getOrigin().y);
    }
    if (_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 960) {
        _sprite.setPosition(960 - (_sprite.getGlobalBounds().width -_sprite.getOrigin().x), _sprite.getPosition().y);
    }
    if (_sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height > 320) {
        _sprite.setPosition(_sprite.getPosition().x, 320 );
    }
}

void Personaje::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_sprite, states);
}

void Personaje::setPosition(float x, float y) {
    _sprite.setPosition(x, y);
}

/*bool Personaje:: sf::FloatRect Personaje::getBounds()const
{
    return _sprite.getGlobalBounds();
}
*/
#endif // PERSONAJE_H_INCLUDED

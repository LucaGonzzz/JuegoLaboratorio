#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED
#include <SFML/Graphics.hpp>
class Enemigo: public sf::Drawable
{
private:
    sf::Sprite _spriteEnem;
    sf::Texture _textureEnem;
    sf::Vector2f _velocidadEnem;
public:
    Enemigo();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
};
Enemigo::Enemigo()
{
    _velocidadEnem = sf::Vector2f(1.5, 1.5f);
    _textureEnem.loadFromFile("osoenemigo.png");
    _spriteEnem.setTexture(_textureEnem);
}

void Enemigo::update()
{
    _spriteEnem.move(_velocidadEnem)
    if(_spriteEnem.getPosition().x < 0)
    {
        _spriteEnem.setPosition(0,_spriteEnem.getPosition().y);
    }
    if(_spriteEnem.getPosition().y < 0)
    {
        _spriteEnem.setPosition(_spriteEnem.getPosition().x, 0);
    }

    if(_spriteEnem.getPosition().x+_spriteEnem.getGlobalBounds().width > 800)
    {
        _spriteEnem.setPosition(800 - _spriteEnem.getGlobalBounds().width, _spriteEnem.getPosition().y);
    }

    if(_spriteEnem.getPosition().y+_spriteEnem.getGlobalBounds().height > 600)
    {
        _spriteEnem.setPosition(_spriteEnem.getPosition().x, 600 - _spriteEnem.getGlobalBounds().height);
    }
}
void Enemigo::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(_spriteEnem, states);
}
#endif // ENEMIGO_H_INCLUDED

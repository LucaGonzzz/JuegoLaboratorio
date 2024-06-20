#ifndef ESCENA_H_INCLUDED
#define ESCENA_H_INCLUDED
#include <SFML/Graphics.hpp>

class Escena : public sf::Drawable
{
public:
    Escena();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
};
void Escena::update(){
Personaje.setPosition(0,100);
}

#endif // ESCENA_H_INCLUDED

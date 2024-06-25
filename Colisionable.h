#ifndef COLISIONABLE_H_INCLUDED
#define COLISIONABLE_H_INCLUDED
#include <SFML/Graphics.hpp>
class Colisionable {
private:

public:
    Colisionable();
    virtual sf::FloatRect getBounds() const = 0;
    bool isColision(Colisionable &col)const;
};

bool Colisionable :: isColision(Colisionable& obj) const
{
    return getBounds().intersects(obj.getBounds());
}
#endif // COLISIONABLE_H_INCLUDED

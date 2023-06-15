#ifndef BOSS_H_INCLUDED
#define BOSS_H_INCLUDED

class Boss : public Enemigo{
protected:
    sf::Sprite _Sprite;
    sf::Sound _Sonido;
    sf::SoundBuffer _Buffer;

public:
    void setSprite(Sprite sprite);
    void setSonido (const string* /*ruta*/)

};

#endif // BOSS_H_INCLUDED

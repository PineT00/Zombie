#include "pch.h"
#include "Zombie.h"

Zombie* Zombie::Create(Types zombieType)
{
    Zombie* zombie = new Zombie();

    switch (zombieType)
    {
    case Zombie::Types::Bloater:
        zombie->texturId = "graphics/bloater.png";
        zombie->maxHp = 50;
        zombie->speed = 30;
        break;
    case Zombie::Types::Chase:
        zombie->texturId = "graphics/chase.png";
        zombie->maxHp = 20;
        zombie->speed = 70;
        break;
    case Zombie::Types::Crawler:
        zombie->texturId = "graphics/crawler.png";
        zombie->maxHp = 30;
        zombie->speed = 20;
        break;
    }

    return zombie;
}

Zombie::Zombie(const std::string& name)
    :SpriteGo(name)
{
}

void Zombie::Init()
{
    SpriteGo::Init();
    Create(Zombie::Types::Crawler);
    SetOrigin(Origins::MC);
}

void Zombie::Release()
{
    SpriteGo::Release();
}

void Zombie::Reset()
{
    SpriteGo::Reset();
}

void Zombie::ZombieMove(float dt)
{
    direction.x = player->GetPosition().x;
    direction.y = player->GetPosition().y;
    if (Utils::Magnitude(direction) > 1.f)

    {
        Utils::Normalize(direction);
    }
    //SetPosition(position + direction * speed * dt);
    Translate(direction * speed * dt);
}

void Zombie::Update(float dt)
{
    SpriteGo::Update(dt);
    ZombieMove(dt);
}

void Zombie::Draw(sf::RenderWindow& window)
{
    SpriteGo::Draw(window);
}

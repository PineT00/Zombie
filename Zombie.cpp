#include "pch.h"
#include "Zombie.h"

Zombie* Zombie::Create(Types zombieType)
{
    Zombie* zombie = new Zombie();
    zombie->type = zombieType;

    switch (zombieType)
    {
    case Zombie::Types::Bloater:
        zombie->texturId = "graphics/bloater.png";
        zombie->maxHp = 50;
        zombie->speed = 50;
        break;
    case Zombie::Types::Chase:
        zombie->texturId = "graphics/chaser.png";
        zombie->maxHp = 20;
        zombie->speed = 90;
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
    SetTexture(texturId);
    SetOrigin(Origins::MC);
}

void Zombie::Release()
{
    SpriteGo::Release();
}

void Zombie::Reset()
{
    SpriteGo::Reset();

    player = dynamic_cast<Player*>(SCENE_MGR.GetCurrentScene()->FindGo("Player"));
}

void Zombie::ZombieMove(float dt)
{
    direction.x = player->GetPosition().x;
    direction.y = player->GetPosition().y;

    if (Utils::Magnitude(direction) > 1.f)
    {
        Utils::Normalize(direction);
    }
    SetPosition(position + direction * speed * dt);
    //Translate(direction * speed * dt);
}

void Zombie::Update(float dt)
{
    SpriteGo::Update(dt);

    look = player->GetPosition() - position;
    Utils::Normalize(look); 

    SetRotation(Utils::Angle(look));
    //SetPosition(position + look * speed * dt);
    Translate(look * speed * dt);

}

void Zombie::Draw(sf::RenderWindow& window)
{
    SpriteGo::Draw(window);
}

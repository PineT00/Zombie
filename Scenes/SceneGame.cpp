#include "pch.h"
#include "SceneGame.h"
#include "Player.h"
#include "TileMap.h"

SceneGame::SceneGame(SceneIds id)
    :Scene(id)
{
}

void SceneGame::Init()
{
    tileMap = new TileMap("Background");
    AddGo(tileMap);

    player = new Player("Player");
    AddGo(player);

    Scene::Init();
}

void SceneGame::Release()
{
    Scene::Release();
}

void SceneGame::Enter()
{
    Scene::Enter();

    sf::Vector2f windowSize = (sf::Vector2f)FRAMEWORK.GetWindowSize();
    sf::Vector2f centerPos = windowSize * 0.5f;
    worldView.setSize(windowSize);
    worldView.setCenter({ 0.f, 0.f });
    uiView.setSize(windowSize);
    uiView.setCenter(centerPos);

    //sf::Vector2f centerPos = (sf::Vector2f)FRAMEWORK.GetWindowSize() * 0.5f;

    TileMap* tileMap = dynamic_cast<TileMap*>(FindGo("Background"));
    tileMap->SetPosition({ centerPos });
    tileMap->SetScale({ 1, 1 });
    tileMap->SetRotation(0);
    tileMap->SetOrigin(Origins::MC);

    player->SetPosition({ centerPos });
}

void SceneGame::Exit()
{
    Scene::Exit();
}

void SceneGame::Update(float dt)
{
    Scene::Update(dt);

    worldView.setCenter(player->GetPosition());
}

void SceneGame::Draw(sf::RenderWindow& window)
{
    Scene::Draw(window);
}

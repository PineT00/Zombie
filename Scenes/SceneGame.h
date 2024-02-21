#pragma once
#include "Scene.h"

class Player;
class TileMap;
class Zombie;


class SceneGame : public Scene
{
protected:
	Player* player = nullptr;
	TileMap* tileMap = nullptr;
	//Zombie* zombie = nullptr;

public:
	SceneGame(SceneIds id);
	~SceneGame() override = default;
	void Init() override;
	void Release() override;

	void Enter() override;
	void Exit() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};


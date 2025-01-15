﻿#include "scene_manager.h"
#include "game_manager.h"
#include "player_manager.h"
#include "Monster_Spawn_Manager.h"
#include "battle_manager.h"
#include "../03_ingame/player/player.h"
#include "windows.h"
#include "../04_Util/util.h"
#include "../03_ingame/weapons/weapon_default.h"


void GameManager::Init()
{
	if (sceneManager == nullptr)
	{
		sceneManager = SceneManager::GetInstance();
	}
	SetConsoleOutputCP(CP_UTF8);

	sceneManager->LoadScene(EST_START);
}

void GameManager::Run()
{
	system("cls");
	UTIL::UPrintEndl("TEAM17 TEXTRPG 게임이 실행되었습니다.");

	CreatePlayerBase();
	IsPlaying = true;

	int testCount = 0;
	while (IsPlaying)
	{
		if (testCount > 6) IsPlaying = false;
		UTIL::UPrintEndl("-----------------------------------");
		UTIL::UPrintEndl("마을입니다.원하는 행동을 입력하세요.");
		UTIL::UPrintEndl("1. 던전\n2.상점 \n3.전직소");
		int num;
		cin >> num;
		switch (num)
		{
		case 1:
			Battle();
			break;
		case 2:
			VisitShop();
			break;
		case 3:
			UTIL::UPrintEndl("준비중인 기능입니다.");
			break;
		default:
			UTIL::UPrintEndl("잘못된 입력입니다.");
			break;
		}

		testCount++;
	}

	if (!IsPlaying)
	{
		Exit();
	}
}

void GameManager::CreatePlayerBase()
{
	playerManager = PlayerManager::GetInstance();
	playerManager->CreatePlayer();

	Player& player = playerManager->GetPlayer();
	auto ptr_weapon = make_unique<DefaultWeapon>();
	player.GetInventory()->EquipWeapon(move(ptr_weapon));
}

void GameManager::SpawnRandomMonster()
{
	MonsterSpawnManager* spawnManager = MonsterSpawnManager::GetInstance();
	Monster randomMonster = spawnManager->SpawnRandomMonster();
}

void GameManager::Battle()
{
	system("cls");

	Player& player = playerManager->GetPlayer();
	player.SetLevel(10);

	if (player.GetLevel() < 10)
	{
		Monster randomMonster = MonsterSpawnManager::GetInstance()->SpawnRandomMonster();
		uprintendl("전투 시작");
		randomMonster.DisplayMonster();
		BattleManager::GetInstance()->Excute(randomMonster);
	}
	else
	{
		BossMonster bossMonster(player);
		uprintendl("보스 전투 시작!");
		bossMonster.DisplayBossUI();
		BattleManager::GetInstance()->BossBattle(player, bossMonster);
	}

	if (!BattleManager::GetInstance()->GetIsWin())
	{
		IsPlaying = false;
	}
}

void GameManager::VisitShop()
{
	uprintendl("--------------------------------");
	if (shopManager == nullptr)
	{
		shopManager = ShopManager::GetInstance();

	}
	Player& player = playerManager->GetPlayer();

	shopManager->WelcomShop(player.GetInventory());
	UTIL::UPrintEndl("상점 방문 완료");
}

void GameManager::Exit()
{
	UTIL::UPrintEndl("게임이 종료되었습니다.");
}



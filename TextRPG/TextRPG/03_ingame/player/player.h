﻿#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../../03_ingame/inventory.h" 
#include "../../04_Util/util.h"

using namespace std;

class Player
{
public:
	Player() : hp(200), level(1), attack(30), exp(0), maxHp(200), title(ustring("🌱 초심자"))
	{
		inventory = new Inventory();
	}
	~Player()
	{
		delete inventory;
	}

	void SetHp(const int& hp);
	int GetHp() const { return hp; }

	void SetMaxHp(const int& maxHp);
	int GetMaxHp() const { return maxHp; }

	void SetName(const string& name);
	string GetName() const;

	void SetLevel(const int& level);
	int GetLevel() const { return level; }

	void SetAttack(const int& attack);
	int GetAttack() const { return attack; }

	void SetExp(const int& exp);
	int GetExp() const { return exp; }

	void SetPlayerJob(const string& job);
	string GetPlayerJob() const { return job; }

	Inventory* GetInventory();
	void UseItem(Monster& monster);

	void LevelUp();
	bool CanLevelUp() const;

	void GainExp(int expAmount);

	void UpdateTitle();

	void SetEquipStaus(Weapon* newWeapon);

	bool IsDead();
	bool IsJobChosen() { return isJobChosen; }
	void ChangeJob(string job, string jobName);

	void ResetGUI();

	void SetDamage(const int & damage) { (hp < damage) ? hp = 0 : hp -= damage; }

	void DisplayExpInfo();
	void DisplayLevelInfo();

private:
	int hp;
	int maxHp;
	int level;
	int attack;
	int exp;
	string name;
	string title;
	string job;
	vector<string> titles = { ustring("🌱 초심자"), ustring("🌴 모험가"), ustring("🌳 도전자"), ustring("🌍 베테랑") };
	bool isJobChosen = false;
	bool isDead = false;
	Inventory* inventory;
};
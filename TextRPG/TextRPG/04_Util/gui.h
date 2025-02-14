﻿#pragma once
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "../04_Util/util.h"
#include "../02_manager/stage_manager.h"
#include "../02_manager/player_manager.h"
#include "../02_manager/monster_manager.h"
using namespace std;
class GUI
{
public:
	static void DrawAskText(string str) {
		GUI::GoToXY(4, 26);
		uprint(str);
		GUI::GoToXY(4, 27);
		UTIL::UPrint("->");
	}

	static void DrawConfirmAsk()
	{
		int back = 0;
		while (back != 1)
		{
			DrawAskText("확인 시 1 누르세요.");
			back = UTIL::IntegerVerify(back, 1, 1);
		}
	}

	static void DrawGoldInfo() 
	{
		GUI::GoToXY(106, 2);
		uprint("           ");
		GUI::GoToXY(106, 2);
		int intGold = PlayerManager::GetInstance()->GetPlayer().GetInventory()->GetGold();
		string gold = ustring("💰 골드 " + to_string(intGold));
		uprint(gold);
	}
	static void ClearUI() //하단 텍스트 창만 초기화
	{
		string blank = "                                                                                ";
		for (int i = 0; i < 8; ++i)
		{
			GoToXY(4, 21 + i);
			uprint(blank);
		}
	}
	static void GoToXY(const int x, const int y)
	{
		COORD coord = { (SHORT)x, (SHORT)y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	
	/// <summary>
	/// 아무것도 입력 안하면 기본 배경 박스(0, 0, 120, 30)
	/// </summary>
	static void DrawFullBox() 
	{
		DrawBox(0, 0, 120, 30);
	}

	static void DrawInGameBox() 
	{
		DrawBox(0, 0, 120, 20);
		DrawBox(0, 20, 120, 10);
	}

	static void DrawBox(const int x, const int y, const int width, const int height)
	{
		for (int i = 0; i < height; i++)
		{
			GoToXY(x, y + i);
			if (i == 0 || i == height - 1) {
				cout << "+" << string(width - 2, '-') << "+";
			}
			else {
				cout << "|" << string(width - 2, ' ') << "|";
			}
		}
	}

	static void DrawTextBox(const int x, const int y, const int width, const int height, string inputText = ustring("준비중입니다."))
	{
		DrawBox(x, y, width, height);
		GoToXY(x + 2, y + 2);
		uprint(inputText);
	}

	static void PrintTitleText() 
	{
		string text[] = {
			" _____ __  __  ___      _ ___           ____  ____   ____ ",
			"| ____|  \\/  |/ _ \\    | |_ _|         |  _ \\|  _ \\ / ___|",
			"|  _| | |\\/| | | | |_  | || |   _____  | |_) | |_) | |  _ ",
			"| |___| |  | | |_| | |_| || |  |_____| |  _ <|  __/| |_| |",
			"|_____|_|  |_|\\___/ \\___/|___|         |_| \\_\\_|    \\____|",
		};
		GoToXY(31, 4);
		for (int i = 0; i < 8; i++) 
		{
			UTIL::UPrint("✨ ♦ ♦ ");
		}
		UTIL::UPrint("✨");
		GoToXY(31, 5);
		cout << text[0] << endl;
		GoToXY(31, 6);
		cout << text[1] << endl;
		GoToXY(31, 7);
		cout << text[2] << endl;
		GoToXY(31, 8);
		cout << text[3] << endl;
		GoToXY(31, 9);
		cout << text[4] << endl;
		GoToXY(31, 11);
		for (int i = 0; i < 8; i++)
		{
			UTIL::UPrint("✨ ♦ ♦ ");
		}
		UTIL::UPrint("✨");
	}

	static void PrintClearText()
	{
		string text[] = {
			"  ____ _     _____    _    ____    _   _ ",
			" / ___| |   | ____|  / \\  |  _ \\  | | | |",
			"| |   | |   |  _|   / _ \\ | |_) | | | | |",
			"| |___| |___| |___ / ___ \\|  _ <  |_| |_|",
			" \\____|_____|_____/_/   \\_\\_| \\_\\ (_) (_)",
		};

		GoToXY(31, 4);
		for (int i = 0; i < 6; i++)
		{
			UTIL::UPrint("🌟 🎉 🏆 ");
		}
		UTIL::UPrint("🌟");
		GoToXY(39, 5);
		cout << text[0] << endl;
		GoToXY(39, 6);
		cout << text[1] << endl;
		GoToXY(39, 7);
		cout << text[2] << endl;
		GoToXY(39, 8);
		cout << text[3] << endl;
		GoToXY(39, 9);
		cout << text[4] << endl;
		GoToXY(31, 11);
		for (int i = 0; i < 6; i++)
		{
			UTIL::UPrint("🌟 🎉 🏆 ");
		}
		UTIL::UPrint("🌟");
	}
	
	static void PrintLoadingText()
	{
		
		string text[] = {
			" _     ___    _    ____ ___ _   _  ____   _   _ ",
			"| |   / _ \\  / \\  |  _ \\_ _| \\ | |/ ___| | | | |",
			"| |  | | | |/ _ \\ | | | | ||  \\| | |  _  | | | |",
			"| |__| |_| / ___ \\| |_| | || |\\  | |_| | |_| |_|",
			"|_____\\___/_/   \\_\\____/___|_| \\_|\\____| (_) (_)",
		};
		GoToXY(31, 4);
		for (int i = 0; i < 6; i++)
		{
			UTIL::UPrint("⏳ 🔄 🚀 ");
		}
		UTIL::UPrint("⏳");
		GoToXY(36, 5);
		cout << text[0] << endl;
		GoToXY(36, 6);
		cout << text[1] << endl;
		GoToXY(36, 7);
		cout << text[2] << endl;
		GoToXY(36, 8);
		cout << text[3] << endl;
		GoToXY(36, 9);
		cout << text[4];
		GoToXY(31, 11);
		for (int i = 0; i < 6; i++)
		{
			UTIL::UPrint("⏳ 🔄 🚀 ");
		}
		UTIL::UPrint("⏳");
	}

	static void PrintFailText()
	{
		GoToXY(31, 4);
		for (int i = 0; i < 6; i++)
		{
			UTIL::UPrint("☠️ ❌ ⚠️ ");
		}
		UTIL::UPrint("☠️");
		string text[] = {
			" _____ _    ___ _     _____ ____  ",
			"|  ___/ \\  |_ _| |   | ____|  _ \\ ",
			"| |_ / _ \\  | || |   |  _| | | | |",
			"|  _/ ___ \\ | || |___| |___| |_| |",
			"|_|/_/   \\_\\___|_____|_____|____/ ",
		};
		GoToXY(31, 11);
		for (int i = 0; i < 6; i++)
		{
			UTIL::UPrint("☠️ ❌ ⚠️ ");
		}
		UTIL::UPrint("☠️");
		GoToXY(42, 5);
		cout << text[0] << endl;
		GoToXY(42, 6);
		cout << text[1] << endl;
		GoToXY(42, 7);
		cout << text[2] << endl;
		GoToXY(42, 8);
		cout << text[3] << endl;
		GoToXY(42, 9);
		cout << text[4];
	}

	static void SettingTitle(string title) 
	{
		GoToXY(4, 2);
		uprintendl(title);
	}

	static void SettingDungeonTitle(string stageText)
	{
		GoToXY(4, 2);
		cout << ustring("STAGE - ") << ustring(stageText);
	}

	static void DrawLevelBox(const int x, const int y, const int width, const int height, int level, int exp)
	{
		DrawBox(x, y, width, height);
		GoToXY(x + 2, y + 1);
		cout << ustring("[Lv.") << level << ustring("] exp: ") << exp << ustring("/100");
	}

	// 플레이어와 몬스터를 출력하기 위한 박스
	static void DrawNamingBox(string names)
	{
		DrawTextBox(46, 5, 28, 5, names);
	}

	static void DrawBossBox(string names)
	{
		DrawTextBox(50, 5, 21, 5, names);
	}

	static void DrawBattleNameingBox(string playerName, string monsterName)
	{
		DrawTextBox(20, 5, 28, 5, playerName);
		DrawTextBox(72, 5, 28, 5, monsterName);
	}

	static void DrawBattleHpBox()
	{
		int monsterHp, monsterMaxHp;
		if (MonsterManager::GetInstance()->GetMonster().IsBoss())
		{
			monsterHp = MonsterManager::GetInstance()->GetBossMonster().GetBossHp();
		}
		else
		{
			monsterHp = MonsterManager::GetInstance()->GetMonster().GetHp();
		}
		monsterMaxHp = MonsterManager::GetInstance()->GetMonster().GetMaxHp();

		int playerHp = PlayerManager::GetInstance()->GetPlayer().GetHp();
		int playerHpMaxHp = PlayerManager::GetInstance()->GetPlayer().GetMaxHp();

		GoToXY(23, 10);
		cout << "                                                                                ";

		GoToXY(23, 10);
		cout << "HP: " << playerHp << "/" << playerHpMaxHp;
		GoToXY(75, 10);
		cout << "Monster HP: " << monsterHp << "/" << monsterMaxHp;
	}

	// 선택 목록을 출력하는 박스(전직소, 상점 등)
	static void DrawSelectBox(vector<string> boxNames) 
	{
		switch (boxNames.size())
		{
			case 1:
				DrawTextBox(50, 12, 20, 5, boxNames[0]);
				break;
			case 2:
				DrawTextBox(26, 12, 20, 5, boxNames[0]);
				DrawTextBox(74, 12, 20, 5, boxNames[1]);
				break;
			case 3:
				DrawTextBox(14, 12, 20, 5, boxNames[0]);
				DrawTextBox(50, 12, 20, 5, boxNames[1]);
				DrawTextBox(86, 12, 20, 5, boxNames[2]);
				break;
			default:
				break;
		}
	}
	static void DrawAttackText(vector<string> attackTexts)
	{
		GoToXY(4, 22);
		uprint(attackTexts[0]);
		Sleep(1000);
		GoToXY(4, 23);
		uprint(attackTexts[1]);
		Sleep(1000);
		GoToXY(4, 24);
		uprint(attackTexts[2]);
		Sleep(2500);
	}

	static void DrawQuestionText(vector<string> questionTexts)
	{
		GoToXY(4, 22);
		uprint(questionTexts[0]);
		GoToXY(4, 23);
		uprint(questionTexts[1]);
		GoToXY(4, 24);
		uprint(questionTexts[2]);

		GoToXY(4, 27);
		uprint("->");
	}

	static void DrawStoryBox(vector<string> storyTexts)
	{
		GoToXY(30, 4);
		uprint(storyTexts[0]);
		Sleep(1000);
		GoToXY(30, 9);
		uprint(storyTexts[1]);
		Sleep(1000);
		GoToXY(30, 14);
		uprint(storyTexts[2]);
	}

	static void DrawStartStory()
	{
		GoToXY(30, 4);
		uprint("😨 플레이어 ? 내가 플레이어가 된건가 ?");
		Sleep(1000);

		GoToXY(30, 7);
		uprint("*보스 몬스터 주의*");
		GoToXY(30, 8);
		uprint("레벨 10 미만의 분들은 보스 몬스터에 주의하시기 바랍니다.");
		Sleep(1000);

		GoToXY(30, 11);
		uprint("😮 엥 저건 내가 만든 보스 몬스터잖아 ?!");
		Sleep(1500);

		GoToXY(30, 14);
		uprint("🤨 일단 보스 몬스터 잡으면 끝나는 게임이니까");
		Sleep(1000);

		GoToXY(30, 16);
		uprint("😠 레벨을 올려서 보스 몬스터를 잡자...!");
	}

	static void DrawStageBox(vector<string> stageNames)
	{
		DrawTextBox(20, 5, 14, 5, stageNames[0]);
		DrawTextBox(40, 13, 14, 5, stageNames[1]);
		DrawTextBox(60, 7, 14, 5, stageNames[2]);
		DrawTextBox(90, 8, 20, 5, stageNames[3]);
	}

	static void DrawBossAttack(vector<string> bossAttackTexts)
	{
		GUI::GoToXY(14, 13);
		uprint("나의 공격을 받아라");
		Sleep(1000);

		GUI::GoToXY(14, 16);
		uprint(bossAttackTexts[0]);
		Sleep(1000);

		GUI::GoToXY(14, 19);
		uprint(bossAttackTexts[1]);
		Sleep(1000);

		GUI::GoToXY(68, 16);
		uprint("회피 방법을 입력하세요");
		GUI::GoToXY(68, 17);
		uprint("->");
		GUI::GoToXY(72, 17);
	}
};
#include "05_shop_scene.h"

#include "../../02_manager/player_manager.h"
#include "../../02_manager/scene_manager.h"
#include "../../04_Util/gui.h"

void ShopScene::Init()
{
	SceneManager::GetInstance()->SetStageProgress(2);

    DrawMainLayout();
    SelectCommand();
}

void ShopScene::DrawMainLayout()
{
    GUI::DrawInGameBox();

    string sceneTitle = ustring("🏪 상점");
    GUI::SettingTitle(sceneTitle);

	string playerName = PlayerManager::GetInstance()->GetPlayer().GetName();
	GUI::DrawNamingBox(playerName);


    PlayerManager::GetInstance()->GetPlayer().GetInventory()->SetGold(200);

    GUI::GoToXY(106, 2);
    int intGold = PlayerManager::GetInstance()->GetPlayer().GetInventory()->GetGold();
    string gold = ustring("💰 골드 " + to_string(intGold));
    uprint(gold);

    string dungeon = ustring("1. 🍷HP포션");
    string shop = ustring("2. 🧪DMG포션");
    string jobChangeCenter = ustring("3. 💣폭탄");
    vector<string> boxNames = { dungeon, shop, jobChangeCenter };
    GUI::DrawSelectBox(boxNames);

    DrawStartText();

    GUI::GoToXY(8, 27);
}
void ShopScene::DrawStartText() {
    string questionText1 = ustring("상점에 오신걸 환영합니다.");
    string questionText2 = ustring("원하는 행동을 입력하세요.");
    string questionText3 = ustring("1. 구매 2. 판매 3. 강화 4. 나가기");
    vector<string> questionTexts = { questionText1, questionText2, questionText3 };
    GUI::DrawQuestionText(questionTexts);
}



void ShopScene::SelectCommand()
{
    int num;
    Inventory* inven = PlayerManager::GetInstance()->GetPlayer().GetInventory();

    while (true)
    {
        GUI::ClearUI();
        DrawStartText();
        num = UTIL::IntegerVerify(num, 1, 4);

        switch (num)
        {
        case 1:
            DrawBuy(inven);
            break;
        case 2:
            DrawSell(inven);
            break;
        case 3:
            DrawEnhance(inven);
            break;
        case 4:
            SceneManager::GetInstance()->LoadScene(EST_LOADING);
            return;
        default:
            UTIL::UPrintEndl("잘못된 입력입니다.");
            break;
        }
    }
}

void ShopScene::DrawBuy(Inventory* inven)
{
    GUI::ClearUI();

    ShopManager::GetInstance()->BuyItem(inven);

    //uprint("->");
}

void ShopScene::DrawSell(Inventory* inven)
{
    GUI::ClearUI();

    ShopManager::GetInstance()->SellItem(inven);
}

void ShopScene::DrawEnhance(Inventory* inven)
{
    GUI::ClearUI();
    GUI::GoToXY(4, 22);
    UTIL::UPrintEndl("아직 준비되지 않았습니다.");
    int back = 0;

    while (back != 1)
    {
        GUI::GoToXY(4, 26);
        UTIL::UPrintEndl("뒤로 가려면 1 누르세요.");
        GUI::GoToXY(4, 27);
        UTIL::UPrint("->");
        back = UTIL::IntegerVerify(back, 1, 1);
    }

}




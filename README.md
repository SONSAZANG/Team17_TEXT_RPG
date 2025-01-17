# **CMD EMOJI RPG**

## **1. 프로젝트 소개**

### **프로젝트 이름**

**CMD EMOJI RPG**

[![Video Label](http://img.youtube.com/vi/Pgght9vl7Dc/0.jpg)](https://youtu.be/Pgght9vl7Dc)

### **프로젝트 개요**

- **목적**
    - 이 프로젝트는 텍스트와 이모지를 기반의 GUI RPG 게임입니다.  
    - 주요 콘텐츠는 몬스터를 잡아 경험치와 골드를 얻을 수 있으며 이를 통해 아이템을 구입할 수 있습니다.
    - 최종적으로는 레벨 10을 달성한 후 보스몬스터에 도전해 cmd 세상을 탈출해야 합니다.
- **목표**
    - 학습한 내용을 바탕으로 효율적이고 구조적인 프로그램을 개발.
    - 완성도 높은 게임 구현.

### **주요 콘텐츠**

- 플레이어 생성 및 관리
- 몬스터 생성 및 관리
- 전투 시스템 (턴제 RPG)
- 상점 및 인벤토리 시스템
- 아이템 시스템
- 무기 시스템
- 전직 시스템
- GUI
- 칭호 시스템

### **주요 기능 요약**

- **플레이어**
    - 플레이어 생성 및 스탯 관리.
    - 레벨업 시스템 구현.
    - 레벨 기준 칭호 시스템 구현.
    - 전직 시스템 구현.
- **몬스터**
    - 3가지 종류의 몬스터 생성.
    - 칭호 시스템 (최대 공격력을 가진 몬스터 생성 시 "불타는 스켈레톤" 등).
- **전투 시스템**
    - 플레이어와 몬스터 간 턴제 전투 진행.
    - 턴마다 플레이어와 몬스터가 번갈아 공격.
- **상점 시스템**
    - 아이템 구매 및 판매 (판매 시 원가의 60% 회수).
    - 인벤토리 시스템 (구매한 아이템과 재화 확인).
- **GUI 시스템**
    - 한글과 이모지 동시 사용하여 GUI 구현
- **예외처리 시스템**
    - 다양한 입력에 대처하기 위해 예외처리 시스템 구현
- **유틸 시스템**
    - 화면에 박스 및 텍스트, 효과 등을 원하는 위치에 구현하느 `GUI` 구현
    - 자주 사용하는 유틸리티 함수를 정리한 `UTIL` 구현 

### **라이브러리/기술 스택**

- C++ Modern Singleton 패턴을 사용하여 설계.

---

## **2. 개발 환경**

- **개발 도구**
    - IDE: Visual Studio 2022
    - 언어: C++
- **실행 방법**
    - Visual Studio에서 `play` 파일 실행.

---

## **3. 프로젝트 구조**

``` ASCII Art
CMD EMOJI RPG
┣ 01_base(Folder)
┃ ┣ singleton_base
┃ ┣ scene_base
┃ ┗ item_base
┣ 02_manager(Folder)
┃ ┣ battle_manager
┃ ┣ game_manager
┃ ┣ job_manager
┃ ┣ monster_manager
┃ ┣ player_manager
┃ ┣ scene_manager
┃ ┣ shop_manager
┃ ┗ stage_manager
┣ 03_ingame(Folder)
┃ ┣ stage
┃ ┣ shop
┃ ┣ inventory
┃ ┣ monster(Folder)
┃   ┣ monsters
┃   ┗ boss_monster
┃ ┣ items(Folder)
┃   ┣ attack_boost
┃   ┣ bomb
┃   ┗ health_potion
┃ ┣ weapons(Folder)
┃   ┣ weapon
┃   ┣ weapon_bow
┃   ┗ weapon_sword
┃ ┗ player(Folder)
┃   ┗ player
┣ 04_Util(Folder)
┃ ┣ util
┃ ┗ gui
┣ 05_Scenes(Folder)
┃ ┣ 01_start_scene
┃ ┣ 02_loading_scene
┃ ┣ 03_player_setting_scene
┃ ┣ 04_town_scene
┃ ┣ 05_shop_scene
┃ ┣ 06_job_center_scene
┃ ┣ 07_select_stage_scene
┃ ┣ 08_dungeon_scene
┃ ┗ 09_end_scene
```

---

## **4. 멤버 소개**

| 이름 | 담당 역할 |
| --- | --- |
| **김민수** | 플레이어, 플레이어 칭호, 전직 |
| **이학민** | 몬스터, 보스 몬스터, 몬스터 칭호 |
| **장종기** | 전투, 예외처리, 무기 |
| **한가윤** | 상점, 인벤토리, 아이템, 발표자료, 스토리 |
| **손은수** | 프로젝트 구조, 유틸, 그래픽, 씬구성, 발표 |

---

## **5. 추가 기능 구현**

### 플레이어 성장 및 몰입감 강화
- **칭호 및 전직 시스템**: 플레이어의 성장과 몰입감을 증대시키기 위한 다양한 칭호와 전직 시스템을 구현했습니다.

### 전투 시스템
- **타자 입력을 통한 회피 기능**: 타자 입력으로 공격을 회피할 수 있는 기능을 추가하여 전투에 새로운 전략성을 더했습니다.
- **보스 몬스터의 고유 공격 패턴**: 각 보스 몬스터마다 고유한 공격 패턴을 설계하여 전투의 긴장감을 강화했습니다.

### 아이템 및 상호작용
- **폭탄 및 무기 시스템**: 플레이어의 상호작용을 증대시키기 위한 다양한 폭탄 및 무기 아이템 시스템을 구현했습니다.

### 사용자 친화적인 GUI
- **텍스트와 이모지를 활용한 GUI 디자인**: 텍스트와 이모지를 활용하여 직관적이고 사용자 친화적인 GUI를 제작했습니다.

### 시스템 안정성
- **모던 싱글톤 디자인 패턴**: 템플릿을 활용한 모던 싱글톤 디자인 패턴을 적용하여 매니저들의 효율성을 높였습니다.
- **예외처리 시스템**: 안정적인 동작을 보장하기 위한 예외처리 시스템을 구축했습니다.

---

## **6. 주의사항**

- **빌드 환경**
    - 프로젝트는 Visual Studio 2022 기준으로 작성되었으며, 다른 컴파일러에서는 빌드가 제대로 작동하지 않을 수 있습니다.
    - 이모지로 인해 윈도우11이어야 원활한 플레이가 가능합니다.
    - 윈도우 제어판 -> 국가 또는 지역 -> 시스탬 로캘 변경 -> Beta 유니코드 지원을 켜둔 상태로 빌드 해야합니다.

---

## **7. 트러블슈팅 및 기술적 도전**

개발 과정에서 주요 이슈로 **팀원 간 컴퓨터 환경 차이로 인한 이모지 출력 문제**가 발생했습니다.  
이를 해결하기 위해 다음과 같은 방법을 적용했습니다:
- 다양한 환경에서의 폰트 및 설정 조정
- 테스트를 통해 모든 컴퓨터에서 동일한 이모지 출력 확인

이 과정을 통해 팀의 협업 능력과 문제 해결 역량이 한층 향상되었습니다.

---

## **8. 결과 및 마무리**

**Emoji RPG**는 창의적인 스토리, 텍스트와 이모지를 조화롭게 활용한 UX, 그리고 도전적인 추가 기능을 통해 차별화된 게임 경험을 제공합니다.  
게임의 실제 플레이를 확인할 수 있는 시연 영상을 아래 링크에서 확인해 보세요:  
[시연 영상 링크](https://youtu.be/Pgght9vl7Dc)

팀노션 : https://teamsparta.notion.site/1-17-914e4f587cdf457ca42a6cf1d584b420

저희 **Emoji RPG 프로젝트**에 관심을 가져주셔서 감사합니다!  
앞으로도 많은 피드백과 관심 부탁드립니다. 질문이 있으시면 언제든지 편하게 DM으로 연락 주세요. 😊

#pragma once
#include "../01_core/singleton_base.h"
#include "../01_core/scene_base.h"
class SceneManager : public SingletonBase<SceneManager>
{
	friend class SingletonBase<SceneManager>;

private:
	SceneManager() {};
	~SceneManager() {};

public:
	void Init();
	void Clear();

public:
	void LoadScene(ESceneType sceneType);

private:
	class SceneBase* scene;
	ESceneType sceneType = ESceneType::None;
};
#pragma once
#include "Scene.h"
#include "Accounting.h"
class Game
{
private:
	int number_of_months_for_development, available_resources,number_of_scenes;
	double overal_quality = 0;
	Accounting *accounting;
public:
	Game(int deadline, int resources, int scenes_num, Accounting* corp_accounting);
	void next_month();//просто счётчик времения
	bool scene_release(Scene &scene);
};


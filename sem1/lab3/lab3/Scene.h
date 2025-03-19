#pragma once
#include "Script.h"
#include "Level.h"
#include "Model.h"
#include "Code.h"
#include "Music.h"

class Scene
{
private:
	Script script;
	Level level;
	Model model;
	Code code;
	Music music;
public:
	Scene(Script scene_script, Level scene_level, Model scene_model, Code scene_code, Music scene_music,MOOD mood);
	void scene_release(double* final_quality, int* final_resourse_intensity);
	Script* get_scene_script() { return &script; };
	Level* get_scene_level() { return &level; };
	Model* get_scene_model() { return &model; };
	Code* get_scene_code() { return &code; };
	Music* get_scene_music() { return &music; };
};


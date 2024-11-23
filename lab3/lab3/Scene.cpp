#include "Scene.h"

Scene::Scene(Script scene_script, Level scene_level, Model scene_model, Code scene_code, Music scene_music, MOOD mood)
{
	script = scene_script;
	level = scene_level;
	model = scene_model;
	music = scene_music;
	code = scene_code;
	if(script.get_mood()!=mood||music.get_mood()!=mood) throw std::runtime_error("The mood is not maintained");
}

void Scene::scene_release(double* final_quality, int* final_resourse_intensity)
{
	(*final_quality) += script.get_quality() + level.get_quality() + model.get_quality() + music.get_quality()+code.get_quality();
	(*final_resourse_intensity) -= (level.get_resourse_intensity() + model.get_resourse_intensity()+code.get_resourse_intensity());
	if ((*final_resourse_intensity )<= 0) throw std::runtime_error("Creature scope");
}

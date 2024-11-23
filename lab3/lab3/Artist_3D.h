#pragma once
#include "Worker.h"
#include "Model.h"
class Artist_3D:public Worker
{
private:
	bool motion_capture;
	//Трата денег на то,чтобы снять motion capture с актёров
public:
	Artist_3D(std::string artist_3D_name, double  artist_3D_professionalism, Accounting* place_of_work_artist_3D);
	void filming();
	Model create_model();
	void optimization(Model* model);
	void revision(Model* model);
	bool get_motion_capture()const { return motion_capture; }
};


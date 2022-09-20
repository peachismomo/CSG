#pragma once
#include "cprocessing.h"

typedef struct Car
{
	CP_Vector position;
	float direction;
	CP_Color color;
	int selected;
} Car;
#pragma once
#include "cprocessing.h"

typedef struct Car
{
	CP_Vector position;
	float direction;//degrees from (0,1)
	CP_Color color;
	int selected;
} Car;
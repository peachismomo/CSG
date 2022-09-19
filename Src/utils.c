#include "cprocessing.h"
#include <math.h>

int IsAreaClicked(float area_center_x, float area_center_y, float area_width, float area_height, float click_x, float click_y)
{
	int isInArea = 0;

	float xMin = area_center_x - area_width / 2;
	float xMax = area_center_x + area_width / 2;

	float yMin = area_center_y - area_height / 2;
	float yMax = area_center_y + area_height / 2;

	//check if mouse position is within area
	if (xMin <= click_x <= xMax && yMin <= click_y <= yMax) {
		isInArea = 1;
	}
	return isInArea;
}

int IsCircleClicked(float circle_center_x, float circle_center_y, float diameter, float click_x, float click_y)
{
	int isInArea = 0;
	CP_Vector circleCenter = CP_Vector_Set(circle_center_x, circle_center_y);
	CP_Vector mousePos = CP_Vector_Set(click_x, click_y);

	float dist = CP_Vector_Distance(circleCenter, mousePos);
	if (dist <= diameter / 2) {
		isInArea = 1;
	}
	return isInArea;
}

CP_Vector AngleToVector(float radian_angle)
{
    // TODO 
    CP_Vector ret;
	ret = CP_Vector_Set(cos(radian_angle), sin(radian_angle));
    return ret;
}
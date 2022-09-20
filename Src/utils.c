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
	if (!(click_x < xMin || click_x > xMax || click_y < yMin || click_y > yMax)) {
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

	//Check if the distance of the mouse from the centre of the circle is smaller than the radius of the circle
	if (dist <= diameter / 2) {
		isInArea = 1;
	}
	return isInArea;
}

CP_Vector AngleToVector(float radian_angle)
{
	//cos(angle) = x, sin(angle) = y
    return CP_Vector_Set((float)cos(radian_angle), (float)sin(radian_angle));
}

CP_Vector moveCar(CP_Vector position, CP_Vector direction, float speed) {
	//multiply speed by delta time to ensure speed is the same regardless of framerate
	float dtSpeed = speed * CP_System_GetDt(); //x units per second

	//normalize the vector and scale to the number to the number of units
	CP_Vector norm = CP_Vector_Normalize(direction);
	CP_Vector newPosition = CP_Vector_Add(position, CP_Vector_Scale(norm, dtSpeed));

	return newPosition;
}
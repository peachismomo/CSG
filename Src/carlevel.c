#include "cprocessing.h"
#include "structs.h"
#include "utils.h"
#include <math.h>

Car redCar;
Car greenCar;
Car blueCar;
Car carArray[3];

void Car_Level_Init()
{
	CP_System_SetWindowSize(CP_System_GetDisplayWidth() / 2, CP_System_GetDisplayHeight() / 2);
	//Create 3 cars
	redCar.position = CP_Vector_Set(100, 100);
	redCar.direction = 90;
	redCar.color = CP_Color_Create(255, 0, 0, 255);
	redCar.selected = 1;

	greenCar.position = CP_Vector_Set(200, 100);
	greenCar.direction = 90;
	greenCar.color = CP_Color_Create(0, 255, 0, 255);
	greenCar.selected = 0;

	blueCar.position = CP_Vector_Set(100, 200);
	blueCar.direction = 90;
	blueCar.color = CP_Color_Create(0, 0, 255, 255);
	blueCar.selected = 0;

	carArray[0] = redCar;
	carArray[1] = greenCar;
	carArray[2] = blueCar;
}

void Car_Level_Update()
{
	if (CP_Input_KeyDown(KEY_ESCAPE)) {
		CP_Engine_Terminate();
	}

	//Car select
	if (CP_Input_MouseClicked()) {
		CP_Vector mousePos = CP_Vector_Set(CP_Input_GetMouseX(), CP_Input_GetMouseY());

		for (int i = 0; i < 3; i++) {
			if (IsCircleClicked(carArray[i].position.x, carArray[i].position.y, 50, mousePos.x, mousePos.y)) {
				carArray[i].selected = 1;
			}
			else
			{
				carArray[i].selected = 0;
			}
		}
	}

	////Movement
	//Car* selectedCar;
	//for (int i = 0; i < 3; i++) {
	//	if (carArray[i].selected == 1) {
	//		selectedCar = &carArray[i];
	//	}
	//}

	//if (CP_Input_KeyDown(KEY_W)) {
	//	//decrease angle
	//	if (selectedCar->direction == 0) {
	//		selectedCar->direction = 359;
	//	}
	//	else selectedCar->direction--;
	//}

	//if (CP_Input_KeyDown(KEY_S)) {
	//	//increase angle
	//	if (selectedCar->direction == 359) {
	//		selectedCar->direction = 0;
	//	}
	//	else selectedCar->direction++;
	//}

	//if (CP_Input_KeyDown(KEY_A)) {
	//	//move backward
	//}

	//if (CP_Input_KeyDown(KEY_D)) {
	//	//move forward
	//}

	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));
}

void Car_Level_Exit()
{

}
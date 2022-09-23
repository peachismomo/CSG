#include "cprocessing.h"
#include "utils.h"
#include "mainmenu.h"
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


typedef struct Car
{
	CP_Vector position;
	float direction;
	CP_Color color;
	int selected;
} Car;

Car redCar;
Car greenCar;
Car blueCar;
Car carArray[3];

void Car_Level_Init()
{
	CP_System_SetWindowSize(CP_System_GetDisplayWidth() / 2, CP_System_GetDisplayHeight() / 2);

	//Create 3 cars
	redCar.position = CP_Vector_Set(100, 100);
	redCar.direction = 0;
	redCar.color = CP_Color_Create(255, 0, 0, 255);
	redCar.selected = 1;

	greenCar.position = CP_Vector_Set(200, 100);
	greenCar.direction = 0;
	greenCar.color = CP_Color_Create(0, 255, 0, 255);
	greenCar.selected = 0;

	blueCar.position = CP_Vector_Set(100, 200);
	blueCar.direction = 0;
	blueCar.color = CP_Color_Create(0, 0, 255, 255);
	blueCar.selected = 0;

	//Add cars to array
	carArray[0] = redCar;
	carArray[1] = greenCar;
	carArray[2] = blueCar;
}

void Car_Level_Update()
{
	if (CP_Input_KeyDown(KEY_ESCAPE)) {
		CP_Engine_Terminate();
	}

	//CAR SELECT
	if (CP_Input_MouseClicked()) {
		//Get Mouse position
		CP_Vector mousePos = CP_Vector_Set(CP_Input_GetMouseX(), CP_Input_GetMouseY());

		//interate through each car
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

	//MOVEMENT

	//Set default car to red car
	Car* selectedCar = &carArray[0];

	//Interate through all 3 cars
	for (int i = 0; i < 3; i++) {
		//Draw each car
		CP_Settings_Fill(carArray[i].color);
		CP_Graphics_DrawCircle(carArray[i].position.x, carArray[i].position.y, 50); //Diameter = 50

		CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255)); //triangle color set to white
		
		//Draw triangle and the rotation in degrees

		float deg1 = carArray[i].direction;
		float deg2 = carArray[i].direction + 120;
		float deg3 = carArray[i].direction + 240;

		if (deg2 > 360) {
			deg2 -= 360;
		}

		if (deg3 > 360) {
			deg3 -= 360;
		}

		float x1 = carArray[i].position.x + 25 * cos(deg1 * M_PI / 180);
		float y1 = carArray[i].position.y + 25 * sin(deg1 * M_PI / 180);

		float x2 = carArray[i].position.x + 20 * cos(deg2 * M_PI / 180);
		float y2 = carArray[i].position.y + 20 * sin(deg2 * M_PI / 180);

		float x3 = carArray[i].position.x + 20 * cos(deg3 * M_PI / 180);
		float y3 = carArray[i].position.y + 20 * sin(deg3 * M_PI / 180);

		CP_Graphics_DrawTriangle(x1, y1, x2, y2, x3, y3);

		//Set selected car
		if (carArray[i].selected == 1) {
			selectedCar = &carArray[i];
		}
	}

	if (CP_Input_KeyDown(KEY_A)) {
		//decrease angle
		if (selectedCar->direction == 0) {
			selectedCar->direction = 359;
		}
		else selectedCar->direction--;
	}

	if (CP_Input_KeyDown(KEY_D)) {
		//increase angle
		if (selectedCar->direction == 359) {
			selectedCar->direction = 0;
		}
		else selectedCar->direction++;
	}

	//Get direction the car is facing based on the degrees from the positive x axis
	CP_Vector directionVector = AngleToVector(selectedCar->direction * (float)(M_PI / (float)180));

	if (CP_Input_KeyDown(KEY_S)) {
		//move backwards (negate the vector)
		selectedCar->position = moveCar(selectedCar->position, CP_Vector_Negate(directionVector), 100);
	}

	if (CP_Input_KeyDown(KEY_W)) {
		//move forward
		selectedCar->position = moveCar(selectedCar->position, directionVector, 100);
	}

	//go back to main menu
	if (CP_Input_KeyDown(KEY_Q)) {
		CP_Engine_SetNextGameState(Main_Menu_Init, Main_Menu_Update, Main_Menu_Exit);
	}

	CP_Graphics_ClearBackground(CP_Color_Create(197, 199, 196, 255));
	
}

void Car_Level_Exit()
{

}
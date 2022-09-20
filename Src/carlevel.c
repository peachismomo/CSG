#include "cprocessing.h"
#include "structs.h"
#include "utils.h"
#include "mainmenu.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

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
		CP_Vector point1 = CP_Vector_Set(carArray[i].position.x + 25, carArray[i].position.y); //Point 1 => the head of the triangle
		CP_Vector point2 = CP_Vector_Set(carArray[i].position.x - 15, carArray[i].position.y + 15);
		CP_Vector point3 = CP_Vector_Set(carArray[i].position.x - 15, carArray[i].position.y - 15);

		//Draw triangle and the rotation in degrees
		CP_Graphics_DrawTriangleAdvanced(point1.x, point1.y, point2.x, point2.y, point3.x, point3.y, carArray[i].direction);

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
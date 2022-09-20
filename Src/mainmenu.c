#include "cprocessing.h"
#include "carlevel.h"
#include "utils.h"

void Main_Menu_Init()
{
	CP_System_SetWindowSize(CP_System_GetDisplayWidth() / 2, CP_System_GetDisplayHeight() / 2);
	CP_Settings_RectMode(CP_POSITION_CENTER);
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_CENTER, CP_TEXT_ALIGN_V_MIDDLE);
}

void Main_Menu_Update()
{
	if (CP_Input_KeyDown(KEY_ESCAPE)) {
		CP_Engine_Terminate();
	}
	if (CP_Input_MouseClicked()) {
		CP_Vector mousePos = CP_Vector_Set(CP_Input_GetMouseX(), CP_Input_GetMouseY());


		if (IsAreaClicked((float)CP_System_GetWindowWidth() / 2.0f, (float)CP_System_GetWindowHeight() / 2.0f, 100, 50, mousePos.x, mousePos.y) > 0) {
			CP_Engine_SetNextGameState(Car_Level_Init, Car_Level_Update, Car_Level_Exit);
		}

		if (IsAreaClicked((float)CP_System_GetWindowWidth() / 2.0f, (float)CP_System_GetWindowHeight() / 2.0f + 100.0f, 100, 50, mousePos.x, mousePos.y) > 0) {
			CP_Engine_Terminate();
		}
	}
	/*---------------------------------------------Buttons--------------------------------------------------------*/
	//Play
	CP_Graphics_ClearBackground(CP_Color_Create(197, 199, 196, 255));
	CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
	CP_Graphics_DrawRect(CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.0f, 100, 50);

	//Exit
	CP_Graphics_DrawRect(CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.0f + 100, 100, 50);

	/*-----------------------------------------------Text---------------------------------------------------------*/
	//Play
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(20.0f);
	CP_Font_DrawText("Play", CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.0f);

	//Exit
	CP_Font_DrawText("Exit", CP_System_GetWindowWidth() / 2.0f, CP_System_GetWindowHeight() / 2.0f + 100);
}

void Main_Menu_Exit()
{

}
#include "cprocessing.h"

void Main_Menu_Init()
{
	CP_System_Fullscreen();
	CP_Settings_RectMode(CP_POSITION_CENTER);

	//CP_System_SetWindowSize(CP_System_GetDisplayWidth() / 2, CP_System_GetDisplayHeight() / 2);
}

void Main_Menu_Update()
{
	if (CP_Input_KeyDown(KEY_ESCAPE)) {
		CP_Engine_Terminate();
	}
	CP_Graphics_ClearBackground(CP_Color_Create(197, 199, 196, 255));
	CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
	//CP_Graphics_DrawRect(CP_System_GetWindowWidth() / 2, CP_System_GetWindowHeight() / (-2), 50, 25);
	CP_Graphics_DrawRect(CP_System_GetWindowWidth() / 2, CP_System_GetWindowHeight() / (-2), 50, 25);
	CP_Settings_TextSize(20.0f);
	CP_Font_DrawText("Play", CP_System_GetWindowWidth() / 2, CP_System_GetWindowHeight() / -2);

}

void Main_Menu_Exit()
{

}
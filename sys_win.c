#include "winquake.h"
#include "quakedef.h"

int32_t CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int32_t nCmdShow)
{
	COM_ParseCmdLine(lpCmdLine);
	{ //test
		uint8_t s1[] = "LOLKA TEST";
		uint8_t s2[9];
		Q_strcpy(s1, s2);
		int len = Q_strlen(s2);
		uint8_t s3[20];
		Q_strncpy(s1, s3, 3);
	    len = Q_strlen(s3);
	}
	int32_t test = COM_CheckParm("-setalpha"); 
	int32_t value = Q_atoi(com_argv[test + 1]);
    return 0;
}

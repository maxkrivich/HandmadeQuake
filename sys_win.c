#include "winquake.h"
#include "quakedef.h"

int32 CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int32 nCmdShow)
{
	COM_ParseCmdLine(lpCmdLine);
	/*
	{ //test
		char s1[] = "LOLKA TEST";
		char s2[9];
		Q_strcpy(s1, s2);
		int len = Q_strlen(s2);
		char s3[20];
		Q_strncpy(s1, s3, 3);
		len = Q_strlen(s3);
		int32 test = COM_CheckParm("-setalpha");
		int32 value = Q_atoi(com_argv[test + 1]);
		int32 cc = Q_atoi("0b110010");
	}
	*/
    return 0;
}

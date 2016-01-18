#pragma once

#define MAX_NUM_ARGVS 50

extern int32 com_argc;
extern char *com_argv[MAX_NUM_ARGVS + 1];

int32 COM_CheckParm(char *parm);
void COM_ParseCmdLine(char *lpCmdLine);
#include <windows.h>
#include <stdint.h>
#include <assert.h>

#define MAX_NUM_ARGVS 50
#define NDEBUG

int32_t argc = 1;
uint8_t *largv[MAX_NUM_ARGVS + 1];

int32_t Q_strcmp(const uint8_t *s1, const uint8_t *s2) 
{
	while (*s1 && *s2 && *s1 == *s2) {++s1; ++s2;}
	return *s1 - *s2;
}

int32_t Q_atoi(const uint8_t *s)
{
	assert(s);
	int32_t sign = 1, val = 0;
	uint8_t c;

	if (*s == '-')
	{
		sign = -1;
		s++;
	}

	// hex 0xf 0Xf
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
	{
		s += 2;
		while (1) 
		{
			c = *s;
			s++;
			if (isdigit(c))
				val = val * 16 + c - '0';
			else if (isxdigit(c))
			{
				if (isupper(c)) c = c + 32;
				val = val * 16 + c - 'a' + 10;
			}
			else
				return sign * val;
		}
	}


	//dec
	while (1)
	{
		c = *s;
		s++;
		if (!isdigit(c))
			return sign * val;
		val = val * 10 + c - '0';
	}
	return 0;
}

int32_t COM_CheckParm(char *parm)
{
    for (int32_t i = 1; i < argc; i++)
        if (!Q_strcmp(parm, largv[i]))
            return i;
    return 0;
}

int32_t CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int32_t nCmdShow)
{
    largv[0] = "";

    while (*lpCmdLine && (argc < MAX_NUM_ARGVS + 1))
    {
        while (*lpCmdLine && ((*lpCmdLine <= 32) || (*lpCmdLine > 126)))
            lpCmdLine++;

        if (*lpCmdLine)
        {
            largv[argc] = lpCmdLine;
            argc++;

            while (*lpCmdLine && ((*lpCmdLine > 32) && (*lpCmdLine <= 126)))
                lpCmdLine++;

            if (*lpCmdLine)
            {
                *lpCmdLine = 0;
                lpCmdLine++;
            }
        }
    }

	int32_t test = COM_CheckParm("-setalpha");
	int32_t value = Q_atoi(largv[test + 1]);
    return 0;
}

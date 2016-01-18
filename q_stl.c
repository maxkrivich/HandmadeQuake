#include "quakedef.h"

int32 Q_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2) { ++s1; ++s2; }
	return *s1 - *s2;
}

int32 Q_atoi(const char *s)
{
	int32 sign = 1, val = 0;
	char c;

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
			if (c >= '0' && c <= '9')
				val = (val << 4) + c - '0';
			else if (c >= 'a' && c <= 'f')
				val = (val << 4) + c - 'a' + 10;
			else if (c >= 'A' && c <= 'F')
				val = (val << 4) + c - 'A' + 10;
			else
				return sign * val;
		}
	}

	//bin 0b0110
	if (s[0] == '0' && (s[1] == 'b' || s[1] == 'B')) 
	{
		s += 2;
		while (1)
		{
			c = *s;
			s++;
			if (c == '0' || c == '1')
				val = (val << 1) + c - '0';
			else
				return sign * val;
		}
	}

	//dec
	while (1)
	{
		c = *s;
		s++;
		if (!(c >= '0' && c <= '9'))
			return sign * val;
		val = val * 10 + c - '0';
	}
}

void Q_strcpy(const char *from, char *to)
{
	int32 i = 0;
	for (; from[i]; ++i)
		to[i] = from[i];
	to[i] = 0;
}

void Q_strncpy(const char *from, char *to, int32 cnt)
{
	if (cnt <= 0)
		return;
	int32 i = 0;
	for (; from[i] && cnt; ++i, --cnt)
		to[i] = from[i];
	for (; cnt; --cnt, ++i)
		to[i] = 0;
}

size_t Q_strlen(const char *str)
{
	const char *s;
	for (s = str; *s; ++s);
	return (s - str);
}
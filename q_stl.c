#include "quakedef.h"

int32 Q_strcmp(const uint8 *s1, const uint8 *s2)
{
	while (*s1 && *s2 && *s1 == *s2) { ++s1; ++s2; }
	return *s1 - *s2;
}

int32 Q_atoi(const uint8 *s)
{
	int32 sign = 1, val = 0;
	uint8 c;

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

void Q_strcpy(const uint8 *from, uint8 *to)
{
	size_t i = 0;
	for (; from[i]; ++i)
		to[i] = from[i];
	to[i] = 0;
}

void Q_strncpy(const uint8 *from, uint8 *to, int32 cnt)
{
	if (cnt < 0)
		return;
	size_t i = 0;
	for (; from[i] && cnt; ++i, --cnt)
		to[i] = from[i];
	for (; cnt; --cnt, ++i)
		to[i] = 0;
}

size_t Q_strlen(const uint8 *s)
{
	size_t len = 0;
	for (; s[len]; ++len){}
	return len;
}
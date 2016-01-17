#include "quakedef.h"

int32_t Q_strcmp(const uint8_t *s1, const uint8_t *s2)
{
	while (*s1 && *s2 && *s1 == *s2) { ++s1; ++s2; }
	return *s1 - *s2;
}

int32_t Q_atoi(const uint8_t *s)
{
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

void Q_strcpy(const uint8_t *from, uint8_t *to)
{
	size_t i = 0;
	for (; from[i]; ++i)
		to[i] = from[i];
	to[i] = 0;
}

void Q_strncpy(const uint8_t *from, uint8_t *to, int32_t cnt)
{
	if (cnt < 0)
		return;
	size_t i = 0;
	for (; from[i] && cnt; ++i, --cnt)
		to[i] = from[i];
	for (; cnt; --cnt, ++i)
		to[i] = 0;
}

size_t Q_strlen(const uint8_t *s)
{
	size_t len = 0;
	for (; s[len]; ++len){}
	return len;
}
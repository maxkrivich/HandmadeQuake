#pragma once

int32 Q_strcmp(const uint8 *s1, const uint8 *s2);
int32 Q_atoi(const uint8 *s);
void Q_strcpy(const uint8 *from, uint8 *to);
void Q_strncpy(const uint8 *from, uint8 *to, int32 cnt);
size_t Q_strlen(const uint8 *s);
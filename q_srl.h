#pragma once

int32_t Q_strcmp(const uint8_t *s1, const uint8_t *s2);
int32_t Q_atoi(const uint8_t *s);
void Q_strcpy(const uint8_t *from, uint8_t *to);
void Q_strncpy(const uint8_t *from, uint8_t *to, int32_t cnt);
size_t Q_strlen(const uint8_t *s);
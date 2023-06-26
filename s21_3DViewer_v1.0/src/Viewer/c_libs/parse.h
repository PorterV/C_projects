#ifndef C8_3DVIEWER_V1_0_1_PARSE_H
#define C8_3DVIEWER_V1_0_1_PARSE_H

#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>

int s21_parse(char *filename, float **ver, unsigned int **pov, int *ver_col, int *per_col);
void s21_scale(float *points, float scale, int n_points);
void s21_rotate(float *points, int n_points, float alpha, int type, float pos_x, float pos_y, float pos_z);
void s21_movement(float *points, int n_points, float delta, int type);

#endif //C8_3DVIEWER_V1_0_1_PARSE_H

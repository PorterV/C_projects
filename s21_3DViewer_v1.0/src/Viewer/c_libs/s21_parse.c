#include "parse.h"

int s21_parse(char *filename, float **ver, unsigned int **pov, int *ver_col, int *pov_col) {
    int res = 1;
    FILE *file = fopen(filename, "rw+");
    char *tmp = NULL;
    size_t len;
    float x_min = FLT_MAX, x_max = FLT_MIN;
    float y_min = FLT_MAX, y_max = FLT_MIN;
    float z_min = FLT_MAX, z_max = FLT_MIN;
    float max_range;
    while (getline(&tmp, &len, file) != -1) {
        if (tmp[0] == 'v' && tmp[1] == ' ') {
            float x = 0, y = 0, z = 0;
            if((sscanf(tmp, "v %f %f %f", &x, &y, &z)) != 3) {
                res = 0; break;
            }
            (*ver_col)++;
            x_max = fmaxf(x, x_max);
            x_min = fminf(x, x_min);
            y_max = fmaxf(y, y_max);
            y_min = fminf(y, y_min);
            z_max = fmaxf(z, z_max);
            z_min = fminf(z, z_min);
        } else if (tmp[0] == 'f' && tmp[1] == ' ') {
            *pov_col += 6;
        }
    }
    if(res){
        rewind(file);
        *ver = (float *) calloc(*ver_col * 3, sizeof(float));
        *pov = (unsigned int *) calloc(*pov_col, sizeof(unsigned int));
        max_range = fmaxf(fmaxf(x_max - x_min, y_max - y_min), z_max - z_min);
        
        size_t ver_now = 0;
        size_t pov_now = 0;
        while (getline(&tmp, &len, file) != -1) {
            if (tmp[0] == 'v' && tmp[1] == ' ') {
                float x, y, z;
                sscanf(tmp, "v %f %f %f", &x, &y, &z);
                ver[0][ver_now++] = (x - x_min) / max_range;
                ver[0][ver_now++] = (y - y_min) / max_range;
                ver[0][ver_now++] = (z - z_min) / max_range;
            } else if (tmp[0] == 'f' && tmp[1] == ' ') {
                int i1, i2, i3;
                
                strtok(tmp, " ");
                char *tmp1 = strtok(NULL, " ");
                if(tmp1 == NULL) {
                    printf("%s", tmp1);
                    res = 0;
                    break;
                }
                sscanf(tmp1, "%d", &i1);
                tmp1 = strtok(NULL, " ");
                if(tmp1 == NULL) {
                    printf("%s", tmp1);
                    res = 0;
                    break;
                }
                sscanf(tmp1, "%d", &i2);
                tmp1 = strtok(NULL, " ");
                if(tmp1 == NULL) {
                    printf("%s", tmp1);
                    res = 0;
                    break;
                }
                sscanf(tmp1, "%d", &i3);
                
                pov[0][pov_now++] = i1 - 1;
                pov[0][pov_now++] = i2 - 1;
                pov[0][pov_now++] = i2 - 1;
                pov[0][pov_now++] = i3 - 1;
                pov[0][pov_now++] = i3 - 1;
                pov[0][pov_now++] = i1 - 1;
            }
        }
    }
    fclose(file);
    if (tmp) {
        free(tmp);
    }
    return res;
}

void s21_scale(float *points, float scale, int n_points) {
    for (int i = 0; i < n_points * 3; i++) {
        points[i] *= scale;
    };
}

void s21_rotate(float *points, int n_points, float alpha, int type, float pos_x, float pos_y, float pos_z) {
    switch (type) {
        case 1:
            for (int i = 0; i < n_points * 3; i += 3) {
                float y = points[i + 1] + pos_y * 0.1;
                float z = points[i + 2] + pos_z * 0.1;
                points[i + 1] = y * cosf(alpha) + z * sinf(alpha) - pos_y * 0.1;
                points[i + 2] = -y * sinf(alpha) + z * cosf(alpha) - pos_z * 0.1;
            }
            break;
        case 2:
            for (int i = 0; i < n_points * 3; i += 3) {
                float x = points[i] + pos_x * 0.1;
                float z = points[i + 2] + pos_z * 0.1;
                points[i] = x * cosf(alpha) + z * sinf(alpha) - pos_x * 0.1;
                points[i + 2] = -x * sinf(alpha) + z * cosf(alpha) - pos_z * 0.1;
            }
            break;
        case 3:
            for (int i = 0; i < n_points * 3; i += 3) {
                float x = points[i] + pos_x * 0.1;
                float y = points[i + 1] + pos_y * 0.1;
                points[i] = x * cosf(alpha) + y * sinf(alpha) - pos_x * 0.1;
                points[i + 1] = -x * sinf(alpha) + y * cosf(alpha) - pos_y* 0.1;
            }
            break;
    }
}

void s21_movement(float *points, int n_points, float delta, int type) {
    switch (type) {
        case 1:
            for (int i = 0; i < n_points * 3; i+=3)
                points[i] += delta;
            break;
        case 2:
            for (int i = 0; i < n_points * 3; i+=3)
                points[i+1] += delta;
            break;
        case 3:
            for (int i = 0; i < n_points * 3; i+=3)
                points[i+2] += delta;
            break;
    }
}

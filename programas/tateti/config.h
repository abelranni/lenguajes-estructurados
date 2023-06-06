#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#ifndef _INC_CONFIG
#define _INC_CONFIG

typedef struct {
    int screen_width;
    int screen_height;
    int background_color[3];
} Config;

Config read_config(const char *filename);
void write_config(const char *filename, const Config *config);
void modify_config(const char *filename, const char *key, const char *value);

#endif // _INC_CONFIG
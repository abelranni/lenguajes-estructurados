
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "config.h"
#include "global.h"

Config read_config_2(const char *filename)
{
    Config config;
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "No se pudo abrir el archivo %s\n", filename);
        exit(1);
    }

    fscanf(file, "screen_width=%d\n", &config.screen_width);

    fscanf(file, "screen_height=%d\n", &config.screen_height);

    fscanf(file, "background_color=%d,%d,%d\n",
           &config.background_color[0],
           &config.background_color[1],
           &config.background_color[2]);

    fclose(file);
    return config;
}

Config read_config(const char *filename)
{
    Config config;
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "No se pudo abrir el archivo %s\n", filename);
        exit(1);
    }

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        if (strncmp(line, "screen_width=", 13) == 0)
        {
            sscanf(line, "screen_width=%d", &config.screen_width);
        }
        else if (strncmp(line, "screen_height=", 14) == 0)
        {
            sscanf(line, "screen_height=%d", &config.screen_height);
        }
        else if (strncmp(line, "background_color=", 17) == 0)
        {
            sscanf(line, "background_color=%d,%d,%d",
                   &config.background_color[0],
                   &config.background_color[1],
                   &config.background_color[2]);
        }
    }

    fclose(file);
    return config;
}

void write_config(const char *filename, const Config *config) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Could not open config file %s\n", filename);
        exit(1);
    }

    fprintf(file, "screen_width=%d\n", config->screen_width);
    fprintf(file, "screen_height=%d\n", config->screen_height);
    fprintf(file, "background_color=%d,%d,%d\n", 
            config->background_color[0], 
            config->background_color[1], 
            config->background_color[2]);

    fclose(file);
}

void modify_config(const char *filename, const char *key, const char *value) {

    Config config = read_config(filename);
    
    if (strcmp(key, "screen_width") == 0) {
        config.screen_width = atoi(value);
    } else if (strcmp(key, "screen_height") == 0) {
        config.screen_height = atoi(value);
    } else if (strcmp(key, "background_color") == 0) {
        sscanf(value, "%d,%d,%d", 
               &config.background_color[0], 
               &config.background_color[1], 
               &config.background_color[2]);
    } else {
        fprintf(stderr, "Unknown key: %s\n", key);
        exit(1);
    }

    write_config(filename, &config);
}
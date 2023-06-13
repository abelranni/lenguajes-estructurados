#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "config.h"
#include "global.h"

#define CONFIG_FILE  "./config.cfg"

int parse_command( int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usar: %s <command> [args]\n", argv[0]);
        printf("No se detectan argumentos de comando\n");
        return 0;    
    }

    if (strcmp(argv[1], "set_param") == 0)
    {
        if (argc != 4)
        {
            fprintf(stderr, "Usar: %s parametro valor\n", argv[0]);
            exit(1);
        }
        const char *key = argv[2];
        const char *value = argv[3];      

        printf("Configuración modificada\n");
        printf("Clave: %s\n", key);
        printf("Valor: %s\n", value);
        
        modify_config(CONFIG_FILE, key, value);
    }
    else
    {
        fprintf(stderr, "Comando desconocido: %s\n", argv[1]);
        exit(1);
    }
    return 0;
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
        else if (strncmp(line, "game_mode=", 10) == 0)
        {
            sscanf(line, "game_mode=%d", &config.game_mode);
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

void modify_config(const char *filename, const char *key, const char *value) {

    Config config = read_config(filename);
    
    if (strcmp(key, "screen_width") == 0) {
        config.screen_width = atoi(value);
    } else if (strcmp(key, "screen_height") == 0) {
        config.screen_height = atoi(value);
    } else if (strcmp(key, "game_mode") == 0) {
        config.game_mode = atoi(value);        
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

void write_config(const char *filename, const Config *config) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Could not open config file %s\n", filename);
        exit(1);
    }
    fprintf(file, "game_mode=%d\n", config->game_mode);
    fprintf(file, "screen_width=%d\n", config->screen_width);
    fprintf(file, "screen_height=%d\n", config->screen_height);
    fprintf(file, "background_color=%d,%d,%d\n", 
            config->background_color[0], 
            config->background_color[1], 
            config->background_color[2]);

    fclose(file);
}

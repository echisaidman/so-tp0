#include <stdlib.h>
#include <commons/log.h>
#include <commons/config.h>
#include <readline/readline.h>

int main(void)
{
    t_log *logger = log_create("cfg/log_tp0.txt", "TP0", true, LOG_LEVEL_INFO);
    log_info(logger, "Empezando TP0...");

    t_config *config = config_create("cfg/tp0.config");
    char *clave = config_get_string_value(config, "CLAVE");
    log_info(logger, "Clave: %s", clave);
    config_destroy(config);

    char *linea = readline(" TP0> ");
    while (strcmp(linea, "") != 0)
    {
        log_info(logger, "%s", linea);
        free(linea);
        linea = readline(" TP0> ");
    }
    free(linea);

    log_info(logger, "Finalizo el TP0");
    log_destroy(logger);
}

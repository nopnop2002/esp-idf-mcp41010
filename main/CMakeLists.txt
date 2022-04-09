set(component_srcs "main.c" "mcp41010.c")

idf_component_register(SRCS "${component_srcs}"
                       INCLUDE_DIRS ".")



set(component_srcs "mcp41010.c")

idf_component_register(SRCS "${component_srcs}"
                       PRIV_REQUIRES driver
                       INCLUDE_DIRS ".")

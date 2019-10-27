#include "hello_world.h"

void hello(char *buffer, int length, const char *name) {
    snprintf(buffer, length, "Hello, %s!", strlen(name) > 0 ? name : "World");
}

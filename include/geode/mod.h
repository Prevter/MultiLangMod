#ifndef GEODE_INTEROP_MOD_H
#define GEODE_INTEROP_MOD_H

#include "utils.h"
#include <stdbool.h>

typedef struct geode_Mod geode_Mod;

/// @brief Get the Mod of the current mod being developed
EXTERNC GEODE_INTEROP_API geode_Mod* geode_Mod_get();

EXTERNC GEODE_INTEROP_API void geode_Mod_getID(geode_Mod* self, char* buffer, size_t buffer_size);
EXTERNC GEODE_INTEROP_API void geode_Mod_getName(geode_Mod* self, char* buffer, size_t buffer_size);
EXTERNC GEODE_INTEROP_API bool geode_Mod_isEnabled(geode_Mod* self);

#endif //GEODE_INTEROP_MOD_H
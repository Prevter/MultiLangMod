#include <geode/mod.h>

EXTERNC GEODE_INTEROP_API geode_Mod* geode_Mod_get() {
    return (geode_Mod*) geode::Mod::get();
}

EXTERNC GEODE_INTEROP_API void geode_Mod_getID(geode_Mod* self, char* buffer, size_t buffer_size) {
    auto* mod = (geode::Mod*) self;
    auto id = mod->getID();
    strncpy_s(buffer, buffer_size, id.c_str(), id.size());
}

EXTERNC GEODE_INTEROP_API void geode_Mod_getName(geode_Mod* self, char* buffer, size_t buffer_size) {
    auto* mod = (geode::Mod*) self;
    auto name = mod->getName();
    strncpy_s(buffer, buffer_size, name.c_str(), name.size());
}

EXTERNC GEODE_INTEROP_API bool geode_Mod_isEnabled(geode_Mod* self) {
    auto* mod = (geode::Mod*) self;
    return mod->isEnabled();
}
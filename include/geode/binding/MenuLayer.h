#ifndef GEODE_INTEROP_BINDING_MENULAYER_H
#define GEODE_INTEROP_BINDING_MENULAYER_H

#include "../utils.h"

typedef struct MenuLayer MenuLayer;

/// ==== MenuLayer::init ==== ///
EXTERNC GEODE_INTEROP_API bool MenuLayer_init(MenuLayer* self);
EXTERNC GEODE_INTEROP_API void MenuLayer_init_hook(bool(*detour)(MenuLayer* self));

/// ==== MenuLayer::onMoreGames ==== ///
EXTERNC GEODE_INTEROP_API void MenuLayer_onMoreGames(MenuLayer* self, void* sender);
EXTERNC GEODE_INTEROP_API void MenuLayer_onMoreGames_hook(void(*detour)(MenuLayer* self, void* sender));

/// ==== MenuLayer::onTwitter ==== ///
EXTERNC GEODE_INTEROP_API void MenuLayer_onTwitter(MenuLayer* self, void* sender);
EXTERNC GEODE_INTEROP_API void MenuLayer_onTwitter_hook(void(*detour)(MenuLayer* self, void* sender));

#endif
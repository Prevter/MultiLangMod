#ifndef GEODE_INTEROP_BINDING_FLALERTLAYER_H
#define GEODE_INTEROP_BINDING_FLALERTLAYER_H

#include "../utils.h"

typedef struct FLAlertLayer FLAlertLayer;

/// ==== FLAlertLayer::create ==== ///
EXTERNC GEODE_INTEROP_API FLAlertLayer* FLAlertLayer_create(const char* title, const char* body, const char* button);

/// ==== FLAlertLayer::show ==== ///
EXTERNC GEODE_INTEROP_API void FLAlertLayer_show(FLAlertLayer* self);
EXTERNC GEODE_INTEROP_API void FLAlertLayer_show_hook(void(*detour)(FLAlertLayer* self));

#endif
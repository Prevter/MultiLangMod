#include <geode/binding/FLAlertLayer.h>

EXTERNC GEODE_INTEROP_API FLAlertLayer* FLAlertLayer_create(const char* title, const char* body, const char* button) {
    return FLAlertLayer::create(title, body, button);
}

EXTERNC GEODE_INTEROP_API void FLAlertLayer_show(FLAlertLayer* self) {
    ((FLAlertLayer*)self)->show();
}

EXTERNC GEODE_INTEROP_API void FLAlertLayer_show_hook(void(*detour)(FLAlertLayer* self)) {
    static auto address = geode::base::get() + 0x31cd0;
    (void) geode::Mod::get()->hook(
        reinterpret_cast<void*>(address),
        detour, "FLAlertLayer::show",
        tulip::hook::TulipConvention::Thiscall
    );
}
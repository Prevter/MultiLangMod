#include <geode/binding/MenuLayer.h>

EXTERNC GEODE_INTEROP_API bool MenuLayer_init(MenuLayer* self) {
    return self->init();
}

EXTERNC GEODE_INTEROP_API void MenuLayer_init_hook(bool(*detour)(MenuLayer* self)) {
    static auto address = geode::base::get() + 0x27b450;
    (void) geode::Mod::get()->hook(
        reinterpret_cast<void*>(address),
        detour, "MenuLayer::init",
        tulip::hook::TulipConvention::Thiscall
    );
}

EXTERNC GEODE_INTEROP_API void MenuLayer_onMoreGames(MenuLayer* self, void* sender) {
    self->onMoreGames(static_cast<cocos2d::CCObject *>(sender));
}

EXTERNC GEODE_INTEROP_API void MenuLayer_onMoreGames_hook(void(*detour)(MenuLayer* self, void* sender)) {
    static auto address = geode::base::get() + 0x27c7a0;
    (void) geode::Mod::get()->hook(
        reinterpret_cast<void*>(address),
        detour, "MenuLayer::onMoreGames",
        tulip::hook::TulipConvention::Thiscall
    );
}

EXTERNC GEODE_INTEROP_API void MenuLayer_onTwitter(MenuLayer* self, void* sender) {
    self->onTwitter(static_cast<cocos2d::CCObject *>(sender));
}

EXTERNC GEODE_INTEROP_API void MenuLayer_onTwitter_hook(void(*detour)(MenuLayer* self, void* sender)) {
    static auto address = geode::base::get() + 0x27c720;
    (void) geode::Mod::get()->hook(
        reinterpret_cast<void*>(address),
        detour, "MenuLayer::onTwitter",
        tulip::hook::TulipConvention::Thiscall
    );
}
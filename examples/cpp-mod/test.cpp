#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

$execute {
    auto* mod = geode::Mod::get();
    geode::log::info("Hello, world from \"{}\"!", mod->getName());
    geode::log::warn("The ID of the mod is \"{}\".", mod->getID());
}

class $modify(MenuLayer) {
    void onMoreGames(cocos2d::CCObject* sender) {
        FLAlertLayer::create("Hello, world!", "This is a test alert.", "OK")->show();
    }
};
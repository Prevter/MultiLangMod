#include <geode.h>

$execute {
    geode_Mod* mod = geode_Mod_get();
    char id[256]; geode_Mod_getID(mod, id, sizeof(id));
    char name[256]; geode_Mod_getName(mod, name, sizeof(name));

    log_info("Hello, world from \"%s\"!", name);
    log_warn("The ID of the mod is \"%s\".", id);
}

$hook(void, MenuLayer_onMoreGames, (MenuLayer* self, void* sender)) {
    FLAlertLayer* alert = FLAlertLayer_create("Hello, world!", "This is a test alert.", "OK");
    FLAlertLayer_show(alert);
}



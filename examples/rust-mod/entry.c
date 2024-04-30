extern void geode_main();
void e() __attribute__((constructor));
void e() { geode_main(); }
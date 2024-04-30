extern void GeodeMain();
void e() __attribute__((constructor));
void e() { GeodeMain(); }


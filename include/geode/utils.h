#ifndef GEODE_INTEROP_UTILS_H
#define GEODE_INTEROP_UTILS_H

#ifdef GEODE_INTEROP_SHARED
    #ifdef _WIN32
        #ifdef GEODE_INTEROP_EXPORTS
            #define GEODE_INTEROP_API __declspec(dllexport)
        #else
            #define GEODE_INTEROP_API __declspec(dllimport)
        #endif
    #else
        #define GEODE_INTEROP_API
    #endif
#else
    #define GEODE_INTEROP_API
#endif

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

#define $stringify(x) $stringify2(x)
#define $stringify2(x) #x

#define $concat(a, b) $concat2(a, b)
#define $concat2(a, b) a ## b

#define $unique(name) $concat(name, __LINE__)

#undef $execute
#define $execute \
void $unique(execute)() __attribute__((constructor));\
void $unique(execute)()

#define $hook(returnType, method, args) \
returnType $unique(method##hook)args; \
$execute { method##_hook($unique(method##hook)); } \
returnType $unique(method##hook)args

#endif //GEODE_INTEROP_UTILS_H
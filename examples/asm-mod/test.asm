; Import some Geode API functions
extern _geode_Mod_get ; GeodeMod* geode_Mod_get()
extern _geode_Mod_getName ; void geode_Mod_getName(GeodeMod* mod, char* buffer, int bufferSize)
extern _geode_Mod_getID ; void geode_Mod_getID(GeodeMod* mod, char* buffer, int bufferSize)
extern _log_info ; void log_info(const char* fmt, ...)
extern _log_warn ; void log_warn(const char* fmt, ...)
extern _MenuLayer_onMoreGames_hook ; void MyMenuLayer_onMoreGames_hook(void(*detour)(MenuLayer* self, void* sender))
extern _FLAlertLayer_create ; FLAlertLayer* FLAlertLayer_create(const char* title, const char* body, const char* button);
extern _FLAlertLayer_show ; void FLAlertLayer_show(FLAlertLayer* self);

section .text
; Geode mod entry point
; Stack layout:
; 0x000 - GeodeMod* mod
; 0x004 - char id[0x100]
; 0x104 - char name[0x100]
; 0x204 - return address
global _GeodeMain

_GeodeMain:
    push ebx
    push edi
    push esi

    ; Set up the stack
    sub esp, 0x204

    ; Get the mod
    call _geode_Mod_get
    mov esi, eax

    ; Get the mod name
    lea edi, [esp + 0x100] ; name
    push 0x100 ; buffer size
    push edi   ; buffer
    push eax   ; mod
    call _geode_Mod_getID
    add esp, 0x0c

    ; Get the mod ID
    mov ebx, esp ; id
    push 0x100 ; buffer size
    push ebx   ; buffer
    push esi   ; mod
    call _geode_Mod_getName
    add esp, 0x0c

    ; Log the mod name
    push ebx
    push log1
    call _log_info
    add esp, 0x8

    ; Log the mod ID
    push edi
    push log2
    call _log_info
    add esp, 0x8

    ; Hook the More Games button
    push MyMenuLayer_onMoreGames
    call _MenuLayer_onMoreGames_hook
    add esp, 0x4

    ; Return
    add esp, 0x204
    pop esi
    pop edi
    pop ebx
    ret

MyMenuLayer_onMoreGames:
    push alertButton
    push alertBody
    push alertTitle
    call _FLAlertLayer_create
    add esp, 0x0c
    push eax
    call _FLAlertLayer_show
    add esp, 0x4
    ret

section .data
log1 db "Hello, world from ", 34, "%s", 34, "!", 0
log2 db "The ID of the mod is ", 34, "%s", 34, ".", 0

alertTitle db "Hello, world!", 0
alertBody db "This alert is made using x86 Assembly!", 0
alertButton db "OK", 0

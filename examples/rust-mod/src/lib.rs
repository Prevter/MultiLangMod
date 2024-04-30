// MenuLayer

pub struct MenuLayer {
    _ptr: *mut std::ffi::c_void
}

impl MenuLayer {
    pub fn on_twitter(detour: extern "C" fn(*mut std::ffi::c_void, *mut std::ffi::c_void)) {
        unsafe {
            MenuLayer_onTwitter_hook(detour);
        }
    }
}

// FLAlertLayer

pub struct FLAlertLayer {
    _ptr: *mut std::ffi::c_void
}

impl FLAlertLayer {
    pub fn create(title: &str, message: &str, button: &str) -> FLAlertLayer {
        let title = format!("{}\0", title);
        let message = format!("{}\0", message);
        let button = format!("{}\0", button);
        FLAlertLayer {
            _ptr: unsafe { FLAlertLayer_create(title.as_ptr(), message.as_ptr(), button.as_ptr()) }
        }
    }

    pub fn show(&self) {
        unsafe {
            FLAlertLayer_show(self._ptr);
        }
    }
}

extern "C" {
    fn geode_Mod_get() -> *mut std::ffi::c_void;
    fn geode_Mod_getName(object: *mut std::ffi::c_void, buffer: *mut u8, buffer_size: usize);
    fn geode_Mod_getID(object: *mut std::ffi::c_void, buffer: *mut u8, buffer_size: usize);
    fn geode_Mod_isEnabled(object: *mut std::ffi::c_void) -> bool;
    fn log_vimpl(severity: Severity, fmt: *const u8, args: *const u8);
    fn MenuLayer_onTwitter_hook(detour: extern "C" fn(*mut std::ffi::c_void, *mut std::ffi::c_void));
    fn FLAlertLayer_create(title: *const u8, message: *const u8, button: *const u8) -> *mut std::ffi::c_void;
    fn FLAlertLayer_show(layer: *mut std::ffi::c_void);
}

// geode::Mod wrapper

pub struct Mod {
    _ptr: *mut std::ffi::c_void
}

impl Mod {
    pub fn get() -> Mod {
        Mod {
            _ptr: unsafe { geode_Mod_get() }
        }
    }

    pub fn get_name(&self) -> String {
        let mut buffer = [0u8; 256];
        unsafe {
            geode_Mod_getName(self._ptr, buffer.as_mut_ptr(), buffer.len());
        }
        String::from_utf8(buffer.to_vec()).unwrap()
    }

    pub fn get_id(&self) -> String {
        let mut buffer = [0u8; 256];
        unsafe {
            geode_Mod_getID(self._ptr, buffer.as_mut_ptr(), buffer.len());
        }
        String::from_utf8(buffer.to_vec()).unwrap()
    }

    pub fn is_enabled(&self) -> bool {
        unsafe {
            geode_Mod_isEnabled(self._ptr)
        }
    }

}

// Logging macros

#[repr(C)]
pub enum Severity {
    DEBUG = 0,
    INFO = 1,
    WARN = 2,
    ERROR = 3
}

macro_rules! log_vimpl {
    ($severity:expr, $fmt:expr) => {
        unsafe {
            // nullterminate the string
            let fmt = format!("{}\0", $fmt);
            log_vimpl($severity, fmt.as_ptr(), std::ptr::null());
        }
    };
    ($severity:expr, $fmt:expr, $($arg:tt)*) => {
        unsafe {
            let fmt = format!("{}\0", format!($fmt, $($arg)*));
            log_vimpl($severity, fmt.as_ptr(), std::ptr::null());
        }
    };
}
macro_rules! log_debug {
    ($($arg:tt)*) => {
        log_vimpl!(Severity::DEBUG, $($arg)*);
    };
}
macro_rules! log_info {
    ($($arg:tt)*) => {
        log_vimpl!(Severity::INFO, $($arg)*);
    };
}
macro_rules! log_warn {
    ($($arg:tt)*) => {
        log_vimpl!(Severity::WARN, $($arg)*);
    };
}
macro_rules! log_error {
    ($($arg:tt)*) => {
        log_vimpl!(Severity::ERROR, $($arg)*);
    };
}

// Our main entry point

#[no_mangle]
pub extern fn geode_main() {
    let my_mod = Mod::get();
    log_info!("Hello, world from \"{}\"!", my_mod.get_name());
    log_warn!("The ID of the mod is \"{}\".", my_mod.get_id());

    MenuLayer::on_twitter(my_twitter_hook);
}

pub extern fn my_twitter_hook(_this: *mut std::ffi::c_void, _sender: *mut std::ffi::c_void) {
    let alert = FLAlertLayer::create("OMG", "Why did you press the twitter button? Are you stupid or something?", "Yes");
    alert.show();
}


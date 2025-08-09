// Print debugging (run with -DLOCAL, only compatible with C++17 or higher)
#ifdef LOCAL
template<typename T, typename = void>
struct is_pair : false_type {};
template<typename T>
struct is_pair<T, void_t<typename T::first_type, typename T::second_type>> : true_type {};

#define dbg(...) do { \
    const char* _s = #__VA_ARGS__; \
    auto _print = [&](auto&& self, const auto& dbgx) -> void { \
        using dbgX = decay_t<decltype(dbgx)>; \
        if constexpr (is_arithmetic_v<dbgX> || is_same_v<dbgX, string>) cout << dbgx; \
        else if constexpr (is_pair<dbgX>::value) { cout << "{"; self(self, dbgx.first); cout << ", "; self(self, dbgx.second); cout << "}"; } \
        else { cout << "{ "; for (auto &element : dbgx) { self(self, element); cout << " "; } cout << "}"; } \
    }; \
    auto _process_arg = [&](const auto& arg) { \
        while (*_s == ' ' || *_s == ',') ++_s; const char* _b = _s; while (*_s && *_s != ',') ++_s; cout.write(_b, _s - _b); cout << " = "; \
        _print(_print, arg); cout << "; "; \
    }; \
    ([&] <typename... Ts>(Ts&&... args) { ((_process_arg(args)), ...); } )(__VA_ARGS__); \
    cout << endl; \
} while (0)
#else
#define dbg(...) ((void)0)
#endif

// Time delay in seconds
#define delay(t) this_thread::sleep_for(chrono::seconds(t))
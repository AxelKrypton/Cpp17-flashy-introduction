// Only issues a warning when `error_info` is returned by value.
struct [[nodiscard]] error_info {
    int id{0};
};

error_info do_something() {
    return error_info{};
}

error_info& do_something_ref() {
    static error_info err{};
    return err;
}

int main(){
    do_something();
    do_something_ref();    
}


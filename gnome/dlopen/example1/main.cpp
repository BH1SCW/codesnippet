#include <iostream>
#include <dlfcn.h>
#include <gtk/gtk.h>

int main() {
    using std::cout;
    using std::cerr;

    cout << "C++ dlopen demo\n\n";

    gtk_init (NULL, NULL);

    // open the library
    cout << "Opening hello.so...\n";
    void* handle = dlopen("./hello.so", RTLD_LAZY);
    
    if (!handle) {
        cerr << "Cannot open library: " << dlerror() << '\n';
        return 1;
    }
    
    // load the symbol
    cout << "Loading symbol hello...\n";
    typedef void (*hello_t)();

    // reset errors
    dlerror();
    hello_t hello = (hello_t) dlsym(handle, "hello");
    const char *dlsym_error = dlerror();
    if (dlsym_error) {
        cerr << "Cannot load symbol 'hello': " << dlsym_error <<
            '\n';
        dlclose(handle);
        return 1;
    }
    
    // use it to do the calculation
    cout << "Calling hello...\n";
    hello();
   /* start the main loop, and let int rest there until the application is closed */
    gtk_main ();

    // close the library
    cout << "Closing library...\n";
    dlclose(handle);
}

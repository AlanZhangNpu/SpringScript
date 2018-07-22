#ifndef SPRINGLIBRARYLOADER_H
#define SPRINGLIBRARYLOADER_H

#include <string>

namespace spr {

    class SpringRuntimeEnvironment;
    class __declspec(dllexport) SpringLibraryLoader
    {
    public:
        SpringLibraryLoader();

        static void loadBasicLib(SpringRuntimeEnvironment &env);
        static void loadStandardLib(const std::string &libName, SpringRuntimeEnvironment &env);
        static void loadExtensionLib(const std::string &libPath, SpringRuntimeEnvironment &);
    };

}
#endif // SPRINGLIBRARYLOADER_H

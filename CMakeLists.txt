cmake_minimum_required (VERSION 3.8)

project ("MinecraftClient")

add_executable (MinecraftClient "InjectorClient.cpp" "Injector.h" "Injector.cpp")

add_library(McClient SHARED "lib/DllMain.cpp")

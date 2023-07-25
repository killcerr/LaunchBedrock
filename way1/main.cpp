#include <Windows.h>
#include <WinUser.h>
#include <errhandlingapi.h>
#include <handleapi.h>
#include <minwindef.h>
#include <processthreadsapi.h>
#include <stdlib.h>
#include <synchapi.h>
#include <windef.h>
#include <tlhelp32.h>
#include <winnt.h>

#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
void StartBeta() {
  std::cout << "start Beta.\n";
  system("explorer.exe shell:AppsFolder\\Microsoft.MinecraftWindowsBeta_8swekyb3d8bbwe!App");
}
void StartUWP() {
  std::cout << "start UWP.\n";
  system("explorer.exe shell:AppsFolder\\Microsoft.MinecraftUWP_8wekyb3d8bbwe!App");
}
std::unordered_map<std::string, std::string> ParseArgs(int argc, char** argv) {
  std::unordered_map<std::string, std::string> args;
  args["path"] = argv[0];
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    auto dp = arg.find('=');
    std::string key = arg.substr(0, dp);
    std::string value = arg.substr(dp + 1, arg.length() - dp - 1);
    args[key] = value;
  }
  return args;
}
int main(int argc, char** argv) {
  auto args = ParseArgs(argc, argv);
  if (args.count("start_type") == 1) {
    if (args["start_type"] == "UWP")
      StartUWP();
    else if (args["start_type"] == "Beta")
      StartBeta();
    else
      std::cout << "unknown start_type.\n";
  } else {
    std::cout << "start_type is not set.\n";
  }
  system("pause");
}

#include "launcher.h"
#include "launcher_cv.h"
#include "demo_day.h"

int main(int argc, char *argv[])
{
  //instantiate Launcher, LauncherCV or DemoDay here
    DemoDay l;

    l.cam_test();
    return 0;
}

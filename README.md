### Using this code

Clone this repository into `/external`. Make sure you are within the right AOSP env, then cd to the directory of the checkout and run `mm`. The output of the build will tell you where to find the file, e.g.:

    [100% 9/9] Install: out/target/product/generic_x86/system/bin/vmx2-hwc2

Then push the code to the emulator with:

    adb push ${OUT}/system/bin/vmx2-hwc2 /data/local/vmx2-hwc2

And finally run it:

    adb shell /data/local/vmx2-hwc2

You'll see a segfault via:

    adb logcat

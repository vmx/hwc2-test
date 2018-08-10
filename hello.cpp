#include <iostream>

#include <hardware/hwcomposer2.h>

// void hwc2TestHotplugCallback(hwc2_callback_data_t callbackData,
//         hwc2_display_t display, int32_t connected);
// void hwc2TestVsyncCallback(hwc2_callback_data_t callbackData,
//         hwc2_display_t display, int64_t timestamp);



    // void registerCallback(hwc2_callback_descriptor_t descriptor,
    //         hwc2_callback_data_t callbackData, hwc2_function_pointer_t pointer,
    //         hwc2_error_t* outErr = nullptr)
    // {
    //     auto pfn = reinterpret_cast<HWC2_PFN_REGISTER_CALLBACK>(
    //             getFunction(HWC2_FUNCTION_REGISTER_CALLBACK));
    //     ASSERT_TRUE(pfn) << "failed to get function";
    //
    //     auto err = static_cast<hwc2_error_t>(pfn(mHwc2Device, descriptor,
    //             callbackData, pointer));
    //     if (outErr) {
    //         *outErr = err;
    //     } else {
    //         ASSERT_EQ(err, HWC2_ERROR_NONE) << "failed to register callback";
    //     }
    // }

    // hwc2_function_pointer_t getFunction(hwc2_function_descriptor_t descriptor)
    // {
    //     return mHwc2Device->getFunction(mHwc2Device, descriptor);
    // }

// template<typename T>
// void HwcHal::initDispatch(hwc2_function_descriptor_t desc, T* outPfn)
// {
//     auto pfn = mDevice->getFunction(mDevice, desc);
//     if (!pfn) {               
//         LOG_ALWAYS_FATAL("failed to get hwcomposer2 function %d", desc);
//     }                         
//                               
//     *outPfn = reinterpret_cast<T>(pfn);
// }                             
//            


void hwc2TestHotplugCallback(hwc2_callback_data_t ,
        hwc2_display_t , int32_t )
{
  std::cout << "hotplug callback called" << std::endl;
}

int main()
{
          hw_module_t const* hwc2Module;
          hwc2_device_t* mHwc2Device = nullptr;

        int err = hw_get_module(HWC_HARDWARE_MODULE_ID, &hwc2Module);
        if (err) {
          std::cout << "failed to get hwc2 hardware module: " << strerror(-err);
        }

        /* The following method will fail if you have not run
         * "adb shell stop" */
        err = hwc2_open(hwc2Module, &mHwc2Device);
        if (err) {
          std::cout << "failed to open hwc hardware module: " << strerror(-err);
        }


// uint32_t majorVersion = (device->version >> 24) & 0xF;
//  mHwcDevice = std::make_unique<HWC2::Device>(useVrComposer);


    std::cout << "hwcdevce: " << mHwc2Device->common.version << std::endl;

    // registerCallback(HWC2_CALLBACK_HOTPLUG, nullptr,
    //                  reinterpret_cast<hwc2_function_pointer_t>(
    //                      hwc2TestHotplugCallback));


        // auto pfn = reinterpret_cast<HWC2_PFN_REGISTER_CALLBACK>(
        //         getFunction(HWC2_FUNCTION_REGISTER_CALLBACK));
        auto pfn = reinterpret_cast<HWC2_PFN_REGISTER_CALLBACK>(
            mHwc2Device->getFunction(mHwc2Device, HWC2_FUNCTION_REGISTER_CALLBACK));
        // ASSERT_TRUE(pfn) << "failed to get function";

    std::cout << "vmx: still here 1" << pfn << std::endl;

    // XXX vmx 2018-07-17: GO ON HERE and make this call work
        auto err2 = static_cast<hwc2_error_t>(pfn(mHwc2Device, HWC2_CALLBACK_HOTPLUG,
                nullptr, reinterpret_cast<hwc2_function_pointer_t>(
                    hwc2TestHotplugCallback)));

        // mDispatch.registerCallback(mDevice, HWC2_CALLBACK_HOTPLUG, this,
        //         reinterpret_cast<hwc2_function_pointer_t>(hotplugHook));
        // if (outErr) {
        //     *outErr = err2;
        // } else {
        //   if (err2 == HWC2_ERROR_NONE) {
            std::cout << "failed to register callback" << err2 << std::endl;
        // }



    std::cout << "Hello, World4!" << std::endl;

    return 0;
}

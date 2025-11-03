#include <iostream>

#include <vulkan/vulkan.h>

int main() {
    uint32_t instanceVersion = 0;
    VkResult result = vkEnumerateInstanceVersion(&instanceVersion);

    if (result == VK_SUCCESS) {
        std::cout << "Vulkan instance version: "
                << VK_VERSION_MAJOR(instanceVersion) << "."
                << VK_VERSION_MINOR(instanceVersion) << "."
                << VK_VERSION_PATCH(instanceVersion) << std::endl;
    } else {
        std::cerr << "Failed to enumerate Vulkan instance version!" << std::endl;
        return -1;
    }

    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Vulkan Test";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    VkInstance instance;
    result = vkCreateInstance(&createInfo, nullptr, &instance);

    if (result != VK_SUCCESS) {
        std::cerr << "Failed to create Vulkan instance!" << std::endl;
        return -1;
    }

    std::cout << "Vulkan instance create successfully!" << std::endl;

    vkDestroyInstance(instance, nullptr);

    return 0;
}

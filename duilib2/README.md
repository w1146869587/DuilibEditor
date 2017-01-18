# 架构设计

## 基本设计

![architecture](https://github.com/yjwx0017/DuilibEditor/blob/master/architecture.jpg)

## 使用方法

``` c++
#include <duilib2.h>
using namespace duilib2;

// or WinMain
int main(int argc, char *argv[])
{
    // 初始化duilib2
    System::create();

    // 设置资源
    ResourceManager::getSingleton().addResourcePackage("default", "zip", "default.zip");
    ResourceManager::getSingleton().setCurrentResourcePackage("default");

    // 加载布局文件
    Window* rootWindow = WindowManager::getSingleton().loadLayoutFromFile("main.xml");

    // 显示窗口
    rootWindow->showModal();

    // 清理
    System::destroy();

    return 0;
}
```

# ToDoList

- 各控件的绘制

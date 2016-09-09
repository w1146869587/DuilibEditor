# DuilibEditor

这是一个所见即所得的[DuiLib](https://github.com/duilib/duilib)界面编辑器。

开发进度：1%

# 动机

- 开发一个优秀的Duilib界面编辑器
- 学习Qt
- 学习OGRE、CEGUI的架构设计
- 学习可用于Doxygen的代码注释风格
- 学习DuiLib

# 目录说明

```
<root>
 |- <duilib2>      # duilib的重构版本
 |- <DuilibEditor> # DuilibEditor编辑器
 |- <Test>         # 测试代码
 |- <Licenses>     # 第三方Licenses
 |- duilib2.pro    # Qt工程文件
 |- License         
```

# duilib2架构设计

试图学习CEGUI的架构，使代码结构清晰，易于维护。

## 基本设计

![architecture](https://github.com/yjwx0017/DuilibEditor/architecture.jpg)

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

Qt本身就提供了专门的宏 Q_GLOBAL_STATIC

通过这个宏不但定义简单，还可以获得线程安全性。
写法很简单，用法也很简单

在任何地方，引用头文件 include "testdemo.h"

就可以 testdemo::instance()->xxxxxx() 

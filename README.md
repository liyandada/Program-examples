# Program-xamples

这个例程，参考了https://blog.51cto.com/9291927/2118468 的文章

本D-bus例程分为五种方式：
1、创建服务并注册对象
2、通过QDBusMessage访问Service
3、通过QDBusInterface 访问Service
4、从D-Bus XML自动生成Proxy类
5、使用Adapter注册Object
 

如何自动启动Service ？

D-Bus系统提供了一种机制可以在访问某个service时，自动把应用程序运行起来。
需要在/usr/share/dbus-1/services下面建立com.scorpio.test.service文件，文件的内容如下：

	[D-BUS Service]
	Name=com.scorpio.test
	Exec=/path/to/scorpio/test

在访问test的method前，不必手动运行应用程序。

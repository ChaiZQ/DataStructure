# 配置并测试ADB
需要手机已经root
### 安装
```
sudo apt-get update
sudo apt-get install android-tools-adb android-tools-fastboot
```
### 配置


**查看手机id**
```
lsusb
```

**创建规则**

在/etc/udev/rules.d/下创建一个配置文件
创建一个51-android.rules
➜ ~ cd /etc/udev/rules.d/
sudo vi51-android.rules
编辑内容如下，下面“2717”为前面记住的id号：
```
SUBSYSTEM=="usb",ATTR(idVendor)=="2717",
 MODE="0666", GROUP="plugdev"
 ```
 __给这个文件设置权限__
 ```
 sudo chmod 777 51-android.rules
 ```
 
__重启udev__

/etc/init.d/udev restart

增加adb_usb.ini文件
在~/.android目录下增加一个adb_usb.ini文件，这里的路径实际上是各个用户的根目录，如果你需要切换用户的话，记得每个用户下都需要增加这个东东。
adb_usb.ini文件中写入厂商ID号，和前面不同的是这里需要写上0x的前缀，比如我的小米手机手机就是写0x2717
cd ~/.android
然后创建这个文件，然后写上ox2717,然后保存，然后设置权限777
sudo chmod 777 adb_usb.ini

**重启adb**
```
adb kill-server
adb start-server
adb devices
```


### 测试ADB
```
# 打印版本号
adb version
```

截屏并复制到本地
```
adb screencap /sdcard/zzz.png
adb pull /sdcard/zzz.png ~/
```



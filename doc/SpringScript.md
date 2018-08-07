# **SpringScript 0.1 参考手册**
##### by ZYW
## **1 SpringScript简介**
SpringScript是一种轻量级、可嵌入、面向对象的高级程序设计语言，它支持面向过程编程、面向对象编程以及函数式编程等多种编程范式。SpringScript解释器的词法/语法分析器由Flex/Bison生成，运行时环境与标准库使用标准C++11编写，以源代码方式开放，遵循MIT许可证。  
SpringScript程序设计语言具有以下特性：
#### (1) 简单易用
SpringScript语法非常简洁，即使没有编程经验的人也能经过简单训练，很快写出可用的程序。SpringScript不使用指针，所有变量都是引用，并提供了自动垃圾回收机制，使得程序员不必为内存管理而困扰。SpringScript解释器小巧精炼，源码仅一万五千行左右，可以很方面地嵌入到其他程序中。
#### (2) 开发效率高
SpringScript是动态语言和动态数据类型语言，所以其开发效率高。SpringScript支持在运行时改变代码结构，如修改函数、增删对象的成员变量与成员函数等。同时，SpringScript也是动态数据类型语言，在运行时检查变量类型；变量与其类型并未绑定，变量的类型可在运行时任意修改。  
一门程序设计语言的效率可分为开发效率和运行效率两方面，而两者往往是矛盾的，难以兼顾。SpringScript更加重视易学易用性和开发高效性，所以不可避免地牺牲了一部分程序运行效率。SpringScript的开发者认为，随着计算机硬件设备速度的逐年指数级增长，程序运行效率将不再关键。此外，SpringScript还支持与C/C++代码深度交互（请参阅后文相关章节），用户可将项目中耗时的SpringScript代码用C/C++代码替换，从而提高程序运行效率。
#### (3) 面向对象
SpringScript是面向对象的脚本语言，但其语法中并没有类的概念，也不使用类来创建对象。SpringScript是基于原型（prototype）的，而不是基于类的面向对象语言，具有封装、继承和多态三大面向对象的基本特征，也支持运算符重载等复杂概念。为了简单起见，SpringScript只支持单继承。
#### (4) 与C/C++深度交互
SpringScript解释器有两种使用方式。首先，SpringScript解释器可作为一个独立的程序，解释执行SpringScript源代码文件。其次，SpringScript解释器还可作为一个C++库，嵌入到其他C++程序中（这个C++程序称为宿主程序）。宿主程序可通过SpringScript解释器调用SpringScript代码和读写SpringScript变量的值；宿主程序还可以将自身的C/C++函数注册至SpringScript解释器，以便在SpringScript程序中调用。  
![image](https://github.com/AlanZhangNpu/SpringScript/blob/master/screenshots/interaction.jpg)
## **2 SpringScript IDE (SpringStudio)简介**

## **2 SpringScript基础语法**
SpringScript的语法与C++、Java有许多相似之处，但也有很多差异。
### **2.1 第一个SpringScript程序**
新建一个名为 hello.spr 的文本文件（所有SpringScript程序源码文件以.spr作为扩展名），在其中输入：
``` java
print("Hello, SpringScript!")

```
其中，print是一个解释器内置的标准输出函数。运行hello.spr文件，控制台会输出：
``` java
Hello, SpringScript!
```
### **2.2 注释**
SpringScript中单行注释以//开头；  
多行注释使用三单引号或三双引号；  
任何ASCII字符集之外的字符（如汉字）将被直接识别为注释。
``` Java
print("Hello, world!") // 这里是一个单行注释

'''
这里是多行注释，使用三单引号
这里是多行注释，使用三单引号
这里是多行注释，使用三单引号
'''

"""
这里是多行注释，使用三双引号
这里是多行注释，使用三双引号
这里是多行注释，使用三双引号
"""

这里的汉字也会被识别为注释，但这种注释方式不推荐使用。

print("Hello, SpringScript!") 这里的汉字也会被识别为注释，但这种注释方式不推荐使用。

```
运行上面的代码，控制台会输出：
``` java
Hello, World!
Hello, SpringScript!
```
### **2.3 标识符**
SpringScript标识符用来标识变量、常量、函数、对象等的名称，由英文字母、数字和下划线（_）组成，但不能以数字开头；  
SpringScript标识符是对英文字母的大小写敏感的；  
以大写英文字母开头的标识符被自动识别为常量，常量必须在声明时初始化，且初始化后常量的值不可改变。  
非以大写英文字母开头的标识符被识别为变量，变量的数据类型及其值可任意改变。
下面的示例代码中，标识符r被识别为变量，PI被识别为常量，PI的值被修改时，解释器将抛出错误。
``` java
var r = 1, PI = 3.14
r = 10
PI = 3.2 // 运行到此处时，解释器将抛出错误：[Line3, Runtime error] A constant cannot be changed after initialization.

```
### **2.4 保留字**
下表列出了SpringScript的保留字，这些保留字不能用作变量或常量的标识符。
||||||
|:--|:--|:--|:--|:--|
|import|if|else|while|loop|
|for|in|switch|case|break|
|continue|return|exit|nil|true|
|false|func|class|new|
### **2.5 语句和语句块**
#### **2.5.1 语句中的分号可省略**
SpringScript语句必须用分号或回车符结尾。
与C/C++或Java不同，SpringScript语句末尾的分号不是必需的，但省略分号后，语句必须以回车符结尾。
``` Java
a = 1
b = 2
c = a + b

```
``` Java
a = 1;
b = 2;
c = a + b;
```
以上两种语句结尾方式是等价的。（注意：在第一种省略分号的结尾方式中，第三行的末尾要输入至少一个回车符。）

#### **2.5.2 在一行中编写多条语句**
使用分号可在一行中编写多条语句
``` Java
a = 1; b = 2; c = a + b;
```
#### **2.5.3 跨行语句**
当一条语句过长时，可选择使用连接符 \ 将一条长语句分多行编写。
``` Java
sum = item_one + \
item_two + \
item_three

```

## **SpringScript变量**
### 变量声明
### 变量赋值
``` Java
a : 1 // 声明一个变量a，并将其值初始化为1
PI : 3.14 // 声明一个常量PI，并将其值初始化为3.14
a = 2 // 正确，a的值将会变为2
PI = 3.14 // 错误，解释器将抛出：[Line4, Runtime error] A constant cannot be changed after initialization.
```
### 多变量赋值
### 数据类型
#### 基本数据类型
bool
int
double
string
function
#### 引用类型
list
dictionary
object

### 数据类型转换
#### 隐式类型转换
bool <-> int <-> double
#### 显式类型转换
类型转换函数

## **SpringScript运算符**

## **SpringScript语句**
## **import语句**
### SpringScript语句 - if
### SpringScript语句 - while
### SpringScript语句 - loop
### SpringScript语句 - for
### SpringScript语句 - continue
### SpringScript语句 - break
### SpringScript语句 - return
### SpringScript语句 - exit

## **SpringScript数字**
## **SpringScript字符串**
## **SpringScript列表**
循环下标
列表作为下标
## **SpringScript函数**
## **SpringScript面向对象**
### 定义一个对象
### new运算符
### 运算符重载
### 继承与函数重写

## **SpringScript标准库**
## **SpringScript本地接口（SNI）**
## **SpringScript扩展开发**
## **嵌入式SpringScript解释器**

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
SpringScript解释器有两种使用方式。首先，SpringScript解释器可作为一个独立的程序，解释执行SpringScript源代码文件。其次，SpringScript解释器还可作为一个C++库，嵌入到其他C++程序中（这个C++程序称为宿主程序）。宿主程序可通过SpringScript解释器调用SpringScript代码和读写SpringScript变量的值；宿主程序还可以将自身的C/C++函数注册至SpringScript解释器，以便在SpringScript程序中调用。SpringScript解释器作为一个C++库，是可重入的，即解释器程序没有任何全局变量或静态变量，所以一个宿主程序甚至可以持有多个SpringScript解释器实例。
    ![image](https://github.com/AlanZhangNpu/SpringScript/blob/master/screenshots/interaction.jpg)  
SpringScript可应用于以下场景：
#### (1) 作为程序设计入门语言
SpringScript是一种轻量级、语法简洁但完整的脚本语言，学习门槛低，适合程序设计的初学者作为入门语言学习。
#### (2) 快速开发软件原型与算法验证程序
对于熟练的开发者，SpringScript的动态数据类型、开发高效性、多种编程范式以及与C/C++的深度交互能力，可帮助开发者快速开发软件原型或算法验证程序。
#### (3) 用做软件配置解析器
用SpringScript编写配置数据文件，利用SpringScript解释器进行解析，使用户免于手动开发配置解析程序。
#### (4) 开发支持脚本驱动的软件
将SpringScript解释器嵌入到第三方软件中，并将软件内的部分函数暴露给SpringScript解释器，让自己软件的用户可使用SpringScript对自己的软件进行二次开发。
#### (5) 开发支持热更新的软件
将软件项目中需求变动大的模块用SpringScript编写，软件更新时，只需替换SpringScript文件，避免重新编译，甚至在软件不重启的情况下更新软件。
## **2 SpringScript IDE (SpringStudio)简介**
TODO
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
SpringScript语句必须用分号或回车符结尾。与C/C++或Java不同，SpringScript语句末尾的分号不是必需的，但如果省略分号，语句必须以回车符结尾。
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
## **3 SpringScript数据类型和变量**
### **3.1 SpringScript数据类型**
SpringScript的基本数据类型有8种，如下表所示。SpringScript中的所有值都是第一类值（包括function类型的值），即所有值都可以存储在变量中、作为参数传递给函数或作为函数返回值。
|数据类型|描述|
|:--|:--|
|nil|表示空值或无效值类型，仅包含一个值：nil|
|boolean|表示布尔类型，包含两个值：true与false|
|int|表示整数类型|
|double|表示双精度实浮点数|
|string|字符串类型，由双引号表示|
|function|由SpringScript或C/C++编写的函数|
|list|链表类型，链表内的元素可以是任意数据类型|
|object|SpringScript对象类型|
解释器内置的type函数可用来测试一个变量或值的数据类型。
``` Java
print(type(nil))
print(type(false))
print(type(1))
print(type(2.7))
print(type("hello"))
print(type(type))
print(type([0, 1.1, "spring"]))
print(type({
    a : 0
    b : false
}))

```
运行以上的程序，控制台将输出：
``` Java
nil
boolean
int
double
string
function
list
object
```
#### **数据类型转换**
##### 隐式类型转换
bool <-> int <-> double
##### 显式类型转换
类型转换函数


### **3.2 SpringScript变量**
#### **变量定义与初始化**
SpringScript可用两种方式定义和初始化变量。  
第一种方式使用var关键字定义变量。var关键字可一次定义多个变量，不同的变量用逗号分割。可在变量标识符后添加等号来对变量进行初始化，初始化是可选的，定义而未初始化的变量的初值均为nil。

``` Java
var a // 此时，a的值为nil
var b, c = true, d = "hello" // b的值为nil，c被初始化为布尔值true，d被初始化为字符串“hello”

```
另外，SpingScript还可以使用冒号，便捷地定义变量并初始化。下面的代码将定义了r和PI两个标识符，并将其分别初始化为1和3.14。注意，PI是一个常量。
``` Java
r : 1
PI : 3.14

```
#### **变量赋值**
赋值是改变变量的值的最基本方法，使用等号给变量赋予新值。前面提到，SpringScript是动态数据类型语言，变量本身是没有类型的，变量的类型取决于其值的类型。
``` Java
a : 1 // a被初始化为1，此时其数据类型为int
a = false // a的数据类型变为boolean
a = "spring" // a的数据类型变为string 
a = func(x) -> x**2 // a的数据类型变为function。
'''
注意，上面的第四行代码展示了一种使用箭头（->）定义SpringScript函数的语法。
这里读者看不懂也无所谓，本文后续的章节将会详细介绍如何定义一个SpringScript函数。
'''
```
#### **多变量赋值**
SpringScript作为一门现代程序设计语言，支持多变量赋值。使用逗号间隔变量列表和值列表中的各元素，赋值语句会将等号右边表达式的值依次赋值给等号左边的变量。
``` Java
var a, b, c
a, b, c = 0.1, true, "spring"
print(a, b, c)

```
执行上面的代码，控制台将输出：
``` Java
0.1, true, "spring"
```
注意，使用多变量赋值语句时，需保证等号两侧的变量列表和值列表长度一致，否则解释器将抛出左值与右值个数不匹配的错误。例如，执行下面的代码，解释器将抛出：[Line2, Runtime error] The number of variables does not match: there are 3 left value(s) and 2 right value(s).
``` Java
var a, b, c
a, b, c = 0.1, true

```
多变量赋值经常用来交换变量的值，或接受函数的多个返回值。
``` Java
var a = true, b = false
a, b = b, a // 此时， a = false, b = true
a, b = f() // 假设f是一个函数，且f具有两个返回值，此时，f的两个返回值将分别赋值于a和b

```
#### **变量作用域**
同一个作用域内，同一个标识符不能重复定义，否则解释器将抛出变量重定义的错误。


## **SpringScript运算符**
### **算术运算符**
### **位运算符**
### **逻辑运算符**
### **比较运算符**
### **长度运算符**
### **new运算符**
### **运算符优先级**
### **隐式类型转换**

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
### **函数定义**
三种定义方式
（直接定义，lambda表达式定义，箭头函数）
匿名函数
函数默认参数
### **函数返回值**


## **SpringScript面向对象**
### 定义一个对象
### new运算符
### 运算符重载
### 继承与函数重写

## **SpringScript标准库**
## **SpringScript本地接口（SNI）**
## **SpringScript扩展开发**
## **嵌入式SpringScript解释器**

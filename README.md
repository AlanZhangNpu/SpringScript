 # The SpringScript and the SpringStudio IDE
## SpringScript

SpringScript is an object-oriented (based on the prototype chain, similar to JavaScript), dynamically typed, and interpreted language. Its syntax is simpler than almost all existing object-oriented languages (statically or dynamically typed languages). 
The following code demonstrates how to define a class named "Foo" (which is, in fact, an object) and its constructor and operator overloading functions.
The syntax documentation is being written.

SpringScript是一个面向对象的（基于原型链，与JavaScript类似）、动态类型、解释型语言。它的语法几乎比目前已有的任何面向对象语言（无论动态类型还是静态类型）都要简单。
下面的代码演示了如何定义一个名为“Foo”的类（实际上它也是一个对象），以及它的构造函数和运算符重载函数。
语法说明文档正在写作中。

``` java
// 一个SpringScript对象
foo : {
	// 属性
	bar0 : 1
	bar1 : true

	// 子类对象
	bar2 : {
		baz : "hello"
	}

	// 带默认参数的构造函数
	(arg0, arg1 = false, arg2 = "string"){
		this.bar0 = arg0
		this.bar1 = arg1
		this.bar2.baz = arg2
		return this
	}
	
	// 运算符重载
	+ other{
		this.bar0 += other.bar0
		return this
	}
	
	// 成员方法
	func print(){
		print(this.bar0, this.bar1, this.bar2)
	}
}
f0 : new foo(1, false, "abc")
f1 : new foo(2)
f0 += f1
f0.print()
f1.print()

```

SpringScript同时支持中/英文关键字，对照表如下。
![image](https://github.com/AlanZhangNpu/SpringScript/blob/master/screenshots/spring_studio0.png)

## SpringStudio
The SpringStudio is an Integrated Development Environment (IDE) of the SpringScript. Below are two screenshot of the SpringStudio. More documentation on SpringStudio is being written.

SpringStudio是SpringScript的一个集成开发环境（IDE）。下面是其两张屏幕截图。更多的说明文档正在写作中。

![image](https://github.com/AlanZhangNpu/SpringScript/blob/master/screenshots/spring_studio0.png)

![image](https://github.com/AlanZhangNpu/SpringScript/blob/master/screenshots/spring_studio1.png)

## yeild

先把`yield`看做`return`，这个是直观的，它首先是个`return`，普通的`return`是什么意思，就是在程序中返回某个值，返回之后程序就不再往下运行了。看做`return`之后再把它看做一个是生成器（generator）的一部分（带`yield`的函数才是真正的迭代器）

```python
def foo():
    print("starting...")
    while True:
        res = yield 4
        print("res:",res)
g = foo()
print(next(g))
print("*"*20)
print(next(g))
```

代码的输出这个：

```python
starting...
4
********************
res: None
4
```

代码单步调试：

1. 程序开始执行以后，因为`foo`函数中有`yield`关键字，所以`foo`函数并不会真的执行，而是先得到一个生成器`g`(相当于一个对象)

2. 直到调用`next`方法，`foo`函数正式开始执行，先执行`foo`函数中的`print`方法，然后进入`while`循环

3. 程序遇到`yield`关键字，然后把`yield`想象成`return`,`return`了一个`4`之后，程序停止，并没有执行赋值给`res`操作，此时`next(g)`语句执行完成，所以输出的前两行（第一个是`while`上面的`print`的结果,第二个是`return`出的结果）是执行`print(next(g))`的结果，

4. 程序执行`print("*"*20)`，输出20个`*`

5. 又开始执行下面的`print(next(g))`,这个时候和上面那个差不多，不过不同的是，这个时候是从刚才那个`next`程序停止的地方开始执行的，也就是要执行`res`的赋值操作，这时候要注意，这个时候赋值操作的右边是没有值的（因为刚才那个是`return`出去了，并没有给赋值操作的左边传参数），所以这个时候`res`赋值是`None`,所以接着下面的输出就是`res:None`,

6. 程序会继续在`while`里执行，又一次碰到`yield`,这个时候同样`return`出4，然后程序停止，`print`函数输出的`4`就是这次`return`出的4.

**到这里你可能就明白`yield`和`return`的关系和区别了，带`yield`的函数是一个生成器，而不是一个函数了，这个生成器有一个函数就是`next`函数，`next`就相当于“下一步”生成哪个数，这一次的`next`开始的地方是接着上一次的`next`停止的地方执行的，所以调用`next`的时候，生成器并不会从`foo`函数的开始执行，只是接着上一步停止的地方开始，然后遇到`yield`后，`return`出要生成的数，此步就结束。**

```python
def foo():
    print("starting...")
    while True:
        res = yield 4
        print("res:",res)
g = foo()
print(next(g))
print("*"*20)
print(g.send(7))
```

再看一个这个生成器的send函数的例子，这个例子就把上面那个例子的最后一行换掉了，输出结果：

```python
starting...
4
********************
res: 7
4
```

先大致说一下`send`函数的概念：此时你应该注意到上面那个`res`的值为什么是`None`，这个变成了`7`，到底为什么，这是因为，`send`是发送一个参数给`res`的，因为上面讲到，`return`的时候，并没有把4赋值给`res`，下次执行的时候只好继续执行赋值操作，只好赋值为`None`了，而如果用`send`的话，开始执行的时候，先接着上一次（`return 4`之后）执行，先把7赋值给了`res`,然后执行`next`的作用，遇见下一回的`yield`，`return`出结果后结束。

5.程序执行`g.send(7)`，程序会从`yield`关键字那一行继续向下运行，`send`会把7这个值赋值给`res`变量

6.由于`send`方法中包含`next()`方法，所以程序会继续向下运行执行`print`方法，然后再次进入`while`循环

7.程序执行再次遇到`yield`关键字，`yield`会返回后面的值后，程序再次暂停，直到再次调用`next`方法或`send`方法。

这就结束了，说一下，为什么用这个生成器，是因为如果用`List`的话，会占用更大的空间，比如说取`0,1,2,3,4,5,6............1000`

你可能会这样：

```python
for n in range(1000):
    a = n
```

这个时候`range(1000)`就默认生成一个含有1000个数的`list`了，所以很占内存。

这个时候你可以用刚才的`yield`组合成生成器进行实现，也可以用`xrange(1000)`这个生成器实现

yield组合：

```python
def foo(num):
    print("starting...")
    while num<10:
        num=num+1
        yield num

for n in foo(0):
    print(n)
```

输出：

```python
starting...
1
2
3
4
5
6
7
8
9
10
```

xrange(1000):

```python
for n in xrange(1000):
    a = n
```

其中要注意的是python3时已经没有`xrange()`了，在python3中，`range()`就是`xrange()`了，你可以在python3中查看`range()`的类型，它已经是个`<class 'range'>`了，而不是一个`list`了，毕竟这个是需要优化的。 

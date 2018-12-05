### Effective Go

1.  the built-in functions `new` 

   1. it does not *initialize* the memory, it only *zeros* it.

   2. `new(T)`allocates zeroed storage for a new item of type `T` and returns its address.

   3. Constructors and composite literals

      ```go
      func NewFile(fd int, name string) *File {
          if fd < 0 {
              return nil
          }
          f := File{fd, name, nil, 0}
          return &f
      }
      ```

      the storage associated with the variable survives after the function returns.

      ```go
      return &File{fd, name, nil, 0}
      return &File{fd: fd, name: name}
      ```

2. the built-in functions `make`

   1. The built-in function `make(T, `*args*`)` serves a purpose different from `new(T)`. It creates slices, maps, and channels only, and it returns an *initialized* (not *zeroed*) value of type `T` (not `*T`).
   2. The reason for the distinction is that these three types represent, under the covers, references to data structures that must be initialized before use.

   ```go
   var p *[]int = new([]int)       // allocates slice structure; *p == nil; rarely useful
   var v  []int = make([]int, 100) // the slice v now refers to a new array of 100 ints
   
   // Unnecessarily complex:
   var p *[]int = new([]int)
   *p = make([]int, 100, 100)
   
   // Idiomatic:
   v := make([]int, 100)
   ```

   Remember that `make` applies only to maps, slices and channels and does not return a pointer. To obtain an explicit pointer allocate with `new` or take the address of a variable explicitly.

#### Arrays

* 是什么？

  1. 是对分配的一块slice数据结构的描述
  2. 和C中Array(数组)的不同之处
     1. Go中的Array是所有值(占据内存)描述，做Array的赋值时，会copy所有的元素。而C中，数组名是一个指针，指向该数组的起始位置。
     2. 如果把Array传递给一个函数时，Go Array将会形成一个本地变量，对每一个元素进行copy
     3. size是Array的一部分

* 为什么有Array?

  1. 用来分配内存为Slice结构
  2. Arrays are useful when planning the detailed layout of memory and sometimes can help avoid allocation **还没在具体的场景中体会**；

* 怎么用？

  注意在传递Array将指针进行传递

  ```go
  func Sum(a *[3]float64) (sum float64){
      for _, v := range *a {
          sum += v
      }
      return
  }
  
  array := [...]float64{7.0, 8.5, 9.1}
  x := Sum(&array) // Note the explicit address-of operator
  ```

  这不是完美的Go，应该使用slice做替代。

#### Slices

* 是什么？

  1. slice是用来包裹数组内存Array，为序列化数据提供更加方便，功能更加强大，更加通用的接口。除了提供显性化维度的序列，大多数Go中的编码是使用slice的。

  2. Slice 为底层的数组提供了一个reference，可以理解为一个指向该数组的指针，功能更加强大。在函数中改变slice指向的数据，调用函数的空间也可以感受到。
  3. the **length** within the slice sets an upper limit of how much data to read，讲述Slice的功能
  4. The ***capacity*** of a slice, the limits of the underlying array. **Array**的capacity，指底层的数据空间的大小。

* 为什么？

  1. 对比C++的指针，包含更多数组的信息，这样传递的参数时更少，更方便
  2. 对比C++容器中的Vector, 容器更多的Value, 我们在传递时，传实体的话，需要更多的深复制，更多的使用情况还是引用。

  **思考： 有需要不改变原引用的情况吗？如果有，该怎么处理？**

* 怎么用？

  Slice 本身就是一个struct 记录了数据的起始位置指针、len和cap，传递函数的时候就会将slice自身进行复制，append中会改变slice的属性，返回值需要对其进行更新。

  ```go
  func Append(slice, data []byte) []byte {
      l := len(slice)
      if l + len(data) > cap(slice) {
          newSlice := make([]byte, (l+len(data))*2)
          copy(newSlice, slice)
          slice = newSlice
      }
      
      slice = slice[0:l+len(data)]
      copy(slice[l:], data)
      
      return slice
  }
  ```

  We must return the slice afterwards

#### Two-dimensional slices

* 是什么？

   an array-of-arrays or slice-of-slices

  ```go
  type Transform [3][3]float64  // A 3x3 array, really an array of arrays.
  type LinesOfText [][]byte     // A slice of byte slices.
  ```

  1. slices 内每一行的长度可以都不相同，因为slices是一个动态长度的类型

* 为什么？

  1.  it's necessary to allocate a 2D slice, a situation that can arise when processing scan lines of pixels, for instance. 有时候必须要用到这个2D的slice的结构，例如图形的像素。

* 怎么用？

  两种方式完成2Dslices的初始化

  First, a line at a time:

  ```go
  // Allocate the top-level slice.
  picture := make([][]uint8, YSize) // One row per unit of y.
  // Loop over the rows, allocating the slice for each row.
  for i := range picture {
  	picture[i] = make([]uint8, XSize)
  }
  ```

  And now as one allocation, sliced into lines:

  ```go
  // Allocate the top-level slice, the same as before.
  picture := make([][]uint8, YSize) // One row per unit of y.
  // Allocate one large slice to hold all the pixels.
  pixels := make([]uint8, XSize*YSize) // Has type []uint8 even though picture is [][]uint8.
  // Loop over the rows, slicing each row from the front of the remaining pixels slice.
  for i := range picture {
  	picture[i], pixels = pixels[:XSize], pixels[XSize:]
  }
  ```

  第一种，每次分配一排，并对slice进行赋值

  第二种，一次分配一大块内存，然后对每行进行分配

#### Maps

* 是什么？
  1. Maps are a convenient and powerful built-in data structure that associate values of one type (the *key*) with values of another type (the *element* or *value*).
  2. The key can be of any type for which the equality operator is defined;
  3. Like slices, maps hold references to an underlying data structure.  

* 为什么？

* 怎么用？

  1. constructer

     ```go
     var timeZone = map[string]int{
         "UTC":  0*60*60,
         "EST": -5*60*60,
         "CST": -6*60*60,
         "MST": -7*60*60,
         "PST": -8*60*60,
     }
     ```

  2. Assigning and fetching map values

     ```go
     offset := timeZone["EST"]
     ```

      not present in the map will return the zero.

  3.  “comma ok” idiom

     ```go
     func offset(tz string) int {
         if seconds, ok := timeZone[tz]; ok {
             return seconds
         }
         log.Println("unknown time zone:", tz)
         return 0
     }
     ```

  4. delete a map entry

     ```go
     delete(timeZone, "PDT")  // Now on Standard Time
     ```

#### Printing

* 是什么？

  1. The functions live in the `fmt` package and have capitalized names: `fmt.Printf`, `fmt.Fprintf`,`fmt.Sprintf` and so on. The string functions (`Sprintf` etc.) return a string rather than filling in a provided buffer.

  2. The formatted print functions `fmt.Fprint` and friends take as a first argument any object that implements the `io.Writer` interface; the variables `os.Stdout` and `os.Stderr` are familiar instances.

     ```go
     fmt.Printf("Hello %d\n", 23)
     fmt.Fprint(os.Stdout, "Hello ", 23, "\n")
     fmt.Println("Hello", 23)
     fmt.Println(fmt.Sprint("Hello ", 23))
     ```

  3. 格式的区别

     ```go
     var x uint64 = 1<<64 - 1
     fmt.Printf("%d %x; %d %x\n", x, x, int64(x), int64(x))
     
     // 18446744073709551615 ffffffffffffffff; -1 -1
     
     
     ```

     format `%v` (for “value”)

     ```go
     fmt.Printf("%v\n", timeZone)  // or just fmt.Println(timeZone)
     
     // map[CST:-21600 PST:-28800 EST:-18000 UTC:0 MST:-25200]
     ```

     When printing a struct, the modified format

      `%+v` **annotates the fields of the structure with their names**, and for any value the alternate format `%#v` prints the value in **full Go syntax.**

     ```go
     type T struct {
         a int
         b float64
         c string
     }
     t := &T{ 7, -2.35, "abc\tdef" }
     fmt.Printf("%v\n", t)
     fmt.Printf("%+v\n", t)
     fmt.Printf("%#v\n", t)
     fmt.Printf("%#v\n", timeZone)
     
     // &{7 -2.35 abc   def}
     // &{a:7 b:-2.35 c:abc     def}
     // &main.T{a:7, b:-2.35, c:"abc\tdef"}
     // map[string] int{"CST":-21600, "PST":-28800, "EST":-18000, "UTC":0, "MST":-25200}
     ```

     `%q` when applied to a value of type `string` or `[]byte`.

     `%x` works on strings, byte arrays and byte slices as well as on integers, generating **a long hexadecimal string,** and with a space in the format (`% x`) it puts spaces between the bytes.

      `%T`which prints the *type* of a value.

     ```go
     fmt.Printf("%T\n", timeZone)
     ```

* 怎么用？

  1. control the default format for a custom type, to define a method with the signature `String() string` on the type. 重载String 方法

     ```go
     func (t *T) String() string {
         return fmt.Sprintf("%d/%g/%q", t.a, t.b, t.c)
     }
     fmt.Printf("%v\n", t)
     ```

#### Append

* 是什么？

  1. the `append` built-in function

  2. ```go
     func append(slice []T, elements ...T) []T
     ```

     `append` is built in: it needs support from the compiler.

  2. What `append` does is append the elements to the end of the slice and return the result. **The result needs to be returned**.

* 怎么用？

  and append a slice to a slice? Easy: use `...` at the call site.

  ```go
  x := []int{1,2,3}
  y := []int{4,5,6}
  x = append(x, y...)
  fmt.Println(x)
  ```

### Initialization

#### Constants

* 是什么？

  1. constant. They are created at compile time, even when defined as locals in functions, and can **only be numbers, characters (runes), strings or booleans.**

     math.Sin(math.Pi/4) 不是constant，因为需要在runtime 去调用math.sin。

* 怎么用？

  1. Go中没有enum关键词，但是提供了iota关键词，并且在枚举的表达式中可以使用iota作为度量单位

     ```go
     type ByteSize float64
     
     const (
         _           = iota // ignore first value by assigning to blank identifier
         KB ByteSize = 1 << (10 * iota) // 1024B
         MB	// 1024 KB
         GB
         TB
         PB
         EB
         ZB
         YB
     )
     ```

#### Variables

* 变量的初始化类似于常量，但是可以使用在run time计算的调用

  ```go
  var (
      home   = os.Getenv("HOME")
      user   = os.Getenv("USER")
      gopath = os.Getenv("GOPATH")
  )
  ```

#### The init function

* 什么对象拥有？

  each source file can define its own niladic `init` function to set up whatever state is required.

* 什么时候调用？

  `init` is called after all the variable declarations in the package have evaluated their initializers, and those are evaluated only after all the imported packages have been initialized.

  在所有的变量都被声明并且所有的导入的包被初始化。

### Methods

#### Pointer Vs Method

The rule about pointers vs. values for receivers is that value methods can be invoked on pointers and values, but pointer methods can only be invoked on pointers.

1. This rule arises because pointer methods can modify the receiver
2. Invoking them on a value would cause the method to receive a copy of the value, so any modifications would be discarded.

### Interfaces and other types

#### Interfaces

* 是什么？
  1. Interfaces in Go provide a way to specify the behavior of an object。
  2.  Interfaces with only one or two methods are common

* 为什么？

  有某些方法的集合很多对象都可以实现，我们把这些方法的集合就可以统一称为一个接口，每个可以完成接口类规定了方法的类，都可以直接转化为接口类型，接口类型可被进行的调用，该对象都都可以进行。并且对应接口的方法被该对象对应的方法覆盖。

* 怎么用？

  典型的sort package 中的Sort接口

  ```go
  type Sequence []int
  
  // Methods required by sort.Interface.
  func (s Sequence) Len() int {
      return len(s)
  }
  func (s Sequence) Less(i, j int) bool {
      return s[i] < s[j]
  }
  func (s Sequence) Swap(i, j int) {
      s[i], s[j] = s[j], s[i]
  }
  
  // Method for printing - sorts the elements before printing.
  func (s Sequence) String() string {
      sort.Sort(s) // s 完成了sort接口的所有方法，可以调用接口定义的方法
      str := "["
      for i, elem := range s {
          if i > 0 {
              str += " "
          }
          str += fmt.Sprint(elem)
      }
      return str + "]"
  }
  ```

#### Conversions

#### Interface conversions and type assertions

1. Type Switch是一种形式的转换：

   ```go
   
   type Stringer interface {
       String() string
   }
   
   var value interface{} // Value provided by caller.
   switch str := value.(type) {
   case string:
       return str
   case Stringer:
       return str.String()
   }
   
   ```

   第一种是找到了具体的类型，第二种做了类型的转换。

2. Type assertion

   ```go
   str, ok := value.(string)
   if ok {
       fmt.Printf(&quot;string value is: %q\n&quot;, str)
   } else {
       fmt.Printf(&quot;value is not a string\n&quot;)
   }
   ```

   Interface类型的转换

#### Generality

#### Interfaces and methods

### The Blank Identifier

* 是什么？

  The blank identifier can be assigned or declared with any value of any type, with the value discarded harmlessly.

  空白符 可以被赋值为任意类型的任意值，只要这个值是无用的。

* 怎么用？

  1. 在多值赋值的时候

     ```go
     if _, err := os.Stat(path); os.IsNotExist(err) {
     	fmt.Printf("%s does not exist\n", path)
     }
     ```

  2. 没有用的imports and variable

     ```go
     package main
     
     import (
         "fmt"
         "io"
         "log"
         "os"
     )
     
     var _ = fmt.Printf // For debugging; delete when done.
     var _ io.Reader    // For debugging; delete when done.
     
     func main() {
         fd, err := os.Open("test.go")
         if err != nil {
             log.Fatal(err)
         }
         // TODO: use fd.
         _ = fd
     }
     ```

     对于暂时没被用到的变量，使用_可以停止编译的错误

  3. Import for side effect

     1. side effects 是什么？

        For example, during its `init` function, the `net/http/pprof` package registers HTTP handlers that provide debugging information. It has an exported API, but most clients need only the handler registration and access the data through a web page.

        side effect 副作用：这里就是导入包在init函数被调用时会运行 init func() 副作用在这里就有效了。

     ```go
     import _ "net/http/pprof"
     ```

  4. Interface checks

     ```go
     if _, ok := val.(json.Marshaler); ok {
         fmt.Printf("value %v of type %T implements json.Marshaler\n", val, val)
     }
     ```

     1. In practice, most interface conversions are static and therefore checked at compile time. 
     2. Some interface checks do happen at run-time. 

     ```go
     var _ json.Marshaler = (*RawMessage)(nil)
     ```

     a global declaration that property will be checked at compile time.

  ### Embedding(嵌套)

  Go没有典型的类型驱动的子类的概念，通过嵌套类的形式去向其他类型或者接口借用一些方法实现。

  ```go
  type Job struct {
      Command string
      *log.Logger
  }
  
  job.Log("starting now...")
  // 不直接给feild name 可以直接调用嵌套类的方法
  ```

  也可以重写嵌套类的方法

  ```go
  func (job *Job) Logf(format string, args ...interface{}) {
      job.Logger.Logf("%q: %s", job.Command, fmt.Sprintf(format, args...))
      // 在调用嵌套类的方法时，如果该类没有feild.name 则直接使用 type名
  }
  ```

### Concurrency

#### Share by communicating

* 是什么？

  1. Go encourages a different approach in which shared values are passed around on channels and, in fact, never actively shared by separate threads of execution.  通过channel去传递变量，不要使用共享能量。

  2. Do not communicate by sharing memory; instead, share memory by communicating.
  3. Unix pipelines, for example, fit this model perfectly. Although Go's approach to concurrency originates in Hoare's Communicating Sequential Processes (CSP), it can also be seen as a type-safe generalization of Unix pipes.

#### Goroutines

* 是什么？

  1. 简单的定义？

     A goroutine has a simple model: it is a function executing concurrently with other goroutines in the same address space. 

* 为什么？

  1. Goroutines are multiplexed onto multiple OS threads，their design hides many of the complexities of thread creation and management.

* 怎么用？

  1. Prefix a function or method call with the `go` keyword to run the call in a new goroutine. When the call completes, the goroutine exits, silently. 

  ```go
  go list.Sort() // run list.Sort concurrently; don't wait for it
  ```

  2. A function literal can be handy in a goroutine invocation.  goroutine 也可以调用回调函数

  ```go
  func Announce(message string, delay time.Duration) {
      go func() {
          time.Sleep(delay)
          fmt.Println(message)
      }()  // Note the parentheses - must call the function.
  }
  ```

#### Channels

* 是什么？
  1. channels are allocated with `make`, and the resulting value acts as a reference to an underlying data structure. 

  2. Receivers always block until there is data to receive. If the channel is unbuffered, the sender blocks until the receiver has received the value. If the channel has a buffer, the sender blocks only until the value has been copied to the buffer; if the buffer is full, this means waiting until some receiver has retrieved a value. Channel 

     阻塞的规则，分为有buffer和无buffer，有buffer又分为满了和未满的情况。

* 怎么用？

  1. 声明

  ```go
  c1 := make(chan int)
  c2 := make(chan int, 0) // unbuffered channel of integers
  c3 := make(chan *os.File, 100) // buffered channel of pointers to Files
  ```

  分为有buffer和buffer size 为 0 的情况，不输入buffer即为buffer为0的情况。

  Unbuffered channels combine communication—the exchange of a value—with synchronization—guaranteeing that two calculations (goroutines) are in a known state.

  2. idiom 1-等待某个协程的完成

  ```go
  c := make(chan int)
  
  go func(){
      list.Sort()
      c <- 1 // Send a signal; value does not matter
  }()
  doSomethingForAWhile()
  <- c // Wait for sort to finish; discard sent value
  ```

  3. idiom 2 —像信号量一样的使用，例如去限制throughput。

  ```go
  var sem = make(chan int, MaxOutstanding)
  
  func handle(r *Request) {
      sem <- 1    // Wait for active queue to drain.
      process(r)  // May take a long time.
      <-sem       // Done; enable next request to run.
  }
  
  func Serve(queue chan *Request) {
      for {
          req := <-queue
          go handle(req)  // Don't wait for handle to finish.
      }
  }
  ```

  maxOutstanding 限制了并发去请求处理的量。这个设计有一个问，程序会不断的消耗无限的资源，当请求来的太快的时候。需要去限制协程的创建。

  ```go
  var sem = make(chan int, MaxOutstanding)
  
  func Serve(queue chan *Request) {
      for req := range queue {
          sem <- 1
          go func(req *Request) {
              process(req)
              <-sem
          }(req)
      }
  }
  ```

  通过channel限制同时运行的goroutine的数量，与之前的不同是channel阻塞位置的不同。

#### Channels of Channels

Client side:

```go
type Request struct {
    args        []int
    f           func([]int) int
    resultChan  chan int
}

func sum(a []int)(s int){
    for _, v := range a {
        s += v
    }
    return 
}

request := &Request{[]int{3, 4, 5}, sum, make(chan int)}
// Send request
clientRequest <- request

// Wait for response
fmt.Printf("answer: %d\n", <-request.resultChan)
```

Server side:

```go
func handle(queue chan *Request) {
    for req := range queue {
        req.resultChan <- req.f(req.args)
    }
}
```

#### Parallelization

1. 对一些可以并行化计算的算法进行并行化，当各个协程完成计算之后，使用channel做通知。

```go
type Vector []float64

func (v Vector) DoSome(i,n int, u Vector, c chan int){
    for ; i < n; i++ {
        v[i] += u.Op(v[i])
    }
    c <- 1
}
```

```go
const numCPU = 4

func (v Vector) DoAll(u Vector) {
    c := make(chan int, numCPU)
    for i := 0; i < numCPU; i++ {
        go v.DoSome(i*len(v)/numCPU, (i+1)*len(v)/numCPU, u, c)
    }
    
    for i := 0; i < numCPU; i++ {
        <- c // 等待所有的协程运行完
    }
    // all done
}
```

`runtime.NumCPU()`记录的是hardware核心的数量

`runtime.GOMAXPROCS`记录的是用户定义的核的数量，这个数量决定了go program 可以同时running的协程的数量。默认情况下是等于NumCPU()的。

不要受扰于完美的并行化思想，Go虽然是一个并行化的语言，但是不是所有的并行化问题都适合用Go来解决。

#### A leaky buffer

一个 free buffer list 使用channel的例子：

```go
var freeList = make(chan *Buffer, 100)
var serverChan = make(chan *Buffer)

func client() {
    for {
        var b *Buffer
        
        select {
            case b = <- freeList:
            	// Got one; nothing to do.
            default:
            	// None free, so allocate a new one.
            	b = new(Buffer)
        }
        load(b)  // Read next message from the net.
        serverChan <- b // Send to server.
    }
}
```

Server side:

```go
func server() {
    for {
        b := <-serverChan // wait for work
        process(b)
        select {
            case freeList <- b:
            	// Buffer on free list; nothing more to do.
            default:
            	// Free list full, just carry on.
        }
    }
}
```



### Errors

* 是什么？

  Library routines must often return some sort of error indication to the caller.

  1. error的interface

     ```go
     type error interface {
         Error() string
     }
     ```

#### Panic

The error is unrecoverable. 

* 是什么？
  1. there is a built-in function `panic` that in effect creates a run-time error that will stop the program (but see the next section). 内建的panic函数会产生一个run-time的error，这个error会将这个program停止。
  2. 这个函数只接受**一个**、**任意类型**的参数，（通是一个字符串）

#### Recover

* 是什么？

  1. `recover` to regain control of the goroutine and resume normal execution.

  2. Recover 会停止unwinding的过程，返回参数给panic。因为在unwinding过程中唯一可以唯一可以运行的代码段只能在deferred function中，所以recover函数只能在deferred functions 中使用。

* 怎么用？

  1. 一个使用案例：停止一个异常失败的goroutine而不killing其他的goroutine.

  ```go
  func server(workChan <- chan *Work) {
      for work := range workChan {
          go safelyDo(work)
      }
  }
  
  func safelyDo(work *Work) {
      defer func() {
          if err := recover(); err != nil {
              log.Println("work failed:", err)
          }
      }()
      do(work)
  }
  ```

  2. recovery pattern模式，简化panic处理

  ```go
  type Error string
  func (e Error) Error() string {
      return string(e)
  }
  
  
  func (regexp *Regexp) error (err string){
      panic(Error(err))
  }
  
  func Compile(str string) (regexp *Regexp, err error) {
      regexp = new(Regexp)
      
      defer func() {
          if e := recover(); e != nil {
              regexp = nil // Clear return value
              err = e.Error() // Will re-panic if not a parse error
          }
      }()
      
      return regexp.doParse(str), nil
  }
  
  ```







#### c++基础

1. ofstream open 方法打开文件的不同模式？

   从c++17开始打开文件的open方法的文件名开始接受c++风格字符串，也是就是string类型的文件名或者路径名，迷人是ios::out的模式，那么不同的模式打开文件会有什么不同，在什么样的场合这样的文件试用呢？

   - mode

     |  mode  |                       解释                       |                        场景                        |
     | :----: | :----------------------------------------------: | :------------------------------------------------: |
     |  app   |   seek to the end of stream before each write    |           适合每次写入都是追加内容的场景           |
     | binary |          二进制形式打开，保留之前的状态          |         适合对文件是否的细节要求很高的场景         |
     |   in   |                 open for reading                 |                      读取文件                      |
     |  out   |                 open for writing                 |                      写出文件                      |
     | trunc  | discard the contents of the stream when opening  | 丢弃文件之前的内容，适合需要清空文件之前内容的场景 |
     |  ate   | seek to the end of stream immediately after open |          打开文件后立刻找到文件的追加位置          |


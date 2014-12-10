full-permutation
================

algorithm to generate full permutation

源码在"code"目录下，可执行程序在"program"目录下(OS X 10.10系统下可执行，其他系统未经测试)，附有example，报告在"report"目录下

编译：
    进入code目录，make(程序只在OS X 10.10系统下编译过，其它系统不保证正确性...)
    
运行：
    编译后，生成permutation.out可执行文件，./permutation.out可执行程序
    permutation.out程序接受参数如下：
        参数1：permutation算法，参数为一个小写字母
            "o":我们提出的Com-permutation算法
            "p":stl的next_permutation算法
            "l":我们的字典序法
            "d":递减序法
            "i":递增序法
            "g":我们改进后的递减序法
            "e":邻位对换法
        参数2：元素集合的大小n，参数为一个正整数
        参数3到n+3：n个不同的整数
        特别的，当使用Com-permutation方法，即第一个参数为"o"时，最后还需要输入整数k的值。k的意义见报告

输出：
    程序的输出为元素集合的大小和生成全排列所消耗的时间，以毫秒位单位。为节约时间，程序不提供I/O输出

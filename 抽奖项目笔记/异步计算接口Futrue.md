# 异步计算接口Future


## 概述

&emsp;Future是一个表示异步计算结果的接口。提供一个检查计算是否完成的方法，以及等待计算完成并检索其结果的方法 在Java并发包中，Future提供一个取消计算 查询是否完成以及获取计算结果的框架，但是原生Future只提供阻塞操作来获取结果 这在一些场景不够灵活


## 主要方法


* cancel(boolean mayInterruptIfRunning),参数用于指示是否取消正在执行的任务，如果任务成功取消 返回true
* isCancelled() 如果任务在完成前被取消 返回true
* isDone() 如果任务完成了 无论是正常完成 异常还是取消 返回true
* get 等待计算完成 然后检索其结果
* get(long timeout,TimeUnit unit) 如果必要最多等待给定的时间来获取计算结果 然后检索结果


## 使用场景

* 执行长时间运行的计算任务，不希望阻塞主线程。
* 当你需要执行多个并行任务，并在它们全部完成后进行下一步操作。
* 管理一些需要长时间等待的异步操作，如网络请求、文件I/O等



## 实例代码

* ExecutorService 提交了一个Callable任务，该任务简单休眠2s,然后返回一个证书 通过Future.get方法 我们可以获取这个异步任务的结果，需要注意，get方法会阻塞调用线程直到任务完成，因此如果异步任务执行很长时间，可能会影响程序的响应性，可以通过(long timeout,TimeUnnit unit)方法设置最大等待时间来避免这种情况
* Future接口是Java并发包中处理异步计算的一个基本工具。通过使用Future和ExecutorService，可以简化异步任务的执行和管理，使得程序能够更加高效地利用系统资源，同时提高用户体验。


```java

import java.util.concurrent.*;

public class FutureExample {
    public static void main(String[] args) throws ExecutionException, InterruptedException {
        ExecutorService executor = Executors.newCachedThreadPool();
        Future<Integer> future = executor.submit(new Callable<Integer>() {
            @Override
            public Integer call() throws Exception {
                // 模拟长时间运算
                TimeUnit.SECONDS.sleep(2);
                return 123;
            }
        });

        // 做一些其他的事情
        System.out.println("执行其他任务...");

        // 获取异步计算的结果，如果未完成会阻塞等待
        Integer result = future.get();
        System.out.println("异步计算结果: " + result);
        
        executor.shutdown();
    }
}

```

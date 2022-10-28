# 由两个栈组成的队列

## 题目

用两个栈实现队列，支持队列的基本操作。

输入描述:
第一行输入一个整数N，表示对队列进行的操作总数。

下面N行每行输入一个字符串S，表示操作的种类。

如果S为"add"，则后面还有一个整数X表示向队列尾部加入整数X。

如果S为"poll"，则表示弹出队列头部操作。

如果S为"peek"，则表示询问当前队列中头部元素是多少。

## 思路

* 设置两个栈，一个输入栈，一个输出栈
* 输入栈元素送到输出栈中，然后在出栈，正好满足队列先进先出的顺序
* 同时需要注意两个原则：只有输出栈元素为空，输入栈元素才可以送入输出栈中，并且输出栈要送入元素进入输出栈，必须全部送入输出栈

## 代码

```java


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

class Queue {

    private Stack<Integer> stackpush;
    private Stack<Integer> stackpop;
    // 逻辑：stackpush 要想将元素送入stackpop中 必须全部送入stackpop中  不能值送入一部分 因为这样的话 出栈顺序就不一样
    // stackpop 必须为空 stackpush才可以送入数据  否则影响出栈顺序
    // 注意一下：队列为空指的是  stackpush 和 stackpop同时为空 不是仅仅只stackpop为空
    // 初始化代码
    public Queue()
    {
        // 初始化
        this.stackpop = new Stack<>();
        this.stackpush = new Stack<>();
    }

    // add操作  入队操作
    public  void add(int x){
        // 将x直接送入stackpush中即可
        this.stackpush.push(x);
    }

    // poll 出队操作
    public  int poll()
    {
        // 如果需要出队
        // 如果stackpop是空栈 直接报错
        if(this.stackpop.empty() && this.stackpush.empty())
        {
            throw new RuntimeException("Queue is empty");
        }
        else if(this.stackpop.empty())
        {
            // 将stackpush中的元素全部送入stackpop中
            while(!this.stackpush.empty())
            {
                this.stackpop.push(this.stackpush.pop());
            }
        }
        return this.stackpop.pop();// 出栈
    }

    // 取队头元素
    public int peek()
    {
        // 和出队代码逻辑一样
        // 首先明确队列为空的逻辑：stackpush 和stackpop 都是空
        if(this.stackpop.empty() && this.stackpush.empty())
        {
            // 如果两个都是空  直接抛出异常
            throw new RuntimeException("Your queue is empty");
        }
        else if(this.stackpop.empty())
        {
            // 如果stackpush中存在元素 直接全部入stackpop
            while(!this.stackpush.empty())
            {
                this.stackpop.push(this.stackpush.pop());
            }
        }
        return this.stackpop.peek();// 返回栈顶元素
    }
}

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        Queue queue = new Queue();

        for(int i = 0; i < n; i++)
        {
            String[] params = br.readLine().trim().split(" ");
            String op = params[0];

            if(op.equals("peek"))
            {
                System.out.println(queue.peek());
            }
            else if(op.equals("poll"))
            {
                queue.poll();
            }
            else{
                int val = Integer.parseInt(params[1]);
                queue.add(val);
            }
        }
    }
}

```

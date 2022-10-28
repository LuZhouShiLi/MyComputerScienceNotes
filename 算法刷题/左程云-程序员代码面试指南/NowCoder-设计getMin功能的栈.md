# 设计getMin功能的栈

## 题目


实现一个特殊功能的栈，在实现栈的基本功能的基础上，再实现返回栈中最小元素的操作。

输入描述:
第一行输入一个整数N，表示对栈进行的操作总数。

下面N行每行输入一个字符串S，表示操作的种类。

如果S为"push"，则后面还有一个整数X表示向栈里压入整数X。

如果S为"pop"，则表示弹出栈顶操作。

如果S为"getMin"，则表示询问当前栈中的最小元素是多少。


输出描述:
对于每个getMin操作，输出一行表示当前栈中的最小元素是多少。

## 思路

* 设计两个栈
* 一个栈用来保存当前栈中的元素，其功能和一个正常的栈没有区别，这个栈记为stackData,另一个栈用来保存每一步的最小值，这个栈记为stackMin
* 每一次入栈的元素都和stackMin的栈顶元素进行比较，如果小于等于栈顶元素，直接入栈，每一次stackData出栈元素和statckMin栈顶元素进行比较，如果相等，stackMin出栈顶元素


## 代码

```java
package NewCoder.Day1;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main{

    // 创建两个栈 一个用于正常的存储 一个用于保存每一步的最小值
    private Stack<Integer>  stackData;
    private Stack<Integer>  stackMin;// 这个栈只有一个最小值

    public Main()
    {
        // 构造方法
        this.stackMin = new Stack<>();
        this.stackData = new Stack<>();
    }

    // 入栈操作
    public void push(int newNum)
    {
        // 代码逻辑：newNum <= stackMin的栈顶元素  那么直接入栈stackMin
        // 同时如果stackMin本来就是空的栈  直接入栈
        if(this.stackMin.isEmpty())
        {
            this.stackMin.push(newNum);
        }
        else if(newNum <= this.stackMin.peek())
        {
            this.stackMin.push(newNum);
        }
        this.stackData.push(newNum);
    }

    // 出栈操作
    public int pop()
    {
        if(this.stackData.isEmpty())
        {
            // 栈空 直接抛出一个一场
            throw new RuntimeException("Your Stack is Empty");
        }
        int value = this.stackData.pop();

        // 同时更新statckMin
        if(value == this.stackMin.peek()) {
            this.stackMin.pop();// 直接pop最小值 更新最小值
        }
        return value;
    }

    // 获取最小值
    public void getMin()
    {

        if(this.stackMin.isEmpty())
        {
            throw  new RuntimeException("Your stack is empty");
        }

//      sout
        System.out.println(this.stackMin.peek());
    }

    public static void main(String[] args) throws IOException {
        Main m = new Main();

        // 读入进来的string转换成Integer
        BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));

        // 读入进来的string 要转换成Integer
        int rows = Integer.parseInt((scanner.readLine()));

        for(int i = 0; i < rows; i++)
        {
            // 字符串空格隔开后放进数组  一个数组存放一组操作
            String[] inputData = scanner.readLine().split(" ");
            if(inputData[0].equals("push")){
                m.push(Integer.parseInt(inputData[1]));
            }

            if(inputData[0].equals("pop")){
                m.pop();
            }

            if(inputData[0].equals("getMin")){
                m.getMin();
            }
        }

        scanner.close();
    }
}


```

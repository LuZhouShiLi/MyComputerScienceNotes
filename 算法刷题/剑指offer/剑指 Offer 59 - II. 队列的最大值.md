# 剑指 Offer 59 - II. 队列的最大值

## 题目

请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1

## 思路

* 定义一个双端队列deque,在每次入队，如果deque队尾元素小于即将入队的元素value,则将小于value的元素全部入队之后，再将value入队；否则直接入队。

## 代码

```cpp
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(deque.size() == 0)
        {
            return -1;
        }

        return deque.front();// 取出双端队列 队头元素 就是当前最大值
    }
    
    void push_back(int value) {
        queue.push(value);

        if(deque.size() == 0)
        {
            deque.push_back(value);
        }
        else if(value > deque.front())
        {
            // value 比 当前最大值都要大 直接清除队列所有值
            deque.clear();
            deque.push_back(value);
        }
        else
        {
            while(deque.back() < value)
            {
                deque.pop_back();// 将小于value的元素全部出队 
            }
            deque.push_back(value);
        }

    }
    
    int pop_front() {
        if(queue.size() == 0)
        {
            return -1;
        }
        int res = queue.front();// 取出普通队列的队头元素
        queue.pop();

        if(res == deque.front())
        {
            deque.pop_front();
        }

        return res;

    }

    std::queue<int> queue;
    std::deque<int> deque;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

```


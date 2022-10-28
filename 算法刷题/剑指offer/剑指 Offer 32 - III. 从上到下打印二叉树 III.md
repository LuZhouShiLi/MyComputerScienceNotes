# 剑指 Offer 32 - III. 从上到下打印二叉树 III

## 题目
&emsp;请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。


## 思路

* 首先将根节点入队
* BFS 循环：当队列queue为空时跳出循环
  * 大小：计算队列的大小也就是当前根节点有多少个孩子节点
  * 新建一个临时列表temp,用于存储当前层打印结果
  * 当前层打印循环：循环次数为当前层节点数（即队列queue长度）
    * 出队：队首元素出队，记作Node
    * 打印：将Node.val添加到tmp尾部
    * 添加子节点：若node的左（右）子节点不为空，将左右子节点加入队列queue中
  * 判断当前层数是奇数还是偶数，如果是奇数层，需要借助栈来将数据进行反向，再存入tmp中
* 将当前层结果tmp添加进入res中


## 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;// 根据函数返回值定义存储结果的变量

        // 定义一个队列用于存储节点的数据
        queue<TreeNode*> que;

        // 将根节点入队
        if(root != NULL) que.push(root);

        int count = 0;// 判断奇数还是偶数

        while(!que.empty())
        {
            // 计算队列的大小
            int size = que.size();

            // 定义临时的vector 
            vector<int> temp;
            stack<int> st;// 反向数据

            // 层次遍历
            for(int i = 0; i < size; i++)
            {
                // 获取第一个节点数据
                TreeNode* node = que.front();
                que.pop();// 删除

                temp.push_back(node->val);// 将节点值 存储临时vector
                if(node->left != NULL)  que.push(node->left);
                if(node->right != NULL) que.push(node->right);

            }

            if(count % 2 != 0)
            {
                // 奇数层需要反向
                for(int i = 0; i < temp.size(); i++)
                {
                    st.push(temp[i]);// 将临时vector中的数据全部入栈 
                }

                temp.clear();// 清空  然后将栈中的数据读取进入temp中
                while(!st.empty())
                {
                    temp.push_back(st.top());
                    st.pop();
                }
            }
            // 将一层的数据保存
            result.push_back(temp);
            count++;
        }
        return result;
    }
};

```


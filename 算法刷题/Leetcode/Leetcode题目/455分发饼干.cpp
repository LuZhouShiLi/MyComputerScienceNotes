class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int child = 0,cookie = 0;

        while(child < g.size() && cookie < s.size())
        {
            if(s[cookie] >= g[child])
            {
                // 最小饥饿的孩子分配最小能饱腹的饼干
                child++;//  满足 + 1
            }

            // 即使 我这个饼干不满足 这个孩子的胃口 他也就要吃掉  
            // 如果出现一次这样的情况 那么后面都是不满足情况
            cookie++;
        }

        return child;

    }
};
# Postman使用教程


## 创建集合

### 新建一个collection

![图 1](../images/a8becd6a682bee9df6f0e8126740e76f3fbb3ab9c545f106b2d7d3b812694693.png)  


### 新建一个请求 默认get

![图 2](../images/6515fd1c34a7ecf2857cf7ebcc014ce33b468936cf73573cc5111c4f140d57da.png)  

### 举例测试get请求

**后端controller代码，该功能是查询所有信息**

```java
//     查询所有员工信息
    @RequestMapping(value = "/employee",method = RequestMethod.GET)
    public String getAllEmployee(Model model){
//         调用dao中的方法  查询所有的员工信息
        Collection<Employee> all = employeeDao.getAll();

        // 要在浏览器中显示信息  需要将查询出来的结果  放到域对象中
        model.addAttribute("employeeList",all);

        // 将数据转发到 employee_list.html中
        return "employee_list";
    }

```



**然后使用postman进行测试,输入url,不要携带参数，然后点击send**

![图 5](../images/ecce6dfd12f6a02cebfdb70c7300f461aaac07a354ebc7c8067fd9800fcdb375.png)


**测试的结果，Body表示返回的ResponseBody**

![图 6](../images/17265e9b2c32afaf11067cb47bad501cebed423431545e0da3fede683e8390f0.png)  


**状态200表示请求成功**
![图 7](../images/a283ba6429befba2ae98f93b2b1341af08e2572db468b67ff1d975d8e984c720.png)  


### 测试Post请求

**后端controller代码，添加一个employee对象**


```java
     @RequestMapping(value = "/employee",method = RequestMethod.POST)
    public String addEmployee(Employee employee){
         //     添加功能 Post请求  提交form表单 将form表单元素填充到employee对象
         employeeDao.save(employee);// 调用dao对象存储
//          返回列表页面
         return "redirect:/employee";
     }
```

**注意参数再body里面填写参数，这里的参数是form表单参数，里面的所有元素最后会被填充到employee对象中**

![图 8](../images/98a200c35e22adccc0c9f1f2a8e22466a4f4005e8a855feae671290f835bfca5.png)  

**填写完参数之后**

![图 9](../images/c622bab761e48ed79a371108ea373fb17fe54f2fcbc9bd178957fe40b683f525.png)  

**可以看到添加了一个employee对象，最后一行**

![图 10](../images/64e8b6ee1b02ce495360ffb032db8a2100ccee6b1f34f135bf3885d0586c5d69.png)  


**同时上面的实例对象也可以使用Json格式进行传参**

![图 11](../images/eebded30b86d64488c2abe7f9a2563132a3eb650915c36aa1a480b6d7c0cf209.png)  




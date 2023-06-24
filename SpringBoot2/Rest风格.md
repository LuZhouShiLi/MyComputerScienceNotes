# Rest风格复习

## 简介

![图 1](../images/32d896d09af8d0d0cffbd6728abfc84950690290d342dd5c24648464bb0bcc73.png)  

**通过一段路径和访问方式来确定访问资源的行为方式**

![图 2](../images/12b0d7cdc63174012bc3f39bdf60f49db5568c9ee23780fc48cee7944d608089.png)  

![图 3](../images/8788b13c42cdb54109a3b5a0b47cc58e7efdbea6775b6a1bee4767da214639d7.png)  


**使用POST方式**

```java
    // value定义 路径  method定义访问的方式
    @RequestMapping(value = "/users",method = RequestMethod.POST)
    @ResponseBody
    public String save(){
        System.out.println("user save...");
        return "{'module':'user save'}";
    }
```

![图 4](../images/e254a695e729f0a248ef79a72c477f78a7733f623191c188d8fe9f2031da9f43.png)  

**使用DELETE方式**

```java
    @RequestMapping(value = "/users/{id}",method = RequestMethod.DELETE)
    @ResponseBody
    public String delete(@PathVariable Integer id){
        System.out.println("user delete ..." + id);
        return "{'module':'user delete'}";
    }

```

![图 5](../images/1ee918bbc5e946f64617b9fe963b00b5f41c8b7991dfc4848fa14b11a9c98773.png)  

![图 6](../images/51a65d4ae0cc85c8c71b733407633a2b22818c5a590082502aaabcf7857edbd9.png)  

## 三种注解的风格

* @RequestParam用于接受url地址传参或者表单传参
* @RequestBody用于接受json数据
* @PathVariable用于接受路径参数，使用{参数名称}描述路径参数
* 如果发送请求参数超过一个,以json格式为主 
* 如果发送非json个数数据 使用@RequestParam接受请求参数
* 采用RESTful进行开发，当参数数量比较少，使用@PathVariable接受请求路径变量，通常用来传递id值

## 快速开发

* RestController
* 类注解
* 作用：设置当前控制类为restful风格，等同于@Controller与@ResponseBody两个注解的功能


* GetMapping PostMapping PutMapping DeleteMapping
* 方法注解
* 基于springMVC的restful开发控制器方法
* 设置当前控制器方法请求访问路径与请求动作

![图 7](../images/831d7c01c331979fcc4faed021d52fe5e3c587f5ffdccf45c869d3b27c706d5c.png)  





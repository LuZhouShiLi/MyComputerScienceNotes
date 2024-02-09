# Spring基础 - Spring和Spring框架组成


## Spring 特性

* 非侵入式：基于Spring 开发的应用中的对象可以不依赖于Spring 的API
* 控制反转：IOC，对象的创建权交给Spring去创建
* 依赖注入：依赖的对象不需要手动调用set方法去设置，而是通过配置赋值
* 面向切面编程：AOP
* 容器：Spring是一个容器，包含并且管理应用对象的生命周期
* 组件化：Spring实现了使用简单的组件配置组合成一个复杂的应用，在Spring中可以使用XML和JAVA注解组合这些对象
* 一站式：在IOC和AOP的基础上可以整合各种企业应用的开源框架和优秀的第三方类库


## Spring有哪些组件

* Spring核心容器是其他模块建立的基础，由Beans模块，Core核心模块，Conext上下文模块和SpEL表达式语言模块组成
* Beans模块：提供了框架的基础部分，包括控制翻转和依赖注入
* Core核心模块：封装了Spring框架的底层部分，包括资源访、类型转换医院及一些常用的工具类
* Context上下文模块：建立在Core和Beans模块的基础上，集成Beans模块功能并且添加资源绑定、数据验证、国际化、Java EE 支持、容器生命周期、事件传播等。ApplicationContext 接口是上下文模块的焦点。
* SpEL 模块：提供了强大的表达式语言支持，支持访问和修改属性值，方法调用，支持访问及修改数组、容器和索引器，命名变量，支持算数和逻辑运算，支持从 Spring 容器获取 Bean，它也支持列表投影、选择和一般的列表聚合等。


## Data Access/Integration（数据访问／集成）

* JDBC 模块：提供了一个 JDBC 的样例模板，使用这些模板能消除传统冗长的 JDBC 编码还有必须的事务控制，而且能享受到 Spring 管理事务的好处。
* ORM 模块：提供与流行的“对象-关系”映射框架无缝集成的 API，包括 JPA、JDO、Hibernate 和 MyBatis 等。而且还可以使用 Spring 事务管理，无需额外控制事务。
* OXM 模块：提供了一个支持 Object /XML 映射的抽象层实现，如 JAXB、Castor、XMLBeans、JiBX 和 XStream。将 Java 对象映射成 XML 数据，或者将XML 数据映射成 Java 对象。
* JMS 模块：指 Java 消息服务，提供一套 “消息生产者、消息消费者”模板用于更加简单的使用 JMS，JMS 用于用于在两个应用程序之间，或分布式系统中发送消息，进行异步通信。
* Transactions 事务模块：支持编程和声明式事务管理。


## Web模块

* Web 模块：提供了基本的 Web 开发集成特性，例如多文件上传功能、使用的 Servlet 监听器的 IOC 容器初始化以及 Web 应用上下文。
* Servlet 模块：提供了一个 Spring MVC Web 框架实现。Spring MVC 框架提供了基于注解的请求资源注入、更简单的数据绑定、数据验证等及一套非常易用的 JSP 标签，完全无缝与 Spring 其他技术协作。
* WebSocket 模块：提供了简单的接口，用户只要实现响应的接口就可以快速的搭建 WebSocket Server，从而实现双向通讯。
* Webflux 模块： Spring WebFlux 是 Spring Framework 5.x中引入的新的响应式web框架。与Spring MVC不同，它不需要Servlet API，是完全异步且非阻塞的，并且通过Reactor项目实现了Reactive Streams规范。Spring WebFlux 用于创建基于事件循环执行模型的完全异步且非阻塞的应用程序。


## AOP、Aspects、Instrumentation和Messaging

* AOP 模块：提供了面向切面编程实现，提供比如日志记录、权限控制、性能统计等通用功能和业务逻辑分离的技术，并且能动态的把这些功能添加到需要的代码中，这样各司其职，降低业务逻辑和通用功能的耦合。
* Aspects 模块：提供与 AspectJ 的集成，是一个功能强大且成熟的面向切面编程（AOP）框架。
* Instrumentation 模块：提供了类工具的支持和类加载器的实现，可以在特定的应用服务器中使用。
* messaging 模块：Spring 4.0 以后新增了消息（Spring-messaging）模块，该模块提供了对消息传递体系结构和协议的支持。jcl 模块： Spring 5.x中新增了日志框架集成的模块。



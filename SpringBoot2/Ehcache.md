# 变更缓存供应商EHCACHE

## 变更缓存供应商EHCACHE

### 导入相关坐标依赖

```java
   <dependency>
            <groupId>net.sf.ehcache</groupId>
            <artifactId>ehcache</artifactId>
        </dependency>


```


### 导入相关配置

```
spring.cache.type=ehcache
```

### 导入ehcache xml配置


这里需要指定特定的缓存位置 testCache,timeToIdleSeconds 表示设置缓存的时间

```xml
     <?xml version="1.0" encoding="UTF-8"?>
    <ehcache xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
             xsi:noNamespaceSchemaLocation="http://ehcache.org/ehcache.xsd"
             updateCheck="false">
    
        <!--持久化磁盘路径-->
        <diskStore path="java.io.tmpdir"/>
    
    
    
        <!--默认缓存设置-->
        <defaultCache maxElementsInMemory="1000"
                       eternal="false"
                       timeToIdleSeconds="3600"
                       timeToLiveSeconds="0"
                       overflowToDisk="true"
                       maxElementsOnDisk="10000"
                       diskPersistent="false"
                       diskExpiryThreadIntervalSeconds="120"
                       memoryStoreEvictionPolicy="FIFO"
        />
        　
    
        <!--
            <cache     name 缓存名唯一标识
                       maxElementsInMemory="1000" 内存中最大缓存对象数
                       eternal="false" 是否永久缓存
                       timeToIdleSeconds="3600" 缓存清除时间 默认是0 即永不过期
                       timeToLiveSeconds="0" 缓存存活时间 默认是0 即永不过期
                       overflowToDisk="true" 缓存对象达到最大数后，将其写入硬盘
                       maxElementsOnDisk="10000"  磁盘最大缓存数
                       diskPersistent="false" 磁盘持久化
                       diskExpiryThreadIntervalSeconds="120" 磁盘缓存的清理线程运行间隔
                       memoryStoreEvictionPolicy="FIFO" 缓存清空策略
                       FIFO 先进先出
                       LFU  less frequently used  最少使用
                       LRU  least recently used 最近最少使用
        />
        -->
    
    
        <cache name="testCache"
               maxEntriesLocalHeap="2000"
               eternal="false"
               timeToIdleSeconds="3600"
               timeToLiveSeconds="0"
               overflowToDisk="false"
               statistics="true"
               memoryStoreEvictionPolicy="FIFO">
    
        </cache>
    
    
    </ehcache>


```


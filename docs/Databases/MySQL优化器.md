## MySQL优化器

1. 查看优化器状态

```sql
show variables like 'optimizer_trace'
```

2. 会话级别临时开启

```sql
set session optimizer_trace="enabled=on",end_markers_in_json=on;
```

3. 设置优化器追踪的内存大小

```sql
set OPTIMIZER_TRACE_MAX_MEM_SIZE=1000000
```

4. 执行SQL

```sql
select ...
```

5. information_schema.optimizer_trace表

```sql
SELECT trace FROM information_schema.OPTIMIZER_TRACE;
```

6. 导入到一个命名为xx.trace的文件

```sql
SELECT TRACE INTO DUMPFILE "E:\\test.trace" FROM INFORMATION_SCHEMA.OPTIMIZER_TRACE;
```

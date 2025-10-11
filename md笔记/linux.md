`cd /home/nginx/login/`

`systemctl restart nginx`重启nginx服务
`pm2 start server.js --name "login-service"`运行后端服务

 `vim /etc/nginx/conf.d/default.conf`编辑路由配置

`scp "C:\Users\10109\Desktop\html\自我介绍.zip" root@8.137.36.227:/home/nginx/`

### 1. 文件 / 目录命名（创建）

- 创建文件：`touch 文件名`

  示例：`touch document.txt`（创建空文件）

- 创建目录：`mkdir 目录名`

  示例：`mkdir documents`（创建单个目录）

  示例：`mkdir -p a/b/c`（创建嵌套目录，`-p`确保父目录存在）

### 2. 打开 / 查看文件

- 文本文件查看：

  - ```
    cat 文件名
    ```

    ：一次性显示全部内容

    

    示例：

    ```
    cat note.txt
    ```

  - ```
    less 文件名
    ```

    ：分页查看（按

    ```
    q
    ```

    退出，支持上下滚动）

    

    示例：

    ```
    less longfile.log
    ```

  - ```
    head 文件名
    ```

    ：查看前 10 行（

    ```
    -n
    ```

    指定行数）

    

    示例：

    ```
    head -n 5 data.csv
    ```

  - ```
    tail 文件名
    ```

    ：查看后 10 行（

    ```
    -f
    ```

    实时跟踪更新）

    

    示例：

    ```
    tail -f /var/log/syslog
    ```

- 编辑文件：

  - `nano 文件名`：简单文本编辑器（新手友好）
  - `vim 文件名`：功能强大的编辑器（按`i`进入编辑模式，`ESC`+`:wq`保存退出）

### 3. 删除文件 / 目录

- 删除文件：`rm 文件名`

  示例：`rm oldfile.txt`

- 删除目录：`rm -r 目录名`（`-r`递归删除目录及内容）

  示例：`rm -r empty_dir`

- 强制删除（不提示确认）：`rm -f 文件名` 或 `rm -rf 目录名`

  注意：`rm -rf` 非常危险，避免误删重要文件（尤其是`rm -rf /`会删除系统所有文件）

### 4. 展示目录下所有文件

- `ls`：列出当前目录文件（默认不显示隐藏文件）

- `ls -l`：详细列表形式（包含权限、大小、修改时间等）

- `ls -a`：显示所有文件（包括隐藏文件，以`.`开头的文件）

- `ls -lh`：人性化显示文件大小（如 KB、MB）

- ```
  ls /目标目录
  ```

  ：查看指定目录内容

  

  示例：

  ```
  ls /home/user/documents
  ```

组合使用：`ls -la`（显示所有文件的详细信息）

### 其他常用操作

- 移动 / 重命名：`mv 源 目标`

  示例：`mv file.txt newname.txt`（重命名）

  示例：`mv file.txt /home/docs/`（移动文件）

- 复制：`cp 源 目标`

  示例：`cp document.txt backup.txt`（复制文件）

  示例：`cp -r dir1 dir2`（复制目录，`-r`递归）

- 查看当前目录路径：`pwd`
github上 remote  

main branch 

本地git

disk磁盘存储 





**git clone  从github上复制到本地git**

建立feature branch(功能分支)：

**在git clone之后使用git checkout -b ()**

**使用git diff检查改完之后本地存储的代码与git的区别**

**git add ()把本地修改之后的文件放到暂存区** 

**之后使用git commit修改本地git**

**git push origin ()会把本地git上传github**

## 如果在这段时间内main branch有更新

**git checkout main会切换为main branch**

**git pull origin master同步有了新变化的remote**

**git checkout ()**

# 解决开vpn上传github443端口超时报错的方法

git config --global http.proxy http://127.0.0.1:7897

git config --global https.proxy http://127.0.0.1:7897

可以开梯子上传

http://127.0.0.1:7897是我的代理地址，查看自己的代理地址路径：网络和internet-代理-手动设置代理

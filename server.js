const express = require('express');
const bodyParser = require('body-parser');
const app = express();
// 多个用户账户信息 - 存储用户名和对应的密码哈希
const users = [
    {
        username: 'a',
        password: 'a'
    },
    
    {
        username: 'kfyzadmin',
        
        hashedpassword:'123456'
    }
];
// 解析JSON请求体
app.use(bodyParser.json());
// 解析表单数据
app.use(bodyParser.urlencoded({ extended: true }));
// 允许跨域请求
app.use((req, res, next) => {
    res.setHeader('Access-Control-Allow-Origin', '*');
    res.setHeader('Access-Control-Allow-Methods', 'GET, POST, OPTIONS');
    res.setHeader('Access-Control-Allow-Headers', 'Content-Type');
    next();
});
// 配置静态文件服务，允许访问当前目录下的文件
app.use(express.static(__dirname));
// 目标文件路径
const targetFileName = 'http://8.137.36.227/home';

// 处理登录请求
app.post('/submit', (req, res) => {
    const { username, password: password } = req.body;
    console.log('收到登录请求：', { username, password });

    // 查找匹配的用户
    const matchedUser = users.find(user =>
        user.username === username && user.password === password
    );

    if (matchedUser) {
        // 生成可访问的URL（重要！）
        const fileAccessUrl = targetFileName;
        res.json({
            code: 200,
            fileUrl: fileAccessUrl  // 返回网络可访问的URL
        });
        console.log(fileAccessUrl);
    } else {
        res.status(400).json({
            code: 400,
            message: '用户名或密码错误'
        });
    }
});

// 启动服务器
const PORT = 4000;
app.listen(PORT, () => {
    console.log(`服务器运行在 http://127.0.0.1:${PORT}`);
    console.log(`请在浏览器中打开 http://127.0.0.1:4000 或你的HTML文件路径`);
});

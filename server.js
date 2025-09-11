const express = require('express');
const bodyParser = require('body-parser');
const app = express();

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

// 处理表单提交的POST请求
app.post('/submit', (req, res) => {
    const { username, password } = req.body;
    
    console.log('收到登录请求：', { username, password });
    
    // 简单的验证逻辑
    if (username === 'a' && password === 'a') {
        res.json({ code: 200, message: '登录成功！欢迎回来，' + username });
    } else {
        res.status(400).json({ code: 400, message: '用户名或密码错误' });
    }
});

// 启动服务器
const PORT = 3000;
app.listen(PORT, () => {
    console.log(`服务器运行在 http://127.0.0.1:${PORT}`);
    console.log(`请在浏览器中打开 http://127.0.0.1:5500 或你的HTML文件路径`);
});

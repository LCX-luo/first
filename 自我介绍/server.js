const express = require('express');
const bodyParser = require('body-parser');
const app = express();
// 多个用户账户信息 - 存储用户名和对应的密码哈希
const users = [
    {
        username: 'a',
        // 原密码 'a' 的 SHA-256 哈希值
        hashedpassword: 'ca978112ca1bbdcafac231b39a23dc4da786eff8147c4e72b9807785afee48bb'
    },
    {
        username: 'b',
        // 原密码 'b' 的 SHA-256 哈希值
        hashedpassword: '3e23e8160039594a33894f6564e1b1348bbd7a0088d42c4acb73eeaed59c009d'
    },
    {
        username: 'c',
        // 原密码 'c' 的 SHA-256 哈希值
        hashedpassword: '2e7d2c03a9507ae265ecf5b5356885a53393a2029d241394997265a1a25aefc6'
    },
    {
        username: 'kfyzadmin',
        // 原密码 '123456' 的 SHA-256 哈希值
        hashedpassword:'8d969eef6ecad3c29a3a629280e686cf0c3f5d5a86aff3ca12020c923adc6c92'
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

// 处理登录请求
app.post('/submit', (req, res) => {
    const { username, password: hashedPassword } = req.body;
    console.log('收到登录请求：', { username, hashedPassword });

    // 查找匹配的用户
    const matchedUser = users.find(user => 
        user.username === username && user.hashedpassword === hashedPassword
    );

    if (matchedUser) {
        res.json({ 
            code: 200, 
            username: matchedUser.username  // 返回当前登录的用户名
        });
    } else {
        res.status(400).json({ 
            code: 400, 
            message: '用户名或密码错误' 
        });
    }
});

// 启动服务器
const PORT = 3000;
app.listen(PORT, () => {
    console.log(`服务器运行在 http://127.0.0.1:${PORT}`);
    console.log(`请在浏览器中打开 http://127.0.0.1:5500 或你的HTML文件路径`);
});

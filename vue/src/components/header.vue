<style scoped>
.headerstyle {
    display: flex;
    align-items: center;
    margin-bottom: 40px;
    padding: 15px;
    background-color: #e0e7ff;
    border-radius: 8px;
}

header img {
    width: 100px;
    height: 100px;
    border-radius: 50%;
    margin-right: 20px;
}

header img:hover {
    transform: scale(1.1);
    box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2);
}

header ul {
    list-style-type: none;
    display: flex;
    gap: 20px;
    margin-left: auto;
}

header ul li a {
    text-decoration: none;
    color: #569ef0;
    font-weight: bold;
}

header ul li a:hover {
    color: #0074f9;
}
</style>
<template>
    <header class="headerstyle">
        <img src="../assets/dorohead.png" alt="图片不见了" title="好看吗">
        <h1>你好！</h1>
        <ul>
            <li><a href="#skills">技能</a></li>
            <li><a href="#life">生活</a></li>
            <li><a href="#contact">联系我</a></li>
            <li><a href="#message-boardbackground">留言版</a></li>

        </ul>
    </header>
</template>
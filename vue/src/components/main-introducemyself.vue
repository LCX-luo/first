<template>
    <div class="main-introducemyself">
        <img src="../assets/dorohead.png" alt="我的照片">
        <div class="main-text">
            <h1>欢迎来到我的自我介绍页面！</h1>
            <p>我叫罗晨轩,信软24级中登,<br>
                由于大一摆了一年于是今年开始<s>带着愧疚</s>狠狠卷<br>
                喜欢探索世界,因此也热爱旅游,开拓新地图<br>
                所以我也喜欢拍照,记录生活中的美好瞬间<br>
                当然,我也喜欢美食,约饭可以找我！<br>
                运动,喜欢游泳和骑行,骑绿道是我的最爱<br>
                目前正在学习前端开发<br>
            </p>
        </div>
    </div>
</template>

<script>
export default {
    // 在mounted钩子中执行DOM操作，确保组件已渲染
    mounted() {
        const introImage = document.querySelector('.main-introducemyself img');
        // 增加判断，确保元素存在
        if (introImage) {
            introImage.addEventListener('mouseover', () => {
                introImage.style.transform = 'rotate(10deg) scale(1.1)';
                introImage.style.transition = 'transform 0.3s ease'; // 增加过渡效果
            });
            introImage.addEventListener('mouseout', () => {
                introImage.style.transform = 'scale(1)';
                introImage.style.boxShadow = 'none';
            });
        }
    },
    // 组件卸载前移除事件监听，避免内存泄漏
    beforeUnmount() {
        const introImage = document.querySelector('.main-introducemyself img');
        if (introImage) {
            // 注意：需要使用具名函数才能正确移除事件监听
            const handleMouseOver = () => {
                introImage.style.transform = 'rotate(10deg) scale(1.1)';
            };
            const handleMouseOut = () => {
                introImage.style.transform = 'scale(1)';
                introImage.style.boxShadow = 'none';
            };
            introImage.removeEventListener('mouseover', handleMouseOver);
            introImage.removeEventListener('mouseout', handleMouseOut);
        }
    }
}
</script>

<style scoped>
.main-introducemyself {
    margin: 50px;
    background-color: #e9e9e9;
    display: flex;
    align-items: center;
    padding: 20px;
    min-height: 200px;
    border-radius: 50px;
}

.main-introducemyself img {
    width: 100px;
    height: 100px;
    border-radius: 50%;
    flex-shrink: 0;
    transition: transform 0.3s ease; /* 也可以在这里定义过渡效果 */
}

.main-text {
    flex: 1;
    text-align: center;
}

.main-introducemyself h1 {
    margin: 0 0 10px 0;
}

.main-introducemyself p {
    margin: 0;
    line-height: 1.6;
}
</style>

<template>
    <div id="movebuttonbackground">
        <h1>评价一下？</h1>
        <div id="twobutton">
            <button id="yesbutton">好看</button>
            <button id="nobutton">不好看</button>
        </div>
    </div>
</template>

<style scoped>
#movebuttonbackground {
    margin-left: auto;
    margin-right: auto;
    width: 500px;
    height: 300px;
    box-shadow: 0 4px 12px rgba(0, 0, 0, 0.1);
    border-radius: 10px;
    padding: 10px;
    position: relative;
    background-color: white;
}

#movebuttonbackground h1 {
    text-align: center;
    color: #333;
    margin-top: 30px;
}

#twobutton {
    display: flex;
    justify-content: space-between;
    margin-top: 180px;
    padding: 0 50px;
}

#yesbutton {
    width: 100px;
    padding: 12px 20px;
    border-radius: 8px;
    border: none;
    background-color: #4CAF50;
    color: white;
    font-size: 16px;
    font-weight: 600;
    cursor: pointer;
    transition: all 0.3s ease;
    box-shadow: 0 4px 6px rgba(76, 175, 80, 0.2);
}

#yesbutton:hover {
    background-color: #45a049;
    transform: translateY(-2px);
    box-shadow: 0 6px 8px rgba(76, 175, 80, 0.3);
}

#yesbutton:active {
    transform: translateY(0);
    box-shadow: 0 2px 4px rgba(76, 175, 80, 0.2);
}

#nobutton {
    width: 100px;
    padding: 12px 20px;
    border-radius: 8px;
    border: none;
    background-color: #f44336;
    color: white;
    font-size: 16px;
    font-weight: 600;
    cursor: pointer;
    transition: all 0.3s ease;
    box-shadow: 0 4px 6px rgba(244, 67, 54, 0.2);
}

#nobutton:hover {
    background-color: #d32f2f;
    transform: translateY(-2px);
    box-shadow: 0 6px 8px rgba(244, 67, 54, 0.3);
}

#nobutton:active {
    transform: translateY(0);
    box-shadow: 0 2px 4px rgba(244, 67, 54, 0.2);
}

/* 响应式调整 */
@media (max-width: 600px) {
    #movebuttonbackground {
        width: 90%;
        height: 250px;
    }
    
    #twobutton {
        padding: 0 20px;
        margin-top: 120px;
    }
}
</style>

<script>
export default {
    data() {
        return {
            yesButton: null,
            noButton: null,
            movebuttonbackground: null,
            buttonWidth: 0,
            buttonHeight: 0
        }
    },
    mounted() {
        // 在组件挂载后获取DOM元素
        this.yesButton = document.getElementById('yesbutton');
        this.noButton = document.getElementById('nobutton');
        this.movebuttonbackground = document.getElementById('movebuttonbackground');
        
        // 获取按钮尺寸
        this.buttonWidth = this.noButton.offsetWidth;
        this.buttonHeight = this.noButton.offsetHeight;
        
        // 绑定事件
        this.yesButton.addEventListener('click', () => this.handleYesClick());
        this.noButton.addEventListener('mouseover', () => this.moveButton());
        this.noButton.addEventListener('click', () => this.handleNoClick());
    },
    methods: {
        handleYesClick() {
            alert('谢谢认可！');
        },
        handleNoClick() {
            alert('你再仔细看看嘛！');
        },
        moveButton() {
            // 获取背景框的尺寸和位置信息
            const boxRect = this.movebuttonbackground.getBoundingClientRect();
            const boxWidth = boxRect.width;
            const boxHeight = boxRect.height;
            
            // 计算最大可移动范围（减去按钮自身尺寸和内边距）
            const maxX = boxWidth - this.buttonWidth - 20; // 减去内边距
            const maxY = boxHeight - this.buttonHeight - 20;
            
            // 生成框内的随机位置
            const x = Math.floor(Math.random() * maxX);
            const y = Math.floor(Math.random() * maxY);
            
            // 设置按钮位置
            this.noButton.style.position = 'absolute';
            this.noButton.style.left = `${x}px`;
            this.noButton.style.top = `${y}px`;
        }
    },
    beforeUnmount() {
        // 移除事件监听，防止内存泄漏
        this.yesButton.removeEventListener('click', () => this.handleYesClick());
        this.noButton.removeEventListener('mouseover', () => this.moveButton());
        this.noButton.removeEventListener('click', () => this.handleNoClick());
    }
}
</script>

<template>
    <div>
        <h2 style="text-align: center" id="message-boardbackground">留言板</h2>
        <div class="message-boardbackground">
            <div class="message-boardform">
                <form @submit.prevent="handleSubmit">
                    <label for="name">名字:</label>
                    <br>
                    <input type="text" id="name" v-model="name" required>
                    <br>
                    <label for="message">留言:</label>
                    <br>
                    <textarea id="message" v-model="message" rows="4" cols="40" required></textarea>
                    <br>
                    <button type="submit">提交</button>
                    <button type="reset">重置</button>
                </form>
            </div>
            <div class="message">
                <h2>留言</h2>
                <div id="messages">
                    <template v-if="messages.length === 0">
                        <p style="text-align:center">还没有留言，快来抢沙发吧！</p>
                    </template>
                    <template v-else>
                        <div 
                            v-for="(msg, index) in reversedMessages" 
                            :key="index"
                            class="message-item"
                        >
                            <strong>{{ msg.name }}</strong> <small>{{ formatTime(msg.timestamp) }}</small>
                            <p>{{ msg.content }}</p>
                        </div>
                    </template>
                </div>
                <button 
                    id="clearAllMessages" 
                    @click="clearAllMessages"
                    v-if="messages.length > 0"
                >
                    清空所有留言
                </button>
            </div>
        </div>
    </div>
</template>

<style scoped>
.message-boardbackground {
    width: auto;
    height: auto;
    margin: auto;
    display: flex;
    flex-direction: row;
    background-color: #ced8f2;
    border-radius: 25px;
}

.message-boardform {
    height: 200px;
    margin: 50px;
    display: flex;
    flex-direction: row;
    border-radius: 25px;
    padding: 20px;
    background-color: #e0e7ff;
}

.message-boardform button,
.message-boardform input,
.message-boardform textarea {
    margin-top: 10px;
    margin-right: 10px;
    padding: 5px 10px;
    border-radius: 5px;
    border: none;
    background-color: #ffffff;
    color: black;
    cursor: pointer;
}

.message-boardform button:hover {
    background-color: #c0c7ff;
}

.message {
    margin: 50px;
    padding: 10px;
    border-radius: 25px;
    background-color: #e0e7ff;
    flex-grow: 1;
    height: auto;
    overflow-y: auto;
}

#clearAllMessages {
    margin-top: 10px;
    margin-left: auto;
    margin-right: auto;
    padding: 5px 10px;
    border-radius: 5px;
    border: none;
    background-color: #9faaff;
    color: white;
    cursor: pointer;
    display: block;
}

#clearAllMessages:hover {
    background-color: #c0c7ff;
}

.message-item {
    border-bottom: 1px solid #ccc;
    margin-bottom: 10px;
    padding-bottom: 10px;
}
</style>

<script>
export default {
    data() {
        return {
            name: '',
            message: '',
            messages: []
        }
    },
    computed: {
        reversedMessages() {
            // 返回反转后的留言数组，最新的在前面
            return [...this.messages].reverse();
        }
    },
    mounted() {
        // 页面加载时读取留言
        this.loadMessages();
    },
    methods: {
        handleSubmit() {
            // 创建留言对象
            const newMessage = {
                name: this.name,
                content: this.message,
                timestamp: new Date().toISOString()
            };

            // 保存新留言
            this.saveMessage(newMessage);

            // 刷新显示
            this.loadMessages();

            // 清空表单
            this.name = '';
            this.message = '';
        },
        getMessages() {
            const messagesStr = localStorage.getItem('messages');
            return messagesStr ? JSON.parse(messagesStr) : [];
        },
        saveMessage(newMessage) {
            const messages = this.getMessages();
            messages.push(newMessage);
            localStorage.setItem('messages', JSON.stringify(messages));
        },
        loadMessages() {
            this.messages = this.getMessages();
        },
        clearAllMessages() {
            if (confirm("确定要删除所有留言吗？此操作不可恢复。")) {
                localStorage.removeItem('messages');
                this.messages = [];
            }
        },
        formatTime(timestamp) {
            const date = new Date(timestamp);
            return date.toLocaleString();
        }
    }
}
</script>

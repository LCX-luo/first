# Vue 常用语法与函数速查表

## 一、模板语法

### 1. 文本插值

```vue
<template>
  <p>{{ message }}</p>       <!-- 基本插值 -->
  <p>{{ count + 1 }}</p>     <!-- 简单表达式 -->
  <p>{{ isActive ? '激活' : '未激活' }}</p>  <!-- 三元运算 -->
</template>
```

### 2. 指令

- **条件渲染**

  ```vue
  <p v-if="score > 90">优秀</p>
  <p v-else-if="score > 60">及格</p>
  <p v-else>不及格</p>
  <p v-show="isVisible">显示/隐藏</p>  <!-- 仅切换display -->
  ```

- **循环渲染**

  ```vue
  <ul>
    <li v-for="(item, index) in list" :key="index">
      {{ index }}. {{ item }}
    </li>
  </ul>
  ```

  

- **属性绑定**

  ```vue
  <img :src="imgUrl" :class="{ active: isActive }">
  <div :style="{ color: textColor, fontSize: '16px' }"></div>
  ```

- **事件绑定**

  ```vue
  <button @click="handleClick">点击</button>
  <button @click="handleAdd(5)">加5</button>
  <form @submit.prevent="handleSubmit">提交</form>  <!-- 修饰符 -->
  ```

- **双向绑定**

  ```vue
  <input v-model="username">
  <textarea v-model="content"></textarea>
  <input type="checkbox" v-model="isAgree">
  ```

## 二、响应式数据

### 1. 基础类型 (ref)

<script setup> import { ref } from 'vue' const count = ref(0)         // 初始值 console.log(count.value)     // 访问值 count.value = 10             // 修改值 </script>

### 2. 对象 / 数组 (reactive)

```vue
<script setup>
import { reactive } from 'vue'
const user = reactive({
  name: '张三',
  age: 20
})
user.age = 21                // 直接修改属性

const list = reactive([1, 2, 3])
list.push(4)                 // 数组操作
</script>
```

### 3. 计算属性 (computed)

```vue
<script setup>
import { ref, computed } from 'vue'
const count = ref(1)
// 只读计算属性
const doubleCount = computed(() => count.value * 2)
// 可写计算属性
const fullName = computed({
  get: () => firstName.value + lastName.value,
  set: (val) => { /* 拆分逻辑 */ }
})
</script>
```

## 三、方法与事件

```vue
<template>
  <button @click="increment">加1</button>
  <button @click="greet('Hello')">问候</button>
</template>

<script setup>
import { ref } from 'vue'
const count = ref(0)

// 定义方法
const increment = () => {
  count.value++
}

const greet = (msg) => {
  alert(msg)
}
</script>
```

## 四、生命周期钩子

```vue
<script setup>
import { onMounted, onUpdated, onUnmounted } from 'vue'

// 组件挂载后执行
onMounted(() => {
  console.log('组件已挂载')
})

// 组件更新后执行
onUpdated(() => {
  console.log('组件已更新')
})

// 组件卸载前执行
onUnmounted(() => {
  console.log('组件将卸载')
})
</script>
```

## 五、组件通信

### 1. 父传子 (props)

```vue
<!-- 子组件 Child.vue -->
<script setup>
import { defineProps } from 'vue'
// 定义接收的属性
const props = defineProps({
  title: String,
  count: {
    type: Number,
    default: 0
  }
})
// 使用：props.title
</script>

<!-- 父组件使用 -->
<Child title="标题" :count="10" />
```

### 2. 子传父 (emit)

```vue
<!-- 子组件 Child.vue -->
<template>
  <button @click="handleClick">点击</button>
</template>

<script setup>
import { defineEmits } from 'vue'
// 定义可触发的事件
const emit = defineEmits(['change', 'update'])
const handleClick = () => {
  emit('change', '传递的值')  // 触发事件并传参
}
</script>

<!-- 父组件使用 -->
<Child @change="handleChange" />
```

## 六、常用 API 函数

| 函数            | 说明                      |
| --------------- | ------------------------- |
| `ref()`         | 创建基础类型响应式数据    |
| `reactive()`    | 创建对象 / 数组响应式数据 |
| `computed()`    | 创建计算属性              |
| `watch()`       | 监听数据变化              |
| `watchEffect()` | 自动追踪依赖的监听        |
| `onMounted()`   | 组件挂载后钩子            |
| `defineProps()` | 声明组件接收的属性        |
| `defineEmits()` | 声明组件可触发的事件      |
| `useSlots()`    | 访问插槽内容              |
| `useAttrs()`    | 访问非 props 属性         |

## 七、路由相关 (Vue Router)

```vue
<!-- 路由跳转 -->
<router-link to="/home">首页</router-link>

<!-- 编程式导航 -->
<script setup>
import { useRouter } from 'vue-router'
const router = useRouter()
const goDetail = () => {
  router.push('/detail')
}
</script>

<!-- 获取路由参数 -->
<script setup>
import { useRoute } from 'vue-router'
const route = useRoute()
console.log(route.params.id)  // 路径参数
console.log(route.query)      // 查询参数
</script>
```
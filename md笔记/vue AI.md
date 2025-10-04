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

# v-总结

Vue 中提供了许多 `v-` 开头的指令，用于在模板中实现各种功能。这些指令大多有对应的简写形式，让代码更简洁。以下是常用的 `v-` 指令及其简写的介绍：


### 1. `v-bind`：绑定属性
- **作用**：动态绑定 HTML 属性（如 `src`、`class`、`style` 等）或组件 props。
- **完整语法**：`v-bind:属性名="表达式"`
- **简写**：`:` 属性名（直接用冒号）
- **示例**：
  ```vue
  <!-- 绑定图片 src -->
  <img v-bind:src="imageUrl">
  <img :src="imageUrl"> <!-- 简写 -->

  <!-- 绑定 class -->
  <div v-bind:class="{ active: isActive }"></div>
  <div :class="{ active: isActive }"></div> <!-- 简写 -->
  ```


### 2. `v-on`：绑定事件
- **作用**：绑定 DOM 事件（如点击、输入等）或组件自定义事件。
- **完整语法**：`v-on:事件名="处理函数"`
- **简写**：`@` 事件名
- **示例**：
  ```vue
  <!-- 绑定点击事件 -->
  <button v-on:click="handleClick">点击</button>
  <button @click="handleClick">点击</button> <!-- 简写 -->

  <!-- 绑定输入事件 -->
  <input v-on:input="handleInput">
  <input @input="handleInput"> <!-- 简写 -->
  ```


### 3. `v-model`：双向数据绑定
- **作用**：在表单元素（如输入框、复选框等）上实现数据的双向绑定。
- **特点**：无简写，但本质是 `v-bind:value` 和 `v-on:input` 的语法糖。
- **示例**：
  ```vue
  <input v-model="username">
  <!-- 等价于 -->
  <input :value="username" @input="username = $event.target.value">
  ```


### 4. `v-for`：列表渲染
- **作用**：基于数组或对象循环渲染元素。
- **语法**：`v-for="(item, index) in 数组" :key="唯一标识"`（`key` 用于优化渲染）
- **无简写**
- **示例**：
  ```vue
  <ul>
    <li v-for="(item, index) in list" :key="index">
      {{ index }}: {{ item }}
    </li>
  </ul>
  ```


### 5. `v-if` / `v-else-if` / `v-else`：条件渲染
- **作用**：根据条件动态渲染或销毁元素（会真正删除/创建 DOM）。
- **无简写**
- **示例**：
  ```vue
  <p v-if="score >= 90">优秀</p>
  <p v-else-if="score >= 60">及格</p>
  <p v-else>不及格</p>
  ```


### 6. `v-show`：条件显示
- **作用**：根据条件显示或隐藏元素（通过 CSS `display` 控制，不会销毁 DOM）。
- **无简写**
- **示例**：
  ```vue
  <p v-show="isVisible">这段文字可能显示或隐藏</p>
  ```


### 7. `v-text`：设置文本内容
- **作用**：更新元素的文本内容（等价于 `{{ }}` 插值，但不会解析 HTML）。
- **无简写**
- **示例**：
  ```vue
  <p v-text="message"></p>
  <!-- 等价于 -->
  <p>{{ message }}</p>
  ```


### 8. `v-html`：设置 HTML 内容
- **作用**：将表达式的值作为 HTML 解析并插入元素（有 XSS 风险，谨慎使用）。
- **无简写**
- **示例**：
  ```vue
  <p v-html="htmlContent"></p> <!-- htmlContent 如 '<strong>加粗</strong>' -->
  ```


### 9. `v-pre`：跳过编译
- **作用**：让 Vue 跳过对元素及其子元素的编译（用于显示原始 `{{ }}` 等）。
- **无简写**
- **示例**：
  ```vue
  <p v-pre>{{ 这段内容不会被编译 }}</p> <!-- 会直接显示 "{{ 这段内容不会被编译 }}" -->
  ```


### 10. `v-cloak`：隐藏未编译模板
- **作用**：在 Vue 实例编译完成前隐藏元素，避免显示原始 `{{ }}`。
- **用法**：配合 CSS 使用，编译完成后自动移除该属性。
- **无简写**
- **示例**：
  ```css
  [v-cloak] { display: none; }
  ```
  ```vue
  <p v-cloak>{{ message }}</p> <!-- 编译完成前不会显示 -->
  ```


### 11. `v-once`：只渲染一次
- **作用**：元素和组件只渲染一次，后续数据变化不会重新渲染。
- **无简写**
- **示例**：
  ```vue
  <p v-once>{{ message }}</p> <!-- 即使 message 变化，也不会更新 -->
  ```


这些指令是 Vue 模板语法的核心，掌握它们的用法和简写可以大幅提高开发效率。其中，`v-bind`、`v-on` 的简写（`:` 和 `@`）最为常用，建议优先掌握。


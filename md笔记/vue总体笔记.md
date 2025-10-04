# 0.开始

## 创建

使用vue包中的`import { createApp } from 'vue'`导入`createapp`--创建vue实例

```javascript
import { createApp } from 'vue'
const appindex=createApp({
    //内容
})
```

或者

```js
import { createApp } from 'vue'
const appindex={
    //内容
}
createApp(appindex);
//只有通过 CDN 全局引入 Vue（如 <script src="vue.global.js"></script>）时，才需要用 Vue.createApp()；
//若使用模块化开发（通过 npm 安装 Vue），必须通过 import { createApp } from 'vue' 导入后使用 createApp()，不能写 Vue. 
```

此时生成了一个vue实例，而createApp作为一个函数，执行结果是生成并返回一个**实例**，因此可以对函数直接操作，比如，**挂载**

## 挂载

可以使用`mount()`函数将生成的vue实例挂载到一个id上，即挂载到 HTML 中指定的 DOM 元素上（**挂载后才会在页面渲染组件内容**）。比如之前创建的实例，可以这样改写

```js
import { createApp } from 'vue'
const appindex={
    //内容
}
createApp(appindex).mount('#htmlid');
//或者可以这样写，更清楚地看到参数
const vuetohtml=createApp(appindex);
vuetohtml.mount('#htmlid');
```

这样就可以在html页面中使用`htmlid`这个id

## 实例中的内容

刚才我们创建的vue实例是空的，实际开发中需补充**根组件的核心配置选项**，才能实现数据绑定、页面渲染等功能。以下是最基础的配置项介绍：

### 1. 核心配置项：`data`（组件状态 / 数据）

`data` 是函数，返回一个对象，用于存储组件的响应式数据（数据变化时，页面会自动更新）。

```js
import { createApp } from 'vue'
const rootComponent = {
    // data 必须是函数（避免组件复用时光数据污染），返回数据对象
    data() {
        return {
            message: 'Hello Vue 3!', // 响应式数据：message
            count: 0, // 响应式数据：计数
            user: { name: 'Vue', age: 8 } // 响应式对象
        }
    }
}
// 创建实例并挂载
createApp(rootComponent).mount('#app');
```

### 2. 核心配置项：`template`（组件模板 / 结构）

`template` 是字符串，定义组件的 HTML 结构，可通过 `{{ 数据名 }}` 绑定 `data` 中的响应式数据（插值语法）。

```js
import { createApp } from 'vue'
const rootComponent = {
    data() {
        return {
            message: 'Hello Vue 3!',
            count: 0
        }
    },
    // 模板结构：使用 {{ }} 绑定 data 中的数据
    template: `
        <div>
            <h1>{{ message }}</h1> <!-- 绑定 message -->
            <p>当前计数：{{ count }}</p> <!-- 绑定 count -->
            <button @click="count += 1">点击加1</button> <!-- 简单事件：点击时修改 count -->
        </div>
    `
}
createApp(rootComponent).mount('#app');
```

- 模板中可直接使用 `data` 中的数据，无需额外声明；
- 可通过 `@事件名` 绑定简单事件（如 `@click` 点击事件），直接修改响应式数据。

### 3. 常用配置项：`methods`（组件方法）

当事件逻辑较复杂时，可将逻辑封装到 `methods` 中的函数里，模板中通过 `@事件名="方法名"` 调用。

```js
import { createApp } from 'vue'
const rootComponent = {
    data() {
        return {
            count: 0
        }
    },
    template: `
        <div>
            <p>当前计数：{{ count }}</p>
            <button @click="increment">点击加1</button> <!-- 调用 methods 中的 increment 方法 -->
            <button @click="reset">重置计数</button> <!-- 调用 methods 中的 reset 方法 -->
        </div>
    `,
    // methods 存储组件的方法，函数内可通过 this 访问 data 中的数据
    methods: {
        increment() {
            // this 指向当前组件实例，可直接修改 data 中的 count
            this.count += 1;
        },
        reset() {
            this.count = 0;
        }
    }
}
createApp(rootComponent).mount('#app');
```

- `methods` 中的函数，`this` 始终指向当前组件实例，可通过 `this.数据名` 访问 / 修改 `data` 中的响应式数据；
- 方法名需与模板中绑定的事件名一致，无需加 `()`（如 `@click="increment"`，而非 `increment()`）。

### 4. 配置项的作用总结

| 配置项     | 类型   | 核心作用                                 | 注意事项                                    |
| ---------- | ------ | ---------------------------------------- | ------------------------------------------- |
| `data`     | 函数   | 存储组件的响应式数据，数据变则页面变     | 必须是函数，返回对象（避免数据污染）        |
| `template` | 字符串 | 定义组件的 HTML 结构，支持插值与事件绑定 | 模板内容需用反引号 ``` 包裹（支持多行）     |
| `methods`  | 对象   | 存储组件的方法，封装复杂逻辑             | 方法内通过 `this` 访问组件实例的数据 / 方法 |

通过以上配置，Vue 应用实例就能拥有 “数据 - 视图 - 交互” 的完整能力，后续还可根据需求补充 `computed`（计算属性）、`watch`（数据监听）等更复杂的配置项。
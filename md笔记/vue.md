运行 `npm run serve` 或 `yarn serve`，启动开发服务器

```html
<div id="app">
  <button @click="count++">{{ count }}</button>
</div>

<script>
const { createApp, ref } = Vue;

const app = createApp({
  setup() {
    const count = ref(0);
    function increment() {
      count.value++;
    };
    return { count, increment };
  }
});

app.mount('#app')
</script>
```

### HTML 部分解析

```html
<div id="app">
  <button @click="count++">{{ count }}</button>
</div>
```

- `<div id="app">`：这是 Vue 应用的挂载点，Vue 会管理这个元素内部的所有内容

- ```
  <button @click="count++">
  ```

  - `@click` 是 Vue 的事件绑定语法，等同于 `v-on:click`，用于监听按钮的点击事件
  - `count++` 是点击事件触发时执行的表达式，会将 count 的值加 1

- `{{ count }}`：这是 Vue 的文本插值语法，用于将 count 变量的值显示在按钮上

### JavaScript 部分解析

```javascript
const { createApp, ref } = Vue;
```

- 从 Vue 中解构导出

  ```
  createApp
  ```

  和

  ```
  ref
  ```

  两个函数

  - `createApp`：用于创建一个 Vue 应用实例
  - `ref`：用于创建响应式变量（在 Vue 3 的组合式 API 中使用）

```javascript
const app = createApp({
  setup() {
    const count = ref(0);
    function increment() {
      count.value++;
    };
    return { count, increment };
  }
});
```

- `createApp()`：接收一个配置对象作为参数，创建 Vue 应用实例

- ```
  setup()
  ```

  ：这是 Vue 3 组合式 API 的入口函数，在组件创建前执行

  - `const count = ref(0)`：创建一个响应式变量 count，初始值为 0。`ref`用于处理基本类型的响应式数据

  - ```
    function increment()
    ```

    ：定义了一个名为 increment 的函数，用于增加 count 的值

    - `count.value++`：因为 count 是用`ref`创建的响应式变量，所以需要通过`.value`访问其值

  - `return { count, increment }`：将 count 变量和 increment 函数暴露出去，这样在模板中才能使用

```javascript
app.mount('#app')
```

- 将创建好的 Vue 应用实例挂载到 HTML 中 id 为`app`的元素上，此时 Vue 开始接管该元素的渲染和交互

### 工作原理

1. 页面加载时，Vue 应用初始化，`setup()`函数执行，创建 count 变量并初始化为 0
2. 按钮上显示 count 的初始值 0
3. 当点击按钮时，触发`@click`事件，执行`count++`，使 count 的值增加 1
4. 由于 count 是响应式变量，Vue 会自动检测到其值的变化，并更新按钮上显示的内容

这个例子展示了 Vue 3 组合式 API 的基本用法，包括响应式变量的创建、事件处理和模板渲染。
在 Vue 中，`v-` 开头的指令是特殊的 HTML 属性，用于在模板中实现数据绑定、事件处理、条件渲染等功能。以下是常用的 `v-` 指令及其用法：


### 1. 数据绑定：`v-text` 与 `v-html`
- **`v-text`**：更新元素的文本内容（相当于 `{{ }}` 插值）
- **`v-html`**：更新元素的 HTML 内容（注意 XSS 风险）

```html
<!-- 显示文本 -->
<p v-text="message"></p> <!-- 等价于 <p>{{ message }}</p> -->

<!-- 渲染HTML -->
<div v-html="rawHtml"></div> <!-- 若rawHtml是"<strong>Vue</strong>"，则渲染为粗体文本 -->
```


### 2. 条件渲染：`v-if`、`v-else-if`、`v-else`
根据表达式的真假切换元素的存在（会销毁/创建元素）

```html
<div v-if="score >= 90">优秀</div>
<div v-else-if="score >= 60">及格</div>
<div v-else>不及格</div>

<!-- 配合template分组 -->
<template v-if="isShow">
  <p>标题</p>
  <p>内容</p>
</template>
```


### 3. 列表渲染：`v-for`
基于数据源循环渲染元素（需配合 `key` 提高性能）

```html
<!-- 遍历数组 -->
<ul>
  <li v-for="(item, index) in list" :key="index">
    {{ index + 1 }}. {{ item.name }}
  </li>
</ul>

<!-- 遍历对象 -->
<div v-for="(value, key) in user" :key="key">
  {{ key }}: {{ value }}
</div>
```


### 4. 事件绑定：`v-on`（缩写 `@`）
绑定事件监听器，触发时执行方法或表达式

```html
<!-- 绑定方法 -->
<button v-on:click="handleClick">点击</button>
<!-- 缩写 -->
<button @click="handleClick">点击</button>

<!-- 带参数 -->
<button @click="deleteItem(id)">删除</button>

<!-- 事件修饰符 -->
<button @click.stop="handleClick">阻止冒泡</button>
<input @keyup.enter="submit"> <!-- 回车触发 -->
```


### 5. 属性绑定：`v-bind`（缩写 `:`）
动态绑定 HTML 属性或组件 props

```html
<!-- 绑定普通属性 -->
<img v-bind:src="imageUrl" alt="图片">
<!-- 缩写 -->
<img :src="imageUrl" alt="图片">

<!-- 绑定class -->
<div :class="{ active: isActive, 'text-danger': hasError }"></div>

<!-- 绑定style -->
<div :style="{ color: textColor, fontSize: '16px' }"></div>

<!-- 绑定组件props -->
<user-component :user-id="userId"></user-component>
```


### 6. 双向绑定：`v-model`
在表单元素上创建双向数据绑定（值与数据实时同步）

```html
<!-- 输入框 -->
<input v-model="username" type="text">

<!-- 复选框 -->
<input v-model="isAgree" type="checkbox">

<!-- 下拉框 -->
<select v-model="selectedCity">
  <option value="beijing">北京</option>
  <option value="shanghai">上海</option>
</select>

<!-- 修饰符 -->
<input v-model.trim="username"> <!-- 自动去除首尾空格 -->
<input v-model.number="age"> <!-- 转为数字类型 -->
```


### 7. 显示隐藏：`v-show`
根据表达式的真假切换元素的显示/隐藏（通过 `display` CSS 属性控制，元素始终存在）

```html
<p v-show="isVisible">这段文字可能被隐藏</p>
<!-- 与v-if的区别：v-show适合频繁切换，v-if适合条件很少改变的场景 -->
```


### 8. 指令修饰符
通过 `.` 后缀增强指令功能，例如：
- **事件修饰符**：`.stop`（阻止冒泡）、`.prevent`（阻止默认行为）、`.once`（只触发一次）
- **按键修饰符**：`.enter`、`.esc`、`.space` 等
- **v-model修饰符**：`.trim`、`.number`、`.lazy`（失焦后同步）

```html
<form @submit.prevent="handleSubmit"> <!-- 阻止表单默认提交 -->
  <input @keydown.esc="clearInput"> <!-- 按ESC清空 -->
  <input v-model.lazy="searchText"> <!-- 失焦后才更新数据 -->
</form>
```


### 9. 其他实用指令
- **`v-pre`**：跳过元素和子元素的编译（用于显示原始插值语法）
  ```html
  <p v-pre>{{ 这里的内容不会被编译 }}</p>
  ```

- **`v-cloak`**：隐藏未编译的插值，直到 Vue 实例准备就绪（需配合 CSS 使用）
  ```css
  [v-cloak] { display: none; }
  ```
  ```html
  <p v-cloak>{{ message }}</p> <!-- 编译完成前不会显示{{ message }} -->
  ```

- **`v-once`**：只渲染元素一次，后续更新不重新渲染（优化性能）
  ```html
  <p v-once>{{ staticMessage }}</p> <!-- 即使数据变化，也不会重新渲染 -->
  ```


这些指令是 Vue 模板语法的核心，通过合理组合可以实现各种交互效果。指令的使用遵循 "声明式" 思想，让开发者更关注 "做什么" 而非 "怎么做"。


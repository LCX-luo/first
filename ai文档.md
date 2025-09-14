# markdown

1. **标题**：`#` 开头（`#` 到 `######` 对应 1-6 级标题）。
2. **列表**：
   - 无序列表：`- ` 或 `* ` 开头。
   - 有序列表：`1. ` 开头。
3. **链接**：`[显示文本](链接地址 "可选标题")`。
4. **图片**：`![替代文本](图片地址 "可选标题")`。
5. **强调**：
   - 斜体：`*文本*` 或 `_文本_`。
   - 粗体：`**文本**` 或 `__文本__`。
6. **代码**：
   - 行内代码：` `代码` `。
   - 代码块： ```语言\n代码\n```（如 ```python）。
7. **引用**：`> 引用内容`。
8. **分隔线**：`---` 或 `***`。
9. **表格**：`| 表头 |...\n|---|...\n| 内容 |...`。
10. **任务列表**：`- [x] 已完成` 或 `- [ ] 未完成`。

# vscode

代码格式化用 `Shift+Alt+F`，

`Alt+Up` 或 `Alt+Down` 可移动代码行；

`Shift+Alt+Up` 或 `Shift+Alt+Down` 能快速复制代码行；

`Ctrl+S` 用于快速保存文件；

`Ctrl+F` 方便查找内容；

`Ctrl+H` 则可进行内容替换。

# html

'<head>中的内容一般不会呈现给用户，除了<title>'

***<meta>是单标签<meta charset="utf-8">**,用来指定字体*****

### 一、文档结构标签
#### 1. `<html>`
- **作用**：HTML文档的根标签
- **关键属性**：`lang`（指定页面语言，影响搜索引擎和辅助设备）
```html
<html lang="zh-CN">
  <!-- 页面内容 -->
</html>
```

#### 2. `<head>`
- **作用**：包含文档元数据，不直接显示在页面上
- **常见子标签**：`<title>`, `<meta>`, `<link>`, `<script>`, `<style>`
```html
<head>
  <title>页面标题</title>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <link rel="stylesheet" href="styles.css">
  <script src="script.js"></script>
</head>
```

#### 3. `<body>`
- **作用**：包含所有可见的页面内容
- **注意**：一个HTML文档只能有一个`<body>`标签
```html
<body>
  <!-- 页面可见内容 -->
</body>
```

### 二、文本格式化标签
#### 1. 标题标签 (`<h1>`~`<h6>`)
- **作用**：定义页面标题和子标题
- **语义重要性**：影响SEO和辅助设备（如屏幕阅读器）
```html
<h1>一级标题（最大）</h1>
<h2>二级标题</h2>
<h3>三级标题</h3>
<!-- 以此类推到h6 -->
```

#### 2. `<p>` - 段落标签
- **特点**：块级元素，自动在前后添加换行
```html
<p>这是一个段落。</p>
<p>这是另一个段落，与上一个段落之间有间距。</p>
```

#### 3. 强调标签对比
```html
<strong>重要文本</strong> <!-- 语义：重要性 -->
<em>强调文本</em> <!-- 语义：语气或重点变化 -->
<b>粗体文本</b> <!-- 无特殊语义，仅视觉效果 -->
<i>斜体文本</i> <!-- 无特殊语义，仅视觉效果 -->
```

### 三、列表标签
#### 1. 无序列表 (`<ul>`)
- **项目符号样式**：可通过CSS修改（disc, circle, square等）
```html
<ul>
  <li>苹果</li>
  <li>香蕉</li>
  <li>橙子</li>
</ul>
```

#### 2. 有序列表 (`<ol>`)
- **编号样式**：可通过`type`属性修改（1, A, a, I, i）
```html
<ol type="A">
  <li>第一步</li>
  <li>第二步</li>
  <li>第三步</li>
</ol>
```

#### 3. 定义列表 (`<dl>`)
- **适用场景**：术语表、键值对列表
```html
<dl>
  <dt>HTML</dt>
  <dd>超文本标记语言</dd>
  <dt>CSS</dt>
  <dd>层叠样式表</dd>
</dl>
```

### 四、链接与媒体标签
#### 1. `<a>` - 超链接
- **关键属性**：`href`, `target`, `rel`
```html
<a href="https://example.com">访问外部网站</a>
<a href="#section2">跳转到页面内锚点</a>
<a href="mailto:contact@example.com">发送邮件</a>
<a href="tel:+123456789">拨打电话</a>
```

#### 2. `<img>` - 图片
- **响应式技巧**：使用`max-width:100%; height:auto`
```html
<img 
  src="image.jpg" 
  alt="风景照片" 
  width="300" 
  height="200"
  loading="lazy" <!-- 只有图片出现在页面时才加载图片 -->
>
```

#### 3. `<video>` - 视频
- **多格式支持**：使用`<source>`标签提供多种格式
```html
<video controls width="400">
  <source src="video.mp4" type="video/mp4">
  <source src="video.webm" type="video/webm">
  您的浏览器不支持HTML5视频播放
</video>
```

### 五、表单标签

#### 一、`<form>` 标签的核心属性

这些属性控制整个表单的提交行为和数据处理方式：

1. **`action`**
   - 作用：指定表单数据提交的后端接口地址（URL）。
   - 示例：`<form action="/api/login" ...>` 表示数据会提交到 `/api/login` 接口。
   - 若省略，默认提交到当前页面的 URL。
2. **`method`**
   - 作用：指定表单数据的提交方式（HTTP 方法）。
   - 可选值：
     - `get`（默认）：数据会拼接在 URL 后（如 `?username=xxx&password=xxx`），适合简单、非敏感数据，有长度限制。
     - `post`：数据放在请求体中发送，适合敏感数据（如密码）或大量数据，无长度限制。
   - 示例：`<form method="post" ...>`
3. **`enctype`**
   - 作用：指定表单数据的编码方式，仅在 `method="post"` 时有效。
   - 常用值：
     - `application/x-www-form-urlencoded`（默认）：普通表单数据编码。
     - `multipart/form-data`：用于上传文件（必须配合 `<input type="file">` 使用）。
     - `text/plain`：纯文本编码，适合简单场景。
   - 示例：`<form enctype="multipart/form-data" ...>`（用于文件上传）
4. **`target`**
   - 作用：指定表单提交后响应内容的显示位置。
   - 常用值：
     - `_self`（默认）：在当前窗口显示。
     - `_blank`：在新窗口显示。
     - `_parent`/`_top`：在父框架 / 顶层框架显示。
   - 示例：`<form target="_blank" ...>`
5. **`autocomplete`**
   - 作用：控制表单是否启用自动填充功能（浏览器记住之前输入的值）。
   - 可选值：`on`（默认启用）、`off`（禁用）。
   - 示例：`<form autocomplete="off" ...>`（适合敏感表单，如登录）

#### 二、表单控件（如 `<input>`、`<select>` 等）的常用属性

这些属性控制单个输入字段的行为、验证规则等：

1. **`name`**

   - 作用：定义表单控件的名称，是提交数据时的「键」（与 `value` 组成键值对）。
   - 注意：未设置 `name` 的控件，其值不会被提交。
   - 示例：`<input type="text" name="username">` 提交后为 `username=xxx`。

2. **`value`**

   - 作用：设置控件的默认值或当前值。
   - 示例：`<input type="text" value="默认用户名">`（文本框默认显示该内容）。

3. **`required`**

   - 作用：标记控件为必填项，提交时若为空，浏览器会自动提示验证错误。
   - 适用控件：`<input>`、`<select>`、`<textarea>` 等。
   - 示例：`<input type="password" required>`（密码不能为空）。

4. **`type`**（主要用于 `<input>`）

   - 作用：定义输入控件的类型，决定输入方式和验证规则。
   - 常用值：`text`（文本）、`password`（密码）、`number`（数字）、`email`（邮箱）、`checkbox`（复选框）等。
   - 示例：`<input type="email">`（自动验证邮箱格式）。

5. **`placeholder`**

   - 作用：在控件为空时显示提示文本（如输入示例），不影响实际提交的值。
   - 适用控件：`<input>`（部分类型）、`<textarea>`。
   - 示例：`<input type="text" placeholder="请输入用户名">`。

6. **`disabled`**

   - 作用：禁用控件，使其不可编辑、不可点击，且值不会被提交。
   - 示例：`<input type="text" disabled value="不可修改">`。

7. **`readonly`**

   - 作用：设置控件为只读（可选中但不可编辑），但其值会被正常提交。
   - 示例：`<input type="text" readonly value="只读内容">`。

8. **`checked`**（用于复选框 / 单选按钮）

   - 作用：设置复选框（`checkbox`）或单选按钮（`radio`）默认选中状态。

   - 示例：

     ```html
     <input type="checkbox" checked name="agree"> 同意协议
     <input type="radio" name="gender" value="male" checked> 男
     ```

9. **`maxlength`**（用于文本输入）

   - 作用：限制输入的最大字符数。
   - 示例：`<input type="text" maxlength="10">`（最多输入 10 个字符）。

10. **`min`/`max`**（用于数字 / 日期输入）

    - 作用：限制数字、日期等类型的最小值和最大值。
    - 示例：`<input type="number" min="0" max="100">`（只能输入 0-100 的数字）。

11. **`pattern`**

    - 作用：通过正则表达式自定义输入验证规则。
    - 示例：`<input type="text" pattern="[A-Za-z0-9]{6,}" title="请输入6位以上字母或数字">`（限制 6 位以上字母 / 数字）。

#### 三、其他实用属性

- **`autofocus`**：页面加载时自动聚焦到该控件（一个页面通常只设置一个）。
  示例：`<input type="text" autofocus>`
- **`multiple`**：允许选择多个值（如文件上传、多选下拉框）。
  示例：`<input type="file" multiple>`（可选择多个文件）
- **`size`**：设置控件的显示宽度（以字符为单位，主要用于文本输入）。
  示例：`<input type="text" size="20">`

#### 1. 基础表单结构
```html
<form action="/submit" method="POST">
  <label for="name">姓名：</label>
  <input type="text" id="name" name="name" required>
  
  <label for="email">邮箱：</label>
  <input type="email" id="email" name="email">
  
  <label>性别：</label>
  <input type="radio" id="male" name="gender" value="male">
  <label for="male">男</label>
  <input type="radio" id="female" name="gender" value="female">
  <label for="female">女</label>
  
  <label for="message">留言：</label>
  <textarea id="message" name="message" rows="4"></textarea>
  
  <input type="checkbox" id="agree" name="agree" required>
  <label for="agree">我同意条款</label>
  
  <button type="submit">提交</button>
  <button type="reset">重置</button>
</form>
```

#### 2. 高级输入类型
```html
<input type="date"> <!-- 日期选择器 -->
<input type="color" value="#ff0000"> <!-- 颜色选择器 -->
<input type="range" min="0" max="100" value="50"> <!-- 滑块 -->
<input type="file" accept="image/*"> <!-- 文件上传 -->
```

### 六、表格标签
#### 完整表格示例
```html
<table border="1">
  <caption>员工信息表</caption>
  <thead>
    <tr>
      <th>姓名</th>
      <th>职位</th>
      <th>部门</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>张三</td>
      <td>开发工程师</td>
      <td>技术部</td>
    </tr>
    <tr>
      <td>李四</td>
      <td>产品经理</td>
      <td>产品部</td>
    </tr>
  </tbody>
  <tfoot>
    <tr>
      <td colspan="3">总计：2人</td>
    </tr>
  </tfoot>
</table>
```

### 七、其他功能标签
#### 1. `<template>` - 模板标签
- **特点**：内容不会显示，需通过JavaScript实例化
```html
<template id="user-card">
  <div class="card">
    <h3 class="name"></h3>
    <p class="email"></p>
  </div>
</template>

<script>
  const template = document.getElementById('user-card');
  const clone = document.importNode(template.content, true);
  clone.querySelector('.name').textContent = '张三';
  clone.querySelector('.email').textContent = 'zhangsan@example.com';
  document.body.appendChild(clone);
</script>
```

#### 2. `<canvas>` - 动态绘图
- **示例**：绘制红色矩形
```html
<canvas id="myCanvas" width="200" height="100"></canvas>

<script>
  const canvas = document.getElementById('myCanvas');
  const ctx = canvas.getContext('2d');
  ctx.fillStyle = 'red';
  ctx.fillRect(10, 10, 150, 80);
</script>
```

#### 3. `<svg>` - 矢量图形
- **优势**：缩放不失真，适合图标和简单图形
```html
<svg width="100" height="100">
  <circle cx="50" cy="50" r="40" stroke="green" stroke-width="4" fill="yellow" />
  <text x="50" y="55" font-size="12" text-anchor="middle">圆形</text>
</svg>
```

### 八、HTML5新增语义化标签
#### 语义化布局示例
```html
<!DOCTYPE html>
<html lang="zh-CN">
<head>
  <title>语义化布局示例</title>
</head>
<body>
  <header>
    <h1>网站标题</h1>
    <nav>
      <ul>
        <li><a href="#">首页</a></li>
        <li><a href="#">产品</a></li>
        <li><a href="#">关于</a></li>
      </ul>
    </nav>
  </header>

  <main>
    <section>
      <h2>主要内容区域</h2>
      <article>
        <h3>文章标题</h3>
        <p>文章内容...</p>
      </article>
    </section>
    
    <aside>
      <h3>侧边栏</h3>
      <p>相关链接...</p>
    </aside>
  </main>

  <footer>
    <p>© 2023 版权所有</p>
  </footer>
</body>
</html>
```

### 九、常用属性详解
#### 1. `class` vs `id`
```html
<!-- 多个元素可使用相同class -->
<div class="container">内容1</div>
<div class="container">内容2</div>

<!-- id必须唯一 -->
<div id="unique-element">特殊元素</div>
```


#### 2. `data-*` 自定义属性
- **用途**：存储页面或应用的自定义数据
```html
<div 
  class="user" 
  data-id="123" 
  data-name="张三" 
  data-is-admin="true"
>
  用户信息
</div>

<script>
  const userDiv = document.querySelector('.user');
  console.log(userDiv.dataset.name); // 输出: 张三
</script>
```

#### 3. `disabled` vs `readonly`
```html
<!-- 禁用状态，值不会被提交 -->
<input type="text" disabled value="禁用">

<!-- 只读状态，值会被提交 -->
<input type="text" readonly value="只读">
```

### 十、废弃标签示例
#### 不推荐使用的标签
```html
<font color="red" size="5">红色文字</font> <!-- 用CSS替代 -->
<center>居中内容</center> <!-- 用text-align:center替代 -->
<strike>删除线</strike> <!-- 用<s>或CSS替代 -->
```

建议通过MDN文档进一步学习各标签的详细用法和浏览器兼容性。





以下是HTML中常用标签的分类总结，附带典型示例和核心属性：


### **一、文档结构标签**
| 标签         | 作用                         | 示例代码                     |
|--------------|------------------------------|------------------------------|
| `<html>`     | 根标签                       | `<html lang="zh-CN">`        |
| `<head>`     | 文档元数据（标题、编码等）   | `<head><title>页面标题</title></head>` |
| `<body>`     | 可见页面内容                 | `<body>主体内容</body>`       |
| `<header>`   | 页面/章节头部                | `<header><h1>网站标题</h1></header>` |
| `<main>`     | 主要内容区域                 | `<main>主要内容</main>`       |
| `<footer>`   | 页面/章节底部                | `<footer>版权信息</footer>`   |
| `<nav>`      | 导航链接                     | `<nav><a href="/">首页</a></nav>` |
| `<section>`  | 独立章节                     | `<section><h2>关于我们</h2></section>` |
| `<article>`  | 独立内容（博客、评论等）     | `<article><h3>文章标题</h3></article>` |
| `<aside>`    | 侧边栏/附加信息              | `<aside>相关链接</aside>`     |


### **二、文本格式化标签**
| 标签         | 语义                         | 显示效果                 |
|--------------|------------------------------|--------------------------|
| `<h1>`~`<h6>`| 标题（重要性递减）           | 大号粗体 → 小号粗体      |
| `<p>`        | 段落                         | 自动换行，段落间距       |
| `<strong>`   | 重要内容                     | **粗体**                 |
| `<em>`       | 强调内容                     | *斜体*                   |
| `<u>`        | 下划线文本                   | <u>下划线</u>            |
| `<s>`        | 已删除文本                   | <s>删除线</s>            |
| `<mark>`     | 标记/高亮文本                | <mark>黄色高亮</mark>    |
| `<small>`    | 次要文本                     | 小号字体                 |
| `<code>`     | 代码片段                     | `monospace` 字体         |
| `<pre>`      | 预格式化文本（保留格式）     | 保留空格和换行           |
| `<blockquote>`| 长引用                     | 缩进显示                 |


### **三、列表标签**
| 标签         | 类型                         | 示例                          |
|--------------|------------------------------|-------------------------------|
| `<ul>`       | 无序列表（项目符号）         | `<ul><li>项1</li></ul>`        |
| `<ol>`       | 有序列表（数字/字母）         | `<ol><li>项1</li></ol>`        |
| `<li>`       | 列表项                       | 嵌套在`<ul>`或`<ol>`内        |
| `<dl>`       | 定义列表（术语+定义）         | `<dl><dt>术语</dt><dd>定义</dd></dl>` |


### **四、链接与媒体标签**
| 标签         | 作用                         | 关键属性                     |
|--------------|------------------------------|------------------------------|
| `<a>`        | 超链接                       | `href`, `target`, `rel`       |
| `<img>`      | 图片                         | `src`, `alt`, `width`, `height` |
| `<video>`    | 视频                         | `src`, `controls`, `autoplay` |
| `<audio>`    | 音频                         | `src`, `controls`             |
| `<iframe>`   | 内联框架（嵌入网页）         | `src`, `width`, `height`      |
| `<source>`   | 媒体资源（多格式支持）       | `src`, `type`                 |


### **五、表单标签**
| 标签         | 作用                         | 常见类型/属性                |
|--------------|------------------------------|------------------------------|
| `<form>`     | 表单容器                     | `action`, `method`            |
| `<input>`    | 输入框                       | `type`（text/password/radio/checkbox等） |
| `<textarea>` | 多行文本框                   | `rows`, `cols`, `placeholder` |
| `<select>`   | 下拉选择框                   | `<option>`子项               |
| `<button>`   | 按钮                         | `type`（submit/reset/button） |
| `<label>`    | 输入框标签                   | `for`（关联input的id）        |
| `<fieldset>` | 表单分组                     | 视觉分组                     |
| `<legend>`   | 字段集标题                   | 配合`<fieldset>`使用          |


### **六、表格标签**
| 标签         | 作用                         | 示例                          |
|--------------|------------------------------|-------------------------------|
| `<table>`    | 表格容器                     | `<table></table>`              |
| `<tr>`       | 表格行                       | `<tr><td>单元格</td></tr>`     |
| `<td>`       | 表格单元格                   | 标准单元格                    |
| `<th>`       | 表头单元格                   | 自动加粗居中                  |
| `<thead>`    | 表头区域                     | 通常包含`<tr>`和`<th>`        |
| `<tbody>`    | 表体区域                     | 主要内容区域                  |
| `<tfoot>`    | 表脚区域                     | 汇总信息                      |
| `<caption>`  | 表格标题                     | 位于表格顶部                  |


### **七、其他功能标签**
| 标签         | 作用                         | 示例                          |
|--------------|------------------------------|-------------------------------|
| `<style>`    | 内联CSS样式                  | `<style>body{color:red;}</style>` |
| `<script>`   | JavaScript代码               | `<script>alert('Hello');</script>` |
| `<meta>`     | 元数据（编码、描述等）       | `<meta charset="UTF-8">`      |
| `<link>`     | 外部资源引用                 | `<link rel="stylesheet" href="style.css">` |
| `<title>`    | 页面标题（标签页显示）       | `<title>我的网站</title>`      |
| `<template>` | 未渲染的HTML模板             | `<template><div>模板内容</div></template>` |
| `<canvas>`   | 动态绘图（JS操作）           | `<canvas id="myCanvas"></canvas>` |
| `<svg>`      | 矢量图形                     | `<svg><circle cx="50" cy="50" r="40"></svg>` |


### **八、HTML5新增语义化标签**
| 标签         | 替代方案（旧写法）           | 优势                         |
|--------------|------------------------------|------------------------------|
| `<header>`   | `<div class="header">`       | 明确头部语义                |
| `<nav>`      | `<div class="nav">`          | 导航结构清晰                |
| `<main>`     | `<div id="main">`            | 主内容唯一标识              |
| `<section>`  | `<div class="section">`      | 逻辑章节划分                |
| `<article>`  | `<div class="article">`      | 独立内容识别                |
| `<aside>`    | `<div class="sidebar">`      | 侧边栏语义化                |
| `<footer>`   | `<div class="footer">`       | 页脚明确标识                |


### **九、废弃/不推荐使用的标签**
| 标签         | 替代方案                     | 原因                         |
|--------------|------------------------------|------------------------------|
| `<font>`     | CSS `font-family`, `color`   | 样式与结构分离              |
| `<center>`   | CSS `text-align: center`     | 同上                        |
| `<u>`        | CSS `text-decoration: underline` | 避免与语义标签混淆      |
| `<strike>`   | `<s>` 或 CSS `text-decoration: line-through` | 同上 |
| `<frame>`    | `<iframe>`                   | 框架布局过时                |


### **十、常用属性速查表**
| 属性         | 适用标签                 | 作用                         |
|--------------|--------------------------|------------------------------|
| `id`         | 所有标签                 | 唯一标识符（CSS/JS选择器）   |
| `class`      | 所有标签                 | 样式类名（可复用）           |
| `style`      | 所有标签                 | 内联样式                     |
| `src`        | `<img>`, `<script>`, `<video>`等 | 资源路径                 |
| `href`       | `<a>`, `<link>`           | 链接地址                     |
| `alt`        | `<img>`                  | 图片替代文本（无障碍）       |
| `title`      | 大多数标签               | 悬停提示文本                 |
| `disabled`   | 表单元素                 | 禁用状态                     |
| `readonly`   | `<input>`, `<textarea>`   | 只读状态                     |
| `required`   | 表单元素                 | 必填项验证                   |
| line-height | 字体相关 | 行高 |
| `data-*`     | 所有标签                 | 自定义数据属性（JS使用）     |

`src` 和 `href` 都是用于引入外部资源的属性，但它们的**功能和加载机制**有本质区别，主要体现在以下几个方面：

#### 1. 核心作用不同

- **`src`（Source）**：表示 “资源的来源”，用于将外部资源**嵌入**到当前文档中，替换自身所在的元素位置。
  例如：脚本、图片、视频等，会成为文档的一部分。
- **`href`（Hypertext Reference）**：表示 “超文本引用”，用于建立当前文档与外部资源之间的**关联或链接**，不会嵌入资源本身。
  例如：链接到其他页面、样式表等，资源是独立的。

#### 2. 加载机制不同

- **`src` 会阻塞页面加载**：
  浏览器解析到 `src` 时，会暂停当前文档的渲染，先加载并执行 / 解析外部资源（如脚本、图片），直到资源处理完成才继续。这是因为 `src` 引入的资源是文档不可缺少的一部分（例如脚本会影响页面逻辑，图片会占据布局空间）。
  示例：

  ```html
  <img src="image.jpg" alt="图片"> <!-- 必须加载图片才能显示 -->
  <script src="script.js"></script> <!-- 必须加载并执行脚本，否则后续依赖脚本的代码可能出错 -->
  ```

- **`href` 不会阻塞页面加载**：
  浏览器解析到 `href` 时，会并行加载外部资源（如样式表），但不会暂停当前文档的渲染，因为 `href` 只是建立关联，资源不直接参与当前文档的结构（例如样式表是修饰作用，不影响文档骨架）。
  示例：

  ```html
  <link href="style.css" rel="stylesheet"> <!-- 并行加载样式表，不阻塞页面渲染 -->
  <a href="page.html">跳转</a> <!-- 仅建立链接，点击才会加载目标页面 -->
  ```

#### 3. 适用场景不同

| 属性   | 适用元素                                                 | 典型用途                                    |
| ------ | -------------------------------------------------------- | ------------------------------------------- |
| `src`  | `<img>`, `<script>`, `<iframe>`, `<video>`, `<audio>` 等 | 引入图片、脚本、嵌入页面、视频、音频等      |
| `href` | `<a>`, `<link>`, `<base>` 等                             | 超链接跳转、引入样式表、设置页面基准 URL 等 |

#### 总结

- **`src` 是 “嵌入”**：把外部资源加载到文档中，成为文档的一部分，会阻塞加载。
- **`href` 是 “关联”**：建立当前文档与外部资源的链接，不嵌入资源，不阻塞加载。

记住一个简单的区分方式：需要 “显示 / 执行内容本身” 用 `src`，需要 “链接到其他资源” 用 `href`

### **十一、常用input属性速查表**

| 分类         | type 值           | 用途说明                                                                 | 典型场景                 |
|--------------|-------------------|--------------------------------------------------------------------------|--------------------------|
| 文本输入类   | `text`            | 单行文本输入（默认类型），可输入任意字符                                 | 用户名、昵称             |
| 文本输入类   | `password`        | 密码输入，内容以掩码（*或•）显示，保护隐私                               | 登录密码、支付密码       |
| 文本输入类   | `search`          | 搜索专用输入框，部分浏览器自带“清除”按钮                                 | 搜索框、关键词输入       |
| 文本输入类   | `tel`             | 电话号码输入，移动端自动弹出数字键盘                                     | 手机号、固定电话输入     |
| 文本输入类   | `email`           | 邮箱地址输入，浏览器自动验证格式（需包含@）                              | 注册邮箱、联系邮箱       |
| 文本输入类   | `url`             | 网址输入，浏览器验证格式（需包含 http:// 或 https://）                    | 个人网站、链接地址       |
| 数字与数值类 | `number`          | 仅允许输入数字，带上下箭头调整，可通过 `min`/`max`/`step` 限制范围        | 年龄、数量、分数         |
| 数字与数值类 | `range`           | 滑块控件，用于选择范围内数值（默认0-100），需通过JS获取具体值             | 音量调节、评分、进度     |
| 日期与时间类 | `date`            | 日期选择器（年/月/日），值格式为 `YYYY-MM-DD`                             | 生日、预约日期           |
| 日期与时间类 | `time`            | 时间选择器（时/分），值格式为 `HH:MM`                                     | 会议时间、闹钟时间       |
| 日期与时间类 | `datetime-local`  | 本地日期时间选择器（年/月/日/时/分），值格式为 `YYYY-MM-DDTHH:MM`          | 截止时间、活动开始时间   |
| 日期与时间类 | `month`           | 月份选择器（年/月），值格式为 `YYYY-MM`                                   | 报表月份、缴费月份       |
| 日期与时间类 | `week`            | 周选择器（年/周），值格式为 `YYYY-Www`（如2024-W32）                       | 周计划、周报表           |
| 选择类       | `checkbox`        | 复选框，允许选择多个选项（同`name`为一组），提交选中项的`value`数组       | 兴趣爱好、权限选择       |
| 选择类       | `radio`           | 单选按钮，同`name`组内仅能选一个，提交选中项的`value`                     | 性别、学历、单选题       |
| 文件上传类   | `file`            | 文件选择控件，可通过 `accept` 限制类型（如`image/*`），`multiple`允许多选  | 头像上传、文档上传       |
| 按钮类       | `submit`          | 提交按钮，点击触发表单提交到`action`地址                                  | 表单提交                 |
| 按钮类       | `reset`           | 重置按钮，点击将表单恢复初始状态                                          | 清空输入内容             |
| 按钮类       | `button`          | 普通按钮，无默认行为，需配合JS实现自定义功能                              | 弹窗触发、步骤切换       |
| 其他特殊类型 | `hidden`          | 隐藏输入框（不显示），随表单提交隐藏数据（如用户ID、token）               | 传递页面间隐藏参数       |
| 其他特殊类型 | `color`           | 颜色选择器，返回十六进制颜色码（如`#ff0000`）                             | 主题色设置、颜色选择     |

**选择器的优先级**

CSS中,权重用数字衡量

元素选择器的权重为: 1	p{}

class选择器的权重为: 10  .{}

id选择器的权重为: 100    #{}

内联样式的权重为: 1000	<p {}>

优先级从高到低: **行内样式 > ID选择器 > 类选择器 > 元素选择器**

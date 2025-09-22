# html

### 自己的笔记

'<head>中的内容一般不会呈现给用户，除了<title>'

***<meta>是单标签<meta charset="utf-8">**,用来指定字体*****

**<link>:rel="",有stylesheet（导入css样式），icon（网页标签图标）**

| `id`    | 所有标签                         | 唯一标识符（CSS/JS选择器） |
| ------- | -------------------------------- | -------------------------- |
| `class` | 所有标签                         | 样式类名（可复用）         |
| `style` | 所有标签                         | 内联样式                   |
| `src`   | `<img>`, `<script>`, `<video>`等 | 资源路径                   |
| `href`  | `<a>`, `<link>`                  | 链接地址                   |
| `alt`   | `<img>`                          | 图片替代文本（无障碍）     |
| `title` | 大多数标签                       | 悬停提示文本               |

### label作用：

1. **扩大点击区域**
   默认情况下，只有点击表单元素（如单选按钮、复选框的小方框）才能触发交互。关联 `<label>` 后，点击标签文字也会触发对应的表单元素（如选中 / 取消复选框），大大提升了操作便捷性，尤其适合移动设备。

   示例：
   未关联 `<label>` 时，只能点击小方框；关联后，点击 "同意协议" 文字也能勾选复选框。

   ```html
   <label for="agree">
     <input type="checkbox" id="agree"> 同意协议
   </label>
   ```

2. **提升可访问性**
   屏幕阅读器会将 `<label>` 的文字与关联的表单元素关联起来，当用户聚焦到表单元素时，阅读器会朗读标签内容，帮助视力障碍用户理解输入项的含义。

3. **明确语义关联**
   通过 `<label>` 明确表单元素与描述文字的对应关系，使 HTML 结构更清晰，便于开发者维护和搜索引擎解析。

4. **避免歧义**
   对于多个相似的表单元素（如一组单选按钮），`<label>` 能清晰区分每个选项的含义，避免用户混淆。

<label>可以使用for属性关联其他标签的id属性，但是当其他标签位于label内部时可以省略

其内部一般放入input和纯文本，不要放入其他块级元素如div，和交互标签如button。

| 标签        | 核心语义                | 适用场景                                 | 关键特征                             |
| ----------- | ----------------------- | ---------------------------------------- | ------------------------------------ |
| `<section>` | 有主题的 “内容区块”     | 章节、标签页内容、表单分组、产品列表区域 | 通常包含标题，内容有明确主题         |
| `<div>`     | 无任何语义的 “容器”     | 纯样式 / 布局辅助（如包裹元素调整间距）  | 仅用于 CSS 或 JS 操作，无语义含义    |
| `<article>` | 可独立分发的 “完整内容” | 博客文章、新闻报道、评论、产品详情       | 内容可单独存在（如单独分享一篇文章） |

在 CSS 中，`position` 属性用于控制元素在页面中的**定位方式**，决定元素如何脱离正常文档流、以及基于哪个参考对象进行位置偏移。它是布局设计的核心属性之一，共有 5 个取值，不同取值对应完全不同的定位逻辑。

### 一、`position` 的 5 个取值及核心特性

| 取值       | 是否脱离文档流 | 定位参考对象                                                 | 核心用途                                           |
| ---------- | -------------- | ------------------------------------------------------------ | -------------------------------------------------- |
| `static`   | ❌ 不脱离       | 无（遵循正常文档流）                                         | 默认值，元素按 HTML 结构顺序排列                   |
| `relative` | ❌ 不脱离       | 元素自身的 “初始位置”                                        | 微调元素位置、作为绝对定位（`absolute`）的参考容器 |
| `absolute` | ✅ 完全脱离     | 最近的 “已定位祖先元素”（非 static），若无则为根元素（`<html>`） | 精准定位元素（如弹窗、悬浮菜单）                   |
| `fixed`    | ✅ 完全脱离     | 浏览器视口（viewport）                                       | 固定元素位置（如顶部导航栏、回到顶部按钮）         |
| `sticky`   | ⚠️ 半脱离       | 父容器的 “可视区域”                                          | 滚动时 “吸顶 / 吸底”（如列表标题、筛选栏）         |

CSS 属性表格，包含属性名称、核心作用及典型示例，便于快速查阅和使用：

| 分类       | CSS 属性                      | 核心作用                                                     | 典型示例                                                     |
| ---------- | ----------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 盒模型基础 | `width`                       | 定义元素 **内容区域** 的宽度（默认单位：px，支持 %、rem 等） | `width: 300px;` / `width: 80%;`                              |
|            | `height`                      | 定义元素 **内容区域** 的高度                                 | `height: 200px;` / `height: auto;`                           |
|            | `padding`                     | 元素 **内容与边框之间的内边距**（可分方向：top/right/bottom/left） | `padding: 10px 15px;`（上下 10px，左右 15px）                |
|            | `margin`                      | 元素 **与其他元素之间的外边距**（可分方向，支持`auto`实现水平居中） | `margin: 0 auto;` / `margin-bottom: 20px;`                   |
|            | `border`                      | 元素边框（简写，包含`border-width`+`border-style`+`border-color`） | `border: 2px solid #333;`                                    |
|            | `border-radius`               | 为元素添加 **圆角**（值越大，圆角越明显，支持圆形 / 椭圆）   | `border-radius: 8px;` / `border-radius: 50%;`                |
|            | `box-sizing`                  | 控制盒模型计算方式（解决宽高包含范围问题）                   | `box-sizing: border-box;`（推荐，含 padding+border）         |
| 定位与显示 | `position`                    | 定义元素定位类型，控制元素在页面中的位置                     | `position: relative;` / `position: absolute;`                |
|            | `top`/`right`/`bottom`/`left` | 配合`position`（非 static），精确控制元素的偏移位置          | `top: 20px; right: 10px;`（相对定位偏移）                    |
|            | `display`                     | 定义元素的 **显示模式**（控制元素是否换行、是否可同行排列）  | `display: block;` / `display: flex;` / `display: none;`      |
|            | `z-index`                     | 控制元素的 **层叠顺序**（值越大，层级越高，仅对定位元素生效） | `z-index: 10;`（层级高于 z-index:5 的元素）                  |
|            | `float`                       | 使元素 **脱离文档流浮动**（左 / 右浮动，常用于早期布局，现多被 flex 替代） | `float: left;` / `clear: both;`（清除浮动）                  |
| 背景样式   | `background-color`            | 定义元素的 **背景颜色**（支持十六进制、RGB、英文单词）       | `background-color: #f5f5f5;` / `background-color: rgba(0,0,0,0.5);` |
|            | `background-image`            | 为元素设置 **背景图片**（支持本地图片或网络图片）            | `background-image: url("bg.jpg");`                           |
|            | `background-size`             | 控制背景图片的 **尺寸**（cover：覆盖容器；contain：完整显示） | `background-size: cover;` / `background-size: 100% 100%;`    |
|            | `background-position`         | 控制背景图片的 **位置**（支持方位词或数值）                  | `background-position: center;` / `background-position: 20px 30px;` |
|            | `background-repeat`           | 控制背景图片是否 **重复显示**（no-repeat：不重复；repeat-x：水平重复） | `background-repeat: no-repeat;`                              |
| 文本样式   | `color`                       | 定义 **文本颜色**（同 background-color，支持多种颜色格式）   | `color: #333;` / `color: red;`                               |
|            | `font-size`                   | 定义文本 **字体大小**（默认 16px，推荐用 rem 适配）          | `font-size: 16px;` / `font-size: 1.2rem;`                    |
|            | `font-weight`                 | 定义文本 **粗细**（normal：正常；bold：加粗；数值：100-900） | `font-weight: bold;` / `font-weight: 600;`                   |
|            | `font-family`                 | 定义文本 **字体家族**（推荐设置 fallback 字体，避免字体缺失） | `font-family: "Microsoft YaHei", sans-serif;`                |
|            | `text-align`                  | 控制文本 **水平对齐方式**（left/center/right/justify）       | `text-align: center;`（文本居中）                            |
|            | `line-height`                 | 定义文本 **行高**（控制行间距，值为数字时是 font-size 的倍数） | `line-height: 1.5;` / `line-height: 24px;`                   |
|            | `text-decoration`             | 为文本添加装饰（underline：下划线；none：取消下划线，常用于链接） | `text-decoration: none;`（取消链接下划线）                   |
| 弹性布局   | `display: flex`               | 将元素设置为 **弹性容器**，子元素自动成为弹性项（现代布局核心） | `display: flex;`（父容器添加）                               |
|            | `justify-content`             | 控制弹性项 **水平方向** 的对齐方式（主轴对齐）               | `justify-content: space-between;`（两端对齐）                |
|            | `align-items`                 | 控制弹性项 **垂直方向** 的对齐方式（交叉轴对齐）             | `align-items: center;`（垂直居中）                           |
|            | `flex-direction`              | 控制弹性项的 **排列方向**（row：水平；column：垂直）         | `flex-direction: column;`（垂直排列）                        |
|            | `flex`                        | 控制弹性项的 **伸缩比例**（简写，包含 flex-grow/flex-shrink/flex-basis） | `flex: 1;`（占满剩余空间） / `flex: 0 0 200px;`（固定宽度）  |
| 其他常用   | `cursor`                      | 定义鼠标悬浮在元素上时的 **光标样式**（pointer：手型，常用于按钮 / 链接） | `cursor: pointer;` / `cursor: default;`                      |
|            | `opacity`                     | 控制元素的 **透明度**（0：完全透明；1：不透明，影响子元素）  | `opacity: 0.8;`（80% 不透明度）                              |
|            | `overflow`                    | 控制元素内容 **溢出时的处理方式**（hidden：隐藏；auto：滚动条） | `overflow: hidden;` / `overflow-y: auto;`                    |
|            | `transition`                  | 为元素样式变化添加 **过渡动画**（平滑切换，无需 JS）         | `transition: all 0.3s ease;`（所有样式 300ms 平滑过渡）      |

position详解：

`position: relative` 和 `position: absolute` 的配合是 CSS 定位的经典用法，核心规则是：**绝对定位元素（absolute）会优先相对于 “最近的、设置了 position: relative/absolute/fixed/sticky 的祖先元素” 进行定位；如果没有这样的祖先元素，则相对于浏览器窗口（body）定位**。

# `display`详解：

### 一、基础显示类型（单值）

#### 1. `display: none`

- **作用**：完全隐藏元素，不占据页面空间（与 `visibility: hidden` 不同，后者仍占空间）。

- **场景**：动态显示 / 隐藏元素（如弹窗、折叠菜单）。

- 示例

  ```css
  .hidden-element {
    display: none; /* 元素完全消失，不占布局空间 */
  }
  ```

#### 2. `display: block`（块级元素）

- 特性

  - 独占一行（前后自动换行）。
  - 可设置宽高（`width`/`height` 有效）。
  - 内外边距（`margin`/`padding`）会影响周围元素布局。

- **默认元素**：`div`、`p`、`h1-h6`、`ul`、`li`、`footer` 等。

- **场景**：用于构建页面结构（如容器、段落、标题）。

- 示例

  ```css
  .block-example {
    display: block;
    width: 200px; /* 有效 */
    height: 100px; /* 有效 */
    margin: 10px 0; /* 上下外边距生效 */
  }
  ```

#### 3. `display: inline`（行内元素）

- 特性

- 不独占一行，与其他行内元素并排显示。

  - **不能设置宽高**（`width`/`height` 无效）。
  - 左右外边距（`margin-left`/`right`）有效，但上下外边距（`margin-top`/`bottom`）无效。
  - 内边距（`padding`）有效，但可能重叠其他元素。

- **默认元素**：`span`、`a`、`strong`、`em`、`img`（特殊行内元素，可设宽高）等。

- **场景**：用于文本内的局部样式（如高亮、链接）。

- 示例

  ```css
  .inline-example {
    display: inline;
    width: 200px; /* 无效 */
    margin: 10px; /* 仅左右生效 */
    padding: 5px; /* 有效，但可能覆盖其他内容 */
  }
  ```

#### 4. `display: inline-block`（行内块元素）

- 特性

  - 兼具 `inline` 和 `block` 的特点：并排显示（不独占一行），且可设置宽高。
  - 内外边距均有效，不会重叠其他元素。

- **场景**：需要并排显示且自定义尺寸的元素（如按钮、图标、导航项）。

- 示例

  ```css
  .inline-block-btn {
    display: inline-block;
    width: 120px; /* 有效 */
    height: 40px; /* 有效 */
    margin: 0 10px; /* 左右间距，实现按钮并排 */
  }
  ```

### 二、CSS 表格布局（模拟表格）

#### 5. `display: table` 及相关值

用于模拟 HTML 表格的布局结构，适合需要表格样式但不想用 `<table>` 标签的场景。

- `display: table`：模拟 `<table>` 标签（容器）。

- `display: table-row`：模拟 `<tr>` 标签（行）。

- `display: table-cell`：模拟 `<td>` 标签（单元格）。

- `display: table-header-group`：模拟 `<thead>`。

- `display: table-footer-group`：模拟 `<tfoot>`。

- **特性**：

  - 单元格自动等高、等宽（类似表格）。
  - 支持 `vertical-align` 垂直对齐（常用于居中）。

- **示例**：实现三列等高布局

  ```html
  <div class="table-container">
    <div class="table-row">
      <div class="table-cell">列1</div>
      <div class="table-cell">列2（内容更多）</div>
      <div class="table-cell">列3</div>
    </div>
  </div>
  ```

  ```css
  .table-container { display: table; width: 100%; }
  .table-row { display: table-row; }
  .table-cell { 
    display: table-cell; 
    padding: 10px; 
    border: 1px solid #ccc; 
    vertical-align: middle; /* 垂直居中 */
  }
  ```

### 三、弹性盒布局（Flexbox）

#### 6. `display: flex`（容器）和 `display: inline-flex`

Flexbox 是一维布局模型，适合对齐、分布元素（行或列），是现代布局的首选。

- `display: flex`：容器为块级，独占一行。

- `display: inline-flex`：容器为行内级，与其他元素并排。

- **核心特性**：

  - 子元素（flex 项）自动排列（默认水平方向）。
  - 可通过 `justify-content`（水平对齐）、`align-items`（垂直对齐）控制对齐方式。
  - 子元素尺寸可自适应容器空间。

- **示例**：水平居中且均匀分布的导航栏

  ```css
  .nav {
    display: flex; /* 容器设为 flex */
    justify-content: space-between; /* 子元素两端对齐 */
    align-items: center; /* 垂直居中 */
    padding: 0 20px;
    height: 60px;
  }
  .nav-item {
    margin: 0 10px; /* 子元素间距 */
  }
  ```

### 四、网格布局（Grid）

#### 7. `display: grid`（容器）和 `display: inline-grid`

Grid 是二维布局模型，适合复杂的多行多列布局（如仪表盘、卡片网格）。

- `display: grid`：容器为块级。

- `display: inline-grid`：容器为行内级。

- **核心特性**：

  - 同时控制行和列的布局。
  - 通过 `grid-template-columns`/`rows` 定义列宽和行高。
  - 子元素（grid 项）可跨行列排列。

- **示例**：响应式卡片网格（3 列布局）

  ```css
  .card-grid {
    display: grid; /* 容器设为 grid */
    grid-template-columns: repeat(3, 1fr); /* 3列，每列等宽 */
    gap: 20px; /* 卡片间距 */
    padding: 20px;
  }
  .card {
    padding: 15px;
    border: 1px solid #eee;
  }
  ```

### 五、其他特殊值

#### 8. `display: contents`

- **作用**：使元素本身不产生布局盒模型，但保留其子元素的布局。简单说：“元素消失，但子元素仍在原位置”。

- **场景**：解决嵌套容器对 Flex/Grid 布局的干扰。

- 示例

  ```css
  .wrapper {
    display: flex;
  }
  .wrapper > div {
    display: contents; /* 该 div 不产生布局，子元素直接参与 flex 布局 */
  }
  ```

#### 9. `display: list-item`

- **作用**：使元素表现为列表项（类似 `<li>`），自动生成项目符号。

- 示例

  ```css
  .custom-list-item {
    display: list-item;
    list-style-type: square; /* 项目符号样式 */
    margin-left: 20px; /* 缩进 */
  }
  ```

  

#### 10. `display: flow-root`

- **作用**：创建一个新的块级格式化上下文（BFC），解决父元素高度塌陷问题（替代传统的 `overflow: hidden` 方案）。

- 示例

- 清除浮动影响

  ```css
  .parent {
    display: flow-root; /* 自动包含浮动子元素的高度 */
  }
  .child {
    float: left; /* 子元素浮动 */
    width: 50%;
  }
  ```

### 总结：如何选择 `display` 值？

| 需求场景                | 推荐值         |
| ----------------------- | -------------- |
| 隐藏元素                | `none`         |
| 页面结构容器            | `block`        |
| 文本内局部样式          | `inline`       |
| 并排显示且需自定义尺寸  | `inline-block` |
| 一维布局（行 / 列对齐） | `flex`         |
| 二维布局（网格排列）    | `grid`         |
| 模拟表格布局            | `table` 系列   |
| 清除浮动 / 创建 BFC     | `flow-root`    |

## @用法

在 CSS 中，`@` 符号开头的语法被称为 **at-rule（at 规则）**，它们不是选择器，而是用于控制 CSS 行为、引入资源、条件判断等特殊功能的指令。以下是所有常见 `@` 规则的详细用法和场景：

### 一、基础元数据类

#### 1. `@charset` - 声明字符编码

- **作用**：定义样式表使用的字符编码，确保浏览器正确解析中文等非 ASCII 字符。

- 语法

  ```css
  @charset "编码格式";
  ```

- 注意

  - 必须放在样式表的**最开头**（前面不能有任何字符，包括空格、注释）。
  - 仅对当前样式表有效，且浏览器兼容性良好。

- 示例

  ```css
  @charset "UTF-8"; /* 声明使用 UTF-8 编码（推荐） */
  @charset "GBK"; /* 用于仅包含简体中文的场景 */
  ```

#### 2. `@import` - 引入外部样式表

- **作用**：从外部文件导入 CSS 规则，实现样式模块化。

- 语法

  ```css
  @import url("文件路径") [媒体查询条件];
  ```

- 注意

  - 必须放在样式表的开头（`@charset` 之后，其他规则之前）。
  - 会增加 HTTP 请求，可能影响性能（推荐用 `<link>` 标签替代）。

- 示例

  ```css
  @import url("reset.css"); /* 导入重置样式 */
  @import url("print.css") print; /* 仅在打印时应用 */
  @import url("mobile.css") screen and (max-width: 768px); /* 小屏幕生效 */
  ```

  

### 二、响应式与条件判断类

#### 3. `@media` - 媒体查询（核心）

- **作用**：根据设备特性（屏幕尺寸、分辨率等）应用不同样式，是响应式设计的基础。

- 语法

  ```css
  @media [媒体类型] and (条件) {
    /* 满足条件时应用的样式 */
  }
  ```

  

- 常用媒体类型：

  - `screen`：屏幕设备（默认）
  - `print`：打印预览
  - `all`：所有设备

- 常用条件：

  - `max-width`/`min-width`：屏幕宽度
  - `orientation: portrait/landscape`：竖屏 / 横屏
  - `hover: hover`：设备支持悬停（如桌面端 vs 移动端）

- 示例

  ```css
  /* 屏幕宽度 ≤768px 时（移动端） */
  @media (max-width: 768px) {
    .nav { display: none; } /* 隐藏导航栏 */
    .mobile-menu { display: block; } /* 显示移动端菜单 */
  }
  
  /* 支持悬停的设备（如桌面端） */
  @media (hover: hover) {
    .button:hover { transform: scale(1.05); }
  }
  ```

#### 4. `@supports` - 特性检测

- **作用**：检测浏览器是否支持某个 CSS 特性，实现渐进式增强。

- 语法

  ```css
  @supports (CSS特性) {
    /* 支持时应用的样式 */
  }
  @supports not (CSS特性) {
    /* 不支持时的降级方案 */
  }
  ```

- 示例

  ```css
  /* 如果支持 grid 布局 */
  @supports (display: grid) {
    .container {
      display: grid;
      gap: 20px;
    }
  }
  
  /* 不支持 grid 时用 flex 替代 */
  @supports not (display: grid) {
    .container {
      display: flex;
      flex-wrap: wrap;
      margin: -10px;
    }
    .item { margin: 10px; }
  }
  ```

### 三、资源与样式定义类

#### 5. `@font-face` - 自定义字体

- **作用**：引入网页字体（非系统默认字体），实现个性化文字样式。

- 语法

  ```css
  @font-face {
    font-family: "字体名称"; /* 自定义名称（用于后续引用） */
    src: url("字体文件路径") format("字体格式"); /* 字体源及格式 */
    font-weight: 400; /* 字体粗细（normal/bold/100-900） */
    font-style: normal; /* 字体样式（normal/italic/oblique） */
    font-display: swap; /* 加载策略（swap：先显示默认字体，加载完成后替换） */
  }
  ```

- 常用字体格式：

  - `woff2`：现代浏览器首选（体积小、压缩率高）
  - `woff`：兼容旧版浏览器
  - `ttf`/`otf`：备选格式

- 示例

  ```css
  @font-face {
    font-family: "Inter";
    src: url("inter.woff2") format("woff2"),
         url("inter.woff") format("woff");
    font-weight: 400; /* 常规字重 */
    font-style: normal;
  }
  
  /* 使用自定义字体 */
  body {
    font-family: "Inter", sans-serif;
  }
  ```

#### 6. `@counter-style` - 自定义列表计数器

- **作用**：定义自定义的列表项标记（如序号、符号），扩展默认的 `list-style`。

- 语法

  ```css
  @counter-style 名称 {
    system: 计数系统; /* 如 cyclic（循环）、numeric（数字） */
    symbols: 符号列表; /* 用于计数的符号 */
    suffix: 后缀; /* 符号后的字符（如 "."、")"） */
  }
  ```

- 示例

  ```css
  /* 定义中文数字计数器 */
  @counter-style chinese {
    system: numeric;
    symbols: "一" "二" "三" "四" "五";
    suffix: "、";
  }
  
  /* 使用自定义计数器 */
  .chinese-list {
    list-style: chinese;
  }
  ```

### 四、动画与过渡类

#### 7. `@keyframes` - 定义动画关键帧

- **作用**：创建 CSS 动画的关键帧序列，控制动画的中间状态。

- 语法

  ```css
  @keyframes 动画名称 {
    0% { /* 动画开始状态 */ }
    50% { /* 动画中间状态 */ }
    100% { /* 动画结束状态 */ }
  }
  ```

- **配合使用**：通过 `animation` 属性将动画应用到元素。

- 示例

  ```css
  /* 定义淡入动画 */
  @keyframes fadeIn {
    0% { opacity: 0; transform: translateY(20px); }
    100% { opacity: 1; transform: translateY(0); }
  }
  
  /* 应用动画 */
  .card {
    animation: fadeIn 0.5s ease-out forwards; /* forwards：保持结束状态 */
  }
  ```

### 五、打印相关类

#### 8. `@page` - 打印页面设置

- **作用**：控制打印时的页面样式（页边距、纸张方向等）。

- 语法

  ```css
  @page {
    /* 全局打印设置 */
    margin: 2cm; /* 页边距 */
    size: A4 portrait; /* 纸张大小和方向（portrait/landscape） */
  }
  
  /* 伪类扩展 */
  @page :first { /* 第一页特殊设置 */ }
  @page :left { /* 左页（双面打印） */ }
  @page :right { /* 右页（双面打印） */ }
  ```

- 示例：

  ```css
  @page {
    margin: 1.5cm;
  }
  
  /* 第一页顶部边距更大 */
  @page :first {
    margin-top: 5cm;
  }
  
  /* 打印时隐藏不必要元素 */
  @media print {
    .header, .footer { display: none; }
  }
  ```

### 六、其他特殊规则

#### 9. `@namespace` - XML 命名空间（极少用）

- **作用**：在处理 XML 或 XHTML 文档时，定义命名空间，避免标签冲突。

- 示例：

  ```css
  @namespace html "http://www.w3.org/1999/xhtml"; /* HTML 命名空间 */
  @namespace svg "http://www.w3.org/2000/svg"; /* SVG 命名空间 */
  
  /* 仅匹配 HTML 中的 a 标签 */
  html|a { color: blue; }
  ```

#### 10. `@layer` - 样式层（CSS 新特性）

- **作用**：管理样式优先级，避免 `!important` 滥用。

- 语法：

  ```css
  /* 定义层并分配样式 */
  @layer base {
    body { margin: 0; }
  }
  
  @layer components {
    .button { padding: 8px 16px; }
  }
  
  /* 层的优先级：后定义的层 > 先定义的层 */
  ```

## **定义全局 CSS 变量**

`:root` 是一个伪类选择器，用于匹配文档的根元素，优先级低于主动设置的样式，其中可以通过`--`+属性来定义全局变量，在后续属性可以使用var(属性)来引用，类似于宏定义

# JS

### 输出

1. **alert()**
   - 功能：在浏览器顶部弹出一个模态对话框，显示指定内容
   - 特点：
     - 会中断程序执行，直到用户点击 "确定" 按钮
     - 无论传入什么类型的参数，都会先转换为字符串再显示
     - 对话框样式由浏览器决定，无法自定义
   - 用途：主要用于简单的信息提示或调试，不适合频繁使用，会影响用户体验
   
2. **document.write()**

   - 功能：向当前文档中写入内容，直接输出到页面上
   - 特点：
     - 写入的内容会成为 HTML 文档的一部分，可以包含 HTML 标签
     - 如果在文档加载完成后使用，会覆盖整个文档内容
     - 输出位置与脚本执行位置相关
   - 用途：通常用于页面加载过程中动态生成内容，现代开发中较少使用，一般推荐使用 DOM 操作替代

3. **console.log()**

   - 功能：向浏览器的开发者工具控制台输出内容

   - 特点：

     - 输出内容仅在开发者工具的控制台中可见，普通用户看不到
     - 可以输出各种数据类型，包括对象、数组等，不会强制转换为字符串
     - 不会影响页面展示和程序执行流程

   - 用途：主要用于开发调试，输出变量值、执行流程等信息，是开发过程中最常用的调试手段
###  数据类型

1. **Number（数字）**
   包括整数、浮点数、NaN（非数字）和 Infinity（无穷大）
   示例：`let a = 100; let b = 3.14; let c = NaN;`
   
1. **String（字符串）**
   由单引号、双引号或反引号包裹的文本
    示例：`let str1 = 'hello'; let str2 = "world"; let str3 = `JS`;`
   
2. **Boolean（布尔值）**
   只有两个值：`true`（真）和 `false`（假）
    示例：`let isTrue = true; let isFalse = false;`
   
3. **Undefined（未定义）**
   表示变量声明后未赋值时的默认值
   示例：`let x; console.log(x); // undefined`
   
4. **Null（空值）**
   表示一个空的或不存在的引用，主动赋值表示 "无值"
   示例：`let obj = null;`
   
###  let，var和const

        `var`、`let`、`const` 三者核心区别： 

   1. **作用域**：   - `var`：函数作用域   - `let`/`const`：块级作用域（`{}` 内有效）
      
   1. **变量提升**：   - `var`：声明提升，可提前访问（undefined）   - `let`/`const`：有暂时性死区，声明前访问报错 
      
   2. **赋值特性**：   - `var`/`let`：可重复赋值   - `const`：声明时必须赋值，且不可重新赋值（但对象属性可修改）
      
   3. **重复声明**：   - `var`：允许同一作用域重复声明   - `let`/`const`：同一作用域禁止重复声明 现代开发建议：优先用 `const`（常量）和 `let`（变量），避免 `var`。杂项


​           
​        
###  杂项 

`typeof` 是 JavaScript 中用于检测数据类型的运算符，语法为 `typeof 变量/值`，返回一个表示数据类型的字符串。

```html
!undefined // true

!null // true

!0 // true

!NaN // true

!"" // true

!54 // false

!'hello' // false
```

### 字符串

s.length   返回长度

s.charAt(x)   返回x位置的字符  **不存在时返回空**

s.concat(s2,s3,s4...)   连接两个字符串 

s.substring(x, y)   返回从x-y的字符

s.trim()   返回去除字符串两端空格/制表符/换行符等等

s.split(' ')   按照指定字符分割字符串，如果为空，返回单个字符

### 数组

js中数组较为自由，字符串也可以作为数组元素，还可以先定义后赋值。

a.length  返回成员数量

Array.isArray() 判断参数是不是数组

a.push()                  在数组末尾添加元素，**会改变长度**

a.pop()     删除最后一个元素



var d = new Date('January 6, 2022');
js中声明时间有很多格式，但是最后都会存储为时间戳，有函数可以从时间戳中返回时间

getTime()：返回实例距离1970年1月1日00:00:00的毫秒数

`getDate()：`返回实例对象对应每个月的几号（从1开始）

getDay()：返回星期几，星期日为0，星期一为1，以此类推

getYear()：返回距离1900的年数

getFullYear()：返回四位的年份

getMonth()：返回月份（0表示1月，11表示12月）

getHours()：返回小时（0-23）

getMilliseconds()：返回毫秒（0-999）

getMinutes()：返回分钟（0-59）

getSeconds()：返回秒（0-59）



**不行，先学需要的（）**

document.getElementsByTagName ()

搜索 HTML 标签名，返回符合条件的元素。它的返回值是一个类似数组对象（ HTMLCollection 实例），时反映 HTML 文档的变化。如果没有任何匹配的元素，就返回一个空集

document.getElementsByClassName()

 返回一个类似数组的对象,包括了所有class名字符合指定条件的元素，

## =>

### 一、基本语法

箭头函数的核心是用 `=>` 连接参数列表和函数体，基本形式如下：

#### 1. 完整形式（多参数 + 多语句函数体）

```javascript
// 传统函数
const add = function(a, b) {
  return a + b;
};

// 箭头函数等效写法
const add = (a, b) => {
  return a + b;
};
```

#### 2. 简化形式（单表达式函数体）

如果函数体只有**一条返回语句**，可以省略 `{}` 和 `return`：

```javascript
const add = (a, b) => a + b; // 自动返回表达式结果
```

#### 3. 单参数简化

如果只有**一个参数**，可以省略参数列表的 `()`：

```javascript
const double = num => num * 2; // 等效于 (num) => num * 2
```

#### 4. 无参数

无参数时，必须保留 `()`：

```javascript
const getRandom = () => Math.random();
```

#### 5. 返回对象字面量

如果直接返回对象，需要用 `()` 包裹对象（避免 `{}` 被解析为函数体）：

```javascript
const getUser = () => ({ name: "Alice", age: 20 });
// 错误写法：const getUser = () => { name: "Alice" };（会被解析为函数体）
```

### 二、与传统函数的核心区别

1. **没有自己的 `this`**
   箭头函数不会绑定 `this`，它的 `this` 是**继承自外层作用域**（定义时的上下文），且永远不会改变。
   这解决了传统函数中 `this` 指向易变的问题（例如在回调函数中）。

   ```javascript
   const obj = {
     name: "Bob",
     // 传统函数：this 指向调用者（obj）
     sayHi1: function() {
       console.log(this.name); // "Bob"
     },
     // 箭头函数：this 继承自外层（全局作用域，非 obj）
     sayHi2: () => {
       console.log(this.name); // undefined（浏览器中 this 指向 window）
     }
   };
   ```

2. **不能作为构造函数**
   箭头函数不能用 `new` 调用，否则会报错（因为它没有 `prototype`）。

   ```javascript
   const Person = () => {};
   new Person(); // 报错：Person is not a constructor
   ```

3. **没有 `arguments` 对象**
   无法通过 `arguments` 获取参数列表，需用**剩余参数（`...args`）** 替代。

   ```javascript
   // 传统函数
   function sum1() {
     return Array.from(arguments).reduce((a, b) => a + b, 0);
   }
   
   // 箭头函数
   const sum2 = (...args) => {
     return args.reduce((a, b) => a + b, 0);
   };
   ```

4. **不能使用 `yield`**
   箭头函数不能作为生成器（Generator）函数。

`setTimeout`函数
`setTimeout(function,x);`  function是需要延迟之后执行的代码，x是时间（毫秒，1000=1秒）

- 

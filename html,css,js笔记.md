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

getDate()：返回实例对象对应每个月的几号（从1开始）

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

setTimeout函数
setTimeout(function,x);  function是需要延迟之后执行的代码，x是时间（毫秒，1000=1秒）


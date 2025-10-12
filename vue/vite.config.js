// import { fileURLToPath, URL } from 'node:url'

// import { defineConfig } from 'vite'
// import vue from '@vitejs/plugin-vue'
// import vueDevTools from 'vite-plugin-vue-devtools'

// // https://vite.dev/config/
// export default defineConfig({
//   plugins: [
//     vue(),
//     vueDevTools(),
//   ],
//   resolve: {
//     alias: {
//       '@': fileURLToPath(new URL('./src', import.meta.url))
//     },
//   },
// })



// import { defineConfig } from 'vite'
// import vue from '@vitejs/plugin-vue' // 若你是 Vue 项目，必须有这行；非 Vue 项目可删除

// export default defineConfig({
//   plugins: [vue()], // Vue 项目必备，非 Vue 项目可删除
//   base: './', // 关键配置：设置资源引用为“相对路径”
//   build: {
//     outDir: 'dist', // 打包输出目录（默认就是 dist，可自定义）
//     assetsDir: 'assets' // 资源（CSS/JS/图片）存放目录（默认 assets，无需修改）
//   }
// })
// vue.config.js



import { defineConfig } from 'vite';
import vue from '@vitejs/plugin-vue';
import path from 'path';

export default defineConfig({
  plugins: [vue()],
  resolve: {
    alias: {
      '@': path.resolve(__dirname, 'src'),
    },
  },
  // 其他配置项...
});
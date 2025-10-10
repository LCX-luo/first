<!-- <script setup>
import HelloWorld from './components/HelloWorld.vue'
import TheWelcome from './components/TheWelcome.vue'
</script>

<template>
  <header>
    <img alt="Vue logo" class="logo" src="./assets/logo.svg" width="125" height="125" />

    <div class="wrapper">
      <HelloWorld msg="11111" />
    </div>
  </header>

  <main>
    <TheWelcome />
  </main>
</template>

<style scoped>
header {
  line-height: 1.5;
}

.logo {
  display: block;
  margin: 0 auto 2rem;
}

@media (min-width: 1024px) {
  header {
    display: flex;
    place-items: center;
    padding-right: calc(var(--section-gap) / 2);
  }

  .logo {
    margin: 0 2rem 0 0;
  }

  header .wrapper {
    display: flex;
    place-items: flex-start;
    flex-wrap: wrap;
  }
}
</style> -->
<template>
  <!-- 按顺序引入所有现有组件 -->
  <Header/>
  <main-introducemyself />
  <skills />
  <carousel />
  <contact />
  <message />
  <threedcard />
</template>

<script>

import './components/htmlroot.css'
import Header from './components/header.vue'
import mainIntroducemyself from './components/main-introducemyself.vue'
import skills from './components/skills.vue'
import carousel from './components/carousel.vue'
import contact from './components/contact.vue'
// import movebutton from './components/movebuttonbackground.vue'
import message from './components/message.vue'
import threedcard from './components/3dcard.vue'

export default {
  components: {
    Header,
    mainIntroducemyself,
    skills,
    carousel,
    contact,
    // movebutton,
    message,
    // 注册所有组件
    threedcard
  }
}
</script>

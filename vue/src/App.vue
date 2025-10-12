<template>
  <!-- 按顺序引入所有现有组件 -->
  <Header />
  <main-introducemyself />
  <!-- <skills /> -->
  <new3dcard />
  <carousel />
  <contact />
  <message />
  <!-- <threedcard /> -->

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
import new3dcard from './components/new3dcard.vue'
export default {
  components: {
    Header,
    mainIntroducemyself,
    skills,
    carousel,
    contact,
    // movebutton,
    message,
    threedcard,
    new3dcard
  }
}
</script>

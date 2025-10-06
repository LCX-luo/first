// import './assets/main.css'

import { createApp } from 'vue'
// import App from './App.vue'

// createApp(App).mount('#app')
import './htmlroot.css'
import Header from './header.vue'
createApp(Header).mount('#htmlheader')


import mainIntroducemyself from './main-introducemyself.vue'
createApp(mainIntroducemyself).mount('#main-introducemyself')

import skills from './skills.vue'  
createApp(skills).mount('#skills')

import carousel from './carousel.vue'
createApp(carousel).mount('#carousel')

import contact from './contact.vue'
createApp(contact).mount('#contact')

import movebuttonbackground from './movebuttonbackground.vue'
createApp(movebuttonbackground).mount('#movebuttonbackground')  

import message from './message.vue'
createApp(message).mount('#message')
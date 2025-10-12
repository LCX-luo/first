<template>
  <div id="skills" class="skills-section">
    <h2 class="section-title">我的技能</h2>
    <!-- 3D技能卡片容器 -->
    <div class="skills-3d-container">
      <!-- 3D旋转容器 -->
      <div class="rotation-container" :class="{ paused: isPaused }" 
        @mouseenter="isPaused = true" @mouseleave="isPaused = false">
        <!-- 卡片列表 -->
        <div class="cards-wrapper" :style="{ transform: `rotateY(${rotationDeg}deg)` }">
          <!-- 各个技能卡片 -->
          <div class="card" v-for="(skill, index) in skills" :key="skill.id"
            :style="{ transform: `rotateY(${index * (360 / skills.length)}deg) translateZ(${cardRadius}px)` }"
            @click="showDetail(skill)">
            <div class="card-inner">
              <div class="card-front">
                <div class="card-icon">{{ skill.icon }}</div>
                <h3 class="card-title">{{ skill.name }}</h3>
                <div class="card-overlay">点击查看详情</div>
              </div>
            </div>
          </div>
        </div>
      </div>

      <!-- 详情弹窗 -->
      <div class="modal" v-if="selectedSkill" @click="closeDetail()">
        <div class="modal-content" @click.stop>
          <button class="close-btn" @click="closeDetail()">&times;</button>
          <h2 class="modal-title">{{ selectedSkill.name }}</h2>
          <div class="modal-icon">{{ selectedSkill.icon }}</div>
          <p class="modal-description">{{ selectedSkill.description }}</p>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  data() {
    return {
      // 旋转状态控制
      isPaused: false,
      rotationDeg: 0,
      // 卡片配置
      cardRadius: 180,
      rotationSpeed: 0.8,
      // 技能数据
      skills: [
        {
          id: 1,
          name: "C语言",
          icon: "C",
          description: "掌握C语言基础语法与指针操作，能够编写简单的程序，理解内存管理和数据结构基础应用。"
        },
        {
          id: 2,
          name: "HTML",
          icon: "<>",
          description: "熟练使用HTML5语义化标签构建网页结构，掌握表单、多媒体元素及新特性应用，能够创建简单的html页面。"
        },
        {
          id: 3,
          name: "CSS",
          icon: "CSS",
          description: "精通CSS布局技巧，能够实现响应式设计，掌握动画过渡效果和变量使用。"
        },
        {
          id: 4,
          name: "JavaScript",
          icon: "JS",
          description: "掌握JavaScript核心概念，包括异步编程，能够操作DOM实现交互效果，了解ES6+新特性。"
        },
        {
          id: 5,
          name: "Vue",
          icon: "V",
          description: "熟悉Vue框架核心思想，能够使用Vue进行状态管理，掌握组件化开发和生命周期概念。"
        },
        {
          id: 6,
          name: "Linux",
          icon: "L",
          description: "熟悉Linux常用命令，能够进行系统配置和管理，了解Shell脚本基础，能够搭建基本的开发环境。"
        }
      ],
      // 选中的技能卡片
      selectedSkill: null
    };
  },
  methods: {
    // 旋转动画控制
    rotateCards() {
      if (!this.isPaused) {
        this.rotationDeg = (this.rotationDeg + this.rotationSpeed) ;
      }
      requestAnimationFrame(this.rotateCards);
    },
    // 显示技能详情
    showDetail(skill) {
      this.selectedSkill = skill;
      this.isPaused = true; // 显示详情时暂停旋转
    },
    // 关闭详情弹窗
    closeDetail() {
      this.selectedSkill = null;
    }
  },
  mounted() {
    // 启动旋转动画
    this.rotateCards();
  }
};
</script>

<style scoped>
.skills-section {
  background-color: white;
  padding: 40px 30px;
  border-radius: 12px;
  box-shadow: var(--shadow);
  margin: 40px auto;
  max-width: 1000px;
  overflow: hidden;
}

.section-title {
  text-align: center;
  margin-bottom: 30px;
  color: var(--primary-dark);
}

/* 3D卡片容器适配原技能组件布局 */
.skills-3d-container {
  width: 100%;
  height: 300px;
  display: flex;
  justify-content: center;
  align-items: center;
  background-color: var(--bg-light);
  perspective: 1000px;
  border-radius: 8px;
  padding: 20px 0;
}

/* 旋转容器 */
.rotation-container {
  position: relative;
  width: 100%;
  height: 100%;
  transform-style: preserve-3d;
}

/* 卡片 wrapper */
.cards-wrapper {
  position: absolute;
  width: 100%;
  height: 100%;
  transform-style: preserve-3d;
  transition: transform 0.5s ease;
}

/* 单个卡片样式 */
.card {
  position: absolute;
  top: 50%;
  left: 50%;
  width: 200px;
  height: 260px;
  margin: -130px 0 0 -100px;
  transform-style: preserve-3d;
  cursor: pointer;
  transition: var(--transition);
}

.card:hover {
  transform: rotateY(var(--rotation)) translateZ(calc(var(--card-radius) + 30px)) scale(1.05);
  z-index: 10;
}

/* 卡片内部样式 */
.card-inner {
  position: relative;
  width: 100%;
  height: 100%;
  transform-style: preserve-3d;
  transition: var(--transition);
}

/* 卡片正面 */
.card-front {
  position: absolute;
  width: 100%;
  height: 100%;
  backface-visibility: hidden;
  background-color: white;
  border-radius: 12px;
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  box-shadow: var(--shadow);
  background: linear-gradient(135deg, white, var(--primary-light));
  transition: var(--transition);
}

.card:hover .card-front {
  box-shadow: 0 8px 24px rgba(0, 0, 0, 0.15);
}

/* 卡片图标 */
.card-icon {
  font-size: 48px;
  font-weight: bold;
  color: var(--primary-color);
  margin-bottom: 15px;
  transition: var(--transition);
}

.card:hover .card-icon {
  color: var(--primary-dark);
  transform: scale(1.1);
}

/* 卡片标题 */
.card-title {
  font-size: 22px;
  color: var(--text-dark);
  margin: 0 0 10px 0;
  text-align: center;
}

/* 卡片悬停提示 */
.card-overlay {
  position: absolute;
  bottom: 15px;
  font-size: 14px;
  color: var(--text-light);
  opacity: 0;
  transition: var(--transition);
}

.card:hover .card-overlay {
  opacity: 1;
}

/* 弹窗样式 */
.modal {
  position: fixed;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;
  background-color: rgba(0, 0, 0, 0.7);
  display: flex;
  justify-content: center;
  align-items: center;
  z-index: 100;
  animation: fadeIn 0.3s ease;
}

.modal-content {
  background-color: white;
  border-radius: 12px;
  width: 90%;
  max-width: 600px;
  padding: 30px;
  position: relative;
  animation: scaleIn 0.3s ease;
}

.close-btn {
  position: absolute;
  top: 15px;
  right: 15px;
  font-size: 24px;
  background: none;
  border: none;
  cursor: pointer;
  color: var(--text-light);
  transition: var(--transition);
}

.close-btn:hover {
  color: var(--text-dark);
  transform: rotate(90deg);
}

.modal-title {
  color: var(--primary-dark);
  margin-top: 0;
  margin-bottom: 20px;
  text-align: center;
}

.modal-icon {
  font-size: 60px;
  font-weight: bold;
  color: var(--primary-color);
  text-align: center;
  margin-bottom: 25px;
}

.modal-description {
  color: var(--text-dark);
  line-height: 1.6;
  font-size: 16px;
}

/* 动画效果 */
@keyframes fadeIn {
  from { opacity: 0; }
  to { opacity: 1; }
}

@keyframes scaleIn {
  from {
    transform: scale(0.8);
    opacity: 0;
  }
  to {
    transform: scale(1);
    opacity: 1;
  }
}

/* 响应式调整 */
@media (max-width: 768px) {
  .skills-3d-container {
    height: 400px;
  }
  
  .card {
    width: 150px;
    height: 200px;
    margin: -100px 0 0 -75px;
  }

  .card-title {
    font-size: 18px;
  }

  .card-icon {
    font-size: 40px;
  }
}
</style>